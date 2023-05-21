#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaDuplamenteEncadeada.h"

struct discente* criaAluno(char* nome, int matricula, float media_geral, enum curso curso_aluno){

	struct discente *auxAluno=NULL;

	auxAluno = (struct discente*) malloc (sizeof(struct discente));

	strcpy(auxAluno->nome, nome);
	auxAluno->matricula = matricula;
	auxAluno->media_geral = media_geral;
	auxAluno->curso_aluno = curso_aluno;

	return auxAluno;

}


struct nodo* criaNodo(struct discente *novoAluno){//cria novos discentes para a lista mas não inseri
	struct nodo *novoElemento = (struct nodo *)malloc(sizeof(struct nodo));
	novoElemento->aluno = novoAluno;
	novoElemento->ant =  NULL;
	novoElemento->prox =  NULL;
	return novoElemento;
}
struct desc_lista_duplamente_encadeada * criaDescritor(void){//cria descritores de listas
	struct desc_lista_duplamente_encadeada *novoDescLista = (struct desc_lista_duplamente_encadeada *)malloc(sizeof(struct desc_lista_duplamente_encadeada));
	novoDescLista->tamanho = 0;
	novoDescLista->lista=NULL;
	return novoDescLista;
}


struct desc_lista_duplamente_encadeada * removeLista(struct desc_lista_duplamente_encadeada *minhaLista, int posicao){

	struct nodo*auxLista=NULL, *anterior;
	int contador = 1;

	auxLista = minhaLista->lista;

	if(posicao > (minhaLista->tamanho)) { // caso tente inserir uma posição que não existe na lista.
		printf("Posição inválida\n");
		return minhaLista;
	}

	else { 
		if (posicao == 1) { // remove na primeira posição.
			minhaLista->lista = auxLista->prox;
			minhaLista->tamanho--;
			return minhaLista;
		}

		else if (posicao == (minhaLista->tamanho)){ // remove na última
			while(auxLista->prox != NULL) {
				anterior = auxLista;
				auxLista = auxLista->prox;
			}
				anterior->prox = NULL;
				minhaLista->tamanho--; 
				return minhaLista;
			}

		else {
			while(auxLista != NULL) { // remove o do meio.
				anterior = auxLista;
				auxLista = auxLista->prox;
				contador++;
				if(contador == posicao) {
					anterior->prox = auxLista->prox;
					auxLista->prox->ant = anterior;
					minhaLista->tamanho--;
					return minhaLista;
				}
			}
		}
		}

	}




struct desc_lista_duplamente_encadeada * insere(struct desc_lista_duplamente_encadeada *minhaLista, struct nodo *novo_elemento, int posicao){

	struct nodo *auxLista = NULL, *anterior;
	int contador=1;

	auxLista = minhaLista->lista; 

	if (minhaLista->lista == NULL) { // insere o primeiro elemento já criado

		minhaLista->lista = novo_elemento;
		minhaLista->tamanho++;
		return minhaLista;
		
	}

	else { // insere nos outros 3 casos (início, meio e fim)

	if (posicao == 1) { // insere na primeira posição
		anterior = auxLista; // não perde a referência
		auxLista = novo_elemento;
		auxLista->prox = anterior;
		anterior->ant = auxLista;
		minhaLista->lista = auxLista;
		minhaLista->tamanho++;
		return minhaLista;
	}

	else { // insere no meio e no fim.

		if(posicao > minhaLista->tamanho) { // insere no último
			while(auxLista->prox != NULL) {
			auxLista = auxLista->prox;
			}

			auxLista->prox = novo_elemento;
			novo_elemento->ant = auxLista;
			minhaLista->tamanho++;
			return minhaLista;

		}

		else  { // insere no meio.

			while(auxLista->prox != NULL) {
				anterior = auxLista;
				auxLista = auxLista->prox;
				contador++;
				if(contador == posicao) {
					anterior->prox = novo_elemento;
					novo_elemento->ant = anterior;
					novo_elemento->prox = auxLista;
					minhaLista->tamanho++;
					return minhaLista;
				}
			}

		} 
		}

	}
}




int tamanho(struct desc_lista_duplamente_encadeada *minhaLista){
	return minhaLista->tamanho;
}


void libera(struct desc_lista_duplamente_encadeada *minhaLista){
	struct nodo *aux = minhaLista->lista;
	struct nodo *corrente;
	if(aux != NULL){
		while(aux->prox != NULL){//percorre a lista de discentes liberando o discentes armazenado em corrente
			corrente = aux;
			aux = aux->prox;
			free(corrente->aluno);
			free(corrente);
			aux->ant = NULL;
		}
		if(aux != NULL){
			free(aux->aluno);//libera as infos do último discente restante da lista
			free(aux); //libera o último discente restante da lista
		}
		minhaLista->lista =NULL; //transforma o ponteiro pra lista NULL no descritor
		minhaLista->tamanho=0; //atualiza o tamanho da lista no descritor
		free(minhaLista);
	}
}


struct nodo * get(struct desc_lista_duplamente_encadeada *minhaLista, int posicao){
	struct nodo *aux = minhaLista->lista;
	while((posicao > 1)&&(aux!=NULL)){
		aux=aux->prox;
		posicao--;
	}
	return aux;
}



void imprime(struct desc_lista_duplamente_encadeada *minhaLista){
	struct nodo* aux = minhaLista->lista;
	printf("\n=================================\n");
	printf("LISTA ATUAL:\n");
	while(aux != NULL){
		printf("NOME: %s, MATRICULA: %d, MEDIA: %2.f, CURSO: %d\n",aux->aluno->nome,aux->aluno->matricula, aux->aluno->media_geral, aux->aluno->curso_aluno);
		aux = aux->prox;
	}
	printf("\n=================================\n");
}

void imprimePosicao(struct desc_lista_duplamente_encadeada *minhaLista){
	int i=0;
	struct nodo *aux = NULL;
	printf("\n=================================\n");
	printf("LISTA ATUAL:\n");
	if(minhaLista->tamanho > 0){
		for(i=1;i<= minhaLista->tamanho;i++){
			aux = get(minhaLista, i);  
			printf("NOME: %s, MATRICULA: %d, MEDIA: %2.f, CURSO: %d\n",aux->aluno->nome,aux->aluno->matricula, aux->aluno->media_geral, aux->aluno->curso_aluno);
		}
	}
	printf("\n=================================\n");
}

float max(struct desc_lista_duplamente_encadeada *minhaLista, int posicao){

	struct desc_lista_duplamente_encadeada *auxDesc=NULL;
	struct nodo *auxLista=NULL;
	float media=0;
	auxLista = minhaLista->lista;

	

	if(posicao == 0) return media;

	else {
		if(media >= auxLista->aluno->media_geral) { // compara o atual com o próximo.
			media = auxLista->aluno->media_geral;
		}
		/*else {
			media = auxLista->prox->aluno->media_geral;
		}*/
		auxDesc->lista = auxLista->prox;
		return max(auxDesc, posicao-1);

	}


}

void *imprimeCurso(struct desc_lista_duplamente_encadeada *minhaLista, int curso) {
	struct nodo* aux = minhaLista->lista;
	printf("\n=================================\n");
	printf("LISTA POR CURSO [%d]:\n", curso);
	while(aux != NULL){
		if(aux->aluno->curso_aluno == curso) {
		printf("NOME: %s, MATRICULA: %d, MEDIA: %2.f, CURSO: %d\n",aux->aluno->nome,aux->aluno->matricula, aux->aluno->media_geral, aux->aluno->curso_aluno);
		}
		aux = aux->prox;
	}
	printf("\n=================================\n");

}


