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

void insereListaPag (ListaPag* lista, Pagina* editor);

void imprimeListaPag (ListaPag* lista, char* nome);

void retiraListaPag (ListaPag* lista, char* chave);

void destroiListaPag (ListaPag* lista);

#endif /* LISTAPAG_H */
