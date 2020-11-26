#ifndef LINK_H
#define LINK_H

/*O TAD Link armazena um endereço de uma página (TAD Pagina)*/

/*

struct link{
    Pagina* pag;
};
 
*/

/* Define o tipo Link */
typedef struct link Link;

#include "Pagina.h"

/* Função que inicia um tipo Link através de um endereço de página (TAD Pagina)*/
/* inputs: um endereço de página (TAD Pagina) */
/* Outputs: endereço de memória do tipo Link alocado */
Link* iniciaLink(Pagina* pag);

/* Função que imprime o título da página (TAD Pagina) de um link em um arquivo de texto*/
/* inputs: um link (TAD Link), ponteiro char contendo o nome do arquivo onde o título da página do link será impresso */
/* Outputs: nada */
void imprimeTituloLink(Link* link, char* nome);

/* Função que imprime o nome da página (TAD Pagina) de um link em um arquivo de texto, o nome da página será o nome do arquivo no qual a página (TAD Página) será impressa*/
/* inputs: um link (TAD Link), ponteiro char contendo o nome do arquivo onde o nome da página do link será impresso */
/* Outputs: nada */
void imprimeNomeLink(Link* link, char* nome);

/* Função que destroi um link e libera memória associada*/
/* inputs: um link (TAD Link) */
/* Outputs: nada*/
void destroiLink(Link* link);

/* Função que retorna o endereço da página contida em um link*/
/* inputs: um link (TAD Link)*/
/* Outputs: endereço da página (TAD Pagina) contido no link (TAD Link) */
Pagina* retornaPagLink(Link* link);

#endif /* LINK_H */
