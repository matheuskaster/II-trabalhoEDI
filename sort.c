#include <stdio.h>
#include "sort.h"

void merge_sort (int* vetor, int* aux, int ini, int fim) {
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

    while (i <= meio) {
        aux[k] = vetor[i];
        i++;
        k++;
    }
    while (j <= fim) {
        aux[k] = vetor[j];
        j++;
        k++;
    }

    for (i = ini; i <= fim; i++) {
        vetor[i] = aux[i];
    }
}

void insertion_sort (int* vet, int fim, int tam) {
    if (fim >= tam) return;
    int aux, j = fim;
    aux = vet[j];
    while (j > 0 && aux < vet[j - 1]) {
        vet[j] = vet[j - 1];
        j--;
    }
    vet[j] = aux;
    insertion_sort(vet, fim + 1, tam);
}