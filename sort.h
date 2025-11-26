#ifndef SORT_H
#define SORT_H

/// @brief O merge sort é um algoritmo de ordenação que, por dividir o vetor e depois conquistá-lo, consegue realizar a ordenação tanto no melhor,
/// quanto no pior caso no tempo de nlogn. Complexidade de O(n), pois utiliza um vetor auxiliar que consome memória. Por fim, ele é estável, por 
/// preservar a ordem de elementos com chaves iguais.
///
/// Breve explicação de como isso é realizado: Ele divide o vetor recursivamente apenas com os índices até que cada um tenha somente um elemento, 
/// depois ele junta os elementos de cada subvetor de forma ordenada em um vetor auxiliar, comparando qual dos dois subvetores tem o menor número e o
/// inserindo primeiro, nesse caso que é ordem crescente, e se ainda tiver elementos em algum dos vetores, significa que eles estão ordenados. Após o 
/// vetor auxiliar ter juntado todos os  subvetores de forma ordenada, os elementos do vetor auxiliar são transferidos para o vetor original.
///
/// @param vetor O vetor que deseja ser organizado
/// @param aux O vetor auxiliar, onde são organizados e juntados os subvetores.
/// @param ini É o índice inicial, o que representa a posição do primeiro elemento do subvetor.
/// @param fim É o índice final, o que representa a posição do último elemento do subvetor
void merge_sort (int vetor[], int aux[], int ini, int fim);

#endif