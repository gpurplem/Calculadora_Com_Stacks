#include "headers.h"

//cria stack, empilha como topo da pilha já com valor.
void empilha(elpilha** pilha, lista_de_pilhas** lista){
	int valor_temp;
	elpilha* temp;
	//cria uma stack
	temp = (elpilha*)malloc(sizeof(elpilha));

	//Lista de ID0 guarda o nó seed.
	if((*lista)->id == 0){
		printf(VERMELHO"\nERROR: ID 0 é proibido.\n\n"RESET);
		return;
	}
	
	//Se pilha estiver vazia, o novo nó é o primeiro e seu anterior aponta pra null.
	//Else, a stack existente vai pro ptr anterior da nova stack.
	if((*lista)->pilha == NULL)
		temp->ant = NULL;
	else temp->ant = *pilha;
	
	printf("Digite o valor.");
	scanf("%d", &valor_temp);
	temp->valor = valor_temp;
  
	//Agora o topo aponta para o novo stack.
	(*lista)->pilha = temp;
}

//Cria uma stack, empilha vazia.
void empilhaVazio(elpilha** pilha, lista_de_pilhas** lista){
	int valor_temp;
	elpilha* temp;
	temp = (elpilha*)malloc(sizeof(elpilha));

	if((*lista)->id == 0){
		printf(VERMELHO"\nERROR: ID 0 é proibido.\n\n"RESET);
		return;
	}
	
	if((*lista)->pilha == NULL)
		temp->ant = NULL;
	else temp->ant = *pilha;
	
	temp->valor = 0;
  
	(*lista)->pilha = temp;
}

void empilhaVazioInvertido(elpilha** pilha, lista_de_pilhas** lista){
	int valor_temp;
	elpilha* temp;
	elpilha* backupPilha;
	temp = (elpilha*)malloc(sizeof(elpilha));

	if((*lista)->id == 0){
		printf(VERMELHO"\nERROR: ID 0 é proibido.\n\n"RESET);
		return;
	}
	
	if((*lista)->pilha == NULL){
		temp->ant = NULL;	
		(*lista)->pilha = temp;
	}
	else{
		backupPilha = (*lista)->pilha;
		for(; (*pilha)->ant != NULL; (*pilha) = (*pilha)->ant);
		(*pilha)->ant = temp;
		temp->ant = NULL;
		(*lista)->pilha = backupPilha;
	}	
	temp->valor = 0;
}

//Cria uma stack, empilha com valos recebido.
void empilhaResultadoOperacao(elpilha** pilha, lista_de_pilhas** lista, float resultado){

	int valor_temp;
	elpilha* temp;
	temp = (elpilha*)malloc(sizeof(elpilha));

	if((*lista)->id == 0){
		printf(VERMELHO"\nERROR: ID 0 é proibido.\n\n"RESET);
		return;
	}
	
	if((*lista)->pilha == NULL)
		temp->ant = NULL;
	else temp->ant = *pilha;
	
	temp->valor = resultado;

	(*lista)->pilha = temp;
}

//Faz o pop.
float desempilha(elpilha** end_em_lista_pilha, lista_de_pilhas** lista){

	if((*lista)->id == 0){
		printf(VERMELHO"\nERROR: ID 0 é proibido.\n\n"RESET);
		return -1;
	}

	if((*lista)->pilha == NULL){
		printf(VERMELHO"\nERROR: UNDERFLOW.\n\n"RESET);
		return -1;
	}
		
	//Se não é base da pilha, pega seu valor e libera a stack apagada.
	//Se só tem uma stack, pega o valor e libera da memória esse endereço.
	if((*end_em_lista_pilha)->ant != NULL){
		elpilha* temp;
		float x;
		x = (*end_em_lista_pilha)->valor;
		temp = *end_em_lista_pilha;
		*end_em_lista_pilha = (*end_em_lista_pilha)->ant;

		free(temp);
		temp = NULL;
		return x;
	} else {
			float x;
			x = (*end_em_lista_pilha)->valor;
			free((*lista)->pilha);
			(*lista)->pilha = NULL;
			return x;
	}
}

void listarNosPilha(elpilha** pilha){
	elpilha* backup = *pilha;

	if((*pilha) == NULL){
		printf("Pilha vazia.\n");
		return;
	}
	
	printf("Valores:");

	//a primeira pilha tem ant = null.
	//Em algum momento, (*pilha)->ant vai valer NULL e passará ele para (*pilha).
	for(; (*pilha) != NULL; (*pilha) = (*pilha)->ant){
			printf(" %.2f", (*pilha)->valor);
	}
	putchar('\n');
	//Se não restaurar, o ponteiro em main perde tudo acima da base.
	*pilha = backup;
}

