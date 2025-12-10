#ifndef TEXTO_H
#define TEXTO_H

typedef void *Texto;
typedef void *Estilo;

// TADs relacionados ao estilo do texto:

/// @brief Cria um estilo que sera atribuido a um texto.
/// @param family familia da fonte, podendo ser, como opção, alguma das seguintes: (sans/sans-serif, serif, cursive).
/// @param weight expessura da fonte, podendo ser, como opção, alguma das seguintes: ( n: normal, b: bold, b+: bolder,l: | lighter).
/// @param size tamanho da fonte.
/// @return Retorna o estilo criado com os parâmetros informados.
Estilo cria_estilo(char *family, char *weight, char *size);

/// @brief O char ponteiro passado por parâmetro na função, torna-se a família da fonte.
/// @param ts É um ponteiro para o estilo do texto.
/// @param family É a nova família da fonte.
void set_family_estilo(Estilo ts, char *family); 

/// @brief Informam qual é a família da fonte do texto.
/// @param ts É um ponteiro para o estilo do texto.
/// @return Retorna a família da fonte.
char* get_family_estilo(Estilo ts);

/// @brief O char ponteiro passado por parâmetro na função, torna-se a expessura da fonte.
/// @param ts É um ponteiro para o estilo do texto.
/// @param weight É a nova expessura da fonte.
void set_weight_estilo(Estilo ts, char *weight);

/// @brief Informam qual é a expessura da fonte do texto.
/// @param ts É um ponteiro para o estilo do texto.
/// @return Retorna a expessura da fonte.
char* get_weight_estilo(Estilo ts);

/// @brief O char ponteiro passado por parâmetro na função, torna-se o tamanho da fonte.
/// @param ts É um ponteiro para o estilo do texto.
/// @param size É o novo tamanho da fonte
void set_size_estilo(Estilo ts, char *size);

/// @brief Informam qual é o tamanho da fonte do texto.
/// @param ts É um ponteiro para o estilo do texto.
/// @return Retorna o tamanho da fonte.
char* get_size_estilo(Estilo ts);

// TADs relacionados ao texto:

/// @brief Cria um texto com as informaçoes relacionadas a cada um dos parâmetros.
/// @param id É o identificador, para saber como se referir a esse texto em específico.
/// @param x É a posicao no eixo x, na qual esta localizada a âncora do texto.
/// @param y É a posicao no eixo y, na qual esta localizada a âncora do texto.
/// @param corb É a cor da borda de cada um dos caracteres do texto.
/// @param corp É a cor de preenchimento de cada um dos caracteres do texto.
/// @param a É um char, feito para poder identificar sobre qual parte do texto ele se refere (começo, meio, ou fim).
/// @param txto É o texto que estará escrito no arquivo .svg da forma texto.
/// @param ts É um ponteiro que aponta para o estilo do texto.
/// @return Retorna um texto criado com os parametros informados.
Texto cria_texto (int id, double x, double y, char *corb, char *corp, char a, char *txto, Estilo ts);

/// @brief O número inteiro passado por parametro pela funçao, torna-se o identificador para saber a qual texto ele se refere.
/// @param c É um ponteiro que aponta para o texto.l
/// @param id É o novo identificador do texto.
void set_id_texto (Texto t, int id);

/// @brief Acessa o texto informado atraves do parametro e mostra qual é o numero identificador dele.
/// @param t É um ponteiro que aponta para o texto.
/// @return Retorna um numero inteiro que é o identificador do texto especificado.
int get_id_texto (Texto t);

/// @brief O double passado por parametro pela funçao, torna-se a posiçao referente a qual coordenada ele se encontra no eixo x.
/// @param t É um ponteiro que aponta para o texto.
/// @param x É a nova coordenada no eixo x, onde esta localizado esse texto.
void set_x_texto (Texto t, double x);

/// @brief Acessa o texto informado pelo parametro e mostra qual é a coordenada no eixo x, na qual esta localizada o texto.
/// @param t É um ponteiro que aponta para o texto.
/// @return Retorna um doble representando a coordenada do eixo x que esta localizada o texto.
double get_x_texto (Texto t);

/// @brief O double passado por parametro pela funçao, torna-se a posiçao referente a qual coordenada ele se encontra no eixo y.
/// @param t É um ponteiro que aponta para o texto.
/// @param x É a nova coordenada no eixo y, onde esta localizado esse texto.
void set_y_texto (Texto t, double y);

/// @brief Acessa o texto informado pelo parametro e mostra qual é a coordenada no eixo y, na qual esta localizada o texto.
/// @param t É um ponteiro que aponta para o texto.
/// @return Retorna um doble representando a coordenada do eixo y que esta localizada o texto.
double get_y_texto (Texto t);

