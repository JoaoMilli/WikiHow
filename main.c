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
    
    /* Cria o arquivo log, onde serão reportados erros */
    log = fopen("log.txt","w");
    fclose(log);
    
    /* É necessário um arquivo de entrada contendo os comandos */
    if ( argc != 2 ) {
        log = fopen("log.txt","a");
        fprintf(log, "ERRO: Arquivo de entrada nao especificado\n");
        fclose(log);
        return 0;
    }
    
    FILE* entrada;
    
    /* Abrindo arquivo de entrada */
    entrada = fopen(argv[1],"r");
    
    if (entrada == NULL){
        log = fopen("log.txt","a");
        fprintf(log, "ERRO: Arquivo de entrada nao existe\n");
        fclose(log);
        return 0;
    }
    
    /* Variáveis auxiliares que serão utilizadas para armazenar entradas e saídas de funções */
    char str1[30], str2[30], str3[30];
    Contribuicao* aux_cont;
    Pagina* aux_pag, *aux_pag2;
    ListaPag* wiki;
    Editor* aux_ed;
    ListaEditor* editores;
    Link* aux_link;
    
    /* Inicia a wiki, uma lista de páginas (TAD ListaPag) */
    wiki = iniciaListaPagina();
    /* Inicia uma lista de editores (TAD ListaEditores) */
    editores = iniciaListaEditor();
    
    /* obtem o primeiro comando do arquivo de entrada */
    fscanf(entrada, "%s", str1);
    
    /* Enquanto o comando não for FIM, o programa continuará no loop coletando comandos*/
    while(strcmp(str1, "FIM")){
    	
	/* Checa o comando e entra na função especificada*/

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
                fprintf(log, "ERRO: Pagina %s nao existe para retirada\n", str1);
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
                fprintf(log,"ERRO: Editor %s nao existe para inserir contribuicao\n", str2);
                fclose(log);
            }
            else{
                aux_pag = retornaPagina(wiki, str1);
                if (aux_pag == NULL){
                    log = fopen("log.txt","a");
                    fprintf(log,"ERRO: Pagina %s nao existe para inserir contribuicao\n", str1);
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
                fprintf(log,"ERRO: Editor %s nao existe para retirar contribuicao\n", str2);
                fclose(log);
            }
            else{
                aux_pag = retornaPagina(wiki, str1);
                if (aux_pag == NULL){
                    log = fopen("log.txt","a");
                    fprintf(log,"ERRO: Pagina %s nao existe para retirar contribuicao\n", str1);
                    fclose(log);
                }
                else{
                    aux_cont = retornaContribuicao(retornaListaContPag (aux_pag), str3);
                    if (aux_cont == NULL){
                        log = fopen("log.txt","a");
                        fprintf(log,"ERRO: A contribuicao %s nao existe para retirada\n" , str3);
                        fclose(log);
                    }
                    else{
                        if (strcmp(retornaNomeEditorCont(aux_cont),retornaNomeEditor(aux_ed))){
                            log = fopen("log.txt","a");
                            fprintf(log,"ERRO: A contribuicao nao pertence ao usuario %s\n", str2);
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
                fprintf(log,"ERRO: Pagina %s nao existe para criar link\n", str2);
                fclose(log);
            }
            else{
                aux_pag2 = retornaPagina(wiki, str1);
                if (aux_pag2 == NULL){
                    log = fopen("log.txt","a");
                    fprintf(log,"ERRO: Pagina %s nao existe para inserir link\n", str1);
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
                fprintf(log,"ERRO: Pagina %s nao existe para retirar link\n", str1);
                fclose(log);
            }
            else{
                aux_link = retornaLink (retornaListaLinkPag(aux_pag), str2);
                if (aux_link == NULL){
                    log = fopen("log.txt","a");
                    fprintf(log,"ERRO: Link %s nao existe para retirar\n", str2);
                    fclose(log);
                }
                else{
                    retiraListaLink (retornaListaLinkPag(aux_pag), aux_link);
                }
            }
        }
        
        else if(!strcmp(str1, "CAMINHO")){
            fscanf(entrada, "%s", str1);
            fscanf(entrada, "%s", str2);
            aux_pag = retornaPagina(wiki, str1);
            if(aux_pag == NULL){
                log = fopen("log.txt","a");
                fprintf(log,"ERRO: Pagina %s nao existe para verificar caminho\n", str1);
                fclose(log);
            }
            aux_pag2 = retornaPagina(wiki, str2);
            if(aux_pag == NULL){
                log = fopen("log.txt","a");
                fprintf(log,"ERRO: Pagina %s nao existe para verificar caminho\n", str2);
                fclose(log);
            }
            if(Caminho (aux_pag, aux_pag2)){
                log = fopen("log.txt","a");
                fprintf(log,"EXISTE CAMINHO entre %s e %s\n", str1, str2);
                fclose(log);
            }
            else{
                log = fopen("log.txt","a");
                fprintf(log,"NAO EXISTE CAMINHO entre %s e %s\n", str1, str2);
                fclose(log);
            }
        }
        
        else if(!strcmp(str1, "IMPRIMEPAGINA")){
            fscanf(entrada, "%s", str1);
            aux_pag = retornaPagina(wiki, str1);
            if (aux_pag == NULL){
                log = fopen("log.txt","a");
                fprintf(log,"ERRO: Pagina %s nao existe para ser impressa\n", str1);
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
    
    /* Fecha o arquivo de entrada*/
    fclose(entrada);
    /* Destroi a wiki e a lista de editores*/
    destroiListaPag (wiki);
    destroiListaEditor (editores);
    return 0;
}

