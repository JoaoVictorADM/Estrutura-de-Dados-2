/*

	João Victor Alves de Meira
	Thomas Yoshihiro Kofuji

*/
/*
	
	TE - Tabela Encadeada
	TEA - Tabela Endereçamento Aberto

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FuncoesTEA.h"
#include "FuncoesHashEncadeada.h"
#include "funcoesAVL.h"

int main(void){
	
	int i, j, k, chave, tamTEA = 100, tamTE = 100, numElementos = 0, numBuscas, somaNumComp, numElementosInseridos;
	char op, nomeArquivo[100];
	clock_t inicio, fim;
	double tempoBusca, tempoInsercao;
	
	Nodo *AVL = NULL;
	ElementoTEA *TEA = alocaTEA(tamTEA);
	Tlista **TE = (Tlista **)calloc(tamTE, sizeof(Tlista *));
	
	FILE *arqLeitura = NULL, *arqEscrita = fopen("relatorio.txt", "w");
	
	for(i=0; i<3; i++){ // estrutura
		
		for(j=0; j<3; j++){ //arquivo
			
			tempoBusca = 0;
			tempoInsercao = 0;
			numBuscas = 0;
			somaNumComp = 0;
			numElementosInseridos = 0;
			
			sprintf(nomeArquivo, "in%d.txt", j+1);
			arqLeitura = fopen(nomeArquivo, "r");
			
			while(fscanf(arqLeitura, "%c %d\n", &op, &chave) == 2){
				
				if(op == 'i'){
					
					inicio = clock();
					
					switch(i){
						
						case 0:
							
							AVL = insere(AVL, chave);
							break;
						
						case 1:
							
							inserirTabelaEncadeada((TE + funcaoHashDivisao(chave, tamTE)), criaElemento(chave));
							break;
							
						case 2:
										
							inserirTEA(TEA, chave, tamTEA);
							numElementosInseridos++;
							
							if((float)numElementosInseridos/tamTEA > 0.7){
								TEA = reestruturacaoTEA(TEA, tamTEA);
								tamTEA *= 2;
							}
								
							break;
						
					} 
					
					fim = clock();
					
					tempoInsercao += fim - inicio;
							
				} else{
					
					numBuscas++;
					
					inicio = clock();
					
					switch(i){
						
						case 0: 
							
							somaNumComp += buscaAVL(AVL, chave);
							break;
							
						case 1:
							
							somaNumComp += buscaTabelaEncadeada(*(TE + funcaoHashDivisao(chave, tamTE)), chave);
							break;
							
						case 2:
							somaNumComp += buscaTEA(TEA, chave, tamTEA);
							break;
						
					}	
					
					fim = clock();

					tempoBusca += fim - inicio;
					
				}
				
			}
			
			fclose(arqLeitura);
			
			switch(i){
						
				case 0: 
					
					fprintf(arqEscrita, "Árvore AVL - ");
					desalocarAVL(AVL);
					AVL = NULL;
					break;
					
				case 1:
					
					fprintf(arqEscrita, "Tabela Hash Encadeada - ");
					imprimirTabelaEncadeada(TE, tamTE);
					apagaTE(TE, tamTE);
					break;
					
				case 2:
					
					fprintf(arqEscrita, "Tabela Hash Endereçamento Aberto - ");
					imprimirTEA(TEA, tamTEA);
					free(TEA);
					tamTEA = 100;
					
					if(j != 2)
						TEA = alocaTEA(tamTEA);
						
					break;
				
			}
			
			tempoInsercao = tempoInsercao*1000.0 / CLOCKS_PER_SEC;
			tempoBusca = tempoBusca*1000.0 / CLOCKS_PER_SEC;
			
			fprintf(arqEscrita, "Arquivo %d - Media de comparações: %.4f - Tempo de execução para inserção: %g - Tempo de execução para busca: %g - Tempo de execução total: %g\n", j+1, (float)somaNumComp/numBuscas, tempoInsercao, tempoBusca, tempoInsercao+tempoBusca);
			fclose(arqLeitura);
		}
		
	}
	
	return 0;

}

