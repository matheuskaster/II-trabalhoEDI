#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "sobreposicao.h"
#include "geometria.h"
#include "arvore.h"
#include "poligono.h"
#define PI 3.14159265358979323846

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

bounding_box limite_poligono (double xmin, double ymin, double xmax, double ymax) {
    bounding_box bb;
    bb.x_min = xmin;
    bb.y_min = ymin;
    bb.x_max = xmax;
    bb.y_max = ymax;
    return bb;
}

double distancia_ao_quadrado (double x1, double y1, double x2, double y2) {
    return (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
}

bool p1_eh_inicio(double bx, double by, double x1, double y1, double x2, double y2) {
    double ang1 = atan2(y1 - by, x1 - bx);
    if (ang1 < 0) ang1 += 2 * PI;
    double ang2 = atan2(y2 - by, x2 - bx);
    if (ang2 < 0) ang2 += 2 * PI;
    
    if (ang1 < ang2) return true;
    return false;
}


int orientation(double px, double py, double qx, double qy, double rx, double ry) {
    double val = (qy - py) * (rx - qx) - (qx - px) * (ry - qy);
    if (fabs(val) < 1e-9) return 0;
    return (val > 0) ? 1 : 2;
}

int lado_ponto_relacao_segmento (Segmento st, Segmento sr, double bx, double by) {
    double st_x1 = get_x_p1(st);
    double st_y1 = get_y_p1(st);
    double st_x2 = get_x_p2(st);
    double st_y2 = get_y_p2(st);

    double st_ini_x, st_ini_y, st_fim_x, st_fim_y;
    if (p1_eh_inicio(bx, by, st_x1, st_y1, st_x2, st_y2)) {
        st_ini_x = st_x1;
        st_ini_y = st_y1;
        st_fim_x = st_x2;
        st_fim_y = st_y2;
    } else {
        st_ini_x = st_x2;
        st_ini_y = st_y2;
        st_fim_x = st_x1;
        st_fim_y = st_y1;
    }

    double sr_x1 = get_x_p1(sr);
    double sr_y1 = get_y_p1(sr);
    double sr_x2 = get_x_p2(sr);
    double sr_y2 = get_y_p2(sr);
    
    double sr_ini_x, sr_ini_y;
    
    if (p1_eh_inicio(bx, by, sr_x1, sr_y1, sr_x2, sr_y2)) {
        sr_ini_x = sr_x1;
        sr_ini_y = sr_y1;
    } else {
        sr_ini_x = sr_x2;
        sr_ini_y = sr_y2;
    }

    int o = orientation(st_ini_x, st_ini_y, st_fim_x, st_fim_y, sr_ini_x, sr_ini_y);
    
    if (o == 2) return 1;
    if (o == 1) return -1;
    else return 0;
}

bool onSegment(double px, double py, double qx, double qy, double rx, double ry) {
    if (qx <= fmax(px, rx) && qx >= fmin(px, rx) && qy <= fmax(py, ry) && qy >= fmin(py, ry)) return true;
    return false;
}

bool segmentos_se_intersectam(Ponto p1, Ponto q1, Ponto p2, Ponto q2) {
    double p1x = get_x_ponto(p1), p1y = get_y_ponto(p1);
    double q1x = get_x_ponto(q1), q1y = get_y_ponto(q1);
    double p2x = get_x_ponto(p2), p2y = get_y_ponto(p2);
    double q2x = get_x_ponto(q2), q2y = get_y_ponto(q2);

    int o1 = orientation(p1x, p1y, q1x, q1y, p2x, p2y);
    int o2 = orientation(p1x, p1y, q1x, q1y, q2x, q2y);
    int o3 = orientation(p2x, p2y, q2x, q2y, p1x, p1y);
    int o4 = orientation(p2x, p2y, q2x, q2y, q1x, q1y);

    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && onSegment(p1x, p1y, p2x, p2y, q1x, q1y)) return true;
    if (o2 == 0 && onSegment(p1x, p1y, q2x, q2y, q1x, q1y)) return true;
    if (o3 == 0 && onSegment(p2x, p2y, p1x, p1y, q2x, q2y)) return true;
    if (o4 == 0 && onSegment(p2x, p2y, q1x, q1y, q2x, q2y)) return true;
    return false;
}

Ponto get_interseccao_ponto(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
    double determinante = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    if (determinante == 0) {
        Ponto erro = transforma_ponto(NAN, NAN);
        return erro;
    }
    double t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / determinante;
    double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / determinante;
    if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
        double x = x1 + t * (x2 - x1);
        double y = y1 + t * (y2 - y1);
        Ponto p = transforma_ponto(x, y);
        return p;
    } else {
        Ponto erro = transforma_ponto(NAN, NAN);
        return erro;
    }
}

Ponto interseccao_raio_segmento(double x_bomba, double y_bomba, double angulo, Segmento s) {
    double fim_raio_x = x_bomba + 100000.0 * cos(angulo);
    double fim_raio_y = y_bomba + 100000.0 * sin(angulo);
    double s_x1 = get_x_p1(s);
    double s_y1 = get_y_p1(s);
    double s_x2 = get_x_p2(s);
    double s_y2 = get_y_p2(s);
    Ponto impacto = get_interseccao_ponto(x_bomba, y_bomba, fim_raio_x, fim_raio_y, s_x1, s_y1, s_x2, s_y2);
    return impacto;
}