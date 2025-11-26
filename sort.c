#include <stdio.h>
#include "sort.h"

void merge_sort (int vetor[], int aux[], int ini, int fim) {
    int meio, i, j, k;

    meio = (ini + fim) / 2;

    if (ini < fim) {
        merge_sort (vetor, aux, ini, meio);
        merge_sort (vetor, aux, meio + 1, fim);
    }

    i = ini;
    j = meio + 1;
    k = ini;

    while (i <= meio && j <= fim) {
        if (vetor[i] < vetor[j]) {
            aux[k] = vetor[i];
            i++;
        }
        else {
            aux[k] = vetor[j];
            j++;
        }
        k++;
    }

    while (i < meio) {
        aux[k] = vetor[i];
        i++;
        k++;
    }
    while (j <= fim) {
        aux[k] = vetor[j];
        j++;
        k++;
    }

    for (int i = ini; i < fim; i++) {
        vetor[i] = aux[i];
    }
}