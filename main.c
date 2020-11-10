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
    Pagina* aux_pag, *aux_pag2;
    ListaPag* wiki;
    Editor* aux_ed;
    ListaEditor* editores;
    Link* aux_link;
    
    wiki = iniciaListaPagina();
    editores = iniciaListaEditor();
    
    FILE* entrada;
    
    entrada = fopen("entrada.txt","r");
    
    if (entrada == NULL){
        return 0;
    }
    
    fscanf(entrada, "%s", str1);
    
    while(strcmp(str1, "FIM")){
    
        if(!strcmp(str1, "INSEREPAGINA")){
            fscanf(entrada, "%s", str1);
            fscanf(entrada, "%s", str2);
            aux_pag = iniciaPagina (str2, str1);
            insereListaPag (wiki, aux_pag);
        }
        
        else if(!strcmp(str1, "RETIRAPAGINA")){
            fscanf(entrada, "%s", str1);
            aux_pag = retornaPagina(wiki, str1);
            if (aux_pag == NULL){
                log = fopen("log.txt","a");
                fprintf(log, "ERRO: Pagina nao existe para retirada\n");
                fclose(log);
            }
            else{
                removeLinks(wiki, str1);
                retiraListaPag (wiki, str1);
            }
        }
        
        else if(!strcmp(str1, "INSEREEDITOR")){
            fscanf(entrada, "%s", str1);
            aux_ed = criaEditor (str1);
            insereListaEditor (editores, aux_ed);
        }
        
        else if(!strcmp(str1, "INSERECONTRIBUICAO")){
            fscanf(entrada, "%s", str1);
            fscanf(entrada, "%s", str2);
            fscanf(entrada, "%s", str3);
            aux_ed = retornaEditor(editores, str2);
            if (aux_ed == NULL){
                log = fopen("log.txt","a");
                fprintf(log,"ERRO: Editor nao existe para inserir contribuicao\n");
                fclose(log);
            }
            else{
                aux_pag = retornaPagina(wiki, str1);
                if (aux_pag == NULL){
                    log = fopen("log.txt","a");
                    fprintf(log,"ERRO: Pagina nao existe para inserir contribuicao\n");
                    fclose(log);
                }
                else{
                    aux_cont = iniciaContribuicao (str3, aux_ed);
                    if(aux_cont != NULL){
                        insereListaCont (retornaListaContPag (aux_pag), aux_cont);
                    }
                }
            }
        }
        
        else if(!strcmp(str1, "RETIRACONTRIBUICAO")){
            fscanf(entrada, "%s", str1);
            fscanf(entrada, "%s", str2);
            fscanf(entrada, "%s", str3);
            aux_ed = retornaEditor(editores, str2);
            if (aux_ed == NULL){
                log = fopen("log.txt","a");
                fprintf(log,"ERRO: Editor nao existe para retirar contribuicao\n");
                fclose(log);
            }
            else{
                aux_pag = retornaPagina(wiki, str1);
                if (aux_pag == NULL){
                    log = fopen("log.txt","a");
                    fprintf(log,"ERRO: Pagina nao existe para retirar contribuicao\n");
                    fclose(log);
                }
                else{
                    aux_cont = retornaContribuicao(retornaListaContPag (aux_pag), str3);
                    if (aux_cont == NULL){
                        log = fopen("log.txt","a");
                        fprintf(log,"ERRO: A contribuicao nao existe\n");
                        fclose(log);
                    }
                    else{
                        if (strcmp(retornaNomeEditorCont(aux_cont),retornaNomeEditor(aux_ed))){
                            log = fopen("log.txt","a");
                            fprintf(log,"ERRO: A contribuicao nao pertence ao usuario requerido\n");
                            fclose(log);
                        }
                        else{
                            removeListaCont(retornaListaContPag (aux_pag), str3);
                        }
                    }
                }
            }
        }
        
        else if(!strcmp(str1, "INSERELINK")){
            fscanf(entrada, "%s", str1);
            fscanf(entrada, "%s", str2);
            aux_pag = retornaPagina(wiki, str2);
            if (aux_pag == NULL){
                log = fopen("log.txt","a");
                fprintf(log,"ERRO: Pagina nao existe para criar link\n");
                fclose(log);
            }
            else{
                aux_pag2 = retornaPagina(wiki, str1);
                if (aux_pag2 == NULL){
                    log = fopen("log.txt","a");
                    fprintf(log,"ERRO: Pagina nao existe para inserir link\n");
                    fclose(log);
                }
                else{
                    aux_link = iniciaLink(aux_pag);
                    insereListaLink (retornaListaLinkPag(aux_pag2), aux_link);
                }
            }
        }
        
        else if(!strcmp(str1, "RETIRALINK")){
            fscanf(entrada, "%s", str1);
            fscanf(entrada, "%s", str2);
            aux_pag = retornaPagina(wiki, str1);
            if (aux_pag == NULL){
                log = fopen("log.txt","a");
                fprintf(log,"ERRO: Pagina nao existe para retirar link\n");
                fclose(log);
            }
            else{
                aux_link = retornaLink (retornaListaLinkPag(aux_pag), str2);
                if (aux_link == NULL){
                    log = fopen("log.txt","a");
                    fprintf(log,"ERRO: Link nao existe para retirar\n");
                    fclose(log);
                }
                else{
                    retiraListaLink (retornaListaLinkPag(aux_pag), aux_link);
                }
            }
        }
        
        else if(!strcmp(str1, "CAMINHO")){

        }
        
        else if(!strcmp(str1, "IMPRIMEPAGINA")){
            fscanf(entrada, "%s", str1);
            aux_pag = retornaPagina(wiki, str1);
            if (aux_pag == NULL){
                log = fopen("log.txt","a");
                fprintf(log,"ERRO: Pagina nao existe para ser impressa\n");
                fclose(log);
            }
            else{
                imprimePagina (aux_pag);
            }
        }
        
        else if(!strcmp(str1, "IMPRIMEWIKED")){
            imprimeListaPag (wiki);
        }
        fscanf(entrada, "%s", str1);
    }
    
    fclose(entrada);
    destroiListaPag (wiki);
    destroiListaEditor (editores);
    return 0;
}

