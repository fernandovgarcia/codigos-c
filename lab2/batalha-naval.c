#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void inicializa_matriz(int *linhas, int *colunas, int **tabuleiro){
	for(int i=0; i < *linhas; i++){
		for(int j=0; j < *colunas; j++){
			tabuleiro[i][j] = malloc(sizeof(int));
		}
	}
}

void main(){
	int i, j, linhas, colunas;	

	printf("Escreva o numero de linhas e colunas:\n");
	scanf("%d", &linhas);
	scanf("%d", &colunas);

	int *p, **tabuleiro[linhas][colunas];
	*p = tabuleiro[0][0];
	// inicializa_matriz(&linhas, &colunas, tabuleiro[linhas][colunas]);

	for(i=0; i < 10; i++){
		for(j=0; j < 10; j++){
			printf("[%d] ", *tabuleiro[i][j]);
			if (j == 9){
				printf("\n");
			}
		}
	}

}