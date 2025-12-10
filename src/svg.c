#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "svg.h"

void abre_svg (FILE* arq_svg) {
    
    if (arq_svg == NULL) {
        printf("O aquivo não exite. \n");
        return;
    }
    fprintf(arq_svg,"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n");
    fprintf(arq_svg,"<svg xmlns:svg=\"http://www.w3.org/2000/svg\" xmlns=\"http://www.w3.org/2000/svg\" width=\"1000\" height=\"1000\">\n");
    fprintf(arq_svg,"<g>\n");
}


void desenha_circulo_svg (FILE* arq_svg, Circulo c) {
    fprintf(arq_svg, "<circle id=\"%d\" style=\"fill:%s;fill-opacity:0.5;stroke:%s\" r=\"%lf\" cy=\"%lf\" cx=\"%lf\" />\n", get_id_circulo(c), get_corp_circulo(c), get_corb_circulo(c), get_r_circulo(c), get_y_circulo(c), get_x_circulo(c));
}

void desenha_retangulo_svg (FILE* arq_svg, Retangulo r) {
    fprintf(arq_svg, "<rect id=\"%d\" style=\"fill:%s;fill-opacity:0.5;stroke:%s\" height=\"%lf\" width=\"%lf\" y=\"%lf\" x=\"%lf\" stroke-width=\"%lf\" />\n", get_id_retangulo(r), get_corp_retangulo(r), get_corb_retangulo(r), get_h_retangulo(r), get_w_retangulo(r), get_y_retangulo(r), get_x_retangulo(r), 1.0);
}

void desenha_linha_svg (FILE* arq_svg, Linha l) {
    fprintf(arq_svg, "<line id=\"%d\" x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\" stroke-width=\"%lf\" />\n", get_id_linha(l), get_x1_linha(l), get_y1_linha(l), get_x2_linha(l), get_y2_linha(l), get_cor_linha(l), 1.0);
}

void desenha_texto_svg (FILE* arq_svg, Texto t, Estilo ts) {
    char a = get_a_texto(t);
           if (a == 'i') {
        fprintf(arq_svg, "<text id=\"%d\" font-size=\"%s\" line-height=\"0\" text-anchor=\"start\" fill=\"%s\" stroke=\"%s\" font-family=\"%s\" font-weight=\"%s\" y=\"%lf\" x=\"%lf\" stroke-width=\"%lf\" ><![CDATA[%s]]></text>\n", get_id_texto(t), get_size_estilo(ts), get_corp_texto(t), get_corb_texto(t), get_family_estilo(ts), get_weight_estilo(ts), get_y_texto(t), get_x_texto(t), 1.0, get_txto(t));
    } else if (a == 'm') {
        fprintf(arq_svg, "<text id=\"%d\" font-size=\"%s\" line-height=\"0\" text-anchor=\"middle\" fill=\"%s\" stroke=\"%s\" font-family=\"%s\" font-weight=\"%s\" y=\"%lf\" x=\"%lf\" stroke-width=\"%lf\" ><![CDATA[%s]]></text>\n", get_id_texto(t), get_size_estilo(ts), get_corp_texto(t), get_corb_texto(t), get_family_estilo(ts), get_weight_estilo(ts), get_y_texto(t), get_x_texto(t), 1.0, get_txto(t));
    } else if (a == 'f') {
        fprintf(arq_svg, "<text id=\"%d\" font-size=\"%s\" line-height=\"0\" text-anchor=\"end\" fill=\"%s\" stroke=\"%s\" font-family=\"%s\" font-weight=\"%s\" y=\"%lf\" x=\"%lf\" stroke-width=\"%lf\" ><![CDATA[%s]]></text>\n", get_id_texto(t), get_size_estilo(ts), get_corp_texto(t), get_corb_texto(t), get_family_estilo(ts), get_weight_estilo(ts), get_y_texto(t), get_x_texto(t), 1.0, get_txto(t));
    }
}

void desenha_forma_svg (FILE* arq_svg, Geometria f) {
    char tipo = get_tipo_forma(f);  

    if (tipo == 'c') {
        Circulo c = get_info_forma (f);
        desenha_circulo_svg (arq_svg, c);
    }
    else if (tipo == 'r') {
        Retangulo r = get_info_forma (f);
        desenha_retangulo_svg (arq_svg, r);
    }
    else if (tipo == 'l') {
        Linha l = get_info_forma (f);
        desenha_linha_svg (arq_svg, l);
    }
    else if (tipo == 't') {
        Texto t = get_info_forma (f);
        Estilo ts = get_estilo_texto (t);
        desenha_texto_svg (arq_svg, t, ts);
    }
}

void desenha_poligono_explosao (FILE* svg, Poligono p) {
    if (svg == NULL || p == NULL) return;

    fprintf(svg, "\t<polygon points=\"");
    int qtd = get_qtd_pontos_poligono(p);

    for (int i = 0; i < qtd; i++) {
        Ponto ponto = get_ponto_poligono(p, i);
        fprintf(svg, "%lf,%lf ", get_x_ponto(ponto), get_y_ponto(ponto));
    }
    Ponto ponto = get_ponto_poligono(p, 0);
    fprintf(svg, "%lf,%lf ", get_x_ponto(ponto), get_y_ponto(ponto));

    fprintf(svg, "\" fill=\"yellow\" opacity=\"0.3\" stroke=\"none\" />\n");
}

void fecha_svg(FILE* arq_svg) {
    if (arq_svg == NULL) {
        printf("Não foi possível acessar o arquivo. \n");
        return;
    }
    fprintf(arq_svg, "</g>\n");
    fprintf(arq_svg,"</svg>\n");
}

void svg (FILE* arq_svg, Lista chao) {
    percorrer_do_inicio_lista(chao);
    while (tem_proximo_lista(chao)) {
        Geometria g = get_proximo_lista(chao);
        if (g != NULL) {
            desenha_forma_svg (arq_svg, g);
        }
    }
}