int operarPilha(char operador, elpilha** pilha, lista_de_pilhas** noLista) {
	float resultado;

	if((*noLista)->pilha == NULL){
		printf(VERMELHO"\nERROR: Não há valores suficientes.\n\n"RESET);
		return 0;
	}

	if((*pilha)->ant == NULL || (*pilha) == NULL){
		printf(VERMELHO"\nERROR: Não há valores suficientes.\n\n"RESET);
		return 0;
	}

	switch(operador){
		case '+': resultado = (*pilha)->valor + (*pilha)->ant->valor; break;
		case '-': resultado = (*pilha)->valor - (*pilha)->ant->valor; break;
		case '*': resultado = (*pilha)->valor * (*pilha)->ant->valor; break;

		case '/':
			if((*pilha)->ant->valor == 0){
				printf(VERMELHO"\nERROR: Divisão por zero.\n\n"RESET);
				return 0;
			}
			else{
				resultado = (*pilha)->valor / (*pilha)->ant->valor;
				break;
			}
			
		default: printf(VERMELHO"\nERROR: Operação inválida.\n\n"RESET); return 0;
	}

	desempilha(pilha, noLista);
	desempilha(pilha, noLista);
	empilhaResultadoOperacao(pilha, noLista, resultado);
	(*pilha)->valor = resultado;
	printf(AZUL"\nOPERAÇÃO COMPLETA.\n\n"RESET);
	return 1;
}

void reduzirPilha(char operador, elpilha** pilha, lista_de_pilhas** noLista) {

	//Garantir que a redução não parará, como pede na instrução do trabalho.
	elpilha* temp = (*pilha)->ant;
	if(operador == '/'){
		while(temp->ant != NULL){
			if(temp->valor == 0){
				printf(VERMELHO"\nERROR: Haverá divisão por zero.\n\n"RESET);
			  return;
			}
			temp = temp->ant;
		}
		//Para pegar o último valor da pilha, que tem o ant == NULL.
		if(temp->valor == 0){
			printf(VERMELHO"\nERROR: Haverá divisão por zero.\n\n"RESET);
			return;
		}

	}

	while( operarPilha(operador, pilha, noLista) ){
	}
	printf(AZUL"\nREDUÇÃO COMPLETA.\n\n"RESET);
}

void esvaziarPilha(elpilha** pilha, lista_de_pilhas** lista) {
	while((*pilha)->ant != NULL){
		desempilha(pilha, lista);
	}
	free((*lista)->pilha);
	//Precisa apontar como NULL para não atrapalhar outras funções
	//Que interpretam o NULL como pilha vazia.
	(*lista)->pilha = NULL;
	printf(AZUL"\nESVAZIAMENTO COMPLETO.\n\n"RESET);
}

int contarStacks(lista_de_pilhas** lista){
	int cont = 1;
	elpilha* backup = (*lista)->pilha;
	
	if((*lista)->pilha == NULL){
		return 0;
	}

	while((*lista)->pilha->ant != NULL){
		cont++;
		(*lista)->pilha = (*lista)->pilha->ant;
	}

	//Se não restaurar o backup, parece que o ponteiro original é alterado.
	//Sempre que não é feito backup, dá core dumped.
	(*lista)->pilha = backup;
	return cont;
}

void moverStack(lista_de_pilhas** listaOri, lista_de_pilhas** listaDes, int qtd, int ori, int des){
	int cont = 1;

	//Criada uma lista de um nó.
	//Nó recebe uma pilha vazia.
	lista_de_pilhas* listaLocal = (lista_de_pilhas*)malloc(sizeof(lista_de_pilhas)*1);
	listaLocal->prox = NULL;
	listaLocal->pilha = NULL;
	listaLocal->id = 1;
	elpilha* pilhaLocal = (elpilha*)malloc(sizeof(elpilha)*1);
	listaLocal->pilha = pilhaLocal;

	//Empilhar na local os valores da pilha origem.
	//cont impede acesso de memória inválido.
	while(cont <= qtd){
		listaLocal->pilha->valor = (*listaOri)->pilha->valor;
		//Cria stack e quando termina esta passada, na linha acima chega a recém criada.
		if(cont<qtd) empilhaVazio(&listaLocal->pilha, &listaLocal);
		//A stack que tem ant == NULL é a stack base.
		//Então a pilha se torna vazia por NULL.
		//Essa última pilha já teve seu valor repassado na linha abaixo do while.
		//Aqui já elimina as stacks movidas da pilha origem.
		if((*listaOri)->pilha->ant != NULL) (*listaOri)->pilha = (*listaOri)->pilha->ant;
			else (*listaOri)->pilha = NULL;
		cont++;
	}

	//Empilha na destino os valores da pilha local.
	cont = 1;
	while(cont <= qtd){
		empilhaVazio(&(*listaDes)->pilha, &(*listaDes));
		(*listaDes)->pilha->valor = listaLocal->pilha->valor;
		desempilha(&listaLocal->pilha, &listaLocal);
		cont++;
	}
}

