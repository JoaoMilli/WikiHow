/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Editor.h
 * Author: joao
 *
 * Created on 25 de Outubro de 2020, 10:58
 */

#ifndef EDITOR_H
#define EDITOR_H

typedef struct editor Editor;

char* retornaNomeEditor (Editor* editor);

void imprimeEditor (Editor* editor);

void destroiEditor (Editor* editor);

Editor* criaEditor (char* nome);

#endif /* EDITOR_H */
