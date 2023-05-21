#include <stdio.h>
#include <stdlib.h>
#include "reader.h"

// Lista 4 - Lista Simplesmente Encadeada (LSE)
// 08/05/2023 - (Segunda);
// Jansen Rodrigues de Avila (jansenavila.aluno@unipampa.edu.br)

struct desc_LSE *criaLista() {

	struct desc_LSE *lista;

	lista = (struct desc_LSE *) malloc (sizeof (struct desc_LSE));
	lista->LSE = NULL;
	lista->tamanho = 0;

	return lista;

}

musics *criaMusica() {

	musics *auxiliar;

	auxiliar = (musics*) malloc (sizeof(musics));

		printf("Título: ");
		setbuf(stdin,NULL);
		scanf("%[^\n]s", auxiliar->titulo);
		setbuf(stdin,NULL);
		printf("Artista: ");
		setbuf(stdin,NULL);
		scanf("%[^\n]s", auxiliar->artista);
		setbuf(stdin,NULL);
		printf("Letra: ");
		scanf("%[^\n]s", auxiliar->letra)
		printf("Codigo: ");
		scanf("%d", &(auxiliar->codigo));
		printf("Execuções: ");
		scanf("%d", &(auxiliar->execucoes));

	return auxiliar;
}

void *insere(struct desc_LSE *descritor, int posicao) { // tentar otimizar essa função e colocar tudo para ser adicionado no aux.

	struct nodo *aux, *auxiliarNodo, *anterior;
	int i=1;

	aux = (struct nodo*) malloc (sizeof(struct nodo));
	auxiliarNodo = (struct nodo*) malloc (sizeof(struct nodo));

	if (descritor == NULL) {
		printf("Você ainda não criou a sua lista\n\n");

	}

	else {

	if(descritor->LSE == NULL) { // primeiro elemento

		aux->info = criaMusica(); 
		aux->prox = NULL;
		descritor->LSE = aux;
		descritor->tamanho++;

	}

	else { // inserir na última posição vazia


		aux = descritor->LSE;

		if (posicao > descritor->tamanho) {
		while (aux->prox != NULL) {
			aux = aux->prox;
		}

		auxiliarNodo->info = criaMusica(); 
		auxiliarNodo->prox = NULL;
		aux->prox = auxiliarNodo;
		descritor->tamanho++;
	}
		else { // insere na posicao solicitada (se for valida)

			while (aux != NULL) {
				anterior = aux;
				aux = aux->prox;
				i++;

				if (i == posicao) {
					auxiliarNodo->info = criaMusica();
					auxiliarNodo->prox = aux;
					anterior->prox = auxiliarNodo;
					aux = anterior;
					descritor->tamanho++;
				}
			}

		}
}

	}

}

void *removeNodo(struct desc_LSE *descritor, int posicao) {

	struct nodo *aux, *anterior;
	int i=1;
	aux = descritor->LSE;

	if(posicao > descritor->tamanho || posicao == 0) printf("Posicao Invalida\n\n"); // testa se a posicao existe
	else {
	
	if (posicao == 1) { // remove a primeira posição
		aux = aux->prox;
		descritor->LSE = aux;
		descritor->tamanho--;
	}

	else { // remove no fim ou no meio

		while (aux != NULL) {
			anterior = aux;
			aux = aux->prox;
			i++;
			if(i == posicao) {
				anterior->prox = aux->prox;
				descritor->tamanho--;
				aux = anterior;
			}
		}
	}

	}


}


void *consulta(struct desc_LSE *descritor, int consultor) {

	int i;
	struct nodo *aux;
	aux = descritor->LSE;

	if(consultor > descritor->tamanho) printf("Posição Invalida\n");
	else {
	for(i=1; i <= consultor; i++) {

		if( i == consultor) {
		printf("Titulo: %s\n", aux->info->titulo);
		printf("Artista: %s\n", aux->info->artista);
		printf("Letra: %s\n", aux->info->letra);
		printf("Código: %d\n", aux->info->codigo);
		printf("Execucoes: %d\n\n", aux->info->execucoes);
		}

		aux = aux->prox;
	}
}

}


void *imprime(struct desc_LSE *descritor) {

	struct nodo *aux=NULL;

	aux = descritor->LSE;

	while(aux != NULL) {

		printf("Titulo: %s\n", aux->info->titulo);
		printf("Artista: %s\n", aux->info->artista);
		printf("Letra: %s\n", aux->info->letra);
		printf("Código: %d\n", aux->info->codigo);
		printf("Execucoes: %d\n\n", aux->info->execucoes);

		aux = aux->prox;
	}



}