#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

struct desc_LSE *novaLista(void) {

    struct desc_LSE *auxiliar = NULL;

    auxiliar = (struct desc_LSE*) malloc (sizeof(struct desc_LSE));
    auxiliar->tamanho = 0;
    auxiliar->lista = NULL;

    return auxiliar;
}


struct nodo *criaNodo(void) {

    struct nodo *auxiliar=NULL;

    auxiliar = (struct nodo*) malloc (sizeof(struct nodo));
    printf("Digite a chave que você deseja inserir: ");
    scanf("%d", &(auxiliar->chave));
    auxiliar->prox = NULL;

    return auxiliar;

}

struct desc_LSE *insereNodo(struct desc_LSE *descritor, int posicao) {

    struct nodo *auxLista = NULL, *auxNodo=NULL, *anterior=NULL;
    int contador=1;

    auxLista = descritor->lista;
    auxNodo = criaNodo();

    if(auxLista == NULL) { // primeira inserção
        auxLista = auxNodo;
        descritor->lista = auxLista;
        descritor->tamanho++;
        return descritor;
    }

    else { // outros três casos.

        if(posicao == 1) { // insere na primeira posição.
            anterior = auxLista;
            auxNodo->prox = anterior;
            auxLista = auxNodo;
            descritor->lista = auxLista;
            descritor->tamanho++;
            return descritor;
        }

        else if (posicao > descritor->tamanho) { // insere na última posição.
            while (auxLista->prox != NULL) {
                auxLista = auxLista->prox;
            }
            auxLista->prox = auxNodo;
            descritor->tamanho++;
            return descritor;
        }

        else { // insere no meio
            while (auxLista->prox != NULL) {
                anterior = auxLista;
                auxLista = auxLista->prox;
                contador++;
                if (contador == posicao) {
                    anterior->prox = auxNodo;
                    auxNodo->prox = auxLista;
                    descritor->tamanho++;
                    return descritor;
                }
            }
        }
    }
}


struct desc_LSE *removeNodo(struct desc_LSE *descritor, int posicao) {

    struct nodo *auxLista=NULL, *anterior = NULL;
    int contador=1;

    auxLista = descritor->lista;

    if (auxLista->prox == NULL && posicao == 1) { // quando só possui um elemento na lista.
        descritor->lista = NULL;
        descritor->tamanho--;
        return descritor;
    }

    else {

        if(posicao == 1) { // remove na primeira posição.
        anterior = auxLista->prox;
        descritor->lista = anterior;
        descritor->tamanho--;
        return descritor;
        }

        else if (posicao == descritor->tamanho) { // remove a última posição.

        while(auxLista->prox != NULL) {
        anterior = auxLista;
        auxLista = auxLista->prox;
        }
        anterior->prox = NULL;
        descritor->tamanho--;
        return descritor;
        }

        else { // remove no meio.

        while(auxLista->prox != NULL) {
        anterior = auxLista;
        auxLista = auxLista->prox;
        contador++;
        if(contador == posicao) {
            anterior->prox = auxLista->prox;
            descritor->tamanho--;
            return descritor;
            } 
            }
        }

        }

    }





void *imprimeNodo(struct desc_LSE *descritor) {

    struct nodo *auxLista=NULL;
    int contador=1;

    auxLista = descritor->lista;

    while (auxLista != NULL) {
        printf("Chave [%d]: %d\n", contador, auxLista->chave);
        auxLista = auxLista->prox;
        contador++;

    }
}
