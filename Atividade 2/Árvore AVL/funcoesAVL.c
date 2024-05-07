#include <stdio.h>
#include <stdlib.h>
#include "funcoesAVL.h"

Nodo *criaNodo(int chave){
	
	Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
	nodo->chave = chave;
	nodo->altDireita = 0;
	nodo->altEsquerda = 0;
	nodo->direita = NULL;
	nodo->esquerda = NULL;
	return nodo;
	
}

Nodo *insere(Nodo *arvore, int chave){
    
    if(!arvore){
        return criaNodo(chave);
    }

    if(chave <= arvore->chave){
        arvore->esquerda = insere(arvore->esquerda, chave);
    }else{
        arvore->direita = insere(arvore->direita, chave);
    }
    
    arvore->altEsquerda = alturaNodo(arvore->esquerda);
    arvore->altDireita = alturaNodo(arvore->direita);
    
    arvore = balanceamento(arvore);

    return arvore;
}


Nodo *balanceamento(Nodo *nodo){
	
	if(nodo == NULL){
		
		return NULL;
		
	}
	else{
		
		int fdX = nodo->altDireita - nodo->altEsquerda;
		
		if(fdX == 2){
			
			int dfY = nodo->direita->altDireita - nodo->direita->altEsquerda;
			
			if(dfY >= 0){
				
				nodo = rotacaoEsquerda(nodo);
				
			}
			else{
				
				nodo->direita = rotacaoDireita(nodo->direita);
				nodo = rotacaoEsquerda(nodo);
				
			}
			
		}
		else if(fdX == -2){
			
			int dfY = nodo->esquerda->altDireita - nodo->esquerda->altEsquerda;
			
			if(dfY <= 0){
				
				nodo = rotacaoDireita(nodo);
				
			}
			else{
				
				nodo->esquerda = rotacaoEsquerda(nodo->esquerda);
				nodo = rotacaoDireita(nodo);
				
			}
			
		}
		
		return nodo;
		
	}
	
}

Nodo *rotacaoEsquerda(Nodo *nodo){
	
	Nodo *aux1, *aux2;
	aux1 = nodo->direita;
	aux2 = aux1->esquerda;
	nodo->direita = aux2;
	aux1->esquerda = nodo;
	
	if(!nodo->direita){
		nodo->altDireita = 0;
	}
	else if(nodo->direita->altEsquerda > nodo->direita->altDireita){
			nodo->altDireita = nodo->direita->altEsquerda + 1;
	}
	else{
			nodo->altDireita = nodo->direita->altDireita + 1;
	}
	
	if(aux1->esquerda->altEsquerda > aux1->esquerda->altDireita){
		aux1->altEsquerda = aux1->esquerda->altEsquerda + 1;
	}
	else{
		aux1->altEsquerda = aux1->esquerda->altDireita + 1;
	}
	
	return aux1;
		
}

Nodo *rotacaoDireita(Nodo *nodo){
	
    Nodo *aux1, *aux2;
    aux1 = nodo->esquerda;
    aux2 = aux1->direita;
    nodo->esquerda = aux2;
    aux1->direita = nodo;

    if (!nodo->esquerda) {
        nodo->altEsquerda = 0;
    }else if (nodo->esquerda->altEsquerda > nodo->esquerda->altDireita){
        nodo->altEsquerda = nodo->esquerda->altEsquerda + 1;
    }else{
        nodo->altEsquerda = nodo->esquerda->altDireita + 1;
    }

    if(aux1->direita->altEsquerda > aux1->direita->altDireita) {
        aux1->altDireita = aux1->direita->altEsquerda + 1;
    }else {
        aux1->altDireita = aux1->direita->altDireita + 1;
    }

    return aux1;
}

void imprimirAVL(Nodo *arvore){
	
	if(!arvore){
		return;
	}
	
	imprimirAVL(arvore->esquerda);
	printf("Chave: %d Fator de Balanceamento: %d\n", arvore->chave, alturaNodo(arvore->direita) - alturaNodo(arvore->esquerda));
	imprimirAVL(arvore->direita);
	
}

int alturaNodo(Nodo *nodo){
	
    if(!nodo){
        return -1;
    }else{
        int alturaEsquerda = alturaNodo(nodo->esquerda);
        int alturaDireita = alturaNodo(nodo->direita);

        return 1 + ((alturaEsquerda > alturaDireita) ? alturaEsquerda : alturaDireita);
    }
}

int buscaAVL(Nodo *arvore, int chave){
	
	if(!arvore){
		return 0;
	}
	
	if(chave == arvore->chave){
		return 1;
	}
	
	if(chave > arvore->chave){
		
		return 1 + buscaAVL(arvore->direita, chave);
		
	} else{
		
		return 1 + buscaAVL(arvore->esquerda, chave);
		
	}
	
}
