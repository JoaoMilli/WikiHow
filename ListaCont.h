#ifndef LISTACONT_H
#define LISTACONT_H

/* O TAD ListaCont armazena tipos Contribuicao utilizando a Estrutura de lista simplesmente encadeada com sentinela */

/*

typedef struct celula Celula;

struct celula{
    Contribuicao* cont;
    Celula* prox;
};

struct lista_cont{
    Celula* prim;
    Celula* ult;
};

 
*/

#include "Contribuicao.h"

/* Define o tipo ListaCont */
typedef struct lista_cont ListaCont;

/* Função que inicia um tipo Lista de contribuição (TAD ListaCont)*/
/* inputs: nada */
/* Outputs: endereço de memória do tipo ListaCont alocado */
ListaCont* iniciaListaCont();

/* Função que procura e retorna uma contribuição em uma lista de contribuições*/
/* inputs: uma lista de contribuições (TAD ListaCont), um vetor char contendo o nome da contribuição*/
/* Outputs: ponteiro (TAD Contribuição) contendo o endereço da contribuição com o nome indicado, retorna NULL caso a contribuição indicada não esteja na lista*/
Contribuicao* retornaContribuicao(ListaCont* lista, char chave[20]);

/* Função que insere uma contribuição em uma lista de contribuições*/
/* inputs: uma lista de contribuições (TAD ListaCont), uma contribuição (TAD Contribuicao)*/
/* nada*/
void insereListaCont (ListaCont* lista, Contribuicao* cont);

/* Função que imprime as informações de todas as contribuições contidas em uma lista de contribuições em um arquivo de texto*/
/* inputs: uma lista de contribuições (TAD ListaCont), endereço do nome do arquivo de texto onde a lista será impressa*/
/* Outputs: nada*/
void imprimeListaCont (ListaCont* lista, char* nome);

/* Função que imprime os nomes dos editores que contribuiram na lista de contribuição, assim como o nome de suas contribuições, esta função não imprime o texto das contribuições*/
/* inputs: uma lista de contribuições (TAD ListaCont), endereço do nome do arquivo de texto onde as informações serão impressas */
/* Outputs: nada*/
void imprimeListaContNomes (ListaCont* lista, char* nome);

/* Função que retira e destroi uma contribuição de uma lista de contribuições, liberando memória associada*/
/* inputs: uma lista de contribuições (TAD ListaCont), vetor char contendo o nome da contribuição a ser removida */
/* Outputs: nada*/
void retiraListaCont(ListaCont* lista, char chave[20]);

/* Função que anula uma contribuição de uma lista de contribuições, sem liberar sua memória*/
/* inputs: uma lista de contribuições (TAD ListaCont), vetor char contendo o nome da contribuição a ser anulada */
/* Outputs: nada*/
void removeListaCont(ListaCont* lista, char chave[20]);

/* Função que destroi uma lista de contribuição, liberando memória associada*/
/* inputs: uma lista de contribuições (TAD ListaCont)*/
/* Outputs: nada*/
void destroiListaCont (ListaCont* lista);


#endif /* LISTACONT_H */
