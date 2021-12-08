#include "headers.h"
   
//Cria nó na lista e incrementa o ID.
void novoNoLista(lista_de_pilhas** lista){
	lista_de_pilhas* backup = *lista;
	for( ; (*lista)->prox != NULL; (*lista) = (*lista)->prox);

	lista_de_pilhas* temp = (lista_de_pilhas*)malloc(sizeof(lista_de_pilhas));

	int id = (*lista)->id;
	temp->id = ++id;
	temp->prox = NULL;
	temp->pilha = NULL;
	
	(*lista)->prox = temp;
	(*lista) = backup;
}

void listarNosLista(lista_de_pilhas** lista){
	lista_de_pilhas* backup = *lista;

	if((*lista)->prox == NULL){
		printf(VERMELHO"Lista vazia.\n"RESET);
		return;
	}

	//IMPORTANTE: não pode continuar daqui pra baixo se houver apenas o nó ID 0.
	for( ; (*lista)->prox != NULL; *lista = (*lista)->prox){
		if((*lista)->id != 0)
		printf("Nó n°%d da lista.\n", (*lista)->id);
	}
	//Aqui pega o último nó. Ideia: trocar prox!=null por lista==null.
	//Em algum momento, prox valerá null, então contabilizaria o último nó.
	if((*lista)->id != 0) printf("Nó n°%d da lista.\n", (*lista)->id);

	(*lista) = backup;
}

void removerNoLista(lista_de_pilhas** noDeletar, lista_de_pilhas** listaOriginal){

	if((*noDeletar)->id == 0){
		printf(VERMELHO"\nERROR: Valor inválido. ID 0 não pode ser apagado.\n\n"RESET);
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
	//Aqui só avalia o último nó que sobrou do for acima.
	else return ( (*lista)->id == id_temp );
}

int encontrarNoListaAutomatico(lista_de_pilhas** lista, int id_temp){
	for( ; (*lista)->id != id_temp && (*lista)->prox != NULL; (*lista) = (*lista)->prox);
	
	if((*lista)->prox != NULL){
		return (1);
	} 
	else return ( (*lista)->id == id_temp );
}