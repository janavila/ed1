#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// Lista 2 (Atividade Mercado)
// 04/04/2023 (Terça-feira)
// Jansen Rodrigues de Avila (jansenavila.aluno@unipampa.edu.br)

enum setores {limpeza=1,higiene=2,hortifruti=3, padaria=4, bazar=5, bebidas=6};

typedef struct produto {
	char nome[15];
	enum setores sector;
	int quantidade, preco;

}product;

product insereProdutos();
void apresentaProduto(product *aux,int produto);
int calculaBalanco(product *aux,int nProduto);
void buscaNome(product *aux, char *nome, int tamanhoReal);
void buscaSetor(product *aux, int set_aux, int tamanhoReal);
void printaSetor(product *aux, int n);
product *venda(product *aux, char *produto, int qtdVenda, int tamanhoReal);

void main (void) {

	int nProdutos, selector=0, nApresenta, balanco, tamanhoTotal=0, tamanhoReal, busc_setor, qtdVenda;
	product *mercado=NULL;
	char achaNome[20], produtoVenda[20];

	printf("Digite a quantidade de produtos que voce deseja cadastrar: ");
	scanf("%d", &nProdutos);
	tamanhoReal = nProdutos;

	mercado = (product*) malloc (sizeof(product)*nProdutos);

	printf("\nLISTA DE SETORES\n1) Limpeza\n2) Higiene\n3) Hortifruti\n4) Padaria\n5) Bazar\n6) Bebidas\n-------------------------------------------------------------\n");
	printf("\nOPCOES\n1) Inserir Produtos\n2) Apresentar Produto\n3) Todos Produtos\n4) Balanco\n5) Busca por Nome\n6) Busca por Setor\n7) Venda\n8) Sair\n");

	do {
		printf("Selecione: ");
		scanf("%d", &selector);

		switch(selector){
			case 1:

			if(tamanhoTotal < tamanhoReal){
			
				mercado[tamanhoTotal] = insereProdutos();
				printf("Produto Adicionado, voce ainda possui %d produtos restantes\n", tamanhoReal-(tamanhoTotal+1));
				tamanhoTotal++;

				}
			else {
				printf("Nao ha possibilidade de adicionar mais produtos\n\n");
				} 
			break;

			case 2:
			printf("Qual produto voce deseja ver: ");
			scanf("%d", &nApresenta);
			apresentaProduto(mercado,nApresenta-1);
			break;

			case 3: 
				for(int i=0; i<tamanhoTotal; ++i) {
				apresentaProduto(mercado,i);
				}
			break;

			case 4:
			balanco = calculaBalanco(mercado, nProdutos-1); // para não começar em lixo de memória.
			printf("Balanco: %d ao total\n\n", balanco);
			break;

			case 5:
			printf("Digite o nome que deseja achar: ");
			scanf("%s", achaNome);
			buscaNome(mercado, achaNome, tamanhoTotal);
			break;

			case 6:
			printf("Digite o setor que voce deseja achar: ");
			scanf("%d", &busc_setor);
			buscaSetor(mercado, busc_setor, tamanhoTotal);
			break;

			case 7:
			printf("Produto: ");
			scanf("%s", produtoVenda);
			printf("Quantidade: ");
			scanf("%d", &qtdVenda);
			mercado = venda(mercado, produtoVenda, qtdVenda, tamanhoTotal);
			break; 

		}

	}while(selector!=8);

}

product insereProdutos() {

	int i, aux_sector;
	product auxiliar;

		printf("Nome: ");
		scanf("%s", auxiliar.nome);
		printf("Setor: ");
		scanf("%d", &aux_sector);
		auxiliar.sector = aux_sector;
		printf("Quantidade em estoque: ");
		scanf("%d", &auxiliar.quantidade);
		printf("Preco: ");
		scanf("%d", &auxiliar.preco);
	
	return auxiliar;

}

void apresentaProduto(product *aux,int produto) { 

	printf("Nome: %s\n", aux[produto].nome);
	printaSetor(aux, produto);
	//printf("Setor: %d\n", aux[produto].sector);
	printf("Quantidade: %d\n", aux[produto].quantidade);
	printf("Preco: %d\n", aux[produto].preco);

}


int calculaBalanco(product *aux,int nProduto) {

	if (nProduto == 0) return aux[nProduto].quantidade;

	else return (aux[nProduto].quantidade) + calculaBalanco(aux, nProduto-1);

}

void buscaNome(product *aux, char *nome, int tamanhoTotal) {

	for(int i=0; i<tamanhoTotal; ++i) {

		if( strcmp(aux[i].nome, nome) == 0 ) {
			printf("\nNome: %s\n", aux[i].nome);
			printaSetor(aux, i);
			//printf("Setor: %d\n", aux[i].sector);
			printf("Quantidade: %d\n", aux[i].quantidade);
			printf("Preco: %d\n", aux[i].preco);
		}
	}

} 

void buscaSetor(product *aux, int aux_setor, int tamanhoReal) {

	for(int i=0; i< tamanhoReal; ++i) {

		if ( aux_setor == aux[i].sector) {

			printf("\nNome: %s\n", aux[i].nome);
			printaSetor(aux, i);
			printf("Quantidade: %d\n", aux[i].quantidade);
			printf("Preco: %d\n", aux[i].preco);
		}
	}


}

void printaSetor(product *aux, int n) {

	switch(aux[n].sector) {
	case 1: printf("Setor: Limpeza\n");
		break;
	case 2: printf("Setor: Higiene\n");
		break;
	case 3: printf("Setor: Hortifruti\n");
		break;
	case 4: printf("Setor: Padaria\n");
		break;
	case 5: printf("Setor: Bazar\n");
		break;
	case 6: printf("Setor: Bebidas\n");
		break;
	default: printf("\nSetor nao cadastrado\n");
		break;
	}

}

product *venda(product *aux, char *produto, int qtdVenda, int tamanhoReal) {

	for(int i=0; i< tamanhoReal; ++i) {

		if(strcmp(aux[i].nome, produto) == 0) {

			aux[i].quantidade = aux[i].quantidade - qtdVenda;
			printf("\nProduto Vendido com Sucesso!!!\n");

		}
	}

	return aux;

}