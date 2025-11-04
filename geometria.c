#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "geometria.h"
#include <math.h>

static int ULTIMO_ID = 0;

typedef struct geometria {
    Forma forma;
    char tipo;
    int id;
} geometria;

Geometria cria_forma_circulo (char tipo, int id, double x, double y, double r, char* corb, char* corp) {
    geometria *g = (geometria*)malloc(sizeof(geometria));
    if (g == NULL){
        printf("Erro na alocação de memória para a criação da forma. \n");
        exit (1);
    }
    g->forma = cria_circulo (id, x, y, r, corb, corp);
    g->tipo = 'c';
    g->id = id;
    return ((geometria*)g);
}

Geometria cria_forma_retangulo (char tipo, int id, double x, double y, double w, double h, char* corb, char* corp) {
    geometria *g = (geometria*)malloc(sizeof(geometria));
    if (g == NULL){
        printf("Erro na alocação de memória para a criação da forma. \n");
        exit (1);
    }
    g->forma = cria_retangulo (id, x, y, w, h, corb, corp);
    g->tipo = 'r';
    g->id = id;
    return ((geometria*)g);
}

Geometria cria_forma_linha (char tipo, int id, double x1, double y1, double x2, double y2, char *cor) {
    geometria *g = (geometria*)malloc(sizeof(geometria));
    if (g == NULL){
        printf("Erro na alocação de memória para a criação da forma. \n");
        exit (1);
    }
    g->forma = cria_linha (id, x1, y1, x2, y2, cor);
    g->tipo = 'l';
    g->id = id;
    return ((geometria*)g);
}

Geometria cria_forma_texto (char tipo, int id, double x, double y, char *corb, char *corp, char a, char *txto, Estilo ts) {
    geometria *g = (geometria*)malloc(sizeof(geometria));
    if (g == NULL){
        printf("Erro na alocação de memória para a criação da forma. \n");
        exit (1);
    }
    g->forma = cria_texto (id, x, y, corb, corp, a, txto, ts);
    g->tipo = 't';
    g->id = id;
    return ((geometria*)g);
}

Forma get_info_forma (Geometria g) {
    return ((geometria*)g)->forma;
}

char get_tipo_forma (Geometria g) {
    return ((geometria*)g)->tipo;
}

int get_id_forma (Geometria g) {
    return ((geometria*)g)->id;
}

void set_x_forma(Geometria g, double x) {
     if (g == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((geometria*)g)->tipo == 'c') {
        set_x_circulo( ((geometria*)g)->forma , x);
    }
    else if (((geometria*)g)->tipo == 'r') {
        set_x_retangulo( ((geometria*)g)->forma, x); 
    }
    else if (((geometria*)g)->tipo == 'l') {
        set_x1_linha( ((geometria*)g)->forma, x);
    }
    else if (((geometria*)g)->tipo == 't') {
        set_x_texto( ((geometria*)g)->forma, x);
    }
}

double get_x_forma(Geometria g){

    if (g == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((geometria*)g)->tipo == 'c') {
        return get_x_circulo( ((geometria*)g)->forma );
    }
    else if (((geometria*)g)->tipo == 'r') {
        return get_x_retangulo( ((geometria*)g)->forma ); 
    }
    else if (((geometria*)g)->tipo == 'l') {
        return get_x1_linha( ((geometria*)g)->forma );
    }
    else if (((geometria*)g)->tipo == 't') {
        return get_x_texto( ((geometria*)g)->forma );
    }
}

void set_y_forma(Geometria g, double y) {
     if (g == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((geometria*)g)->tipo == 'c') {
        set_y_circulo( ((geometria*)g)->forma , y);
    }
    else if (((geometria*)g)->tipo == 'r') {
        set_y_retangulo( ((geometria*)g)->forma, y); 
    }
    else if (((geometria*)g)->tipo == 'l') {
        set_y1_linha( ((geometria*)g)->forma, y);
    }
    else if (((geometria*)g)->tipo == 't') {
        set_y_texto( ((geometria*)g)->forma, y);
    }
}

