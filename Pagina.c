#include "Pagina.h"
#include "Contribuicao.h"
#include "ListaCont.h"
#include "ListaLink.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct pagina{
    char* titulo;
    ListaCont* cont;
    ListaLink* link;
    char* nome;   
};

Pagina* iniciaPagina (char nome[20], char titulo[20]){
    Pagina* pag = (Pagina*) malloc (sizeof(Pagina));
    pag -> nome = strdup(nome);
    pag -> titulo = strdup(titulo);
    pag -> cont = iniciaListaCont();
    pag -> link = iniciaListaLink();
    return pag;
}

void imprimePagina (Pagina* pag){
    
    FILE* file;
    
    char* nome = pag -> nome;
    
    file = fopen (pag -> nome, "w");
    
    fprintf(file,"%s\n\n", pag -> titulo);
    fprintf(file,"--> Historico de contribuicoes\n\n");
    
    fclose(file);
    
    imprimeListaContNomes (pag -> cont, pag -> nome);
    
    file = fopen (pag -> nome, "a");
    
    fprintf(file,"\n\n\n");
    fprintf(file,"--> Links\n\n");
    
    fclose(file);
    
    imprimeListaLink (pag -> link, pag -> nome);
    
    file = fopen (pag -> nome, "a");
    
    fprintf(file,"\n\n\n");
    fprintf(file,"--> Textos\n\n");
    
    fclose(file);
    
    imprimeListaCont (pag -> cont, pag -> nome);   
}

char* retornaNomePagina (Pagina* pag){
    return pag -> nome;
}

char* retornaTituloPagina (Pagina* pag){
    return pag -> titulo;
}

ListaCont* retornaListaContPag (Pagina* pag){
    return pag -> cont;
}

ListaLink* retornaListaLinkPag (Pagina* pag){
    return pag -> link;
}

void destroiPagina (Pagina* pag){
    destroiListaCont (pag -> cont);
    destroiListaLink (pag -> link);
    free(pag -> nome);
    free(pag -> titulo);
    free(pag);
}
