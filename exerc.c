#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Pair programming

/*1- Crie um looping para preencher as 5 estruturas de bandas criadas no exemplo passado. Após criar e preencher, exiba todas as informações das bandas/estruturas.
2-Crie uma função que peça ao usuário um número de 1 até 5.Em seguida, seu programa deve exibir informações da banda cuja posição no seu ranking é a que foi solicitada pelo usuário.
3-Crie uma função em C que peça ao usuário um tipo de música e exiba as bandas com esse tipo de música no seu ranking.
4-Crie uma função que peça o nome de uma banda ao usuário e diga se ela está entre suas bandas favoritas ou não.
5-Agora junte tudo e crie uma mega aplicação em que exibe um menu com as opções de preencher as estruturas e todas as opções das questões passadas.
6-Utilize ENUMs para a definição do gênero (tipo da música que toca):
Exemplo: enum genero{ rock=1,samba=2,reggae=3,....}; */


enum genero {rock=1,samba=2,reggae=3,pagode=4,heavymetal=5,funk=6,jazz=7};

struct bands{
	char nome[50];
	enum genero tipo;
	int nIntegrantes, posicao;
};

typedef struct bands Banda;

void mostraBanda(Banda selec[], int n);
void mostraTipo(Banda selec, enum genero tipo);
void comparaBanda(Banda selec, char *sel);


void main () {

Banda musics[2];
int seleciona, i, n, type;

//musics = (Banda*) malloc (sizeof(Banda)*2);

printf("Tipos\n1) Rock\n2) Samba\n3) Reggae\n4) Pagode\n5) Heavy Metal\n6) Funk\n7) Jazz\n\n");

for(i=0; i<2; ++i){
	printf("Nome da banda: ");
	scanf("%s", musics[i].nome);
	printf("Tipo de Musica: ");
//	scanf("%d", &musics[i].tipo);
	scanf("%d", &type);
	musics[n].tipo = type;
	printf("Numero de Integrantes: ");
	scanf("%d", &musics[i].nIntegrantes);
	printf("Posicao no Ranking: ");
	scanf("%d", &musics[i].posicao);

}

printf("Insira a opção que deseja\n1) Informa Banda\n2) Informa Tipo\n3) Favoritas\n4) Sair\n5) Opção: ");
scanf("%d", &seleciona);

do {

	switch(seleciona){

		case 1:
			printf("\nInforme qual banda: ");
			scanf("%d", &n);
			//mostraBanda(musics, n);
				printf("Banda: %s\nIntegrantes: %d\nRanking: %d\n", musics[n].nome, musics[n].nIntegrantes, musics[n].posicao);
	
// tentar adicionar os escopos e o break depois.
	switch(musics[n].tipo){
	case (1): printf("Tipo: Rock\n");
	case (2): printf("Tipo: Samba\n");
	case (3): printf("Tipo: Reggae\n");
	case (4): printf("Tipo: Pagode\n");
	case (5): printf("Tipo: Heavy Metal\n");
	case (6): printf("Tipo: Funk\n");
	case (7): printf("Tipo: Jazz\n");
			break;
//		case 2:
//		case 3:
//		default:
	}
}

scanf("%d", &seleciona);

}while(seleciona!=4);


}





/*void mostraBanda(Banda selec[],int n) {
	printf("Banda: %s\nIntegrantes: %d\nRanking: %d\n", selec[n].nome, selec[n].nIntegrantes, selec[n].posicao);
	printf("%d", selec[n].tipo);
	switch(selec[n].tipo){
	case (rock): printf("Tipo: Rock\n");
	case (samba): printf("Tipo: Samba\n");
	case (reggae): printf("Tipo: Reggae\n");
	case (pagode): printf("Tipo: Pagode\n");
	case (heavymetal): printf("Tipo: Heavy Metal\n");
	case (funk): printf("Tipo: Funk\n");
	case (jazz): printf("Tipo: Jazz\n");
	}

} */

	
