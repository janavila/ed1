#include <stdio.h>
#include <stdlib.h>
#include "tad.h"


void main (void) {

    struct desc_LSE *descritor=NULL;
    int seletor=0, posicao, remove;

    printf("=======MENU=======\n1) Cria Lista\n2) Insere\n3) Remove\n4) Imprime\n5) Sair\nDigite a opção: ");
    scanf("%d", &seletor);

    do {

        switch (seletor) {
            case 1:
                if (descritor == NULL) {
                    descritor = novaLista();
                    printf("Lista criada com sucesso!!!\n\n");
                }
                else printf("Sua lista já foi criada\n");
                break;
            case 2:
                if (descritor == NULL) printf("Você ainda não criou sua lista\n");
                else {
                    printf("Digite a posição que você deseja inserir: ");
                    scanf("%d", &posicao);
                    descritor = insereNodo(descritor, posicao);
                }
                break;
            case 3:
                if (descritor == NULL || descritor->tamanho == 0) printf("Sua lista não foi criada ou não possui elementos\n");
                else {
                    printf("Digite a posição que você deseja remover: ");
                    scanf("%d", &remove);
                    if(remove > descritor->tamanho) printf("Posição inválida\n");
                    else descritor = removeNodo(descritor, remove);
                }
                break;
            case 4:
                if (descritor == NULL || descritor->tamanho == 0) printf("Sua lista não foi criada ou não possui elementos\n");
                else imprimeNodo(descritor);
                break;
            case 5:
                printf("Obrigado por utilizar\n\n");
                break;             
        }

        if (seletor != 5) {
        printf("Nova opção: ");
        scanf("%d", &seletor);
        }

    }while (seletor != 5);




}