#ifndef LISTALINK_H
#define LISTALINK_H

/* O TAD ListaLink armazena tipos Link utilizando a Estrutura de lista simplesmente encadeada com sentinela */

/*

typedef struct celula Celula;

struct celula{
    Link* link;
    Celula* prox;
};

struct lista_link{
    Celula* prim;
    Celula* ult;
};

 
*/

#include "Link.h"
#include "Pagina.h"
#include "ListaPag.h"

/* Define o tipo ListaLink */
typedef struct lista_link ListaLink;

/* Função que inicia um tipo Lista de links (TAD ListaLink)*/
/* inputs: nada */
/* Outputs: endereço de memória do tipo ListaLink alocado */
ListaLink* iniciaListaLink();

/* Função que procura e retorna um link em uma lista de links*/
/* inputs: uma lista de links (TAD ListaLink), um vetor char contendo o nome do título da página (TAD Pagina) que o link contém*/
/* Outputs: ponteiro (TAD Link) contendo o endereço do link com o nome indicado, retorna NULL caso o link indicado não esteja na lista*/
Link* retornaLink (ListaLink* lista, char chave[20]);

/* Função que insere um link em uma lista de links*/
/* inputs: uma lista de links (TAD ListaLink), um link (TAD Link)*/
/* nada*/
void insereListaLink (ListaLink* lista, Link* link);

/* Função que imprime os títulos e os nomes das páginas contidas em uma lista de links em um arquivo de texto*/
/* inputs: uma lista de links (TAD ListaLink), endereço do nome do arquivo de texto onde as informações serão impressas*/
/* Outputs: nada*/
void imprimeListaLink (ListaLink* lista, char* nome);

/* Função que retira e destroi um link de uma lista de links, liberando memória associada*/
/* inputs: uma lista de link (TAD ListaLink), um link (TAD Link) a ser removido */
/* Outputs: nada*/
void retiraListaLink (ListaLink* lista, Link* chave);

/* Função que destroi uma lista de links, liberando memória associada*/
/* inputs: uma lista de links (TAD ListaLink)*/
/* Outputs: nada*/
void destroiListaLink (ListaLink* lista);

/* Função que retira e destroi um link de uma lista de links dado a página pertencente a esse link, liberando memória associada*/
/* inputs: uma lista de link (TAD ListaLink), uma página (TAD Pagina) contida no link a ser removido */
/* Outputs: nada*/
void retiraPaginaLink (ListaLink* lista, Pagina* pagina);

/* Função que checa se existe caminho direto ou indireto de links entre duas páginas*/
/* inputs: uma página p1 (TAD Página) onde se iniciará a procura, uma página p2 (TAD Pagina) de destino */
/* Outputs: um inteiro sendo 1 caso exista caminho direto ou indireto entre p1 e p2 e 0 caso contrário*/
int Caminho (Pagina* p1, Pagina* p2);

#endif /* LISTALINK_H */
