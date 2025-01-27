# C_Rank_Sort_Algorithm
# Parallel Rank Sort

This project demonstrates the implementation of a parallel version of the **Rank Sort** algorithm using OpenMP. It performs sorting of randomly generated arrays and measures the performance (execution time) for different array sizes and thread counts.

## Description

The parallel rank sort algorithm works by computing the rank of each element relative to all other elements in the array. For each element, a rank is determined based on how many elements in the array are smaller or equal. This algorithm is then executed in parallel using OpenMP, which splits the computation across multiple threads.

The program compares the performance of the sorting algorithm across different array sizes and thread counts, measuring the time it takes to sort the arrays.

## Requirements

- **C Compiler**: GCC or any compatible C compiler.
- **OpenMP**: Ensure your compiler supports OpenMP for parallelization.

## Compilation and Execution

### Compilation

To compile the program, run the following command:

```bash
gcc -fopenmp -o parallel_rank_sort parallel_rank_sort.c

```bash
./parallel_rank_sort
