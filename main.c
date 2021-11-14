#include <stdio.h>
#include <stdlib.h>

typedef struct elpilha_ {
	float valor;
	struct elpilha_* ant;
} elpilha;

//Recebe endereço da pilha.
void empilha(elpilha** top){
	elpilha* temp;
	temp = (elpilha*) malloc (sizeof(elpilha));
	temp->ant = *top;

	printf("Digite o valor.");
	int valor_temp;
	scanf("%d", &valor_temp);
	temp->valor = valor_temp;

	*top = temp;
}

float desempilha(elpilha** top){
	if((*top)->ant != NULL){
		elpilha* temp;
		float x;
		x = (*top)->valor;
		temp = *top;
		*top = (*top)->ant;
		//Aqui vai liberar esse lugar!
		return x;
	}
	
		printf("Underflow.\n");
}

typedef struct lista_de_pilhas_{
	int id;
	elpilha* pilha;
	struct lista_de_pilhas* prox;
} lista_de_pilhas;

void addLista(lista_de_pilhas** lista){
	lista_de_pilhas* backup = *lista;
	for( ; (*lista)->prox != NULL; (*lista) = (*lista)->prox);
	lista_de_pilhas* temp = (lista_de_pilhas*)malloc(sizeof(lista_de_pilhas));
	int id = (*lista)->id;
	temp->id = ++id;
	temp->prox = NULL;
	(*lista)->prox = temp;
	(*lista) = backup;
}

/*int listaVazia(lista_de_pilhas** lista){
	return (*lista)->prox == NULL;
}*/

void listar(lista_de_pilhas** lista){
	lista_de_pilhas* backup = *lista;
	for( ; (*lista)->prox != NULL; (*lista) = (*lista)->prox)
	printf("Lista n°: %d\n", (*lista)->id);
	(*lista) = backup;
}

void remover(lista_de_pilhas** lista){
	printf("Digite ID da pilha.");
	int id_temp;
	scanf("%d", &id_temp);

	lista_de_pilhas* backup = *lista;
	lista_de_pilhas* anterior;

	for( ; (*lista)->id != id_temp; (*lista) = (*lista)->prox){
		anterior = *lista;
	}

	anterior->prox = (*lista)->prox;
	free((*lista));
	(*lista) = backup;
}

void encontrar(lista_de_pilhas** lista){
	printf("Digite ID da pilha.");
	int id_temp;
	scanf("%d", &id_temp);

	for( ; (*lista)->id != id_temp; (*lista) = (*lista)->prox);
}

void listarValor(elpilha** lista){
	printf("Valores:");
	elpilha* backup = *lista;
		
	for(; (*lista) != NULL; (*lista) = (*lista)->ant){
		//if((*lista) != NULL){
			printf(" %f", (*lista)->valor);
		//}
	}
	*lista = backup;
}


int main(){
	lista_de_pilhas* temp = NULL;
	lista_de_pilhas* lista_inicio = (lista_de_pilhas*)malloc(sizeof(lista_de_pilhas));
	lista_inicio->prox = NULL;
	lista_inicio->id = 1;

	/*REFERÊNCIA
	empilha(&lista_inicio->pilha);
	lista_inicio->pilha->valor = 16.0;	
	desempilha(&lista_inicio->pilha);
	printf("%f\n", lista_inicio->pilha->valor);*/
	
	int menu;
	do{
		printf("1  - Criar.\n");
		printf("2  - Listar listas.\n");
		printf("0  - Listar valores.\n");
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

		switch(menu){
			case 1: addLista(&lista_inicio); break;
			case 2: listar(&lista_inicio); break;
			case 3: remover(&lista_inicio); break;
			case 4: temp = lista_inicio; encontrar(&temp); empilha(&temp->pilha); break;
			case 0: temp = lista_inicio; encontrar(&temp); listarValor(&(temp->pilha)); break;

		}


	}while(menu >= 0 && menu <  14);


}
