enum curso{ computacao,matematica,producao,quimica,alimentos,fisica,energias,letras,musica };

struct discente{
	char nome[50];
	int matricula;
	float media_geral;
	enum curso curso_aluno;	
};

struct nodo{
	struct nodo *ant;
	struct discente *aluno;
	struct nodo *prox;
};

struct desc_lista_duplamente_encadeada{
	int tamanho;
	struct nodo *lista;
};

struct nodo* criaNodo(struct discente *novoAluno);
struct desc_lista_duplamente_encadeada * criaDescritor(void);
int tamanho(struct desc_lista_duplamente_encadeada *minhaLista);
void libera(struct desc_lista_duplamente_encadeada *minhaLista);
void imprime(struct desc_lista_duplamente_encadeada *minhaLista);
void imprimePosicao(struct desc_lista_duplamente_encadeada *minhaLista);
//implementação dos alunos
struct discente* criaAluno(char* nome, int matricula, float media_geral, enum curso curso_aluno);
struct desc_lista_duplamente_encadeada * removeLista(struct desc_lista_duplamente_encadeada *minhaLista, int posicao);
struct desc_lista_duplamente_encadeada * insere(struct desc_lista_duplamente_encadeada *minhaLista, struct nodo *novo_elemento, int posicao);
struct nodo * get(struct desc_lista_duplamente_encadeada *minhaLista, int posicao);
//funcao encontra maior media geral recursivamente
float max(struct desc_lista_duplamente_encadeada *minhaLista, int posicao);
void *imprimeCurso(struct desc_lista_duplamente_encadeada *minhaLista, int curso);
