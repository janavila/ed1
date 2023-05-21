#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reader.h"

// Lista 4 - Lista Simplesmente Encadeada (LSE)
// 08/05/2023 - (Segunda);
// Jansen Rodrigues de Avila (jansenavila.aluno@unipampa.edu.br)

int main (void) {

	struct desc_LSE *descritor=NULL; 
	int seletor=0, remove, consultor, posicao;


	do {
		printf("-----MENU-----\n1) Criar Lista\n2) Inserir\n3) Remover\n4) Consulta\n5) Imprime\n6) Sair\n--------------------------\n");
		scanf("%d", &seletor);

		switch (seletor) {

		case 1:
			if(descritor != NULL) printf("Lista já criada\n");
			else {
					descritor = criaLista();
					printf("Lista criada com sucesso\n\n");
				}
			break;

		case 2:
					
					if(descritor != NULL && descritor->tamanho > 0) { // insere os demais elementos
						printf("Diga a posição que você deseja inserir: ");
						scanf("%d", &posicao);
						insere(descritor, posicao);
						printf("Inseracao realizada com sucesso, tamanho da lista %d\n", descritor->tamanho);
					}
					else if (descritor != NULL && descritor->tamanho == 0) insere(descritor,0); // insere o primeiro elemento.
					
			break;
		case 3:
					if(descritor == NULL || descritor->tamanho == 0) printf("Você ainda não criou a lista ou a mesma não possui elementos\n\n");
					else {
					printf("Diga a posição que você deseja remover: "); // com problema nessa função
					scanf("%d", &remove);
					removeNodo(descritor,remove);
					}
			break;
		case 4:
					if(descritor == NULL || descritor->tamanho == 0  ) printf("Lista não possui elementos\n\n");
					else {
					printf("Diga a posição que você deseja consultar: ");
					scanf("%d", &consultor);
					consulta(descritor,consultor);
					}
			break;
		case 5: 
					if(descritor == NULL || descritor->tamanho == 0) printf("Lista não possui elementos\n\n");
					else imprime(descritor);
			break;
		case 6: 	printf("Obrigado por utilizar :)\n\n: ");
			break;
		default: 
			break;
		}

	}while (seletor != 6);


	return 0;

	
}