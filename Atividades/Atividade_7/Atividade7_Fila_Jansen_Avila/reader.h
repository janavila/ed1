// Lista 7 - Fila (Queue);
// 09/06/2023 - (Sexta-feira);
// Jansen Rodrigues de Avila (jansenavila.aluno@unipampa.edu.br);

typedef struct musica{
    char titulo[256];
    char artista[256];
    char letra[256];
    int codigo;
    int execucoes;
}Musics;

struct nodo{
Musics *info; 
struct nodo *prox; 
struct nodo *ant;
};

struct desc_queue{
struct nodo *head; 
struct nodo *tail;
int tamanho;
};

struct desc_queue *createQueue(); // cria a fila (ok)
struct nodo *createNodo(); // cria o nodo. (ok)
void deleteQueue(struct desc_queue *fila); // faz a fila ficar vazia
int emptyQueue(struct desc_queue *fila); // verificar se a fila está vazia
void enQueue(struct desc_queue *fila); // insere o item na fila. (ok)
void deQueue(struct desc_queue *fila); // retira o item da fila. (ok)
int queueLenght(struct desc_queue *fila); // mostra o tamanho da fila.
void showQueue(struct desc_queue *fila); // mostra a fila. (ok)
int verifyQueue(struct desc_queue *fila); // FUNÇÃO EXTRA PRA VERIFICAR A FILA.
