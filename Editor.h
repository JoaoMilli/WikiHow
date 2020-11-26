#ifndef EDITOR_H
#define EDITOR_H

/*O TAD Editor armazena o nome do editor apenas*/

/*

struct editor{
    char* nome;
};
 
*/

/* Define o tipo Editor */
typedef struct editor Editor;

/* Função que retorna o nome de um editor*/
/* inputs: um editor (TAD Editor) */
/* Outputs: ponteiro char contendo o endereço do nome do editor */
char* retornaNomeEditor (Editor* editor);

/* Função que imprime o nome de um editor*/
/* inputs: um editor (TAD Editor) */
/* Outputs: nada */
void imprimeEditor (Editor* editor);

/* Função que destroi um tipo Editor, liberando memória associada*/
/* inputs: um editor (TAD Editor) */
/* Outputs: nada */
void destroiEditor (Editor* editor);

/* Função que inicia um tipo Editor*/
/* inputs: vetor char contendo o nome do editor*/
/* Outputs: endereço de memória do tipo Editor alocado */
Editor* criaEditor (char nome[20]);

#endif /* EDITOR_H */
