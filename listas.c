#include "headers.h"

void novoNoLista(lista_de_pilhas** lista){
	lista_de_pilhas* backup = *lista;
	//printf("end em backup = %p\n", backup);
	for( ; (*lista)->prox != NULL; (*lista) = (*lista)->prox);

	lista_de_pilhas* temp = (lista_de_pilhas*)malloc(sizeof(lista_de_pilhas));
	//printf("end temp novonolista: %p\n", temp);

	int id = (*lista)->id;
	temp->id = ++id;
	temp->prox = NULL;
	temp->pilha = NULL;
	
	//printf("end lista prox antes: %p\n", (*lista)->prox);
	(*lista)->prox = temp;
	//printf("end lista prox depois: %p\n", (*lista)->prox);
	(*lista) = backup;
}

/*int listaVazia(lista_de_pilhas** lista){
	return (*lista)->prox == NULL;
}*/

void listarNosLista(lista_de_pilhas** lista){
	lista_de_pilhas* backup = *lista;
	//printf("end em lista listarnoslista= %p\n", *lista);

	if((*lista)->prox == NULL){
		printf("Lista vazia.\n");
		return;
	}

	//IMPORTANTE: não pode continuar daqui pra baixo se houver apenas o nó ID 0.

	//printf("end em (*lista)->prox [deve ser igual end inicial da lista]: %p\n", (*lista)->prox);
	//vai pro prox, mas não o imprime, pois seu prox sempre vai valer null!
	//como sinalizar que é um elemento a ser impresso apesar de seu prox ter null?
	for( ; (*lista)->prox != NULL; *lista = (*lista)->prox){
		if((*lista)->id != 0)
		printf("Nó n°%d da lista.\n", (*lista)->id);
	}
	if((*lista)->id != 0) printf("Nó n°%d da lista.\n", (*lista)->id);
	//printf("end em *lista [deve ser igual end de temp]: %p\n", *lista);

	
	(*lista) = backup;
}

void removerNoLista(lista_de_pilhas** noDeletar, lista_de_pilhas** listaOriginal){

	if((*noDeletar)->id == 0){
		printf("Valor inválido. ID 0 não pode ser apagado.");
	} 
	else {
		lista_de_pilhas* backupOriginal = *listaOriginal;
		lista_de_pilhas* noAnterior;

		for( ; (*listaOriginal)->id != (*noDeletar)->id; (*listaOriginal) = (*listaOriginal)->prox){
			noAnterior = *listaOriginal;
		}

		noAnterior->prox = (*noDeletar)->prox;
		free((*noDeletar));
		(*listaOriginal) = backupOriginal;
	}

}

int encontrarNoLista(lista_de_pilhas** lista){
	printf("Digite ID da pilha.");
	int id_temp;
	scanf("%d", &id_temp);
	
	for( ; (*lista)->id != id_temp && (*lista)->prox != NULL; (*lista) = (*lista)->prox);

	//Significa que achou o elemento e não é o último.
	if((*lista)->prox != NULL){
		return (1);
	} 
	else return ( (*lista)->id == id_temp );
}