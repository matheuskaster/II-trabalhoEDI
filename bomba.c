#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bomba.h"
#include "geometria.h"
#include "poligono.h"
#include "sort.h"
#include "arvore.h"
#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
    double angulo;
    double dist;
    char tipo;
    Segmento original;
} vertice;

void cria_caixa_infinita(Vetor vet) {
    double min = 0, max = 10000;
    Segmento lim1, lim2, lim3, lim4;
    Geometria g = NULL;
    int id = get_ultimo_id();
    char tipo = 'l';
    char* cor = {"#FFEE00"};
    lim1 = transforma_anteparo (id++, min, min, max, min, tipo, cor, g);
    insere_vet (vet, lim1);
    lim2 = transforma_anteparo (id++,max, min, max, max, tipo, cor, g);
    insere_vet (vet, lim2);
    lim3 = transforma_anteparo (id++,max, max, min, max, tipo, cor, g);
    insere_vet (vet, lim3);
    lim4 = transforma_anteparo (id++,min, max, min, min, tipo, cor, g);
    insere_vet (vet, lim4);

    armazena_ultimo_id (id);
}



int compara_vertices (void* a, void* b) {
    vertice* v1 = *(vertice**) a;
    vertice* v2 = *(vertice**) b;

    if (v1->angulo < v2->angulo - 1e-9) return -1;
    if (v1->angulo > v2->angulo + 1e-9) return 1;

    if (v1->dist > v2->dist + 1e-9) return -1;
    if (v1->dist < v2->dist - 1e-9) return 1;

    if (v1->tipo == 'i' && v2->tipo == 'f') return -1;
    if (v1->tipo == 'f' && v2->tipo == 'i') return 1;

    return 0;
}

void a (int i, int j, char direcao, Lista chao, FILE* file_txt, Vetor vet) {
    percorrer_do_inicio_lista(chao);
    Segmento s = NULL;
    int id;
    int ultimo_id = get_ultimo_id();
    char tipo_anteparo = 'a';
    double x, y, x1, y1, x2, y2, raio, xw, yh;
    while (tem_proximo_lista(chao)) {
        Geometria g = get_proximo_lista(chao);
        id = get_id_forma(g);
        if (i <= id && id <= j) {
            char tipo = get_tipo_forma(g);
            
            switch (tipo) {
            case 'c': {
                    Circulo c = get_info_forma(g);
                    x = get_x_circulo(c);
                    y = get_y_circulo(c);
                    raio = get_r_circulo(c);
                    if (direcao == 'v') {
                        x1 = x;
                        y1 = y - raio;
                        x2 = x;
                        y2 = y + raio;
                    }
                    else if (direcao == 'h') {
                        x1 = x - raio;
                        y1 = y;
                        x2 = x + raio;
                        y2 = y;
                    }
                break;
            }
            case 'r': {
                Retangulo r = get_info_forma(g);
                x = get_x_retangulo(r);
                y = get_y_retangulo(r);
                xw = x + get_w_retangulo(r);
                yh = y + get_h_retangulo(r);
                char tipo_anteparo = 'a';
                char* cor = {"#000000"};
                s = transforma_anteparo (ultimo_id++, x, y, xw, y, tipo_anteparo, cor, g);
                insere_vet(vet, s);
                s = transforma_anteparo (ultimo_id++, xw, y, xw, yh, tipo_anteparo, cor, g);
                insere_vet(vet, s);
                s = transforma_anteparo (ultimo_id++, xw, yh, x, yh, tipo_anteparo, cor, g);
                insere_vet(vet, s);
                s = transforma_anteparo (ultimo_id++, x, yh, x, y, tipo_anteparo, cor, g);
                insere_vet(vet, s);
                break;
            }
            case 'l': {
                Linha l = get_info_forma(g);
                x1 = get_x1_linha(l);
                y1 = get_y1_linha(l);
                x2 = get_x2_linha(l);
                y2 = get_y2_linha(l);
                
                break;
            }
            case 't': {
                Texto t = get_info_forma(g);
                
                char a = get_a_texto(t);
                char* txto = get_txto(t);
                double comp = strlen(txto) * 10.0;
                
                double x = get_x_texto(t);
                double y = get_y_texto(t);
                
                if (a == 'i') {
                    x1 = x;
                    x2 = x + comp;
                } else if (a == 'm') {
                    x1 = x - (comp / 2.0);
                    x2 = x + (comp / 2.0);
                } else if (a == 'f') {
                    x1 = x - comp;
                    x2 = x;
                }
                
                y1 = y;
                y2 = y;
                
                break;
            }
            }
            libera_forma(g);
            if (tipo != 'r') {
                char tipo_anteparo = 'a';
                char* cor = {"#000000"};
                s = transforma_anteparo (ultimo_id++, x1, y1, x2, y2, tipo_anteparo, cor, g);
                insere_vet(vet, s);
            }
        }
    }
    armazena_ultimo_id(ultimo_id);
}


