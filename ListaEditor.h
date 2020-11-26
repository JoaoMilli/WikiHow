#ifndef LISTAEDITOR_H
#define LISTAEDITOR_H

/* O TAD ListaEditor armazena tipos Editor utilizando a Estrutura de lista simplesmente encadeada com sentinela */

/*

typedef struct celula Celula;

struct celula{
    Editor* editor;
    Celula* prox;
};

struct lista_editor{
    Celula* prim;
    Celula* ult;
};
 
*/

#include <stdio.h>
#include "Editor.h"

/* Define o tipo ListaEditor */
typedef struct lista_editor ListaEditor;

/* Função que inicia um tipo Lista de editor (TAD ListaEditor)*/
/* inputs: nada */
/* Outputs: endereço de memória do tipo ListaEditor alocado */
ListaEditor* iniciaListaEditor();

/* Função que procura e retorna um editor em uma lista de editores*/
/* inputs: uma lista de editores (TAD ListaEditor), um vetor char contendo o nome do editor*/
/* Outputs: ponteiro (TAD Editor) contendo o endereço do editor com o nome indicado, retorna NULL caso o editor indicado não esteja na lista*/
Editor* retornaEditor(ListaEditor* lista, char chave[20]);

/* Função que insere um editor em uma lista de editores*/
/* inputs: uma lista de editores (TAD ListaEditor), um editor (TAD Editor)*/
/* nada*/
void insereListaEditor (ListaEditor* lista, Editor* editor);

/* Função que imprime os nomes dos editores de uma lista de editores*/
/* inputs: uma lista de editores (TAD ListaEditor)*/
/* Outputs: nada*/
void imprimeListaEditor (ListaEditor* lista);

/* Função que retira e destroi um editor de uma lista de editores, liberando memória associada*/
/* inputs: uma lista de editores (TAD ListaEditores), vetor char contendo o nome do editor a ser removido */
/* Outputs: nada*/
void retiraListaEditor (ListaEditor* lista, char* chave);

/* Função que destroi uma lista de editores, liberando memória associada*/
/* inputs: uma lista de editores (TAD ListaEditores)*/
/* Outputs: nada*/
void destroiListaEditor (ListaEditor* lista);

#endif /* LISTAEDITOR_H */
