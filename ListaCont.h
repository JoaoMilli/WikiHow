/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaCont.h
 * Author: joao
 *
 * Created on 29 de Outubro de 2020, 19:58
 */

#ifndef LISTACONT_H
#define LISTACONT_H

#include "Contribuicao.h"

typedef struct lista_cont ListaCont;

ListaCont* iniciaListaCont();

Contribuicao* retornaContribuicao(ListaCont* lista, char chave[20]);

void insereListaCont (ListaCont* lista, Contribuicao* cont);

void imprimeListaCont (ListaCont* lista, char* nome);

void imprimeListaContNomes (ListaCont* lista, char* nome);

void retiraListaCont(ListaCont* lista, char chave[20]);

void destroiListaCont (ListaCont* lista);


#endif /* LISTACONT_H */
