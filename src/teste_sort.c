#include <stdio.h>
#include "sort.h"

#define TAM 10

void print_vet (int vet[]) {
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int main () {
    int vet[TAM] = {5, 10, 1, 8, 7, 3, 4, 9, 2, 0};
    int aux[TAM];
    printf("--- Teste: merge sort. --- \n");
    printf("Vetor não ordenado: ");
    print_vet (vet);
    merge_sort(vet, aux, 0, TAM - 1);
    printf("Vetor ordenado: ");
    print_vet(vet);
}