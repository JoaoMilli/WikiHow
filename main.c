/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: joao
 *
 * Created on 25 de Outubro de 2020, 10:58
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Editor.h"
#include "ListaEditor.h"


int main(int argc, char** argv) {

    Editor *ed1, *ed2, *ed3, *ed4 ,*ed5;
    ListaEditor* lista_ed;
    
    ed1 = criaEditor("Joao");
    ed2 = criaEditor("Ana");
    ed3 = criaEditor("Maria");
    ed4 = criaEditor("Pedro");
    ed5 = criaEditor("Jorge");
    
    lista_ed = iniciaListaEditor();
    
    insereListaEditor (lista_ed, ed1);
    insereListaEditor (lista_ed, ed2);
    insereListaEditor (lista_ed, ed3);
    insereListaEditor (lista_ed, ed4);
    insereListaEditor (lista_ed, ed5);
    
    imprimeListaEditor (lista_ed);
    printf("\n\n");
    
    retiraLista (lista_ed, "Joao");
    retiraLista (lista_ed, "Jorge");
    retiraLista (lista_ed, "Maria");
    
    imprimeListaEditor (lista_ed);
    printf("\n\n");

    ed1 = criaEditor("Joao");
    ed5 = criaEditor("Jorge");
    
    insereListaEditor (lista_ed, ed1);
    insereListaEditor (lista_ed, ed5);
    
    imprimeListaEditor (lista_ed);
    printf("\n\n");
    
    destroiLista (lista_ed);
   
    
   return (EXIT_SUCCESS);
}