double get_y_forma(Geometria g){

    if (g == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((geometria*)g)->tipo == 'c') {
        return get_y_circulo( ((geometria*)g)->forma );
    }
    else if (((geometria*)g)->tipo == 'r') {
        return get_y_retangulo( ((geometria*)g)->forma ); 
    }
    else if (((geometria*)g)->tipo == 'l') {
        return get_y1_linha( ((geometria*)g)->forma );
    }
    else if (((geometria*)g)->tipo == 't') {
        return get_y_texto( ((geometria*)g)->forma );
    }
}

double get_area_forma (Geometria g) {
    if (g == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((geometria*)g)->tipo == 'c') {
        return calcula_area_circulo( ((geometria*)g)->forma );
    }
    else if (((geometria*)g)->tipo == 'r') {
        return calcula_area_retangulo( ((geometria*)g)->forma ); 
    }
    else if (((geometria*)g)->tipo == 'l') {
        return calcula_area_linha( ((geometria*)g)->forma );
    }
    else if (((geometria*)g)->tipo == 't') {
        return calcula_area_texto( ((geometria*)g)->forma );
    }
}

void set_corb_forma (Geometria g, char *corb) {
    if (g == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((geometria*)g)->tipo == 'c') {
        set_corb_circulo( ((geometria*)g)->forma, corb );
    }
    else if (((geometria*)g)->tipo == 'r') {
        set_corb_retangulo( ((geometria*)g)->forma, corb ); 
    }
    else if (((geometria*)g)->tipo == 'l') {
        set_cor_linha( ((geometria*)g)->forma, corb );
    }
    else if (((geometria*)g)->tipo == 't') {
        set_corb_texto( ((geometria*)g)->forma, corb );
    }
}

char* get_corb_forma(Geometria g) {
    if (g == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((geometria*)g)->tipo == 'c') {
        return get_corb_circulo( ((geometria*)g)->forma );
    }
    else if (((geometria*)g)->tipo == 'r') {
        return get_corb_retangulo( ((geometria*)g)->forma ); 
    }
    else if (((geometria*)g)->tipo == 'l') {
        return get_cor_linha( ((geometria*)g)->forma );
    }
    else if (((geometria*)g)->tipo == 't') {
        return get_corb_texto( ((geometria*)g)->forma );
    }
}

void set_corp_forma (Geometria g, char *corp) {
    if (g == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((geometria*)g)->tipo == 'c') {
        set_corp_circulo( ((geometria*)g)->forma, corp );
    }
    else if (((geometria*)g)->tipo == 'r') {
        set_corp_retangulo( ((geometria*)g)->forma, corp ); 
    }
    else if (((geometria*)g)->tipo == 'l') return;
    else if (((geometria*)g)->tipo == 't') {
        set_corp_texto( ((geometria*)g)->forma, corp );
    }
}

char* get_corp_forma(Geometria g) {
    if (g == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((geometria*)g)->tipo == 'c') {
        return get_corp_circulo( ((geometria*)g)->forma );
    }
    else if (((geometria*)g)->tipo == 'r') {
        return get_corp_retangulo( ((geometria*)g)->forma ); 
    }
    else if (((geometria*)g)->tipo == 'l') {
        char *cor = get_cor_linha( ((geometria*)g)->forma );
        
        if (cor == NULL || cor[0] != '#') return NULL;
        int R, G, B;
        sscanf(cor, "#%02x%02x%02x", &R, &G, &B);
        int R_complem = 255 - R;
        int G_complem = 255 - G;
        int B_complem = 255 - B;

        char* cor_complem = (char*)malloc(sizeof(char) * 16);
        if (cor_complem == NULL) {
            printf("Erro ao alocar memória para a cor complementar. \n");
            return NULL;
        }
        sprintf (cor_complem, "#%02X%02X%02X", R_complem, G_complem, B_complem);
        return cor_complem;
    }
    else if (((geometria*)g)->tipo == 't') {
        return get_corp_texto( ((geometria*)g)->forma );
    }
}

void armazena_ultimo_id(int ultimo_id) {
    ULTIMO_ID = ultimo_id + 1;
}

int get_ultimo_id() {
    return ULTIMO_ID;
}

