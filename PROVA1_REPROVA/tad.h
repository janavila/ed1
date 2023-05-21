struct desc_LSE{
int tamanho;
struct nodo *lista;
};


struct nodo{
int chave;
struct nodo *prox;
};

struct desc_LSE *novaLista(void);
struct nodo *criaNodo(void);
struct desc_LSE *insereNodo(struct desc_LSE *descritor, int posicao);
struct desc_LSE *removeNodo(struct desc_LSE *descritor, int posicao);
void *imprimeNodo(struct desc_LSE *descritor);


