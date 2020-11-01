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
#include "Link.h"
#include "Editor.h"
#include "ListaEditor.h"
#include "Contribuicao.h"
#include "ListaCont.h"
#include "Pagina.h"
#include "ListaPag.h"
#include "ListaLink.h"


int main(int argc, char** argv) {
    
    FILE* log;
    
    log = fopen("log.txt","w");
    fclose(log);
    
    char str1[30], str2[30], str3[30];
    Contribuicao* aux_cont;
    Pagina* aux_pag;
    ListaPag* wiki;
    Editor* aux_ed;
    ListaEditor* editores;
    
    wiki = iniciaListaPagina();
    editores = iniciaListaEditor();
    
    FILE* entrada;
    
    entrada = fopen("entrada.txt","r");
    
    if (entrada == NULL) return 0;
    
    fscanf(entrada, "%s", str1);
    
    while(str1 != "FIM"){
    
        if(str1 == "INSEREPAGINA"){
            fscanf(entrada, "%s", str1);
            fscanf(entrada, "%s", str2);
            aux_pag = iniciaPagina (str2, str1);
            insereListaPag (wiki, aux_pag);
        }
        
        else if(str1 == "RETIRAPAGINA"){
            fscanf(entrada, "%s", str1);
            retiraListaPag (wiki, str1);
        }
        
        else if(str1 == "INSEREEDITOR"){
            fscanf(entrada, "%s", str1);
            aux_ed = criaEditor (str1);
            insereListaEditor (editores, aux_ed);
        }
        
        else if(str1 == "INSERECONTRIBUICAO"){
            fscanf(entrada, "%s", str1);
            fscanf(entrada, "%s", str2);
            fscanf(entrada, "%s", str3);
            aux_ed = retornaEditor(editores, str2);
            aux_cont = iniciaContribuicao (str3, aux_ed);
            aux_pag = retornaPagina(wiki, str1);
            insereListaCont (retornaListaContPag (aux_pag), aux_cont);
        }
        
        else if(str1 == "RETIRACONTRIBUICAO"){
            fscanf(entrada, "%s", str1);
            fscanf(entrada, "%s", str2);
            fscanf(entrada, "%s", str3);
            aux_ed = retornaEditor(editores, str2);
            aux_pag = retornaPagina(wiki, str1);
            retiraListaCont(retornaListaContPag (aux_pag), str3);
        }
        
        else if(str1 == "INSERELINK"){

        }
        
        else if(str1 == "RETIRALINK"){

        }
        
        else if(str1 == "CAMINHO"){

        }
        
        else if(str1 == "IMPRIMEPAGINA"){

        }
        
        else if(str1 == "IMPRIMEWIKED"){

        }
    }
    
    fclose(entrada);
    destroiListaPag (wiki);
    destroiListaEditor (editores);
    return 0;
    
    return (EXIT_SUCCESS);
}

