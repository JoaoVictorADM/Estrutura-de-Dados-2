typedef struct lista{
	
    int chave;
    struct lista *prox; 
    
}Tlista;

Tlista **alocaTabela(int tam);
void inserirTabelaEncadeada(Tlista **tabelaHashEncadeada, Tlista *novoElemento);
Tlista *criaElemento(int chave);
int funcaoHashDivisao(int chave, int tam);
int buscaTabelaEncadeada(Tlista *aux, int chave);
void imprimirTabelaEncadeada(Tlista **tabelaHashEncadeada, int tam);


