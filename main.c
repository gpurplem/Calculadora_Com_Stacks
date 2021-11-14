/*
O que funciona: a lista é criada e dá pra colocar uma pilha infinita dentro dela.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct elpilha_ {
	float valor;
	struct elpilha_* ant;
} elpilha;

void empilha(elpilha** top)
{
	printf("\nEmpilha\n");
	elpilha* temp;
	temp = (elpilha*) malloc (sizeof(elpilha));
	printf("End. temp (objeto) %p\n", temp);
	printf("End. top %p\n", top);
	printf("End. *top %p\n", *top);

	//top é onde tá o endereço da pilha em si.
	temp->ant = *top;
	printf("End. temp_ant %p\n", temp->ant);

	*top = temp;
	printf("End. temp %p\n", temp);
	printf("End. *top %p\n\n", *top);
}

float desempilha(elpilha** top){
	puts("\nDesempilha\n");
	elpilha* temp;
	float x;
	printf("End. temp %p\n", temp);
	x = (*top)->valor;
	printf("(*top)->valor = %f\n", (*top)->valor);
	temp = *top;
	printf("End. top %p\n", top);
	printf("End. *top %p\n", *top);
	//printf("desempilha %p\n", *top);
	//printf("desempilha %p\n", (*top)->ant);
	*top = (*top)->ant;
	printf("End. (*top)->ant %p\n", (*top)->ant);
	printf("End. *top %p\n", *top);
	free(temp);
	return x;
}

typedef struct lista_de_pilhas_{
	int id;
	elpilha* pilha;
	struct lista_de_pilhas* prox;
} lista_de_pilhas;

void addLista(lista_de_pilhas** lista){

	(*lista)->prox = (lista_de_pilhas*)malloc(sizeof(lista_de_pilhas));
}

int listaVazia(lista_de_pilhas** lista){
	return (*lista)->prox == NULL;
}

int main(){
		printf("\nMain\n");
	//Não esqueça que struct pega um monte de endereço pra caber tudo.
	lista_de_pilhas* lista_inicio = (lista_de_pilhas*)malloc(sizeof(lista_de_pilhas));
	//printf("%p\n", &lista_inicio->pilha);
	printf("End. &lista_inicio (ptr) %p\n", &lista_inicio);
	printf("End. lista_inicio (objeto) %p\n", lista_inicio);
	//Pilha é um ponteiro. Por enquanto aponta para NULL.
	printf("End. lista_inicio->pilha %p\n", lista_inicio->pilha);
	//Onde começa a pilha do struct na memória.
	printf("End. &lista_inicio->pilha %p\n", &lista_inicio->pilha);
	//Ponteiro p/ próxima lista.
	printf("End. lista_inicio->prox %p\n", lista_inicio->prox);
	//Endereço deste ponteiro prox.
	printf("End. &lista_inicio->prox %p\n", &lista_inicio->prox);
	//printf("End. lista_inicio->pilha->ant %p\n", lista_inicio->pilha->ant);
	
	//lista_de_pilhas* lista_atual = NULL;
	//Nulo da LISTA
	//lista_inicio->prox = NULL;
	//Nulo da primeira PILHA

	//Aqui dá erro de core dumped porque não existe objeto na memória sendo referenciado pelo PONTEIRO que é ant.
	//lista_inicio->pilha->ant = NULL;

	//if(listaVazia(&lista_inicio)) lista_atual = lista_inicio;

	empilha(&lista_inicio->pilha);
	printf("\nMain após empilha 1\n");
	printf("End. &lista_inicio (ptr) %p\n", &lista_inicio);
	printf("End. lista_inicio (objeto) %p\n", lista_inicio);
	printf("End. lista_inicio->pilha %p\n", lista_inicio->pilha);
	printf("End. &lista_inicio->pilha %p\n", &lista_inicio->pilha);
	printf("End. lista_inicio->prox %p\n", lista_inicio->prox);
	printf("End. &lista_inicio->prox %p\n", &lista_inicio->prox);
  printf("End. lista_inicio->pilha->ant %p\n", lista_inicio->pilha->ant);
	lista_inicio->pilha->valor = 16.0;	
	printf("Valor no topo = %f\n", lista_inicio->pilha->valor);

	empilha(&lista_inicio->pilha);
	printf("\nMain após empilha 2\n");
	printf("End. &lista_inicio (ptr) %p\n", &lista_inicio);
	printf("End. lista_inicio (objeto) %p\n", lista_inicio);
	printf("End. lista_inicio->pilha %p\n", lista_inicio->pilha);
	printf("End. &lista_inicio->pilha %p\n", &lista_inicio->pilha);
	printf("End. lista_inicio->prox %p\n", lista_inicio->prox);
	printf("End. &lista_inicio->prox %p\n", &lista_inicio->prox);
  printf("End. lista_inicio->pilha->ant %p\n", lista_inicio->pilha->ant);
	lista_inicio->pilha->valor = 33.0;	
	printf("Valor no topo = %f\n", lista_inicio->pilha->valor);

	desempilha(&lista_inicio->pilha);

	printf("Valor no topo ao desempilhar = %f\n", lista_inicio->pilha->valor);

	empilha(&lista_inicio->pilha);
	lista_inicio->pilha->valor = 99.0;
	empilha(&lista_inicio->pilha);
	lista_inicio->pilha->valor = 66.0;
	empilha(&lista_inicio->pilha);
	lista_inicio->pilha->valor = 24.0;

	printf("Valor no topo = %f\n", lista_inicio->pilha->valor);
	desempilha(&lista_inicio->pilha);
	desempilha(&lista_inicio->pilha);
	printf("Valor no topo = %f\n", lista_inicio->pilha->valor);	
	
	/*int menu;

	do{
		printf("1  - Criar.\n");
		printf("2  - Listar.\n");
		printf("3  - Remover.\n");
		printf("4  - Empilhar valor.\n");
		printf("5  - Desempilhar.\n");
		printf("6  - Operações.\n");
		printf("7  - Reduzir.\n");
		printf("8  - Esvaziar.\n");
		printf("9  - Mover topo de pilha A a B.\n");
		printf("10 - ID das pilhas: crescente.\n");
		printf("11 - ID das pilhas: decrescente.\n");
		printf("12 - Salvar em arquivo.\n");
		printf("13 - Carregar de arquivo.\n");
		scanf("%d", &menu);
	}while(menu > 0 && menu <  14);*/
}
