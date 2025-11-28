#include "geo.h"
#include "circulo.h"
#include "texto.h"
#include "linha.h"
#include "retangulo.h"
#include "geometria.h"
#include "svg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void geo (Lista chao, FILE* arq_geo) {
    
    if(arq_geo == NULL){
        printf("Arquivo .geo não encontrado. \n");
        exit(1);
    }

    int ultimo_id = 0;

    char linha[256];
    char comando[3];
    Estilo ts = NULL;

    while (fgets(linha, sizeof(linha), arq_geo) != NULL){

        if (linha[0] == '\n' || linha[0] == '#'){
            continue;
        }

        sscanf(linha, "%s", comando);

        if (strcmp(comando, "c") == 0) {
            int id;
            double x, y, r;
            char corb[8], corp[8];
            sscanf (linha, "c %d %lf %lf %lf %s %s", &id, &x, &y, &r, corb, corp);
            if (ultimo_id < id) {
                ultimo_id = id;
            }
            Geometria g = cria_forma_circulo ('c', id, x, y, r, corb, corp);
            insere_lista (chao, g);

        } else if (strcmp(comando, "r") == 0) {
            int id;
            double x, y, w, h;
            char corb[8], corp[8];
            sscanf (linha, "r %d %lf %lf %lf %lf %s %s", &id, &x, &y, &w, &h, corb, corp);
            if (ultimo_id < id) {
                ultimo_id = id;
            }
            Geometria g = cria_forma_retangulo ('r', id, x, y, w, h, corb, corp);
            insere_lista (chao, g);

        } else if (strcmp(comando, "l") == 0) {
            int id;
            double x1,y1,x2,y2;
            char cor[8];
            sscanf (linha, "l %d %lf %lf %lf %lf %s", &id, &x1, &y1, &x2, &y2, cor);
            if (ultimo_id < id) {
                ultimo_id = id;
            }
            Geometria g = cria_forma_linha ('l', id, x1, y1, x2, y2, cor);
            insere_lista (chao, g);

        } else if (strcmp(comando, "t") == 0) {
            int id;
            double x, y;
            char corb[8], corp[8], txto[32];
            char a;
            sscanf (linha, "t %d %lf %lf %s %s %c %s", &id, &x, &y, corb, corp, &a, txto);
            if (ultimo_id < id) {
                ultimo_id = id;
            }
            if (ts == NULL) {
                //criando um estilo padrão, pois não foi informado qual estilo ele quer.
                ts = cria_estilo("sans", "normal", "15");
            } 
            Geometria g = cria_forma_texto ('t', id, x, y, corb, corp, a, txto, ts);
            insere_lista (chao, g);

        } else if (strcmp(comando, "ts") == 0) {
            char family[8], weight[3], size[3];
            sscanf (linha, "ts %s %s %s", family, weight, size);
            if (ts == NULL) {
                //criando um estilo padrão, pois não foi informado qual estilo ele quer.
                ts = cria_estilo(family, weight, size);
            } else {
                set_family_estilo(ts, family);
                set_weight_estilo(ts, weight);
                set_size_estilo(ts, size);
            }
        }
    }
    armazena_ultimo_id (ultimo_id);
}