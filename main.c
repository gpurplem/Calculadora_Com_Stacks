#include <stdio.h>
#include <stdlib.h>

typedef struct elpilha_ {
	float valor;
	struct elpilha_* ant;
} elpilha;

//Precisa ser ponteiro pra ponteiro pra modificar ptr de main.
void empilha(elpilha** top)
{
	elpilha* temp;
	temp = (elpilha*) malloc (sizeof(elpilha));
	temp->ant = *top;
	*top = temp;		
}

//Precisa ser ponteiro pra ponteiro pra modificar ptr de main.
float desempilha(elpilha** top){
	elpilha* temp;
	float x;

	x = (*top)->valor;
	temp = *top;
	*top = (*top)->ant;
	free(temp);
	return x;
}

int main(){
	elpilha** lista = (elpilha**)malloc(sizeof(elpilha)*10);
	for(int i = 0; i<10; i++) lista[i] = NULL;
	empilha(&lista[0]);
	lista[0]->valor = 18.3;
	printf("%f\n", lista[0]->valor);
	printf("%p\n", lista[0]);
	printf("%p\n", lista[0]->ant);
	empilha(&lista[0]);
	lista[0]->valor = 33.3;
	printf("%f\n", lista[0]->valor);
	printf("%p\n", lista[0]->ant);
	//Saber se lista tá vazia: lista[0] == NULL. Tem que apontar tudo pra null ao criar. Ao remover o último elemento, apontar sua lista para NULL.
	
	//top sempre aponta pro elemento do topo.
	elpilha* top = (elpilha*)malloc(sizeof(elpilha));
	top->valor = 15.6;
	top->ant = NULL;
}
