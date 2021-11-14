#include "headers.h"

void empilha(elpilha** pilha, lista_de_pilhas** lista){
	int valor_temp;
	elpilha* temp;
	temp = (elpilha*)malloc(sizeof(elpilha));

	if((*lista)->id == 0){
		printf("ID 0 é proibido.\n");
		return;
	}
	
	if((*lista)->pilha == NULL)
		temp->ant = NULL;
	else temp->ant = *pilha;
	
	printf("Digite o valor.");
	scanf("%d", &valor_temp);
	temp->valor = valor_temp;

	(*lista)->pilha = temp;
}

void empilhaResultadoOperacao(elpilha** pilha, lista_de_pilhas** lista, float resultado){
	int valor_temp;
	elpilha* temp;
	temp = (elpilha*)malloc(sizeof(elpilha));

	if((*lista)->id == 0){
		printf("ID 0 é proibido.\n");
		return;
	}
	
	if((*lista)->pilha == NULL)
		temp->ant = NULL;
	else temp->ant = *pilha;
	
	temp->valor = resultado;

	(*lista)->pilha = temp;
}


//preciso receber a lista tbm e testar se seu campo pilha está com elemento, nesse caso, tira o elemento e faz ela apontar pra free. Se não, pelo 1o if vai ficar sempre um valor pois seu prox valerá null.
//Se ao remover uma pilha, seu endereço for o mesmo de (*lista)->pilha, quer dizer que é o último elemento! aí dá free em (*lista)->pilha, e sabemos que ela está vazia.
//Necessariamente se for NULL em ant, é o último elemento.
float desempilha(elpilha** end_em_lista_pilha, lista_de_pilhas** lista){

	if((*lista)->id == 0){
		printf("ID 0 é proibido.\n");
		return -1;
	}

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
		//printf("End ant = %p\n", (*end_em_lista_pilha)->ant);
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

void listarNosPilha(elpilha** pilha){
	elpilha* backup = *pilha;

	if((*pilha) == NULL){
		printf("Pilha vazia.\n");
		return;
	}
	
	printf("Valores:");

	//a primeira pilha tem ant = null.
	for(; (*pilha) != NULL; (*pilha) = (*pilha)->ant){
			printf(" %.2f", (*pilha)->valor);
	}
	putchar('\n');
	*pilha = backup;
}

int operarPilha(char operador, elpilha** pilha, lista_de_pilhas** noLista) {
	float resultado;

	if((*pilha)->ant == NULL){
		printf("Não há valores suficientes.\n");
		return 0;
	}

	if(operador == '+'){
		resultado = (*pilha)->valor + (*pilha)->ant->valor;
		desempilha(pilha, noLista);
		desempilha(pilha, noLista);
		empilhaResultadoOperacao(pilha, noLista, resultado);
		(*pilha)->valor = resultado;
		return 1;
	} 
	else if(operador == '-'){
		resultado = (*pilha)->valor - (*pilha)->ant->valor;
		desempilha(pilha, noLista);
		desempilha(pilha, noLista);
		empilhaResultadoOperacao(pilha, noLista, resultado);
		(*pilha)->valor = resultado;
		return 1;
	}
	else if(operador == '*'){
		resultado = (*pilha)->valor * (*pilha)->ant->valor;
		desempilha(pilha, noLista);
		desempilha(pilha, noLista);
		empilhaResultadoOperacao(pilha, noLista, resultado);
		(*pilha)->valor = resultado;
		return 1;
	}
	else if(operador == '/'){
		resultado = (*pilha)->valor / (*pilha)->ant->valor;
		desempilha(pilha, noLista);
		desempilha(pilha, noLista);
		empilhaResultadoOperacao(pilha, noLista, resultado);
		(*pilha)->valor = resultado;
		return 1;
	} 
	else {
		printf("Operação inválida.\n");
		return 0;
	}


}

void reduzirPilha(char operador, elpilha** pilha, lista_de_pilhas** noLista) {
	while( operarPilha(operador, pilha, noLista) ){
	}
}