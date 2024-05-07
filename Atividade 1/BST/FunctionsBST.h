// Defição struct BST
typedef struct BST{
	
	int chave;
	struct BST *pai;
	struct BST *esquerda;
	struct BST *direita;
	
}Tnodo;

// Protótipos das funções
Tnodo *criaNodo(int chave);
void inserirNodo(Tnodo **raiz, Tnodo *novoNodo);
int buscaNodo(Tnodo *raiz, int chave);
void imprimirBST(Tnodo *raiz, FILE *arqEscrita);
void removerNodo(Tnodo **raiz, int chave);
void desalocarBST(Tnodo **raiz);
void gerarDotFile(Tnodo* raiz);
int escreverDot(FILE *file, Tnodo* raiz);
