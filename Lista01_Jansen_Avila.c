#include <stdio.h>
#include <stdlib.h>

// Lista 1
// 25/03/2023 - (Sábado);
// Jansen Rodrigues de Avila (jansenavila.aluno@unipampa.edu.br)

int **criaMatriz(int m, int n);
void leiaMatriz (int **mat, int m, int n);
int somaMatriz (int **mat, int m, int n);
int *colunaMat(int **mat, int m, int n, int ncoluna);
void liberaMatriz(int **mat, int ncoluna);
void imprimeMatriz(int **mat, int m, int n);
void imprimeVet (int *vet, int n);

void main (void) {

	int **matriz=NULL, m, n, matrizSoma, *vetor=NULL, selector=0, aux=0;

	printf("Selecione uma operacao\n1) Criar Matriz\n2) Inserir Elementos (Aleatorios)\n3) Imprime Matriz\n4) Soma Matriz\n5) Cria Vetor\n6) Imprime Vetor\n7) Sair\n");
	printf("Opcao Escolhida: ");

do {
	if(selector != 0) printf("\nSelecione um nova operacao: ");
	scanf("%d", &selector);
	switch(selector) {
		case 1: 
				printf("Digite o valor de m (coluna): ");
				scanf("%d", &m);
				printf("Digite o valor de n (linha): ");
				scanf("%d", &n);
				matriz = criaMatriz(m,n);
			if (matriz != NULL) printf("Matriz criada com sucesso!!\n");
			else printf("Erro na criação da Matriz!!\n");
			break;
		case 2: leiaMatriz(matriz,m,n);
			printf("Elementos Inseridos com Sucesso!!\n");
			aux = 1;
			break;
		case 3: if (aux == 1) imprimeMatriz(matriz,m,n);
			else printf("Os elementos nao foram inseridos\n");
			break;
		case 4: matrizSoma = somaMatriz(matriz,m,n);
			printf("\nSoma da Matriz: %d\n", matrizSoma);
			break;
		case 5: vetor = colunaMat(matriz,m,n,m);
			if (vetor != NULL) printf("Vetor criado com sucesso!!\n");
			else printf("Erro na criação do Vetor!!\n");
			break;
		case 6: imprimeVet(vetor, m);
			break;
		case 7: printf("Obrigado por utilizar\n"); 
			liberaMatriz(matriz, m);
			free(vetor);
			break;
		default: printf("Opcao nao inexistente, tente novamente\n");
	}

} while (selector != 7);

}

int **criaMatriz(int m, int n){
	int **matriz = (int**) malloc (sizeof(int*)*m);
	int i, j;

	for(i=0; i<n; i++) {
		matriz[i] = (int*) malloc (sizeof(int)*n);
		}


	return matriz; 
}

void leiaMatriz (int **mat, int m, int n){
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
			mat[i][j] = rand () % 10;
		}
	}

}

int somaMatriz (int **mat, int m, int n) {

	int aux=0;

	for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				aux = aux + mat[i][j]; 
			}
		}

	return aux;

} 

int *colunaMat(int **mat, int m, int n, int ncoluna){
	int *vet, aux;

	vet = (int*) malloc (sizeof(int)*ncoluna);

	for(int i=0; i<m; i++){
			aux = 0;
			for(int j=0; j<n; j++){
				aux = aux + mat[j][i]; 
			}
			vet[i] = aux;
		}

		return vet;
}

void liberaMatriz(int **mat, int ncoluna) {

		for(int i=0; i< ncoluna; i++) free(mat[i]);

}

void imprimeMatriz(int **mat, int m, int n){
	printf("Matriz: \n");
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}

}

void imprimeVet (int *vet, int n){
	printf("Vetor: ");
	for(int i=0; i<n; i++) printf("%d ", vet[i]);
}


