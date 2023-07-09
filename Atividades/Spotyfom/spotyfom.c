#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reader.h"


int main(void){
	
	FILE *arquivoEntrada;
	struct nodo *aux = NULL, *showMusic = NULL;
	struct desc_acervo *descritor = NULL, *pilha = NULL;
	struct desc_Fila *aleatorioFila = NULL;
	char caractere, frase[256];
	int tamanhoAcervo, n=0, seletor=0, criterio, sel_play;

	aux = (struct nodo*) malloc (sizeof(struct nodo)); // cria o auxiliar para armazenar as musicas.
	descritor = criaAcervo();

	arquivoEntrada = fopen("musicas.txt","r");
	if(arquivoEntrada ==NULL){
		printf("não foi possivel abrir o arquivo\n");
		exit(-1);
	}
	
	fscanf(arquivoEntrada,"%d",&tamanhoAcervo);

// =====================================================================================================================================
	while((caractere = fgetc(arquivoEntrada))!= EOF){ // pega frase por frase
		if(caractere != '\n'){ 
			frase[n]=caractere;
			n++;
		}
	
		else{ // encontrou o final da frase
			if(n > 0){
				frase[n]='\0';
				aux = quebraFrase(frase,n);
				insereMusica(descritor, aux);
//				mostraMusica(descritor->acervo);
			}
			n=0;
			frase[n]='\0';
		}
// =====================================================================================================================================
	}

	printf("======MENU======\n1) Execução\n2) Playlist\n3) Busca\n4) Impressão\n5) Sair");
	do{

	printf("\nEscolha a opção: ");
	scanf("%d", &seletor);

	switch(seletor) {
		case 1:
		printf("==Você deseja escutar qual playlist==\n1) Aleatória [Fila]\n2) Pessoal [Pilha]\nOpção: ");
		scanf("%d", &criterio);
		if(criterio == 1 && aleatorioFila != NULL) playListFila(descritor, aleatorioFila);
		else if(criterio == 2 && pilha != NULL) playlistPilha(descritor,pilha); // IMPLEMENTAR
		else printf("Opção invalida ou a playlist não foi criada!\n");
		break;


		case 2:
		printf("==Digite o critério de seleção==\n1) Aleatório [Fila]\n2) Playlist Pessoal [Pilha]\nOpção: ");
		scanf("%d", &sel_play);
		if (sel_play == 1) aleatorioFila = criaPlaylistFila(descritor);
		else if (sel_play == 2) pilha = criaPilha(descritor);
		else printf("Opção inexistente!\n");
		break;



		case 3:
		printf("==Digite o critério de seleção==\n1) Código\n2) Título\n3) Artista\nOpção: ");
		scanf("%d", &criterio);
		if(criterio > 0 && criterio < 4) {
			if(criterio == 1) {
				showMusic = buscaMusica(descritor,criterio); // específico para o primeiro caso por causa do retorno.
				mostraMusica(showMusic);
			}
			else showMusic = buscaMusica(descritor,criterio); // para os outros casos.
		}
		else printf("Opção inválida\n");
		break;

		case 4:
		printf("==Você deseja imprimir==\n1) Acervo\n2) Fila\n3) Pilha\nOpção: ");
		scanf("%d", &criterio);
		if(criterio == 1) imprimeMusicas(descritor->acervo);
		else if (criterio == 2 && aleatorioFila != NULL) imprimeMusicas(aleatorioFila->tail);
		else if (criterio == 3 && pilha != NULL) imprimeMusicas(pilha->acervo);
		else printf("Opção inexistente ou playlist não criada!\n");
		break;
		
		case 5:
		printf("Obrigado por utilizar!!\n");
		break;

		default:
		printf("Opção inexistente\n");
		break;

	}
	
	}while(seletor != 5);

return 0;

}
