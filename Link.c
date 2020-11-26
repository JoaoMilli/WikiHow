#include <stdio.h>
#include <stdlib.h>
#include "Link.h"
#include "Pagina.h"

struct link{
    Pagina* pag;
};

Link* iniciaLink(Pagina* pag){
    Link* link = (Link*) malloc (sizeof(Link));
    link -> pag = pag;
    return link;
}

void imprimeTituloLink(Link* link, char* nome){
    FILE* file;
    
    file = fopen (nome, "a");
    
    fprintf(file, "%s", retornaTituloPagina (link -> pag));
    fclose(file);
}

void imprimeNomeLink(Link* link, char* nome){
    FILE* file;
    
    file = fopen (nome, "a");
    
    fprintf(file, "%s", retornaNomePagina (link -> pag));
    fclose(file);
}

Pagina* retornaPagLink(Link* link){
    return link -> pag;
}

void destroiLink(Link* link){
    free(link);
}
