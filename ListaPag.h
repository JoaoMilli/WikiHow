/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaPag.h
 * Author: joao
 *
 * Created on 30 de Outubro de 2020, 12:38
 */

#ifndef LISTAPAG_H
#define LISTAPAG_H

#include "Pagina.h"

typedef struct lista_pag ListaPag;

ListaPag* iniciaListaPagina();

Pagina* retornaPagina(ListaPag* lista, char chave[20]);

void insereListaPag (ListaPag* lista, Pagina* pag);

void imprimeListaPag (ListaPag* lista);

void retiraListaPag (ListaPag* lista, char* chave);

void destroiListaPag (ListaPag* lista);

void removeLinks(ListaPag* lista, char nome[30]);

#endif /* LISTAPAG_H */
