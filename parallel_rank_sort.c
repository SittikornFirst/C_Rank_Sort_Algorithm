#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

void parallel_rank_sort(int *arr, int *sorted_arr, int n, int threads) {
    #pragma omp parallel num_threads(threads)
    {
        int i, j, rank;
        #pragma omp for schedule(static) 
        for (i = 0; i < n; i++) {
            rank = 0;
            for (j = 0; j < n; j++) {
                if (arr[j] < arr[i] || (arr[j] == arr[i] && j < i)) {
                    rank++;
                }
            }
            sorted_arr[rank] = arr[i];
        }
    }
}

int* generate_random_array(int n) {
    int i;
    int *arr = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100000;  // Random numbers between 0 and 99999
    }
    return arr;
}

int main() {
    int data_sizes[] = {10000, 100000, 500000, 1000000, 2000000};
    int thread_counts[] = {1, 4, 8, 12, 16};
    double start, end;
    int ds;

    printf("Size\tThreads\tTime (seconds)\n");
    for (ds = 0; ds < 5; ds++) {
        int n = data_sizes[ds];
        int *arr = generate_random_array(n);
        int *sorted_arr = (int*)malloc(n * sizeof(int));
        int tc;
        for (tc = 0; tc < 5; tc++) {
            int threads = thread_counts[tc];
            
            start = omp_get_wtime();  // Start time measurement
            parallel_rank_sort(arr, sorted_arr, n, threads);
            end = omp_get_wtime();  // End time measurement

            printf("%d\t%d\t%f\n", n, threads, end - start);
        }

        free(arr);
        free(sorted_arr);
    }

    return 0;
}
