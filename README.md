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

## 🧪 Estrutura dos Laboratórios

### 🔹 Lab 01 – Introdução ao Paralelismo
- Conceitos básicos de paralelismo
- Modelo Fork-Join
- Primeiros exemplos com OpenMP

---

### 🔹 Lab 02 – Paralelismo de Laços (`omp for`)
- Paralelização de laços `for`
- Balanceamento de carga
- Uso das políticas `schedule(static, dynamic, guided)`

---

### 🔹 Lab 03 – Condição de Corrida e Sincronização
- Identificação de **race conditions**
- Uso de:
  - `critical`
  - `atomic`
  - `reduction`
- Comparação de desempenho entre abordagens

---

### 🔹 Lab 04 – Projeto de Algoritmos Paralelos I
- Multiplicação de matrizes
- Comparação entre ordens de laço (**IJK vs IKJ**)
- Impacto da **localidade de cache**
- Mapeamento 1D e problemas de acesso à memória

---

### 🔹 Lab 05 – Projeto de Algoritmos Paralelos II
- Paralelismo de tarefas com `omp task`
- Implementação paralela do **Quicksort**
- Diferença entre:
  - Paralelismo de dados
  - Fila de tarefas

---

### 🔹 Lab 06 – Projeto de Algoritmos Paralelos III
- Algoritmos iterativos com múltiplas fases
- **Odd-Even Sort paralelo**
- Análise de:
  - Barreiras implícitas
  - Overhead de sincronização
  - Escalabilidade limitada

---

### 🔹 Lab 07 – Localidade e Otimização de Cache
- **Blocking (matriz blocada)**
- Localidade espacial vs temporal
- Redução de cache misses
- Comparação entre versões serial e paralela

---

### 🔹 Lab 08 – Profiling e Análise de Desempenho
- Uso do **Valgrind / Cachegrind**
- Métricas analisadas:
  - Cache hits e misses
  - Taxa de miss
  - Instruções executadas
- Identificação de gargalos de memória

---

### 🔹 Lab 09 – Estudo de Caso Completo
- Processamento massivo de dados
- Construção e uso de **Tabela Hash**
- Paralelização com OpenMP
- Análise de:
  - Parede da Memória
  - Parede da Sincronização

---

### 🔹 Lab 10 – Introdução à Programação em GPU
- Modelo **Host–Device**
- Introdução ao **OpenACC**
- Transferência de dados via PCIe
- Conceito da **Muralha do PCIe**

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
gcc -fopenmp -O2 arquivo.c -o programa