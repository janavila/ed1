#include <stdio.h>
#include <stdlib.h>
#include "reader.h"

// Lista 6 - Pilha (Stack);
// 30/05/2023 - (Terça-feira);
// Jansen Rodrigues de Avila (jansenavila.aluno@unipampa.edu.br);

struct desc_Pilha *criaPilha() {

    struct desc_Pilha *descritor=NULL;

    descritor = (struct desc_Pilha*) malloc (sizeof(struct desc_Pilha));

    descritor->Pilha = NULL;
    descritor->tamanho = 0;

    return descritor;

}

struct nodo *criaItem() {

    struct nodo *auxiliar=NULL;
    auxiliar = (struct nodo*) malloc (sizeof(struct nodo));
    Music *musica = malloc (sizeof(Music));

    setbuf(stdin, NULL);
    printf("Título: ");
    scanf("%[^\n]s", musica->titulo);
    setbuf(stdin, NULL);
    printf("Album: ");
    scanf("%[^\n]s", musica->album);
    setbuf(stdin, NULL);
    printf("Artista: ");
    scanf("%[^\n]s", musica->artista);
    setbuf(stdin, NULL);
    printf("Genero: ");
    scanf("%[^\n]s", musica->genero);
    setbuf(stdin, NULL);
    printf("Ano: ");
    scanf("%d", &(musica->ano));

    auxiliar->info = musica;
    auxiliar->prox = NULL;
    return auxiliar;
}

void *pushPilha(struct desc_Pilha *descritor) {


    struct nodo *auxiliar=NULL, *item=NULL, *anterior;

    auxiliar = descritor->Pilha;
    item = criaItem();

    item->prox = auxiliar;
    descritor->Pilha = item;
    descritor->tamanho++;
}

void *popPilha(struct desc_Pilha *descritor) {

    struct nodo *auxiliar = NULL, *anterior = NULL;

    anterior = descritor->Pilha;
    auxiliar = descritor->Pilha->prox; // recebe o topo.
    descritor->Pilha = auxiliar;
    free(anterior);
    descritor->tamanho--;

}

struct nodo *topPilha(struct desc_Pilha *descritor) {
    return descritor->Pilha; // topo da pilha
}

int emptyPilha(struct desc_Pilha *descritor){

    if(descritor->Pilha == NULL) return 1;
    else return 0;

}

void imprimePilha(struct desc_Pilha *descritor) {

    struct nodo *auxiliar = NULL;
    int contador=1;

    auxiliar = descritor->Pilha;

    while (auxiliar != NULL) {
        printf("==========[%d]==========\n", contador);
        printf("Titulo: %s\n", auxiliar->info->titulo);
        printf("Album: %s\n", auxiliar->info->album);
        printf("Artista: %s\n", auxiliar->info->artista);
        printf("Genero: %s\n", auxiliar->info->genero);
        printf("Ano: %d\n", auxiliar->info->ano);

        auxiliar = auxiliar->prox;
        contador++;
    }

}


int verificaPilha(struct desc_Pilha *descritor) {
    if(descritor == NULL || descritor->tamanho == 0) return 1;
    else return 0;
}
