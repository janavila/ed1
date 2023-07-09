struct musica{
char titulo[256];
char artista[256];
char letra[256];
int codigo;
int execucoes; //numero de execuções da musica em playlists
};

struct nodo{ // nodo
    struct musica *info;
    struct nodo *prox;
};

struct desc_acervo{ // descritor Lista // descritor Pilha
    struct nodo *acervo;
    int tamanho;
};

struct desc_Fila{ // descritor Fila
    struct nodo *head;
    struct nodo *tail;
    int tamanho;
};


struct nodo *quebraFrase(char *frase,int n); // okay
struct desc_acervo *criaAcervo(); // okay
struct desc_Fila *criaFila(); // okay
void insereMusica(struct desc_acervo *descritor, struct nodo *musica); // okay
struct nodo *buscaMusica(struct desc_acervo *descritor, int criterio); // ok
struct nodo *buscaCodigo(struct nodo *auxiliar, int code); // ok
void *buscaTitulo(struct nodo *auxiliar, char *title); // ok
void *buscaArtista(struct nodo *auxiliar, char *artista); // ok
void mostraMusica(struct nodo *musica); // okay
struct desc_Fila *criaPlaylistFila(struct desc_acervo *descritor); // ok
void insereFila(struct desc_Fila *descritorFila, struct nodo *musica); // ok
struct desc_acervo *criaPilha(struct desc_acervo *descritor); // ARRUMAR ESSA FUNÇÃO.
struct desc_acervo *inserePilha(struct desc_acervo *pilha, struct nodo *musica); // ARRUMAR ESSA FUNÇÃO.
void imprimeMusicas(struct nodo *musicas); // okay
void playListFila(struct desc_acervo *descritor, struct desc_Fila *fila); // okay
void deQueue(struct desc_Fila *fila); // okay 
void playlistPilha(struct desc_acervo *descritor, struct desc_acervo *pilha);
void popPilha(struct desc_acervo *pilha); 


// execuçao
// playlist
// busca - ok
// impressão
// relatório (opcional)
// sair

//struct nodo *insereDados();
