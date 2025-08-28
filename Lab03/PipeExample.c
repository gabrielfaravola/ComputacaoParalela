            close(pipes[i][1]); // pai não escreve
        }
    }

    // Pai lê resultados dos filhos e soma
    for (int i = 0; i < NUM_PROCESSES; i++) {
        int partial_sum;
        read(pipes[i][0], &partial_sum, sizeof(int));
        close(pipes[i][0]);
        total_sum += partial_sum;
    }

    // Espera todos os filhos terminarem
    for (int i = 0; i < NUM_PROCESSES; i++) {
        waitpid(pids[i], NULL, 0);
    }

    clock_gettime(CLOCK_MONOTONIC, &end_time); // marcador final

    double final_time = (end_time.tv_sec - start_time.tv_sec) +
                        (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    printf("Soma total: %d\n", total_sum);
    printf("Tempo total: %f segundos\n", final_time);

    free(vector);
    return 0;
}
