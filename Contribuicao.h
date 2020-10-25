/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Contribuicao.h
 * Author: joao
 *
 * Created on 25 de Outubro de 2020, 12:27
 */

#ifndef CONTRIBUICAO_H
#define CONTRIBUICAO_H

#include "Editor.h"

typedef struct contribuicao Contribuicao;

Contribuicao* iniciaContribuicao (char nome[20], Editor* editor);

void imprimeContribuicao (Contribuicao* cont, char* nome);

char* retornaNomeContribuicao (Contribuicao* cont);

Editor* retornaEditorContribuicao (Contribuicao* cont);

void destroiContribuicao (Contribuicao* cont);

void removeContribuicao(Contribuicao* cont);

#endif /* CONTRIBUICAO_H */
