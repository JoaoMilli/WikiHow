/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Link.h
 * Author: joao
 *
 * Created on 1 de Novembro de 2020, 16:22
 */

#ifndef LINK_H
#define LINK_H

typedef struct link Link;

#include "Pagina.h"

Link* iniciaLink(Pagina* pag);

void imprimeTituloLink(Link* link);

void imprimeNomeLink(Link* link);

Link* destroiLink(Link* link);

#endif /* LINK_H */
