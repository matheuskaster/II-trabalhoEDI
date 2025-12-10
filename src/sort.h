#ifndef SORT_H
#define SORT_H

/// @brief É um ponteiro para a função "compara_vertices", escrita no bomba.c. O que toda essa linha quer dizer, é que ao passar esse comparador, ele
/// vai pro endereço de memória que está apontando essa variável e os valores em parenteses passados após a escrita do comparador tem que ser variáveis
/// do tipo void*, porque a função vai tranformá-las no tipo vertice* e ver qual é o ângulo, distância e tipo da variável para poder ordená-las de
/// a cordo com a maneira que foi solicitado. Retornando os valores inteiros: -1 se for antes, 1 se for depois e 0 se tudo forem iguais.
typedef int (*Comparador)(void* a, void* b);

/// @brief O merge sort é um algoritmo de ordenação que, por dividir o vetor e depois conquistá-lo, consegue realizar a ordenação tanto no melhor,
/// quanto no pior caso no tempo de nlogn. Complexidade de O(n), pois utiliza um vetor auxiliar que consome memória. Por fim, ele é estável, por 
/// preservar a ordem de elementos com chaves iguais.
///    Breve explicação de como isso é realizado: Ele divide o vetor recursivamente apenas com os índices até que cada um tenha somente um elemento, 
/// depois ele junta os elementos de cada subvetor de forma ordenada em um vetor auxiliar, comparando qual dos dois subvetores tem o menor número e o
/// inserindo primeiro, nesse caso que é ordem crescente, e se ainda tiver elementos em algum dos vetores, significa que eles estão ordenados. Após o 
/// vetor auxiliar ter juntado todos os  subvetores de forma ordenada, os elementos do vetor auxiliar são transferidos para o vetor original.
///
/// @param vetor O vetor que deseja ser organizado
/// @param aux O vetor auxiliar, onde são organizados e juntados os subvetores.
/// @param ini É o índice inicial, o que representa a posição do primeiro elemento do subvetor.
/// @param fim É o índice final, o que representa a posição do último elemento do subvetor
/// @param menos_i É o número que informa qual é o tamanho pequeno suficiente para ele começar a utilizar o insertion sort, ele é iniciado com 15 caso
/// o programa não informe. 
/// @param cmp É um ponteiro para a função de comparação. A utilização dela é escrevê-la e colocar entre parênteses depois os parâmetros da função.
void merge_sort (void** vetor, void** aux, int ini, int fim, int menos_i, Comparador cmp);

#endif