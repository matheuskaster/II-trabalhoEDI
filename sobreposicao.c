#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sobreposicao.h"
#include "geometria.h"

typedef struct {
    double x_min, x_max, y_min, y_max;
} bounding_box;

bool bb_esta_sobreposta (bounding_box l1, bounding_box l2) {
    return (l1.x_max >= l2.x_min && l1.x_min <= l2.x_max && l1.y_max >= l2.y_min && l1.y_min <= l2.y_max);
}

bounding_box get_limite (Geometria g) {
    bounding_box bb;
    char tipo = get_tipo_forma(g);

    switch (tipo) {
    case 'c' : {
        Circulo c = get_info_forma (g);

        bb.x_min = get_x_circulo(c) - get_r_circulo(c);
        bb.x_max = get_x_circulo(c) + get_r_circulo(c);
        bb.y_min = get_y_circulo(c) - get_r_circulo(c);
        bb.y_max = get_y_circulo(c) + get_r_circulo(c);
        break;
    }
    case 'r' : {Retangulo r = get_info_forma (g);

        bb.x_min = get_x_retangulo (r);
        bb.x_max = get_x_retangulo(r) + get_w_retangulo(r);
        bb.y_min = get_y_retangulo(r);
        bb.y_max = get_y_retangulo(r) + get_h_retangulo(r);
        break;
    }
    case 'l' : {
        Linha l = get_info_forma (g);

        double x1 = get_x1_linha (l);
        double y1 = get_y1_linha (l);
        double x2 = get_x2_linha (l);
        double y2 = get_y2_linha (l);

        bb.x_min = fmin(x1, x2);
        bb.x_max = fmax(x1, x2);
        bb.y_min = fmin(y1, y2);
        bb.y_max = fmax(y1, y2);
        break;
    }
    case 't' : {
        Texto t = get_info_forma (g);
        char a = get_a_texto(t);
        char* txto = get_txto(t);
        double comp = strlen(txto) * 10.0;
        double alt = 0.15;
        double x = get_x_texto(t);
        double y = get_y_texto(t);

        bb.y_min = y;
        bb.y_max = y + alt;
        
        if (a == 'i') {
            bb.x_min = x;
            bb.x_max = x + comp;
        } else if (a == 'm') {
            bb.x_min = x - (comp / 2.0);
            bb.x_max = x + (comp / 2.0);
        } else if (a == 'f') {
            bb.x_min = x - comp;
            bb.x_max = x;
        }
        break;
    }
    default:
        printf("[ERRO] Era para ter recebido uma geometria na função, mas recebeu algo que não possui um tipo válido, deve ser lixo. \n");
        exit(1);
        break;
    }
    return bb;
}

Ponto interseccao_biombo (double x_bomba, double y_bomba, double angulo, Segmento s) {
    double raio_x = x_bomba + 100000 * cos(angulo);
    double raio_y = y_bomba + 100000 * sin(angulo);

    return intercecc
}