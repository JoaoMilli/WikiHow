#ifndef CONTRIBUICAO_H
#define CONTRIBUICAO_H

/*O TAD Contribuicao armazena o texto, o autor da contribuição (TAD Editor), o nome do arquivo no qual o texto foi extraído e um booleano para representar se a contribuição foi removida ou não*/

/*

struct contribuicao{
    char* texto;
    char* nome;
    Editor* autor;
    int removida;
};
 
*/

#include "Editor.h"

/* Define o tipo Contribuicao */
typedef struct contribuicao Contribuicao;

/* Função que inicia um tipo Contribuição através de um arquivo de texto*/
/* inputs: vetor char com nome do arquivo contendo a contribuição, um editor (TAD Editor) */
/* Outputs: endereço de memória do tipo Contribuicao alocado */
Contribuicao* iniciaContribuicao (char nome[20], Editor* editor);

/* Função que imprime todas as informações da contribuição em um arquivo de texto*/
/* inputs: uma contribuição (TAD Contribuicao), ponteiro char contendo o nome do arquivo onde a contribuição será impressa */
/* Outputs: nada */
void imprimeContribuicao (Contribuicao* cont, char* nome);

/* Função que retorna o nome do arquivo contendo o texto da contribuição*/
/* inputs: uma contribuição (TAD Contribuicao) */
/* Outputs: ponteiro char contendo o endereço do nome do arquivo de texto da contribuição*/
char* retornaNomeContribuicao (Contribuicao* cont);

/* Função que retorna o editor que inseriu a contribuição*/
/* inputs: uma contribuição (TAD Contribuicao) */
/* Outputs: ponteiro (TAD Editor) contendo o endereço do editor que inseriu a contribuição*/
Editor* retornaEditorContribuicao (Contribuicao* cont);

/* Função que destroi uma contribuição e libera memória associada*/
/* inputs: uma contribuição (TAD Contribuicao) */
/* Outputs: nada*/
void destroiContribuicao (Contribuicao* cont);

/* Função que anula uma contribuição sem liberar memória associada*/
/* inputs: uma contribuição (TAD Contribuicao) */
/* Outputs: nada*/
void removeContribuicao(Contribuicao* cont);

/* Função que retorna o nome do editor que inseriu a contribuição*/
/* inputs: uma contribuição (TAD Contribuicao) */
/* Outputs: ponteiro char contendo o endereço do nome do editor que inseriu a contribuição*/
char* retornaNomeEditorCont(Contribuicao* cont);

/* Função que checa se uma contribuição foi anulada*/
/* inputs: uma contribuição (TAD Contribuicao) */
/* Outputs: inteiro sendo 1 caso a contribuição tenha sido anulada e 0 caso contrário*/
int retornaRemovida(Contribuicao* cont);

#endif /* CONTRIBUICAO_H */