void copiarStack(lista_de_pilhas** listaOri, lista_de_pilhas** listaDes, int qtd, int ori, int des){
	int cont = 1;
	lista_de_pilhas* backup;
	backup->pilha = (*listaOri)->pilha;

	lista_de_pilhas* listaLocal = (lista_de_pilhas*)malloc(sizeof(lista_de_pilhas)*1);
	listaLocal->prox = NULL;
	listaLocal->pilha = NULL;
	listaLocal->id = 1;
	elpilha* pilhaLocal = (elpilha*)malloc(sizeof(elpilha)*1);
	listaLocal->pilha = pilhaLocal;

	while(cont <= qtd){
		listaLocal->pilha->valor = (*listaOri)->pilha->valor;
		if(cont<qtd) empilhaVazio(&listaLocal->pilha, &listaLocal);
		//Aqui não passa a apontar pra NULL se for a stack base.
		//Pois é apenas cópia.
		if((*listaOri)->pilha->ant != NULL) (*listaOri)->pilha = (*listaOri)->pilha->ant;
		cont++;
	}

	(*listaOri)->pilha = backup->pilha;

	cont = 1;
	while(cont <= qtd){
		empilhaVazio(&(*listaDes)->pilha, &(*listaDes));
		(*listaDes)->pilha->valor = listaLocal->pilha->valor;
		desempilha(&listaLocal->pilha, &listaLocal);
		//listaLocal->pilha = listaLocal->pilha->ant;
		cont++;
	}
}

//Função usada no bolha apenas.
void troca(float* a, float* b)
{
	float c;
	c = *a;
	*a = *b;
	*b = c;
}

void listarStackCrescente(lista_de_pilhas* lista){
	int qtd;
	qtd = contarStacks(&lista);
	int qtdBackup = qtd;

	//Vetor dinâmico mais intuitivo para coletar valores e ordenar.
	float* vetor = (float*)malloc(sizeof(float)*qtd);

	elpilha* backup = lista->pilha;
	
	for(int i = 0; i<qtd; i++){
		vetor[i] = lista->pilha->valor;
		lista->pilha = lista->pilha->ant;
	}
	lista->pilha = backup;

	//Bubble.
	for(int i = 0; i<qtd-1; i++)
	{
		if(vetor[i] > vetor[i+1])
		troca(&vetor[i], &vetor[i+1]);

		if(qtd-1-i == 1)
		{
			i=-1;
			qtd--;
		}
	}

	//O bubble altera qtd original.
	qtd = qtdBackup;

	for(int i = 0; i<qtd; i++)
	{
		printf("Elemento %d = %f\n", i+1, vetor[i]);
	}

}

void listarStackDecrescente(lista_de_pilhas* lista){
	int qtd;
	qtd = contarStacks(&lista);
	int qtdBackup = qtd;
	float* vetor = (float*)malloc(sizeof(float)*qtd);

	elpilha* backup = lista->pilha;
	
	for(int i = 0; i<qtd; i++){
		vetor[i] = lista->pilha->valor;
		lista->pilha = lista->pilha->ant;
	}
	lista->pilha = backup;

	//Única diferença é o <.
	for(int i = 0; i<qtd-1; i++)
	{
		if(vetor[i] < vetor[i+1])
		troca(&vetor[i], &vetor[i+1]);

		if(qtd-1-i == 1)
		{
			i=-1;
			qtd--;
		}
	}

	qtd = qtdBackup;

	for(int i = 0; i<qtd; i++)
	{
		printf("Elemento %d = %f\n", i+1, vetor[i]);
	}

}	