/// @brief O ponteiro para um char passado por parametro na funçao, aponta para uma sequencia de letras determinam uma cor, e essa cor, por meio da funçao, passa a ser a nova cor de borda do texto, tambem passado por parametro.
/// @param r É um ponteiro que aponta para o texto.
/// @param corb É a nova cor do texto.
void set_corb_texto (Texto t, char *corb);

/// @brief Informa qual é a cor de borda do texto.
/// @param t É um ponteiro que aponta para o texto.
/// @return Retorna a cor de borda do texto.
char* get_corb_texto (Texto t);

/// @brief O ponteiro para um char passado por parametro na funçao, aponta para uma sequencia de letras determinam uma cor, e essa cor, por meio da funçao, passa a ser a nova cor de preenchimento do texto, tambem passado por parametro.
/// @param t É um ponteiro que aponta para o texto.
/// @param corp É a nova cor do texto.
void set_corp_texto (Texto t, char *corp);

/// @brief Informa qual é a cor de preenchimento do texto.
/// @param t É um ponteiro que aponta para o texto.
/// @return Retorna a cor de preenchimento do texto.
char* get_corp_texto (Texto t);

/// @brief O char passado por parâmetro na função, será a nova posição relativa do texto, podendo ser i, no inicio; m, no meio, ou f, quando é o fim do texto.
/// @param t É um ponteiro que aponta para o texto.
/// @param a É a nova posição relativa do texto.
void set_a_texto (Texto t, char a);

/// @brief Informa qual é a posição relativa do texto, podendo ser i, no inicio; m, no meio, ou f, quando é o fim do texto.
/// @param t É um ponteiro que aponta para o texto.
/// @return Retorna qual é a posição relativa do texto.
char get_a_texto (Texto t);

/// @brief O ponteiro que aponta para um char, passado por parâmetro na função, aponta para um texto e esse texto será o novo texto que estará escrito no arquivo .svg da forma.
/// @param t É um ponteiro que aponta para o texto.
/// @param txto É o novo texto que estará escrito no SVG da forma.
void set_txto (Texto t, char *txto);

/// @brief Informa qual é o texto que estará escrito no arquivo .svg da forma texto.
/// @param t É um ponteiro que aponta para o texto.
/// @return Retorna qual é o txto do texto. 
char* get_txto (Texto t);

/// @brief O ponteiro que aponta para um char, passado por parâmetro na função, aponta para um estilo, esse estilo será o novo estilo do texto.
/// @param t É um ponteiro que aponta para o texto que terá seu estilo alterado.
/// @param ts É novo estilo do texto.
void set_estilo_texto (Texto t, Estilo ts);

/// @brief Informa qual é o estilo que esse estilo possui.
/// @param t É um ponteiro que aponta para o texto que tem esse estilo.
/// @return Retorna qual é o estilo do texto.
Estilo get_estilo_texto (Texto t);

/// @brief Recebe um texto e o transforma em uma linha, convencionando que seu comprimento é 10 vezes o número de caracteres, os 
/// valores de y1 e y2 são metade de sua altura total, e encontra quem seriam o x1 e x2, tomando com referência o 'a' do texto.
/// @param t É um ponteiro que aponta para o texto que será transformado em linha.
/// @param x1 É o menor valor onde uma das extremidades da linha se encontra no eixo x (referente ao vértice inferior esquerdo), indicando a sua posição no plano.
/// @param y1 É o menor valor onde uma das extremidades da linha se encontra no eixo y (referente ao vértice inferior esquerdo), indicando a sua posição no plano.
/// @param x2 É o maior valor onde uma das extremidades da linha se encontra no eixo x (referente ao vértice superior direito), indicando a sua posição no plano.
/// @param y2 É o maior valor onde uma das extremidades da linha se encontra no eixo y (referente ao vértice superior direito), indicando a sua posição no plano.
void transforma_texto_em_linha (Texto t, double *x1, double *y1, double *x2, double *y2);

/// @brief Calcula a área do texto, convencionando que ela seria calculada como 20 vezes a quantidade de caracteres do texto.
/// @param t É um ponteiro que aponta para o texto que terá sua área calculada.
/// @return Retorna um número double correspondente à área do texto.
double calcula_area_texto (Texto t);

/// @brief Libera toda a memória que tinha sido previamente reservada ao texto para poder ser utilizada novamente.
/// @param t É um ponteiro que aponta para o texto.
void libera_texto(Texto t);

#endif