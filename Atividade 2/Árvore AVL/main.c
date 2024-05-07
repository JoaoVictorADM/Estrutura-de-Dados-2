/*
	Jo�o Victor Alves de Meira
*/

#include <stdio.h>
#include <stdlib.h>
#include "funcoesAVL.h"

int main(){
	
	Nodo *arvore = NULL;
	
	FILE *arq = fopen("in1.txt", "r"), *arqleitura = fopen("out1.txt", "w");
	
	char op;
	
	int chave, cont=0;
	
	while(fscanf(arq, "%c %d\n", &op, &chave) == 2){
				
		
		if(op == 'i'){
			
			arvore = insere(arvore, chave);
		
			
		} else{
			
			
			
		}
		
		
	}
	
	imprimirAVL(arvore);
	
	return 0;
}
