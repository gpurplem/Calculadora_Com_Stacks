#include "headers.h"

int main(){
	lista_de_pilhas* listaTemp = NULL;
	
	lista_de_pilhas* lista = (lista_de_pilhas*)malloc(sizeof(lista_de_pilhas));
	//printf("end em lista = %p\n", lista);
	lista->prox = NULL;
	lista->pilha = NULL;
	lista->id = 0;
	
	int menu;
	do{
		printf("\n1  - Criar um novo nó na lista.\n");
		printf("2  - Remover um nó da lista.\n");
		printf("3  - Listar nós da lista.\n");

		printf("4  - Empilhar um nó em uma pilha.\n");
		printf("5  - Desempilhar um nó de uma pilha.\n");
		printf("6  - Listar nós de uma pilha.\n");
		
		
		/*
		printf("6  - Operações.\n");
		printf("7  - Reduzir.\n");
		printf("8  - Esvaziar.\n");
		printf("9  - Mover topo de pilha A a B.\n");
		printf("10 - ID das pilhas: crescente.\n");
		printf("11 - ID das pilhas: decrescente.\n");*/
		scanf("%d", &menu);

		switch(menu){
			case 1: novoNoLista(&lista); break;
			case 2: listaTemp = lista; if(encontrarNoLista(&listaTemp)) removerNoLista(&listaTemp, &lista); else printf("ID não encontrado.\n"); break;
			case 3: listarNosLista(&lista); break;

			case 4: listaTemp = lista; if(encontrarNoLista(&listaTemp)) empilha(&listaTemp->pilha, &lista); else printf("ID não encontrado.\n"); break;
			case 5: listaTemp = lista; encontrarNoLista(&listaTemp); desempilha(&listaTemp->pilha, &lista); break;
			case 6: listaTemp = lista; encontrarNoLista(&listaTemp); listarNosPilha(&(listaTemp->pilha)); break;
		}


	}while(menu >= 0 && menu <  14);

}