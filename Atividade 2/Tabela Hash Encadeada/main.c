#include <stdio.h>
#include <stdlib.h>
#include "FuncoesHashEncadeada.h"

void imprimirLista(Tlista *aux);

int main(void){
	
	int chave, i, tam = 100;
	char op;
	
	FILE *arqLeitura = fopen("in1.txt", "r");
	FILE *arqEscrita = fopen("out1HashEncadeada.txt", "w");
	
	Tlista **tabelaHashEncadeada = (Tlista **)calloc(tam, sizeof(Tlista *)); 
	
	while(fscanf(arqLeitura, "%c %d\n", &op, &chave) == 2){
		
		if(op == 'i'){
			
			inserirTabelaEncadeada((tabelaHashEncadeada + funcaoHashDivisao(chave, tam)), criaElemento(chave));
			
		} else{
			fprintf(arqEscrita, "Tabela Hash Encadeada: Elemento buscado %d - indice %d - numero de comparacoes %d\n", chave, funcaoHashDivisao(chave, tam), buscaTabelaEncadeada(*(tabelaHashEncadeada + funcaoHashDivisao(chave, tam)), chave));
		}
		
	}

	imprimirTabelaEncadeada(tabelaHashEncadeada, tam);

	return 0;
	
}


