#include <stdio.h>
#include <stdlib.h>

#define MAX 100000
#define TAM 10000

int main(void){
	
	int i;
	srand(time(NULL));
	
	FILE *arqLeitura = fopen("in.txt", "w");
	
	if(!arqLeitura){
		printf("Erro ao abrir arquivo");
		return;
	}
	
	for(i=0; i<TAM; i++){
		
		rand()%2 ? fprintf(arqLeitura, "i ") : fprintf(arqLeitura, "b ");	
		fprintf(arqLeitura, "%d\n", rand()%MAX + 10000);
		
	}
	
	fclose(arqLeitura);
	
}
