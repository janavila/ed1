#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reader.h"

// Lista 7 - Fila (Queue);
// 09/06/2023 - (Sexta-feira);
// Jansen Rodrigues de Avila (jansenavila.aluno@unipampa.edu.br);

struct desc_queue *createQueue(void) {

    struct desc_queue *auxiliar = NULL;

    auxiliar = (struct desc_queue*) malloc (sizeof(struct desc_queue));

    auxiliar->head = NULL;
    auxiliar->tail = NULL;
    auxiliar->tamanho = 0;

    return auxiliar;

}

struct nodo *createNodo() {

    struct nodo *auxiliar = NULL;
    Musics *aux= (Musics*) malloc (sizeof(Musics));

    auxiliar = (struct nodo*) malloc (sizeof(struct nodo));

    printf("Titulo: ");
    scanf(" %[^\n]s", aux->titulo);
    printf("Artista: ");
    scanf(" %[^\n]s", aux->artista);
    printf("Letra: ");
    scanf(" %[^\n]s", aux->letra);
    printf("Codigo: ");
    scanf("%d", &(aux->codigo));
    printf("Execuções: ");
    scanf("%d", &(aux->execucoes));

    auxiliar->info = aux;
    auxiliar->prox = NULL;
    auxiliar->ant = NULL;

    return auxiliar;

}

void deleteQueue(struct desc_queue *fila) {

    while(!(emptyQueue(fila))) deQueue(fila); // botar funcão.

}

int emptyQueue(struct desc_queue *fila) {

    if(fila->tamanho == 0) return 1;
    else return 0;

}


void enQueue(struct desc_queue *fila) {

    struct nodo *novo = NULL, *auxiliar = NULL;

    novo = createNodo();

    if (fila->tamanho == 0) { // inserção do primeiro elemento.

    fila->head = novo;
    fila->tail = novo;
    fila->tamanho++;
    }

    else {
    
    auxiliar = fila->tail;
    auxiliar->ant = novo;
    novo->prox = auxiliar;
    fila->tail = novo;
    fila->tamanho++;

    }    

}

void deQueue(struct desc_queue *fila) { // adicionar caso queira remover o primeiro elemento (deixar vazia).

    struct nodo *auxiliar = NULL, *anterior = NULL;

    if(fila->tamanho == 1) { // exclui caso tenha apenas 1 elemento.
        fila->head = NULL;
        fila->tail = NULL;
        fila->tamanho--;
    }

    else {
    auxiliar = fila->head;
    anterior = auxiliar->ant; // fila->head->ant
    anterior->prox = NULL;
    fila->head = anterior;
    free(auxiliar);
    fila->tamanho--;
    }

}

int queueLenght(struct desc_queue *fila) {
    return fila->tamanho;
}

void showQueue(struct desc_queue *fila) {

    struct nodo *auxiliar = fila->tail;
    int aux=1;

    while(auxiliar != NULL) {
        printf("=====[%d]======\n", aux);
        printf("Titulo: %s\n", auxiliar->info->titulo);
        printf("Artista: %s\n", auxiliar->info->artista);
        printf("Letra: %s\n", auxiliar->info->letra);
        printf("Codigo: %d\n", auxiliar->info->codigo);
        printf("Execuções: %d\n", auxiliar->info->execucoes);

        aux++;
        auxiliar = auxiliar->prox;
    }



}

int verifyQueue(struct desc_queue *fila) {

    if(fila == NULL || fila->tamanho == 0) return 1;
    else return 0;
}

