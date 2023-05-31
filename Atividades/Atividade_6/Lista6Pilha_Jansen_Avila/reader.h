// Lista 6 - Pilha (Stack);
// 30/05/2023 - (Terça-feira);
// Jansen Rodrigues de Avila (jansenavila.aluno@unipampa.edu.br);

typedef struct musica{
char titulo[50]; char album[50]; char artista[50]; char genero [10]; int ano;
int execucoes;
}Music;

struct nodo{
    struct nodo *prox;
    Music *info;
};

struct desc_Pilha{
struct nodo *Pilha; 
int tamanho;
};

struct desc_Pilha *criaPilha(void);
void *pushPilha(struct desc_Pilha *descritor); // coloca um elemento na pilha
struct nodo *criaItem(); // cria um elemento para pilha
void *popPilha(struct desc_Pilha *descritor); // apaga o elemento do topo da pilha
struct nodo *topPilha(struct desc_Pilha *descritor); // retorna o topo da pilha.
int emptyPilha(struct desc_Pilha *descritor);
void imprimePilha(struct desc_Pilha *descritor);
int verificaPilha(struct desc_Pilha *descritor);