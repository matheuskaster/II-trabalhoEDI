#include <stdio.h>
#include "bomba.h"

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
            if (tipo != 'r') {
                s = transforma_anteparo (x1, y1, x2, y2, g);
                insere_vet(vet, s);
            }
        }
    }
}