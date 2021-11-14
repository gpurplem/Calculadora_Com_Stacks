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
	//top sempre aponta pro elemento do topo.
	elpilha* top = (elpilha*)malloc(sizeof(elpilha));
	top->valor = 15.6;
	top->ant = NULL;
	
	empilha(&top);
	top->valor = 17.3;
	empilha(&top);
	top->valor = 199.3;
	empilha(&top);
	top->valor = 33.3;

	printf("%f\n", top->valor);
	float t = desempilha(&top);
	printf("%f\n", t);
	printf("%f\n", top->valor);

	printf("%f\n", top->valor);
	t = desempilha(&top);
	printf("%f\n", t);
	printf("%f\n", top->valor);

	printf("%f\n", top->valor);
	t = desempilha(&top);
	printf("%f\n", t);
	printf("%f\n", top->valor);
}
