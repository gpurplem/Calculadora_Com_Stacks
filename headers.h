#ifndef __CABE__
#define __CABE__

#include <stdio.h>
#include <stdlib.h>
#include "estruturas.c"
#include <string.h>

#define VERMELHO "\x1b[31m"
#define VERDE    "\x1b[32m"
#define AZUL     "\x1b[34m"
#define RESET    "\x1b[0m"
#define AMARELO  "\x1b[33m"

//Lista
void novoNoLista(lista_de_pilhas** lista);
void listarNosLista(lista_de_pilhas** lista);
void removerNoLista(lista_de_pilhas** noDeletar, lista_de_pilhas** listaOriginal);
int encontrarNoLista(lista_de_pilhas** lista);
int encontrarNoListaAutomatico(lista_de_pilhas** lista, int id_temp);
//elpilha** encontrarEnderecoNoListaAutomatico(lista_de_pilhas** lista, int id_temp);
void moverStack(lista_de_pilhas** listaOri, lista_de_pilhas** listaDes, int qtd, int ori, int des);
void copiarStack(lista_de_pilhas** listaOri, lista_de_pilhas** listaDes, int qtd, int ori, int des);

//Pilha
void empilha(elpilha** end_em_lista_pilha, lista_de_pilhas** lista);
float desempilha(elpilha** end_em_lista_pilha, lista_de_pilhas** lista);
void listarNosPilha(elpilha** lista);
int operarPilha(char operador, elpilha** pilha, lista_de_pilhas** noListaTemp);
void reduzirPilha(char operador, elpilha** pilha, lista_de_pilhas** noLista);
void esvaziarPilha(elpilha** pilha, lista_de_pilhas** lista);
//int contarStacks(elpilha** pilha);
int contarStacks(lista_de_pilhas** lista);
void empilhaVazio(elpilha** pilha, lista_de_pilhas** lista);
void listarStackCrescente(lista_de_pilhas* lista);
void listarStackDecrescente(lista_de_pilhas* lista);
void backup(lista_de_pilhas* lista);
void restaurar(lista_de_pilhas* lista);

#endif