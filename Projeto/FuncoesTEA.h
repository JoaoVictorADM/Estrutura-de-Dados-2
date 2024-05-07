typedef struct ElementoHashEnderecamentoAberto{
	
	int chave;
	char condicao;
	
}ElementoTEA;

ElementoTEA *alocaTEA(int tam);
void inserirTEA(ElementoTEA *TEA, int chave, int tam);
int funcaoHashDivisao(int chave, int tam);
void imprimirTEA(ElementoTEA *TEA, int tam);
int buscaTEA(ElementoTEA *TEA, int chave, int tam);
ElementoTEA *reestruturacaoTEA(ElementoTEA *TEA, int tam);
