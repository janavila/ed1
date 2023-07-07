#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reader.h"
#include <time.h>

struct desc_acervo *criaAcervo() {
    struct desc_acervo *aux = NULL;

    aux = (struct desc_acervo*) malloc (sizeof(struct desc_acervo));
    aux->acervo = NULL;
    aux->tamanho = 0;

    return aux;

}

struct desc_Fila *criaFila() {
    struct desc_Fila *aux = NULL;

    aux = (struct desc_Fila*) malloc (sizeof(struct desc_Fila));

    aux->head = NULL;
    aux->tail = NULL;
    aux->tamanho = 0;

    return aux;

}


struct nodo *quebraFrase(char *frase,int n){ // e cria a musica.

    struct nodo *auxiliar = NULL;
    struct musica *auxMusic = NULL;

    auxMusic = (struct musica *) malloc (sizeof(struct musica));
    auxiliar = (struct nodo*) malloc (sizeof(struct nodo));

    strcpy(auxMusic->artista,strtok(frase, ";"));
    auxMusic->codigo = atoi(strtok(NULL,";"));
    strcpy(auxMusic->titulo, strtok(NULL,";"));
    strcpy(auxMusic->letra, strtok(NULL,";"));
    auxMusic->execucoes = 0;

    auxiliar->info = auxMusic;
    auxiliar->prox = NULL; // isso aqui faz toda diferença

	return auxiliar;
}

void insereMusica(struct desc_acervo *descritor, struct nodo *musica){

    struct nodo *aux = NULL, *anterior = NULL;

    aux = descritor->acervo;

    if(aux == NULL) { // primeiro elemento da lista.

    descritor->acervo = musica;
    descritor->acervo->prox = NULL;
    descritor->tamanho++;

    }

    else { // demais elementos.

    while(aux->prox != NULL) { // percorre toda lista.
        aux = aux->prox;
    }

    aux->prox = musica;
    descritor->tamanho++;

    }


}

struct nodo *buscaMusica(struct desc_acervo *descritor, int criterio) {

    struct nodo *auxiliar = NULL, *search = NULL;
    int codigo;
    char aux[256];

    auxiliar = descritor->acervo;

    switch(criterio) {
        case 1:
        printf("Diga o número do código: ");
        scanf("%d", &codigo);
        search = buscaCodigo(auxiliar,codigo); 
        break;

        case 2:
        printf("Diga o título: ");
        scanf("%s", aux);
        buscaTitulo(auxiliar, aux);
        break;

        case 3:
        printf("Diga o artista: ");
        scanf("%s", aux);
        buscaArtista(auxiliar, aux);
        break;

    }

    return search;
}

struct nodo *buscaCodigo(struct nodo *auxiliar, int code) {

    while(auxiliar != NULL) {

    if(auxiliar->info->codigo == code) return auxiliar;
    auxiliar = auxiliar->prox;

    }

}

void *buscaTitulo(struct nodo *auxiliar, char *title) { // verificar se é o caso manter tudo minusculo.

    while(auxiliar != NULL) {

    if(strcmp(auxiliar->info->titulo,title) == 0) mostraMusica(auxiliar);
    auxiliar = auxiliar->prox;

    }

}

void *buscaArtista(struct nodo *auxiliar, char *title) { // verificar se é o caso manter tudo minusculo.

    while(auxiliar != NULL) {

    if(strcmp(auxiliar->info->artista,title) == 0) mostraMusica(auxiliar);
    auxiliar = auxiliar->prox;

    }

}

void mostraMusica(struct nodo *musica) {

    printf("\n\n===================================\n");
	printf("artista é: %s \n", musica->info->artista);
	printf("codigo é: %d \n", musica->info->codigo);
	printf("titulo é: %s \n", musica->info->titulo);
	printf("letra é: %s \n", musica->info->letra); 
	printf("===================================\n");

}

void insereFila(struct desc_Fila *descritorFila, struct nodo *musica) {

    struct nodo *novo = NULL, *auxiliar = NULL, *copia = NULL;

    copia = (struct nodo *) malloc (sizeof(struct nodo));
    copia->info = musica->info; // copia os dados da músicas para não perder a referência.
    copia->prox = NULL; // assim, transforma em um nodo completamente novo e copiado.

    if(descritorFila->tamanho == 0) { // primeiro elemento.

        descritorFila->head = copia;
        descritorFila->tail = copia;
        descritorFila->tamanho++;
    }

    else {
        auxiliar = descritorFila->tail; // ARRUMAR ESSA PARTE AQUI.
        copia->prox = auxiliar;
        descritorFila->tail = copia;
        descritorFila->tamanho++;

    }

}

struct desc_Fila *criaPlaylistFila(struct desc_acervo *descritor) {
    
    struct desc_Fila *fila = NULL;
    struct nodo *aux = NULL;
    int nMusicas, nRandom, contador = 0;
    aux = descritor->acervo;

    fila = criaFila();

    srand(time(NULL)); // função que gera os números aleatórios sempre que executado.

    printf("Diga o número de músicas que você deseja: ");
    scanf("%d", &nMusicas);

    for(int i=0; i<nMusicas; i++) {
        nRandom = rand () % 5000;

        while(contador <= nRandom) {
            aux = aux->prox; // vai passando as musicas até chegar no número desejado.
            contador++;
        }
        contador = 0;
        insereFila(fila, aux); // adiciona a música na fila.
        aux = descritor->acervo;
    }

    return fila;
}

struct desc_acervo *criaPilha(struct desc_acervo *descritor) { // ARRUMAR ESSA FUNÇÃO AQUI

    struct desc_acervo *pilha = NULL;
    struct nodo *aux = NULL, *copia = NULL, *auxiliar;
    int codigo;

    aux = (struct nodo *) malloc (sizeof(struct nodo));

    auxiliar = descritor->acervo;
    pilha = criaAcervo();

    printf("Diga o código da música que você deseja inserir (-1 para sair): ");


    do{

    scanf("%d", &codigo);
    if(codigo != -1) {

        aux = buscaCodigo(auxiliar,codigo);
        copia->info = aux->info;
        copia->prox = NULL;
        insereMusica(pilha, aux); // insere como se fosse uma lista normal
    }

    }while(codigo != -1);

    return pilha;
}

void imprimeMusicas(struct nodo *musicas) {

    struct nodo *aux = NULL;
    aux = musicas;

    while (aux != NULL) {
    mostraMusica(aux);
    aux = aux->prox;
    }

}