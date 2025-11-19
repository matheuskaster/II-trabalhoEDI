#include "geo.h"
#include "geometria.h"
#include "sobreposicao.h"
#include "qry.h"
#include "svg.h"
#include "stdio.h"
#include "string.h"
#include <stdlib.h>


void qry (Fila chao, FILE* file_qry, FILE* file_svg_qry, FILE* file_txt) {

    abre_svg(file_svg_qry);

    char linha[512];
    char comando[4];
    
    double potuacao = 0.0;
    int num_clones = 0, num_esmagadas = 0;
    int num_disparos = 0;
    
    while (fgets(linha, sizeof(linha), file_qry) != NULL) {
        if(linha[0] == '\n' || linha[0] == '\r'){
            continue;
        }
        
        sscanf(linha, "%s", comando);
        
        if (strcmp(comando, "a") == 0) {
            int i, j;
            char direcao;
            sscanf(linha, "a %i %i %c", &i, &j, &direcao);
        }
        else if (strcmp(comando, "d") == 0) {
            double x, y;
            sscanf(linha, "d %lf %lf", &x, &y, sfx);
        }
        else if (strcmp(comando, "p") == 0) {
            double x, y;
            char *cor = (char*)malloc(strlen(cor)+1);
            if (cor == NULL) {
                printf("Erro ao alocar memória para a cor da bomba. \n");
                exit(1);
            }
            sscanf(linha,"p %lf %lf %i", &x, &y, &cor, sfx);
        }
        else if (strcmp(comando, "cln") == 0) {
            double x, y, dx, dy;
            sscanf(linha, "cln %i %c %i", &x, &y, &dx, &dy, sfx);
        }
    }
}