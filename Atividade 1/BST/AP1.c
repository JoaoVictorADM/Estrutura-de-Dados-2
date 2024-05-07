#include <stdio.h>
#include <stdlib.h>
#include "FunctionsBST.h"

int main(void) {

	Tnodo *raiz = NULL; 
	FILE *arqLeitura = fopen("in.txt", "r"), *arqEscrita = fopen("out.txt", "w");
	
	if(!arqLeitura){
		
		printf("Erro ao abrir arquivo de leitura \"in.txt\"\n");
		return 0;
	
	}
	
	if(!arqEscrita){

        printf("Erro ao abrir arquivo de escrita \"out.txt\"\n");
        return 0;

    }
    
    char operacao;
    int chave;

    while(fscanf(arqLeitura, "%c %d\n", &operacao, &chave) != EOF){
		// Verifica se a opera��o � 'i' (inser��o) ou 'r' (remo��o) e age de acordo.
		operacao == 'i' ? inserirNodo(&raiz, criaNodo(chave)) : removerNodo(&raiz, chave);

    }
    
    raiz ? imprimirBST(raiz, arqEscrita) : printf("Arvore vazia\n"); // Verifica se tem nodos para serem printandos ou n�o
    
    gerarDotFile(raiz);
    
    desalocarBST(&raiz); // Desaloca a �rvore inteira depois de todas as opera��es
    
    fclose(arqLeitura);
    fclose(arqEscrita);
    
	return 0;
}


