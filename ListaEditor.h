/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaEditor.h
 * Author: joao
 *
 * Created on 25 de Outubro de 2020, 11:07
 */

#ifndef LISTAEDITOR_H
#define LISTAEDITOR_H

#include <stdio.h>
#include "Editor.h"

typedef struct lista_editor ListaEditor;

ListaEditor* iniciaListaEditor();

void insereListaEditor (ListaEditor* lista, Editor* editor);

void imprimeListaEditor (ListaEditor* lista);

void retiraListaEditor (ListaEditor* lista, char* chave);

void destroiListaEditor (ListaEditor* lista);

#endif /* LISTAEDITOR_H */
