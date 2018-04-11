//Aluno: Fernando Vedoin Garcia
#include <stdio.h>
#include <stdlib.h>

int *aloca_vetor(int col){
    int *vet = malloc(col * sizeof(int));

	return vet;
}

void le_vetor(int *vet, int col){
	for(int k=0;k<col;k++){
		printf("informe o valor de vet[%i]: ", k);
		scanf("%d", &vet[k]);
	}
}

void imprime_vetor(int *vet, int col){
	for(int k=0;k<col;k++){
		printf("%i\t", vet[k]);
	}
    printf("\n");
}

int **aloca_matriz(int lin, int col){
    int **mat = malloc(lin * sizeof(int*));

	for (int i = 0; i < lin; i++){
		mat[i] = malloc(col * sizeof(int));
		for (int j = 0; j < col; j++){
			mat[i][j] = -1;
		}
	}
	return mat;
}

void le_matriz(int **mat, int lin, int col){
	for(int j=0;j<lin;j++){
	    mat[j]=malloc(col*sizeof(int));
		for(int k=0;k<col;k++){
			printf("informe o valor de mat[%i][%i]: ", j,k);
			scanf("%d", &mat[j][k]);
		}
	}
}

void imprime_matriz(int **mat, int lin, int col){
	for(int j=0;j<lin;j++){
		for(int k=0;k<col;k++){
			printf("%i\t", mat[j][k]);
		}
	    printf("\n");
	}
    printf("\n");
}

int ***aloca_cubo(int prof, int lin, int col){
    int ***mat=malloc(prof*sizeof(int **));
	for(int i=0;i<prof;i++){
		mat[i]=malloc(lin*sizeof(int *));
		for(int j=0;j<lin;j++){
		    mat[i][j]=malloc(col*sizeof(int));
		}
	}
	return mat;
}

void le_cubo(int ***cubo, int prof, int lin, int col){
	for(int i=0;i<prof;i++){
		cubo[i]=malloc(lin*sizeof(int *));
		for(int j=0;j<lin;j++){
		    cubo[i][j]=malloc(col*sizeof(int));
			for(int k=0;k<col;k++){
				printf("informe o valor de mat[%i][%i][%i]: ", i,j,k);
				scanf("%d", &cubo[i][j][k]);
			}
		}
	}
}

void imprime_cubo(int ***cubo, int prof, int lin, int col){
	for(int i=0;i<prof;i++){
		for(int j=0;j<lin;j++){
			for(int k=0;k<col;k++){
				printf("%i\t", cubo[i][j][k]);
			}
		    printf("\n");
		}
	    printf("\n");
	}
    printf("\n");
}

void *cria_estrutura(int prof, int lin, int col){
	if(prof != 0){
		int ***cubo = aloca_cubo(prof, lin, col);
		return cubo;
	}
	if(lin != 0 && prof == 0){
		int **mat = aloca_matriz(lin, col);
		return mat;
	}
	if(lin == 0 && prof == 0){
		int *vet = aloca_vetor(col);
		return vet;
	}
}

void *le_estrutura(void *estr, int prof, int lin, int col){
	if(prof != 0){
		le_cubo(estr, prof, lin, col);
	}
	if(lin != 0 && prof == 0){
		le_matriz(estr, lin, col);
	}
	if(lin == 0 && prof == 0){
		le_vetor(estr, col);
	}
}

void imprime_estrutura(void *estr, int prof, int lin, int col){
	if(prof != 0){
		imprime_cubo(estr, prof, lin, col);
	}
	if(lin != 0 && prof == 0){
		imprime_matriz(estr, lin, col);
	}
	if(lin == 0 && prof == 0){
		imprime_vetor(estr, col);
	}
}

void main(){
    int l, c, p;

	printf("informe prof: ");
	scanf("%d", &p);
	printf("informe lin: ");
	scanf("%d", &l);
	printf("informe col: ");
	scanf("%d", &c);		
		
	while(p < 0 || l < 0 || c < 0){
		printf("Numero de dimensoes invalido\n");
		printf("informe prof: ");
		scanf("%d", &p);
		printf("informe lin: ");
		scanf("%d", &l);
		printf("informe col: ");
		scanf("%d", &c);	
	}

	void *estrutura = cria_estrutura(p, l, c);
	le_estrutura(estrutura, p, l, c);
	imprime_estrutura(estrutura, p, l, c);
}