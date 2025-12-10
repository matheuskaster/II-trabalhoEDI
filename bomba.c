#include <stdio.h>
#include <math.h>
#include "bomba.h"
#include "poligono.h"
#include "arvore.h"

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
    lim1 = transforma_anteparo (min, min, max, min, g);
    insere_vet (vet, lim1);
    lim2 = transforma_anteparo (max, min, max, max, g);
    insere_vet (vet, lim2);
    lim3 = transforma_anteparo (max, max, min, max, g);
    insere_vet (vet, lim3);
    lim4 = transforma_anteparo (min, max, min, min, g);
    insere_vet (vet, lim4);
}


void a (int i, int j, char direcao, Lista chao, FILE* file_txt, Vetor vet) {
    percorrer_do_inicio_lista(chao);
    Segmento s = NULL;
    int id;
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
                s = transforma_anteparo (x, y, xw, y, g);
                insere_vet(vet, s);
                s = transforma_anteparo (xw, y, xw, yh, g);
                insere_vet(vet, s);
                s = transforma_anteparo (xw, yh, x, yh, g);
                insere_vet(vet, s);
                s = transforma_anteparo (x, yh, x, y, g);
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
                s = transforma_anteparo (x1, y1, x2, y2, g);
                insere_vet(vet, s);
            }
        }
    }
}


void explosao (Vetor vet, double x_bomba, double y_bomba) {
    int qtd_anteparos = get_qtd_vetor(vet);
    vertice* vv = malloc(sizeof(vertice) * qtd_anteparos * 2);
    int qtd_v = 0;

    Segmento s;
    Arvore seg_ativos = cria_arvore();
    double x_ponto1, y_ponto1, x_ponto2, y_ponto2;
    double ang1, ang2;
    for (int i = 0; i < qtd_anteparos; i++) {
        x_ponto1 = get_x_p1 (s);
        y_ponto1 = get_y_p1 (s);
        x_ponto2 = get_x_p2 (s);
        y_ponto2 = get_y_p2 (s);
        ang1 = atan2(y_ponto1 - y_bomba, x_ponto1 - x_bomba);
        ang2 = atan2(y_ponto2 - y_bomba, x_ponto2 - x_bomba);

        vv[qtd_v].x = x_ponto1;
        vv[qtd_v].y = y_ponto1;        
        vv[qtd_v].angulo = ang1;
        vv[qtd_v].original = s;
        vv[qtd_v].tipo = 'i';
        qtd_v++;

        vv[qtd_v].x = x_ponto2;
        vv[qtd_v].y = y_ponto2;    
        vv[qtd_v].angulo = ang1;
        vv[qtd_v].original = s;
        vv[qtd_v].tipo = 'f';
        qtd_v++;
    }

    //ordena_vetor ordem de ângulo


    Poligono area_explosao = cria_poligono();
    Segmento biombo = NULL;
    for (int i = 0; i < qtd_anteparos; i++) {
        vertice v = vv[i];
        if (v.tipo == 'i') {
            insere_arvore(seg_ativos);
        } else if (v.tipo == 'f') {
            remove_arvore(seg_ativos);
        }
        Segmento novo_biombo = seg_mais_proximo(seg_ativos, x_bomba, y_bomba, v.angulo);
        if (novo_biombo != biombo) {
            Ponto p = interseccao_biombo(x_bomba, y_bomba, v.angulo, novo_biombo);
            insere_ponto(area_explosao, p);
            biombo = novo_biombo;
        }
        Ponto p = transforma_ponto(v.x, v.y);
        insere_ponto(area_explosao, p);
    }
}