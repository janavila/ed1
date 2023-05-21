// Lista 4 - Lista Simplesmente Encadeada (LSE)
// 08/05/2023 - (Segunda);
// Jansen Rodrigues de Avila (jansenavila.aluno@unipampa.edu.br)


struct musica {
	char titulo[256];
	char artista[256];
	char letra[256];
	int codigo;
	int execucoes;
};

typedef struct musica musics;

struct nodo {
	struct nodo *prox;
	musics *info;
};

struct desc_LSE { // descritor que controla a lista.
	struct nodo *LSE; // aponta para o começo da lista, sempre (primeiro)
	int tamanho; // controla o tamanho da lista.
};

struct desc_LSE *criaLista();
void *insere(struct desc_LSE *descritor, int posicao);
musics *criaMusica();
void *imprime(struct desc_LSE *descritor);
void *removeNodo(struct desc_LSE *descritor, int posicao);
void *consulta(struct desc_LSE *descritor, int consulta);