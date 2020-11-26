#ifndef PAGINA_H
#define PAGINA_H

/*O TAD Página armazena um título, uma lista de contribuições, uma lista de links e um nome */

/*

struct pagina{
    char* titulo;
    ListaCont* cont;
    ListaLink* link;
    char* nome;   
};
 
*/


#include "ListaCont.h"

/* Define o tipo Pagina */
typedef struct pagina Pagina;

#include "ListaLink.h"

/* Função que inicia um tipo Página*/
/* inputs: vetor char com nome da página (nome do arquivo no qual a página será impressa), vetor char com o título da página*/
/* Outputs: endereço de memória do tipo Pagina alocado */
Pagina* iniciaPagina (char nome[20], char titulo[20]);

/* Função que imprime todas as informações da página em um arquivo de texto*/
/* inputs: uma página (TAD Pagina)*/
/* Outputs: nada */
void imprimePagina (Pagina* pag);

/* Função que retorna o nome da página*/
/* inputs: uma página (TAD Pagina) */
/* Outputs: ponteiro char contendo o endereço do nome da página*/
char* retornaNomePagina (Pagina* pag);

/* Função que retorna o título da página*/
/* inputs: uma página (TAD Pagina) */
/* Outputs: ponteiro char contendo o endereço do título da página*/
char* retornaTituloPagina (Pagina* pag);

/* Função que destroi uma página e libera memória associada*/
/* inputs: uma página (TAD Pagina) */
/* Outputs: nada*/
void destroiPagina (Pagina* pag);

/* Função que retorna a lista de contribuições da página*/
/* inputs: uma página (TAD Pagina) */
/* Outputs: endereço da lista de contribuições (TAD ListaCont) pertencente a pagina*/
ListaCont* retornaListaContPag (Pagina* pag);

/* Função que retorna a lista de links da página*/
/* inputs: uma página (TAD Pagina) */
/* Outputs: endereço da lista de links (TAD ListaLink) pertencente a pagina*/
ListaLink* retornaListaLinkPag (Pagina* pag);


#endif /* PAGINA_H */
