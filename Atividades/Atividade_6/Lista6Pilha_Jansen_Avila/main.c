#include <stdio.h>
#include <stdlib.h>
#include "reader.h"

// Lista 6 - Pilha (Stack);
// 30/05/2023 - (Terça-feira);
// Jansen Rodrigues de Avila (jansenavila.aluno@unipampa.edu.br);

void main (void) {

    struct desc_Pilha *pilha=NULL;
    struct nodo *topo = NULL;
    int seletor=0;

    printf("===========MENU===========\n1) CRIA\n2) PUSH\n3) POP\n4) TOP\n5) EMPTY\n6) IMPRIME\n7) EXIT!");

    do {
        printf("\nEscolha a opção: ");
        scanf("%d", &seletor);
        switch (seletor) {
            case 1:
            if(pilha != NULL) printf("Sua Pilha já foi criada\n");
            else {
                pilha = criaPilha();
                printf("Pilha criada com sucesso!!\n");
            }
            break;

            case 2:
            if(pilha == NULL) printf("Você ainda não criou a sua pilha\n");
            else {
                pushPilha(pilha);
                printf("Elemento inserido com sucesso\n");
            }
            break;

            case 3:
            if(verificaPilha(pilha)) printf("Pilha não criada ou está vazia\n");
            else {
                popPilha(pilha);
                printf("Elemento removido com sucesso\n");
            }
            break;

            case 4:
            if(verificaPilha(pilha)) printf("Pilha não criada ou está vazia\n");
            else {
                topo = topPilha(pilha);
                printf("==========[TOPO]==========\n");
                printf("Titulo: %s\n", topo->info->titulo);
                printf("Album: %s\n", topo->info->album);
                printf("Artista: %s\n", topo->info->artista);
                printf("Genero: %s\n", topo->info->genero);
                printf("Ano: %d\n", topo->info->ano);
            }
            break;

            case 5:
            if(pilha == NULL) printf("Pilha não criada\n");
            else{
                if (emptyPilha(pilha)) printf("Pilha vazia\n");
                else printf("Pilha não está vazia, contêm [%d] elementos\n", pilha->tamanho);
            }
                
            break;

            case 6:
            if(verificaPilha(pilha)) printf("Pilha não criada ou está vazia\n");
            else imprimePilha(pilha);
            break;

            case 7:
            printf("Obrigado por utilizar\n");
            break;
        }

    }while (seletor != 7);


}