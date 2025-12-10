#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "lista.h"
#include "geo.h"
#include "qry.h"
#include "svg.h"

#define PATH_LEN 250
#define FILE_NAME_LEN 100

void trataPath(char *path, int tamMax, char *arg) {
    int argLen = strlen(arg);
    assert(argLen < tamMax);
    if (arg[argLen - 1] == '/') arg[argLen - 1] = '\0';
    strcpy(path, arg);
}

void trataNomeArquivo(char *path, int tamMax, char *arg) {
    int argLen = strlen(arg);
    assert((argLen + 4) < tamMax);
    sprintf(path, "%s", arg);
}

void extrai_nome_base(char* arq_qry, char* nome_base_qry) {
    if (arq_qry == NULL || nome_base_qry == NULL) {
        printf("Erro ao tentar acessar os parâmetros. \n");
        return;
    }

    char nome_base_tmp[strlen(arq_qry) + 1]; 
    char* ultimo_ponto = strrchr(arq_qry, '.');
    int len_ent;

    if (ultimo_ponto == NULL || ultimo_ponto == arq_qry) {
        strcpy(nome_base_tmp, arq_qry);
    } 
    else {
        len_ent = ultimo_ponto - arq_qry;
        strncpy(nome_base_tmp, arq_qry, len_ent);
        nome_base_tmp[len_ent] = '\0';
    }
    char* ultima_barra = strrchr(nome_base_tmp, '/');
    if (ultima_barra == NULL || ultima_barra == arq_qry) {
        strcpy(nome_base_qry, nome_base_tmp);
    } 
    else {
        //len_ent = ultima_barra - arq_qry;
        strcpy(nome_base_qry, ultima_barra + 1);
        //nome_base_qry[len_ent] = '\0';
    }
}

char* monta_caminho_completo (const char* dir, const char* file) {
    int len = strlen(dir) + strlen(file) + 2;
    char* path = (char*)malloc(len * sizeof(char));
    
    if (dir[strlen(dir) - 1] == '/') {
        sprintf(path, "%s%s", dir, file);
    } else {
        sprintf(path, "%s/%s", dir, file);
    }
    return path;
}

char* atualiza_extensao (const char* dir_saida, const char* nome_arq_entrada, const char* nova_extensao) {

    char* nome_base = (char*)malloc(strlen(nome_arq_entrada) + 1);
    extrai_nome_base((char*)nome_arq_entrada, nome_base);

    char* nome_com_ext = (char*)malloc(strlen(nome_base) + strlen(nova_extensao) + 1);
    sprintf(nome_com_ext, "%s%s", nome_base, nova_extensao);

    char* path_final = monta_caminho_completo (dir_saida, nome_com_ext);

    free(nome_base);
    free(nome_com_ext);

    return path_final;
}

int main(int argc, char *argv[]) {
    char dir_entrada[PATH_LEN] = "./";
    char dir_saida[PATH_LEN] = "";
    char arq_geo[FILE_NAME_LEN] = "";
    char arq_qry[FILE_NAME_LEN] = "";
    char tipo_ordenacao = 'q';
    int menos_i = 15;

    FILE *file_geo = NULL; 
    FILE *file_qry = NULL;
    FILE *file_svg_geo = NULL; 
    FILE *file_svg_qry = NULL; 
    FILE *file_txt = NULL;

    int i = 1;
    while (i < argc) {
        if (strcmp(argv[i], "-i") == 0) {
            if (i + 1 < argc) {
                i++;
                menos_i = atoi(argv[i]);
            }
        }
        if (strcmp(argv[i], "-e") == 0) {
            if (i + 1 < argc) {
                i++;
            trataPath(dir_entrada, PATH_LEN, argv[i]);
            }
        } 
        else if (strcmp(argv[i], "-o") == 0) {
            if (i + 1 < argc) {
                i++;    
            trataPath(dir_saida, PATH_LEN, argv[i]);
            }
        } 
        else if (strcmp(argv[i], "-f") == 0) {
            if (i + 1 < argc) {
                i++;
            trataNomeArquivo(arq_geo, FILE_NAME_LEN, argv[i]);
            }
        } 
        else if (strcmp(argv[i], "-q") == 0) {
            if (i + 1 < argc) {
                i++;
            trataNomeArquivo(arq_qry, FILE_NAME_LEN, argv[i]);
            }
        } 
        else if (strcmp(argv[i], "-to") == 0) {
            if (i + 1 < argc) {
                i++;
            tipo_ordenacao = argv[i][0]
            };
        }
        i++;
    }

    if (strlen(arq_geo) == 0 || strlen(dir_saida) == 0) {
        printf("Faltando -f ou -o, parâmetros que são obrigatórios. \n");
        return 1;
    }

    char* path_geo = monta_caminho_completo(dir_entrada, arq_geo);
    file_geo = fopen(path_geo, "r");
    if (!file_geo) { 
        printf("[ERRO] não foi possível abrir o .geo: %s\n", path_geo);
        return 1; 
    }
    free(path_geo);

    char* path_svg_geo = atualiza_extensao (dir_saida, arq_geo, ".svg");
    file_svg_geo = fopen(path_svg_geo, "w");
    if (!file_svg_geo) { 
        fclose(file_geo);
        printf("[ERRO] não foi possível abrir o svg do .geo.\n");
        return 1;
    }
    free(path_svg_geo);


    Lista chao = cria_lista();
    geo(chao, file_geo);
    abre_svg(file_svg_geo);
    svg(file_svg_geo, chao);
    fecha_svg(file_svg_geo);

    if (strlen(arq_qry) > 0) {

        char* path_qry = monta_caminho_completo(dir_entrada, arq_qry);
        file_qry = fopen(path_qry, "r");
        if (!file_qry) { 
            printf("[ERRO] não foi possível abrir o .qry: %s\n", path_qry);
            return 1; 
        }
        free(path_qry);

        char* path_svg_qry = atualiza_extensao(dir_saida, arq_qry, ".svg");
        char* path_txt_qry = atualiza_extensao(dir_saida, arq_qry, ".txt");

        file_svg_qry = fopen(path_svg_qry, "w");
        file_txt     = fopen(path_txt_qry, "w");
        
        free(path_svg_qry);
        free(path_txt_qry);

        if (file_svg_qry && file_txt) {
            qry(chao, file_qry, file_svg_qry, file_txt, tipo_ordenacao, menos_i); 
        }
    }

    libera_lista(chao);

    if (file_geo)     fclose(file_geo);
    if (file_svg_geo) fclose(file_svg_geo);
    if (file_qry)     fclose(file_qry);
    if (file_svg_qry) fclose(file_svg_qry);
    if (file_txt)     fclose(file_txt);

    return 0;
}