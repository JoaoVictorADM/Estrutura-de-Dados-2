#include <stdio.h>
#include <stdlib.h>
#include "FunctionsBST.h"

//Função para criar novo nodo
Tnodo *criaNodo(int chave){
	
	Tnodo *novoNodo = (Tnodo *)malloc(sizeof(Tnodo));
	
	if(!novoNodo){
		return NULL;
	}
	
	novoNodo->chave = chave;
	novoNodo->pai = NULL;
	novoNodo->direita = NULL;
	novoNodo->esquerda = NULL;
	
	return novoNodo;
	
}

//Função para inserir novo nodo
void inserirNodo(Tnodo **raiz, Tnodo *novoNodo){
	
	if(!novoNodo){
		return;
	}
	
	if(!*raiz){
		
		*raiz = novoNodo;
		return;
		
	}
	
	novoNodo->pai = *raiz;
	novoNodo->chave > (*raiz)->chave ? 	inserirNodo(&(*raiz)->direita, novoNodo) : inserirNodo(&(*raiz)->esquerda, novoNodo);
		
}

//Função para buscar nodo pela chave
int buscaNodo(Tnodo *raiz, int chave){
	
	if(!raiz){
		return 1;
	}
	
	return chave == raiz->chave ? 0 : (chave > raiz->chave ? buscaNodo(raiz->direita, chave) : buscaNodo(raiz->esquerda, chave));
	
}

//Função para imprimir a bst em ordem
void imprimirBST(Tnodo *raiz, FILE *arqEscrita){
	
	if(!raiz){
		return;
	}
	
	imprimirBST(raiz->esquerda, arqEscrita);
	fprintf(arqEscrita, "%d\n", raiz->chave);
	imprimirBST(raiz->direita, arqEscrita);
	
}

//Função para remover nodo pela chave
void removerNodo(Tnodo **raiz, int chave){
	
	if(!*raiz){
		return;
	}
	
	
	if(chave == (*raiz)->chave){
		
		Tnodo *nodoR = *raiz;
		
		// Caso 1: Nó sem filhos
		if(!nodoR->direita && !nodoR->esquerda){
			
			free(nodoR);
			*raiz = NULL;		
			return;
				
		}
		
		 // Caso 3: Nó com dois filhos
		if (nodoR->direita && nodoR->esquerda) {
			
		    Tnodo *antecessor = nodoR->esquerda;
		
		    while (antecessor->direita) {
		        antecessor = antecessor->direita;
		    }
		    
		    (*raiz)->chave = antecessor->chave;
		    removerNodo(&(*raiz)->esquerda, antecessor->chave);
		    return;
		    
		}
		
		// Caso 2: Nó com um filho
		*raiz = (*raiz)->direita ? (*raiz)->direita : (*raiz)->esquerda;
		(*raiz)->pai = nodoR->pai;
		free(nodoR);
		
	} else{

		chave > (*raiz)->chave ? removerNodo(&(*raiz)->direita, chave) : removerNodo(&(*raiz)->esquerda, chave);
		
	}
	
}

//Função para desalocar árvore inteira
void desalocarBST(Tnodo **raiz){
	
	if(!*raiz){
		return;
	}
	
	desalocarBST(&(*raiz)->esquerda);
	desalocarBST(&(*raiz)->direita);
	free(*raiz);
	*raiz = NULL;
}



int id = 0;     // Identificador único do nodo. Mesmo que dois nodos tenham a mesma chave, seus identificadores são exclusivos.

/*
 * FUNÇÃO PRIVADA
 * 
 * Função para escrever o arquivo.dot a partir da topologia da árvore.
 * Parâmetro: file - ponteiro para o arquivo em disco usado para armazenar a árvore.
 * Parâmetro: raiz - ponteiro para o nodo que representa a raiz da árvore.
 * Retorno: identificador do filho da esquerda ou da direita.
*/

int escreverDot(FILE *file, Tnodo* raiz) {    
    if (raiz == NULL){
        return id;
    }
    
    int nodoId = ++id;
    fprintf(file, "\t%d [label=\"%d\"];\n",nodoId, raiz->chave);

    int esqId = escreverDot(file, raiz->esquerda);
    int dirId = escreverDot(file, raiz->direita);
    
    if (nodoId != esqId){
        fprintf(file, "\t%d -> %d;\n", nodoId, esqId);
    }
    
    if (nodoId != dirId){
        fprintf(file, "\t%d -> %d;\n", nodoId, dirId);
    }

    return nodoId;
}

void gerarDotFile(Tnodo* raiz){
    FILE *file = fopen("arvore.dot", "w");
    
    if (file != NULL){
        fprintf(file, "digraph arvoreBB{\n");
        escreverDot(file, raiz);
        fprintf(file, "}\n");
        fclose(file);
    }
    else{   
        printf("erro ao criar o arquivo dot\n");
    }
}



