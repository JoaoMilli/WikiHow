/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaLink.h
 * Author: joao
 *
 * Created on 1 de Novembro de 2020, 16:35
 */

#ifndef LISTALINK_H
#define LISTALINK_H

#include "Link.h"

typedef struct lista_link ListaLink;

ListaLink* iniciaListaLink();

void insereListaLink (ListaLink* lista, Link* link);

void imprimeListaLink (ListaLink* lista);

void retiraListaLink (ListaLink* lista, Link* chave);

void destroiListaLink (ListaLink* lista);

#endif /* LISTALINK_H */
