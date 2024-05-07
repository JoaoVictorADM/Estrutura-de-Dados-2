#include <stdio.h>
#include <stdlib.h>
#include "FuncoesTEA.h"

ElementoTEA *alocaTEA(int tam){
	
	int i = 0;
	ElementoTEA *TEA = (ElementoTEA *)malloc(sizeof(ElementoTEA)*tam);
	
	for( ; i<tam; i++)
		(TEA+i)->condicao = 'L';
		
	return TEA;
		
}

void inserirTEA(ElementoTEA *TEA, int chave, int tam){
	
	int i = 0, indice;
	
	for( ; i<tam; i++){
		
		indice = funcaoHashDivisao(chave+i, tam);
		
		if((TEA + indice)->condicao != 'O')
			break;
		
	}
	
	(TEA + indice)->chave = chave;
	(TEA + indice)->condicao = 'O';
		
}

int funcaoHashDivisao(int chave, int tam){
	
	return chave%tam;
	
}

int buscaTEA(ElementoTEA *TEA, int chave, int tam){
	
	int i = 0, indice;
	
	for( ; i<tam; i++){
		
		indice = funcaoHashDivisao(chave+i, tam);
		
		if((TEA + indice)->condicao == 'L')
			break;
		
		if((TEA + indice)->chave == chave)
			return indice;
	
	}
	
	return 0;
	
}

void removerTEA(ElementoTEA *TEA, int chave, int tam){
	
	int indice = buscaTEA(TEA, chave, tam);
	
	if(indice)
		(TEA + indice)->condicao = 'R';
		
	
}

ElementoTEA *reestruturacaoTEA(ElementoTEA *TEA, int tam){
	
	int i = tam, indice;
	TEA = (ElementoTEA *)realloc(TEA, sizeof(ElementoTEA)*tam*2);
	
	for( ; i<tam*2; i++)
		(TEA + i)->condicao = 'L';
	
	for(i=0; i<tam; i++){
		
		if((TEA + i)->condicao != 'L'){
			
			char aux = (TEA + i)->condicao;
			(TEA + i)->condicao = 'L';
			
			indice = funcaoHashDivisao((TEA + i)->chave, tam*2);
			
			(TEA + indice)->chave = (TEA + i)->chave;
			(TEA + indice)->condicao = aux;
			
		}
		
	}
	
	return TEA;
	
}

void imprimirTEA(ElementoTEA *TEA, int tam){
	
	int i = 0;
	
	for( ; i<tam; i++){
	
		printf("%d-", i);
		if((TEA + i)->condicao == 'O')
			printf("%d-", (TEA+i)->chave);
		else
			printf("NULL-");
			
		printf("%c\n", (TEA + i)->condicao);
	}
	
}

