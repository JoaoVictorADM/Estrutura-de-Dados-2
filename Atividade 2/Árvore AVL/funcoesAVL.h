typedef struct No{
	
	int chave;
	int altDireita;
	int altEsquerda;
	struct No *direita;
	struct No *esquerda;
	
}Nodo;

Nodo *criaNodo(int chave);
Nodo *insere(Nodo *arvore, int chave);
Nodo *balanceamento(Nodo *nodo);
Nodo *rotacaoEsquerda(Nodo *nodo);
Nodo *rotacaoDireita(Nodo *nodo);
void imprimirAVL(Nodo *arvore);
int alturaNodo(Nodo *nodo);
int buscaAVL(Nodo *arvore, int chave);
