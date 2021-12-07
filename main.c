#include "headers.h"

int main(){
	char operador;

	lista_de_pilhas* noListaTemp = NULL;
	lista_de_pilhas* noListaTempDes = NULL;
	
	lista_de_pilhas* lista = (lista_de_pilhas*)malloc(sizeof(lista_de_pilhas));
	lista_de_pilhas* backupAtemporal = lista;

	lista->prox = NULL;
	lista->pilha = NULL;
	lista->id = 0;
	
	int menu;
	do{
		printf(VERDE "\n********** MENU **********" RESET);
		printf(AZUL "\n1  - Criar um novo nó na lista\n");
		printf("2  - Remover um nó da lista\n");
		printf("3  - Listar nós da lista\n");
		printf("4  - Empilhar um nó em uma pilha\n");
		printf("5  - Desempilhar um nó de uma pilha\n");
		printf("6  - Listar nós de uma pilha\n");
		printf("7  - Operações aritméticas\n");
		printf("8  - Reduzir pilhas\n");
		printf("9  - Esvaziar\n");	
		printf("10 - Mover stacks\n");	
		printf("11 - Copiar stacks\n");
		printf("12 - Listar stacks crescente\n");
		printf("13 - Listar stacks descrescente\n");
		printf("14 - Backup\n");
		printf("15 - Restaurar backup\n");
    printf(VERDE "****************************\n" RESET);
    printf(AMARELO "\nDigite a opção desejada:");
		
		scanf("%d", &menu);
		switch(menu){
			case 1: 
				novoNoLista(&lista); 
				break;

			case 2:
			 noListaTemp = lista; 
			 if(encontrarNoLista(&noListaTemp)) removerNoLista(&noListaTemp, &lista); 
			 else printf(VERMELHO"\nERROR: ID não encontrado.\n\n"RESET); 
			 break;

			case 3:
			 listarNosLista(&lista); 
			 break;

			case 4:
			 noListaTemp = lista; 
			 if(encontrarNoLista(&noListaTemp)) empilha(&noListaTemp->pilha, &noListaTemp); 
			 else printf(VERMELHO "\nERROR: ID não encontrado.\n\n" RESET); 
			 break;

			case 5: 
				noListaTemp = lista; 
				if(encontrarNoLista(&noListaTemp)) desempilha(&noListaTemp->pilha, &noListaTemp); 
				else printf(VERMELHO "\nERROR: ID não encontrado.\n\n" RESET); 
				break;

			case 6: 
			noListaTemp = lista; 
			if(encontrarNoLista(&noListaTemp)) listarNosPilha(&(noListaTemp->pilha)); 
			else printf(VERMELHO"ERROR: ID não encontrado.\n\n"RESET); 
			break;
			
			case 7: 
				noListaTemp = lista; 
				if(encontrarNoLista(&noListaTemp)){
					printf("Digite o operador desejado: (+ - * /)\n"); 
					scanf(" %c", &operador); 
					operarPilha(operador, &noListaTemp->pilha, &noListaTemp);
				}
				else printf(VERMELHO"ERROR: ID não encontrado.\n\n"RESET);
				break;

			case 8: 
				noListaTemp = lista; 
				if(encontrarNoLista(&noListaTemp)) printf("Digite o operador desejado: (+ - * /)\n"); 
				scanf(" %c", &operador); 
				reduzirPilha(operador, &noListaTemp->pilha, &noListaTemp); 
				break;

			case 9: 
				noListaTemp = lista; 
				if(encontrarNoLista(&noListaTemp)) esvaziarPilha(&noListaTemp->pilha, &noListaTemp);
				break;

			case 10: 
				printf("Insira ID da pilha origem e da destino (Ex: X Y): ");
				int ori, des;
				scanf("%d %d", &ori, &des);
				fflush(stdin);

				noListaTemp = lista;
				if(encontrarNoListaAutomatico(&noListaTemp, ori)){
					if(noListaTemp->pilha == NULL){
						printf(VERMELHO"ERROR: Não há pilha.\n\n"RESET);
						break;	
					} 
					noListaTemp = lista;
					if(encontrarNoListaAutomatico(&noListaTemp, des)){
						if(noListaTemp->pilha == NULL){
							printf(VERMELHO"ERROR: Não há pilha.\n\n"RESET);
							break;	
						} 
						noListaTemp = lista;
						printf("Digite quantidade de stacks da origem: ");
						int qtd, qtdStacks;
						scanf("%d", &qtd);
						fflush(stdin);
						//Apontar lista pro nó em questão.
						encontrarNoListaAutomatico(&noListaTemp, ori);
						qtdStacks = contarStacks(&noListaTemp);

						if(qtd <= qtdStacks){
							noListaTemp = lista;
							noListaTempDes = lista;
							
							encontrarNoListaAutomatico(&noListaTemp, ori);
							encontrarNoListaAutomatico(&noListaTempDes, des);
							moverStack(&noListaTemp, &noListaTempDes, qtd, ori, des);
						}
						else{
							printf(VERMELHO"ERROR: Não há quantidade de stacks suficiente.\n\n"RESET);
						}
					}
					else{
					printf(VERMELHO"ERROR: ID não encontrado.\n\n"RESET);
					}
				}
				else{
					printf(VERMELHO"ERROR: ID não encontrado.\n\n"RESET);
				}
				break;

				case 11: 
				printf("Insira ID da pilha origem e da destino (Ex: X Y): ");
				scanf("%d %d", &ori, &des);
				fflush(stdin);

				noListaTemp = lista;
				if(encontrarNoListaAutomatico(&noListaTemp, ori)){
					if(noListaTemp->pilha == NULL){
						printf(VERMELHO"ERROR: Não há pilha.\n\n"RESET);
						break;	
					} 
					noListaTemp = lista;
					if(encontrarNoListaAutomatico(&noListaTemp, des)){
						if(noListaTemp->pilha == NULL){
							printf(VERMELHO"ERROR: Não há pilha.\n\n"RESET);
							break;	
						} 
						noListaTemp = lista;
						printf("Digite quantidade de stacks da origem: ");
						int qtd, qtdStacks;
						scanf("%d", &qtd);
						fflush(stdin);
						//Apontar lista pro nó em questão.
						encontrarNoListaAutomatico(&noListaTemp, ori);
						qtdStacks = contarStacks(&noListaTemp);

						if(qtd <= qtdStacks){
							noListaTemp = lista;
							noListaTempDes = lista;
							
							encontrarNoListaAutomatico(&noListaTemp, ori);
							encontrarNoListaAutomatico(&noListaTempDes, des);
							copiarStack(&noListaTemp, &noListaTempDes, qtd, ori, des);
						}
						else{
							printf(VERMELHO"ERROR: Não há quantidade de stacks suficiente.\n\n"RESET);
						}
					}
					else{
					printf(VERMELHO"ERROR: ID não encontrado.\n\n"RESET);
					}
				}
				else{
					printf(VERMELHO"ERROR: ID não encontrado.\n\n"RESET);
				}
				break;

				case 12:
					noListaTemp = lista;
					if(encontrarNoLista(&noListaTemp)){
						//printf("lista->pilha->valor = %f\n", noListaTemp->pilha->valor);
						listarStackCrescente(noListaTemp);
					}
					else printf(VERMELHO"ERROR: ID não encontrado.\n\n"RESET);
					break;

				case 13:
				noListaTemp = lista;
				if(encontrarNoLista(&noListaTemp)){
					//printf("lista->pilha->valor = %f\n", noListaTemp->pilha->valor);
					listarStackDecrescente(noListaTemp);
				}
				else printf(VERMELHO"ERROR: ID não encontrado.\n\n"RESET);
				break;

				case 14:
					noListaTemp = backupAtemporal;
					backup(noListaTemp);
					break;

				case 15:
					noListaTemp = backupAtemporal;
					restaurar(noListaTemp);
					break; 

		}

		printf("Pressione enter para continuar.\n");
		char continuar = fgetc(stdin);
		continuar = fgetc(stdin);
		system("clear");
		
	}while(menu >= 0 && menu <  16);
}