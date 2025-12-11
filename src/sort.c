#include <stdio.h>
#include "sort.h"

void insertion_sort(void** vet, int ini, int fim, Comparador cmp) {
    for (int i = ini + 1; i <= fim; i++) {
        void* aux = vet[i];
        int j = i - 1;

        /* cmp expects pointers to elements (const void*). For an array of
           void*, the element type is void*, so we pass the address of the
           element (void**) to the comparator. The comparator must cast
           accordingly. The comparator returns negative/positive/zero. */
        while (j >= ini && cmp(&aux, &vet[j]) < 0) {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = aux;
    }
}

void merge_sort (void** vetor, void** aux, int ini, int fim, int menos_i, Comparador cmp) {

    if ((fim - ini + 1) <= menos_i) {
        insertion_sort(vetor, ini, fim, cmp);
        return;
    }

    int meio = (ini + fim) / 2;

    if (ini < fim) {
        merge_sort (vetor, aux, ini, meio,  menos_i, cmp);
        merge_sort (vetor, aux, meio + 1, fim, menos_i, cmp);
    }

    int i = ini;
    int j = meio + 1;
    int k = ini;

    while (i <= meio && j <= fim) {
        /* cmp returns negative if first < second */
        if (cmp(&vetor[i], &vetor[j]) <= 0) {
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