void explosao (Vetor vet, double x_bomba, double y_bomba, char tipo_ordenacao, int menos_i) {
    int qtd_anteparos = get_qtd_vetor(vet);
    vertice* vv = malloc(sizeof(vertice) * qtd_anteparos * 4);
    int qtd_v = 0;

    Segmento s;
    double x_ponto1, y_ponto1, x_ponto2, y_ponto2, d1, d2;
    double ang1, ang2;
    for (int i = 0; i < qtd_anteparos; i++) {
        s = get_segmento_qualquer(vet, i);
        x_ponto1 = get_x_p1 (s);
        y_ponto1 = get_y_p1 (s);
        x_ponto2 = get_x_p2 (s);
        y_ponto2 = get_y_p2 (s);
        d1 = distancia_ao_quadrado (x_ponto1, y_ponto1, x_bomba, y_bomba);
        d2 = distancia_ao_quadrado (x_ponto2, y_ponto2, x_bomba, y_bomba);
        
        ang1 = atan2(y_ponto1 - y_bomba, x_ponto1 - x_bomba);
        if (ang1 < 0) ang1 += 2 * PI;
        ang2 = atan2(y_ponto2 - y_bomba, x_ponto2 - x_bomba);
        if (ang2 < 0) ang2 += 2 * PI;
        
        if (fabs(ang1 - ang2) > PI) {
            double maior_ang = (ang1 > ang2) ? ang1 : ang2;
            double x_maior_ang = (ang1 > ang2) ? x_ponto1 : x_ponto2;
            double y_maior_ang = (ang1 > ang2) ? y_ponto1 : y_ponto2;
            
            double menor_ang = (ang1 > ang2) ? ang2 : ang1;
            double x_menor_ang = (ang1 > ang2) ? x_ponto2 : x_ponto1;
            double y_menor_ang = (ang1 > ang2) ? y_ponto2 : y_ponto1;
            
            Ponto p_corte = interseccao_raio_segmento(x_bomba, y_bomba, 0.0, s); 
            vv[qtd_v].x = x_maior_ang;
            vv[qtd_v].y = y_maior_ang;
            vv[qtd_v].angulo = maior_ang;
            vv[qtd_v].dist = distancia_ao_quadrado(x_bomba, y_bomba, x_maior_ang, y_maior_ang);
            vv[qtd_v].tipo = 'i';
            vv[qtd_v].original = s;
            qtd_v++;
            vv[qtd_v].x = get_x_ponto(p_corte);
            vv[qtd_v].y = get_y_ponto(p_corte);
            vv[qtd_v].angulo = 2 * PI;
            vv[qtd_v].dist = distancia_ao_quadrado(x_bomba, y_bomba, get_x_ponto(p_corte), get_y_ponto(p_corte));
            vv[qtd_v].tipo = 'f';
            vv[qtd_v].original = s;
            qtd_v++;
            
            vv[qtd_v].x = get_x_ponto(p_corte);
            vv[qtd_v].y = get_y_ponto(p_corte);
            vv[qtd_v].angulo = 0.0;
            vv[qtd_v].dist = distancia_ao_quadrado(x_bomba, y_bomba, get_x_ponto(p_corte), get_y_ponto(p_corte));
            vv[qtd_v].tipo = 'i';
            vv[qtd_v].original = s;
            qtd_v++;
            vv[qtd_v].x = x_menor_ang;
            vv[qtd_v].y = y_menor_ang;
            vv[qtd_v].angulo = menor_ang;
            vv[qtd_v].dist = distancia_ao_quadrado(x_bomba, y_bomba, x_menor_ang, y_menor_ang);
            vv[qtd_v].tipo = 'f';
            vv[qtd_v].original = s;
            qtd_v++;
            free(p_corte);
        } else {
            if (ang1 < ang2) {
                vv[qtd_v].x = x_ponto1;
                vv[qtd_v].y = y_ponto1;
                vv[qtd_v].angulo = ang1;
                vv[qtd_v].dist = distancia_ao_quadrado(x_bomba, y_bomba, x_ponto1, y_ponto1);
                vv[qtd_v].tipo = 'i';
                vv[qtd_v].original = s;
                qtd_v++;

                vv[qtd_v].x = x_ponto2;
                vv[qtd_v].y = y_ponto2;
                vv[qtd_v].angulo = ang2;
                vv[qtd_v].dist = distancia_ao_quadrado(x_bomba, y_bomba, x_ponto2, y_ponto2);
                vv[qtd_v].tipo = 'f';
                vv[qtd_v].original = s;
                qtd_v++;
            } else {
                vv[qtd_v].x = x_ponto2;
                vv[qtd_v].y = y_ponto2;
                vv[qtd_v].angulo = ang2;
                vv[qtd_v].dist = distancia_ao_quadrado(x_bomba, y_bomba, x_ponto2, y_ponto2);
                vv[qtd_v].tipo = 'i';
                vv[qtd_v].original = s;
                qtd_v++;
                
                vv[qtd_v].x = x_ponto1;
                vv[qtd_v].y = y_ponto1;
                vv[qtd_v].angulo = ang1;
                vv[qtd_v].dist = distancia_ao_quadrado(x_bomba, y_bomba, x_ponto1, y_ponto1);
                vv[qtd_v].tipo = 'f';
                vv[qtd_v].original = s;
                qtd_v++;
            }
        }
    }
    
    void** vpv = malloc(sizeof(void*) * qtd_v);
    for (int i = 0; i < qtd_v; i++) {
        vpv[i] = &vv[i];
    }
    if (tipo_ordenacao == 'q') {
        qsort(vpv, qtd_v, sizeof(vertice*), compara_vertices);
    } else if (tipo_ordenacao == 'm') {
        vertice** aux = malloc (sizeof(vertice*) * qtd_v);
        merge_sort(vpv, aux, 0, qtd_v - 1, menos_i, compara_vertices);
        free(aux);
    }
    
    Poligono area_explosao = cria_poligono();
    Arvore seg_ativos = cria_arvore();
    Segmento biombo = NULL;
    for (int i = 0; i < qtd_v; i++) {
        vertice* v = (vertice*) vpv[i];
        if (v->tipo == 'i') {
            insere_arvore(seg_ativos, v->original, x_bomba, y_bomba);
        } else if (v->tipo == 'f') {
            remove_arvore(seg_ativos, v->original, x_bomba, y_bomba);
        }
        Segmento novo_biombo = segmento_mais_proximo(seg_ativos);
        if (novo_biombo != biombo) {
            if (biombo != NULL) {
                Ponto p = interseccao_raio_segmento(x_bomba, y_bomba, v->angulo, biombo);
                insere_ponto(area_explosao, p);
            }
            if (novo_biombo != NULL) {
                Ponto p = interseccao_raio_segmento(x_bomba, y_bomba, v->angulo, novo_biombo);
                insere_ponto(area_explosao, p);
            }
            biombo = novo_biombo;
        }
        Ponto p = transforma_ponto(v->x, v->y);
        insere_ponto(area_explosao, p);
    }
    free(vpv);
    free(vv);
    libera_arvore(seg_ativos);
}