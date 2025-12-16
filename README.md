# Computação Paralela — Laboratórios

Este repositório contém os **laboratórios desenvolvidos na disciplina de Computação Paralela**, com foco em **programação paralela, análise de desempenho e otimizações de memória**, utilizando **OpenMP**, ferramentas de profiling e conceitos clássicos da área.

Os trabalhos exploram desde paralelismo em CPU até noções introdutórias de aceleração em GPU.

---

## 📌 Conteúdos Abordados

* Paralelismo de dados e de tarefas
* Modelo de execução **Fork-Join**
* **OpenMP**: `parallel`, `for`, `schedule`, `reduction`, `critical`, `atomic`, `simd`, `task`
* Análise de **localidade de memória** (espacial e temporal)
* **Cache misses**, cache thrashing e false sharing
* **Blocking (matriz blocada)**
* Leis de **Amdahl** e **Gustafson**
* Profiling de desempenho com **Valgrind / Cachegrind** e **perf`
* Introdução a **OpenACC** e modelo **Host–Device (CPU–GPU)**

---

## 🖥️ Ambiente de Desenvolvimento

Todos os códigos e experimentos deste repositório foram **desenvolvidos, compilados e executados em ambiente Linux**, utilizando:

* **WSL (Windows Subsystem for Linux)**
* **Distribuição Debian**
* Execução em **máquina virtual Linux integrada ao Windows**

Esse ambiente foi escolhido por oferecer maior compatibilidade com ferramentas clássicas de **computação paralela e análise de desempenho**, além de reproduzir um cenário próximo ao encontrado em servidores e ambientes HPC.

---

## 🛠️ Tecnologias Utilizadas

* **C**
* **OpenMP**
* **Valgrind / Cachegrind**
* **perf**
* **OpenACC**
* GCC / Clang
* **Linux (WSL — Debian)**

---

## ▶️ Compilação

### Compilação sequencial

```bash
gcc arquivo.c -o arquivo.exe
```

### Compilação com OpenMP

```bash
gcc arquivo.c -o arquivo.exe -fopenmp
```

---

## 📊 Profiling e Análise de Desempenho

### Cache e localidade de memória (Cachegrind)

```bash
valgrind --tool=cachegrind ./arquivo.exe
cg_annotate cachegrind.out.*
```

### Contadores de desempenho (perf)

```bash
perf stat ./arquivo.exe
```

> Observação: algumas métricas de hardware podem não estar disponíveis em WSL, sendo o **Valgrind/Cachegrind** a principal ferramenta utilizada.

---

## 📂 Organização do Repositório

Cada laboratório contém:

* Código-fonte em **C**
* Versões sequencial e paralela (quando aplicável)
* Experimentos de desempenho
* Observações sobre escalabilidade e uso de memória

---

## 📎 Observações Finais

Este repositório tem caráter **acadêmico**, com foco no aprendizado prático de técnicas de paralelismo e análise de desempenho, priorizando clareza, reprodutibilidade e boas práticas de programação em ambientes Linux.