Geometria clona_forma(Geometria g) {
    if (g == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    int novo_id = get_ultimo_id();

    if (((geometria*)g)->tipo == 'c') {
        Circulo c = get_info_forma (g);
        double x = get_x_circulo(c);
        double y = get_y_circulo(c);
        double r = get_r_circulo(c);
        char* corb = get_corb_circulo(c);
        char* corp = get_corp_circulo(c);
        ULTIMO_ID++;
        return cria_forma_circulo ('c', novo_id, x, y, r, corp, corb);
    }
    else if (((geometria*)g)->tipo == 'r') {
        Retangulo r = get_info_forma(g);
        double x = get_x_retangulo(r);
        double y = get_y_retangulo(r);
        double w = get_w_retangulo(r);
        double h = get_h_retangulo(r);
        char* corb = get_corb_retangulo(r);
        char* corp = get_corp_retangulo(r);
        ULTIMO_ID++;
        return cria_forma_retangulo('r', novo_id, x, y, w, h, corp, corb);
    }
    else if (((geometria*)g)->tipo == 'l') {
        Linha l = get_info_forma(g);
        double x1 = get_x1_linha(l);
        double y1 = get_y1_linha(l);
        double x2 = get_x2_linha(l);
        double y2 = get_y2_linha(l);
        char* cor = get_cor_linha(l);
        ULTIMO_ID++;
        return cria_forma_linha('l', novo_id, x1, y1, x2, y2, cor);
    }
    else if (((geometria*)g)->tipo == 't') {
        Texto t = get_info_forma(g);
        double x = get_x_texto(t);
        double y = get_y_texto(t);
        char* corb = get_corb_texto(t);
        char* corp = get_corp_texto(t);
        char a = get_a_texto(t);
        char* txto = get_txto(t);
        Estilo ts = get_estilo_texto(t);
        ULTIMO_ID++;
        return cria_forma_texto('t', novo_id, x, y, corp, corb, a, txto, ts);
    }
}

void inverte_cores_forma(Geometria g) {
    if (g == NULL) {
        printf("Erro! A forma passada por parâmetro não existe. \n");
        exit (1);
    }

    if (((geometria*)g)->tipo == 'c') {
        char *cbc = get_corb_circulo( ((geometria*)g)->forma );
        char *cpc = get_corp_circulo( ((geometria*)g)->forma );
        set_corb_circulo(((geometria*)g)->forma, cpc);
        set_corp_circulo(((geometria*)g)->forma, cbc);
    }
    else if (((geometria*)g)->tipo == 'r') {
        char *cbr = get_corb_retangulo( ((geometria*)g)->forma );
        char *cpr = get_corp_retangulo( ((geometria*)g)->forma );
        set_corb_retangulo(((geometria*)g)->forma, cpr);
        set_corp_retangulo(((geometria*)g)->forma, cbr);
    }
    else if (((geometria*)g)->tipo == 'l') {
        Linha l = get_info_forma;
        char *cor = (char*)malloc(sizeof(char)*8);
        *cor = get_cor_linha(l);
        if (cor[0] != '#') return;
        int R, G, B;
        sscanf(cor, "#%02x%02x%02x", &R, &G, &B);
        int R_complem = 255 - R;
        int G_complem = 255 - G;
        int B_complem = 255 - B;
        char nova_cor_borda[16];
        sprintf (nova_cor_borda, "#%02X%02X%02X", R_complem, G_complem, B_complem);
        set_cor_linha (l, nova_cor_borda);
    }
    else if (((geometria*)g)->tipo == 't') {
        char *cbt = get_corb_texto( ((geometria*)g)->forma );
        char *cpt = get_corp_texto( ((geometria*)g)->forma );
        set_corb_texto(((geometria*)g)->forma, cpt);
        set_corp_texto(((geometria*)g)->forma, cbt);
    }
}

void libera_forma(Geometria g) {
    if (g == NULL) return;
    geometria* _g = (geometria*)g;
    if (((geometria*)g)->tipo == 'c') {
        Circulo c = get_info_forma(g);
        libera_circulo(c);
    }
    else if (((geometria*)g)->tipo == 'r') {
        Retangulo r = get_info_forma(g);
        libera_retangulo(r);
    }
    else if (((geometria*)g)->tipo == 'l') {
        Linha l = get_info_forma(g);
        libera_linha(l);
    }
    else if (((geometria*)g)->tipo == 't') {
        Texto t = get_info_forma(g);
        libera_texto(t);
    }
    free(_g);
}