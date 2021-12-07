#include "headers.h"

//Só guarda pilhas com valores.
void backup(lista_de_pilhas* lista){
	elpilha* backup;

	FILE* arquivo;
	//Sempre sobrescrever ou criar.
	arquivo = fopen("backup_pilhas.txt", "w");
	if(arquivo == NULL) {
			printf("Backup não disponível\n");
			return;
	}

	//se for ID0, pule pro próximo nó e se a lista não tiver apenas a seed.
	if(lista->prox == NULL){
		return;
	}
	else if(lista->id == 0) lista = lista->prox;
	
	//Escrever valores de todas as listas menos a última.
	for( ; lista->prox != NULL; lista = lista->prox){
		//Backup feito de cada topo.
		//Efeito se não fizer: rodar 2x o backup faz perder todas as stacks menos a base.
		backup = lista->pilha;
		if(lista->pilha != NULL){
			char cabecalho[15] = "Pilha número ";
			fprintf(arquivo, "%s", cabecalho);
			fprintf(arquivo, "%d\n", lista->id);

			for(; lista->pilha->ant != NULL; lista->pilha = lista->pilha->ant)
				fprintf(arquivo, "%.2f\n", lista->pilha->valor);

			//Escreve último valor da pilha (base) que não é pega pelo for.
			fprintf(arquivo, "%.2f\n", lista->pilha->valor);
			fprintf(arquivo, "x\n");

			//Backup restaurado para não perder a pilha.
			lista->pilha = backup;
		}
	}

	//Escreve valores da última lista.
	char cabecalho[15] = "Pilha número ";
	if(lista->pilha != NULL){
		backup = lista->pilha;
		fprintf(arquivo, "%s", cabecalho);
		fprintf(arquivo, "%d\n", lista->id);

		for(; lista->pilha->ant != NULL; lista->pilha = lista->pilha->ant)
			fprintf(arquivo, "%.2f\n", lista->pilha->valor);
		
		fprintf(arquivo, "%.2f\n", lista->pilha->valor);
		fprintf(arquivo, "x\n");

		lista->pilha = backup;
	}
	fprintf(arquivo, "z");
	fclose(arquivo);
}

void restaurar(lista_de_pilhas* lista){

	lista_de_pilhas* listaBackup = lista;
	
	float valor;
	char stringLixo[15];
	int ID;

	FILE* arquivo;
	arquivo = fopen("backup_pilhas.txt", "r");
	if(arquivo == NULL) {
			printf("Backup não disponível\n");
			return;
	}

	while(1){
		//Lê "Pilha" ou "z".
		fscanf(arquivo, "%s", stringLixo);
		
		//"z" é sinal de parar.
		if(strcmp(stringLixo, "z") == 0){
			printf("leu o z\n");
			break;
		}
 
		//"Pilha" é sinal de continuar.
 		if(strcmp(stringLixo, "Pilha") == 0){
			 //Lê "número".
			fscanf(arquivo, "%s", stringLixo);
			fscanf(arquivo, "%d", &ID);

			//BUG?
			novoNoLista(&lista);
			lista->id = ID;

			//enquanto conseguir ler um float, execute.
			//possivel problema aqui: backup dos ponteiros?
			while(fscanf(arquivo, "%f", &valor)){
				empilhaVazio(&lista->pilha, &lista);
				lista->pilha->valor = valor;
			}
			lista = listaBackup;

			//Lê o "x".
			fscanf(arquivo, "%s", stringLixo);
		}

	}
	printf("teste\n");
	lista = listaBackup;
}