# Computação Paralela — Laboratórios

Este repositório contém os **laboratórios desenvolvidos na disciplina de Computação Paralela**, com foco em **programação paralela, análise de desempenho e otimizações de memória**, utilizando **OpenMP**, ferramentas de profiling e conceitos clássicos da área.

Os trabalhos exploram desde paralelismo em CPU até noções introdutórias de aceleração em GPU.

---

## 📌 Conteúdos Abordados

- Paralelismo de dados e de tarefas
- Modelo de execução **Fork-Join**
- **OpenMP**: `parallel`, `for`, `schedule`, `reduction`, `critical`, `atomic`, `simd`, `task`
- Análise de **localidade de memória** (espacial e temporal)
- **Cache misses**, cache thrashing e false sharing
- **Blocking (matriz blocada)**
- Leis de **Amdahl** e **Gustafson**
- Profiling de desempenho com **Valgrind / Cachegrind** e **perf**
- Introdução a **OpenACC** e modelo **Host–Device (CPU–GPU)**

---

## 🛠️ Tecnologias Utilizadas

- **C**
- **OpenMP**
- **Valgrind / Cachegrind**
- **perf**
- **OpenACC**
- GCC / Clang
- Linux / WSL

---

## ▶️ Compilação

Exemplo de compilação com OpenMP:
```bash
gcc arquivo.c -o arquivo.exe -fopenmp
