#ifndef __CABE__
#define __CABE__

#include <stdio.h>
#include <stdlib.h>
#include "estruturas.c"

//Lista
void novoNoLista(lista_de_pilhas** lista);
void listarNosLista(lista_de_pilhas** lista);
void removerNoLista(lista_de_pilhas** noDeletar, lista_de_pilhas** listaOriginal);
int encontrarNoLista(lista_de_pilhas** lista);

//Pilha
void empilha(elpilha** end_em_lista_pilha, lista_de_pilhas** lista);
float desempilha(elpilha** end_em_lista_pilha, lista_de_pilhas** lista);
void listarNosPilha(elpilha** lista);
int operarPilha(char operador, elpilha** pilha, lista_de_pilhas** noListaTemp);
void reduzirPilha(char operador, elpilha** pilha, lista_de_pilhas** noLista);

#endif