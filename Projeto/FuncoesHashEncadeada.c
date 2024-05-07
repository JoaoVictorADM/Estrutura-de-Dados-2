#include <stdio.h>
#include <stdlib.h>
#include "FuncoesHashEncadeada.h"

Tlista **alocaTabela(int tam){
	
	return (Tlista **)calloc(tam, sizeof(Tlista *));
	
} 

Tlista *criaElemento(int chave){
	
	Tlista *novoElemento = (Tlista *)malloc(sizeof(Tlista));
	novoElemento->chave = chave;
	2,
	novoElemento->prox = NULL;
	
	return novoElemento;
	
}

int funcaoHashDivisao(int chave, int tam){
	
	return chave%tam;
	
}

void inserirTabelaEncadeada(Tlista **tabelaHashEncadeada, Tlista *novoElemento){
	
	novoElemento->prox = *tabelaHashEncadeada;
	*tabelaHashEncadeada = novoElemento;
	
}

int buscaTabelaEncadeada(Tlista *aux, int chave){
	
	int cont = 0;
	
	while(aux){
		
		cont++;
		
		if(aux->chave == chave){
			
			return cont;
			
		}
		
		aux = aux->prox;
		
	}
	
	return cont;
	
}

void imprimirTabelaEncadeada(Tlista **tabelaHashEncadeada, int tam){
	
	int i;
	Tlista *aux = NULL;
	
	for(i=0; i<tam; i++){
		
		if(!*(tabelaHashEncadeada+i)){
			printf("Indice %d nao utilizado\n\n", i);
		} else{
			printf("%d: ", i);
		}
		
		aux = *(tabelaHashEncadeada+i);
		
		while(aux){
		
			printf("%d ", aux->chave);
			aux = aux->prox;
			
		}
		
		printf("\n\n");
		
	}
	
}

void apagaTE(Tlista **tabelaHashEncadeada, int tam){
	
	int i;
	
	for(i=0; i<tam; i++){
		
		desalocaLista(*(tabelaHashEncadeada+i));
		*(tabelaHashEncadeada + i)= NULL;
		
	}
	
	
}

void desalocaLista(Tlista *aux){
	
	if(!aux){
		return;
	}
	
	desalocaLista(aux->prox);
	free(aux);
	
}


