#include <stdio.h>
#include <stdlib.h>
#include "listaDuplamenteEncadeada.h"


int main(){
	
	char op='z';
	int posicao;
	struct discente *novo_aluno = NULL;
	int cont=0, matriculaAluno, curso;
	struct nodo *novo_nodo = NULL;
	struct desc_lista_duplamente_encadeada *minhaNovaLista = NULL;
	char nomeAluno[20];
	float mediaAluno, auxMedia;
	enum curso cursoAluno;


	do{
		setbuf(stdin,NULL);
		setbuf(stdin,NULL);
		printf("\n========================\nescolha a opcao:\n[c]-cria lista\n[i]insere\n[r]remove\n[l]libera\n[p]imprime\n[m]maior media geral\n[z]imprime por curso\n[s]sair\n====================\n");
		scanf("%c",&op);
		setbuf(stdin,NULL);
		switch(op){		
		case 'c':
					minhaNovaLista = criaDescritor();
					printf("lista criada com sucesso\n");
					break;
		case 'i':	
					if(minhaNovaLista ==NULL){
						printf("crie uma lista antes com a opção CRIAR\n");
						break;
					}						
					printf("digite o as informações para o novo aluno\n");
					setbuf(stdin,NULL);
					printf("Digite o nome do aluno: ");
					setbuf(stdin,NULL);
					scanf(" %[^\n]s", nomeAluno);
					setbuf(stdin,NULL);
					printf("Digite a matrícula do aluno: ");
					scanf("%d", &matriculaAluno);
					printf("Digite a média geral do aluno: ");
					scanf("%f", &mediaAluno);
					printf("Digite o curso do aluno: \n[1] Computação\n[2] Matemática\n[3] Produção\n[4] Química\n[5] Alimentos\n[6] Física\n[7] Energias\n[8] Letras\n[9] Música\n");
					scanf("%d", &cursoAluno);
					novo_aluno = criaAluno(nomeAluno, matriculaAluno, mediaAluno, cursoAluno);
					novo_nodo = criaNodo(novo_aluno);
					printf("digite a posicao do novo_aluno\n");
					setbuf(stdin,NULL);
					scanf("%d",&posicao);
					minhaNovaLista = insere(minhaNovaLista,novo_nodo,posicao);
					break;
		case 'p':
					if(minhaNovaLista ==NULL){
						printf("crie uma lista antes com a opção CRIAR\n");
						break;
					}						
					imprime(minhaNovaLista);
					//imprimePosicao(minhaNovaLista); duvida nessa
					break;
		case 'r':
					if(minhaNovaLista ==NULL){
						printf("crie uma lista antes com a opção CRIAR\n");
						break;
					}						
					printf("digite a posicao da remocao\n");
					setbuf(stdin,NULL);
					scanf("%d",&posicao);
					minhaNovaLista = removeLista(minhaNovaLista,posicao);
					break;
		case 'l':
					if(minhaNovaLista ==NULL){
						printf("crie uma lista antes com a opção CRIAR\n");
						break;
					}						
					libera(minhaNovaLista);
					break;
		case 'm':
					if(minhaNovaLista ==NULL){
						printf("crie uma lista antes com a opção CRIAR\n");
						break;
					}						
					//funcao recursiva maior media_geral
						if(minhaNovaLista->tamanho > 0){
						//struct nodo *aux = NULL;
						auxMedia = max(minhaNovaLista, minhaNovaLista->tamanho);
						printf("MAIOR MEDIA :::::: %2.f\n",auxMedia);
					}					
					break;
		case 'z':
					if(minhaNovaLista ==NULL){
						printf("crie uma lista antes com a opção CRIAR\n");
						break;
					}						
					if(minhaNovaLista->tamanho > 0){
						printf("Digite qual curso você deseja procurar: ");
						scanf("%d", &curso);
						imprimeCurso(minhaNovaLista, curso);
					}					
					break;
		case 's':
					exit(0);
		}
		op=getchar();
		setbuf(stdin,NULL);
	}while(1);
	return 0;
}
