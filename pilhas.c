#include "headers.h"

//Recebe endereço da pilha.
//temp->ant = *end_em_lista_pilha; é o topo da pilha.
void empilha(elpilha** end_em_lista_pilha, lista_de_pilhas** lista){
	int valor_temp;
	elpilha* temp;
	temp = (elpilha*)malloc(sizeof(elpilha));
	
	if((*lista)->pilha == NULL){
		temp->ant = NULL;

		printf("Digite o valor.");
		scanf("%d", &valor_temp);
		temp->valor = valor_temp;

	} else {
		temp->ant = *end_em_lista_pilha;

		printf("Digite o valor.");
		scanf("%d", &valor_temp);
		temp->valor = valor_temp;
	}

	//*end_em_lista_pilha = temp;
	(*lista)->pilha = temp;
}


//preciso receber a lista tbm e testar se seu campo pilha está com elemento, nesse caso, tira o elemento e faz ela apontar pra free. Se não, pelo 1o if vai ficar sempre um valor pois seu prox valerá null.
//Se ao remover uma pilha, seu endereço for o mesmo de (*lista)->pilha, quer dizer que é o último elemento! aí dá free em (*lista)->pilha, e sabemos que ela está vazia.
//Necessariamente se for NULL em ant, é o último elemento.
float desempilha(elpilha** end_em_lista_pilha, lista_de_pilhas** lista){

	if((*lista)->pilha == NULL){
		printf("Underflow.\n");
		return -1;
	}
		
	if((*end_em_lista_pilha)->ant != NULL){
		elpilha* temp;
		float x;
		x = (*end_em_lista_pilha)->valor;
		temp = *end_em_lista_pilha;
		*end_em_lista_pilha = (*end_em_lista_pilha)->ant;
		printf("End ant = %p\n", (*end_em_lista_pilha)->ant);
		free(temp);
		temp = NULL;
		return x;
	} else {
		free((*lista)->pilha);
		(*lista)->pilha = NULL;
		return -1;
	}


	/*if((*lista)->pilha != NULL){
		elpilha* temp;
		float x;
		x = (*top)->valor;
		free((*lista)->pilha);
		(*lista)->pilha = NULL;		
		return x;
	}*/
	

}

void listarNosPilha(elpilha** lista){
	printf("Valores:");
	elpilha* backup = *lista;
		
	for(; (*lista) != NULL; (*lista) = (*lista)->ant){
		//if((*lista) != NULL){
			printf(" %f", (*lista)->valor);
		//}
	}
	*lista = backup;
}