#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reader.h"

// Lista 7 - Fila (Queue);
// 09/06/2023 - (Sexta-feira);
// Jansen Rodrigues de Avila (jansenavila.aluno@unipampa.edu.br);

void main (void) {

    struct desc_queue *fila=NULL;
    int seletor=0;

    printf("===========MENU===========\n1) CREATE\n2) DELETE\n3) EMPTY\n4) ENQUEUE\n5) DEQUEUE\n6) LENGHT\n7) SHOW\n8) EXIT");

    do {
        printf("\nEscolha a opção: ");
        scanf("%d", &seletor);

        switch (seletor) {
            case 1:
            if(fila != NULL) printf("Você já criou a sua fila");
            else {
                fila = createQueue();
                printf("Fila criada com sucesso\n");
            }
            break;

            case 2:
            if(fila == NULL || fila->tamanho == 0) printf("Fila não criada ou está vazia\n");
            else {
                deleteQueue(fila);
                printf("Fila removida\n");
            }
            break;

            case 3:
            if(fila == NULL) printf("Você ainda não criou a sua fila\n");
            else{
                if(emptyQueue(fila)) printf("A Fila está vazia\n");
                else printf("Fila não está vazia\n");
            }
            break;

            case 4:
            if(fila == NULL) printf("Você ainda não criou a sua fila\n");
            else {
                enQueue(fila);
                printf("Elemento inserido com sucesso! [%d]\n", fila->tamanho);

            }
            break;
            case 5:
            if(verifyQueue(fila)) printf("Fila não criada ou está vazia\n");
            else {
                deQueue(fila);
                printf("Elemento removido com sucesso! [%d]\n", fila->tamanho);
            }
            break;

            case 6:
            if(verifyQueue(fila)) printf("Fila não criada ou está vazia\n");
            else printf("Tamanho da fila: [%d]\n", queueLenght(fila));
            break;

            case 7:
            if(verifyQueue(fila)) printf("Fila não criada ou está vazia\n");
            else showQueue(fila); 

            break;
            case 8:
            break;
            default:
            printf("Opção inexistente\n");
        }

    }while (seletor != 8);

}