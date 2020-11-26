#ifndef LISTAPAG_H
#define LISTAPAG_H

/* O TAD ListaPag armazena tipos Pagina utilizando a Estrutura de lista simplesmente encadeada com sentinela */

/*

typedef struct celula Celula;

struct celula{
    Pagina* pag;
    Celula* prox;
};

struct lista_pag{
    Celula* prim;
    Celula* ult;
};

 
*/


/* Define o tipo ListaPag */
typedef struct lista_pag ListaPag;

#include "Pagina.h"

/* Função que inicia um tipo Lista de páginas (TAD ListaPag)*/
/* inputs: nada */
/* Outputs: endereço de memória do tipo ListaPag alocado */
ListaPag* iniciaListaPagina();

/* Função que procura e retorna uma página em uma lista de páginas*/
/* inputs: uma lista de página (TAD ListaPag), um vetor char contendo o nome da página*/
/* Outputs: ponteiro (TAD Pagina) contendo o endereço da página com o nome indicado, retorna NULL caso a página indicada não esteja na lista*/
Pagina* retornaPagina(ListaPag* lista, char chave[20]);

/* Função que insere uma página em uma lista de páginas*/
/* inputs: uma lista de páginas (TAD ListaPag), uma página (TAD Pagina)*/
/* nada*/
void insereListaPag (ListaPag* lista, Pagina* pag);

/* Função que imprime as informações de todas as páginas contidas em uma lista de páginas em arquivos de texto (um para cada página)*/
/* inputs: uma lista de páginas (TAD ListaPag)*/
/* Outputs: nada*/
void imprimeListaPag (ListaPag* lista);

/* Função que retira e destroi uma página de uma lista de páginas, liberando memória associada*/
/* inputs: uma lista de páginas (TAD ListaPag), vetor char contendo o título da página a ser removida */
/* Outputs: nada*/
void retiraListaPag (ListaPag* lista, char* chave);

/* Função que retira uma página de uma lista de páginas, sem liberar memória da página retirada*/
/* inputs: uma lista de páginas (TAD ListaPag), vetor char contendo o título da página a ser removida */
/* Outputs: nada*/
void retiraListaPagSD (ListaPag* lista, char* chave);

/* Função que destroi uma lista de páginas, liberando memória associada*/
/* inputs: uma lista de páginas (TAD ListaPag)*/
/* Outputs: nada*/
void destroiListaPag (ListaPag* lista);

/* Função que destroi uma lista de páginas, sem liberar memória das páginas contidas*/
/* inputs: uma lista de páginas (TAD ListaPag)*/
/* Outputs: nada*/
void destroiListaPagCelulas (ListaPag* lista);

/* Função que retira o link de uma página de todas as listas de links de todas as páginas de uma lista de páginas*/
/* inputs: uma lista de páginas (TAD ListaPag), vetor char contendo o título da página contida nos links a serem removidos*/
/* Outputs: nada*/        
void removeLinks(ListaPag* lista, char nome[30]);

/* Função que retorna a primeira página de uma lista de páginas*/
/* inputs: uma lista de páginas (TAD ListaPag)*/
/* Outputs: ponteiro (TAD Pagina) contendo o endereço da primeira página da lista*/   
Pagina* retornaPrim(ListaPag* lista);

/* Função que checa se uma lista de páginas está vazia*/
/* inputs: uma lista de páginas (TAD ListaPag)*/
/* Outputs: inteiro que será 1 caso a lista esteja vazia e 0 caso contrário*/   
int vazia (ListaPag* lista);

#endif /* LISTAPAG_H */
