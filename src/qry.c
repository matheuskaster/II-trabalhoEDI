#include "geo.h"
#include "geometria.h"
#include "bomba.h"
#include "sobreposicao.h"
#include "qry.h"
#include "svg.h"
#include "stdio.h"
#include "string.h"
#include <stdlib.h>

void qry (Lista chao, FILE* file_qry, FILE* file_svg_qry, FILE* file_txt, char* path_svg_qry, char tipo_ordenacao, int menos_i) {

    Vetor vet = cria_vet();
    abre_svg(file_svg_qry);
    cria_caixa_infinita(vet);

    char linha[512];
    char comando[4];
    
    while (fgets(linha, sizeof(linha), file_qry) != NULL) {
        if(linha[0] == '\n' || linha[0] == '\r'){
            continue;
        }
        
        sscanf(linha, "%s", comando);
        
        if (strcmp(comando, "a") == 0) {
            int i, j;
            char direcao;
            sscanf(linha, "a %i %i %c", &i, &j, &direcao);
            a(i, j, direcao, chao, file_txt, vet);
        }
        else if (strcmp(comando, "d") == 0) {
            double x, y;
            char sfx[8];
            /* limit string width to avoid overflow */
            sscanf(linha, "d %lf %lf %7s", &x, &y, sfx);
            d(x, y, sfx, chao, file_txt, file_svg_qry, vet, path_svg_qry, tipo_ordenacao, menos_i);
        }
        else if (strcmp(comando, "p") == 0) {
            double x, y;
            char cor[8], sfx[8];
            sscanf(linha,"p %lf %lf %7s %7s", &x, &y, cor, sfx);
            p(x, y, cor, sfx, chao, file_txt, file_svg_qry, vet, path_svg_qry, tipo_ordenacao, menos_i);
        }
        else if (strcmp(comando, "cln") == 0) {
            double x, y, dx, dy;
            char sfx[8];
            sscanf(linha, "cln %lf %lf %lf %lf %7s", &x, &y, &dx, &dy, sfx);
            cln(x, y, dx, dy, sfx, chao, file_txt, file_svg_qry, vet, path_svg_qry, tipo_ordenacao, menos_i);
        }
    }
    svg (file_svg_qry, chao);
    fecha_svg(file_svg_qry);
    libera_vet (vet);
}