//Aluno: Fernando Vedoin Garcia
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int n_aleatorio(int limite){
	int n;
	n = ((rand() % limite) + 1);
	return n;
}

void insere_navio_cinco(int **tabuleiro, int linhas, int colunas, int id_navio){
	int a_coluna, a_linha;
	int direcao;
	a_linha = n_aleatorio(linhas)-1;
	a_coluna = n_aleatorio(colunas)-1;
	while((tabuleiro[a_linha][a_coluna] != -1)){
		a_linha = n_aleatorio(linhas)-1;
			a_coluna = n_aleatorio(colunas)-1;
	}

	direcao = n_aleatorio(2);
	
	if (direcao == 1){
		if(a_linha-4 >= 0){
			if(tabuleiro[a_linha-1][a_coluna] == -1 && tabuleiro[a_linha-2][a_coluna] == -1 && tabuleiro[a_linha-3][a_coluna] == -1 && tabuleiro[a_linha-4][a_coluna] == -1){
				tabuleiro[a_linha][a_coluna] = id_navio;
				tabuleiro[a_linha-1][a_coluna] = id_navio;
				tabuleiro[a_linha-2][a_coluna] = id_navio;
				tabuleiro[a_linha-3][a_coluna] = id_navio;
				tabuleiro[a_linha-4][a_coluna] = id_navio;
			}else{
				insere_navio_cinco(tabuleiro, linhas, colunas, id_navio);
			}
		}else{
			insere_navio_cinco(tabuleiro, linhas, colunas, id_navio);
		}
	}else if(direcao == 2){
		if(a_coluna-4 >= 0){
			if (tabuleiro[a_linha][a_coluna-1] == -1 && tabuleiro[a_linha][a_coluna-2] == -1 && tabuleiro[a_linha][a_coluna-3] == -1 && tabuleiro[a_linha][a_coluna-4] == -1){
				tabuleiro[a_linha][a_coluna] = id_navio;
				tabuleiro[a_linha][a_coluna-1] = id_navio;
				tabuleiro[a_linha][a_coluna-2] = id_navio;
				tabuleiro[a_linha][a_coluna-3] = id_navio;
				tabuleiro[a_linha][a_coluna-4] = id_navio;
			}else{
				insere_navio_cinco(tabuleiro, linhas, colunas, id_navio);
			}
		}else{
			insere_navio_cinco(tabuleiro, linhas, colunas, id_navio);
		}
	}
}

void insere_navio_quatro(int **tabuleiro, int linhas, int colunas, int id_navio){
	int a_coluna, a_linha;
	int direcao;
	a_linha = n_aleatorio(linhas)-1;
	a_coluna = n_aleatorio(colunas)-1;
	while((tabuleiro[a_linha][a_coluna] != -1)){
		a_linha = n_aleatorio(linhas)-1;
		a_coluna = n_aleatorio(colunas)-1;
	}

	direcao = n_aleatorio(2);
	
	if (direcao == 1){
		if(a_linha-3 >= 0){
			if(tabuleiro[a_linha-1][a_coluna] == -1 && tabuleiro[a_linha-2][a_coluna] == -1 && tabuleiro[a_linha-3][a_coluna] == -1){
				tabuleiro[a_linha][a_coluna] = id_navio;
				tabuleiro[a_linha-1][a_coluna] = id_navio;
				tabuleiro[a_linha-2][a_coluna] = id_navio;
				tabuleiro[a_linha-3][a_coluna] = id_navio;
			}else{
				insere_navio_quatro(tabuleiro, linhas, colunas, id_navio);
			}
		}else{
			insere_navio_quatro(tabuleiro, linhas, colunas, id_navio);
		}
	}else if(direcao == 2){
		if(a_coluna-3 >= 0){
			if (tabuleiro[a_linha][a_coluna-1] == -1 && tabuleiro[a_linha][a_coluna-2] == -1 && tabuleiro[a_linha][a_coluna-3] == -1){
				tabuleiro[a_linha][a_coluna] = id_navio;
				tabuleiro[a_linha][a_coluna-1] = id_navio;
				tabuleiro[a_linha][a_coluna-2] = id_navio;
				tabuleiro[a_linha][a_coluna-3] = id_navio;
			}else{
				insere_navio_quatro(tabuleiro, linhas, colunas, id_navio);
			}
		}else{
			insere_navio_quatro(tabuleiro, linhas, colunas, id_navio);
		}
	}
}

void insere_navio_tres(int **tabuleiro, int linhas, int colunas, int id_navio){
	int a_coluna, a_linha;
	int direcao;
	a_linha = n_aleatorio(linhas)-1;
	a_coluna = n_aleatorio(colunas)-1;
	while((tabuleiro[a_linha][a_coluna] != -1)){
		a_linha = n_aleatorio(linhas)-1;
		a_coluna = n_aleatorio(colunas)-1;
	}

	direcao = n_aleatorio(2);
	
	if (direcao == 1){
		if(a_linha-2 >= 0){
			if(tabuleiro[a_linha-1][a_coluna] == -1 && tabuleiro[a_linha-2][a_coluna] == -1){
				tabuleiro[a_linha][a_coluna] = id_navio;
				tabuleiro[a_linha-1][a_coluna] = id_navio;
				tabuleiro[a_linha-2][a_coluna] = id_navio;
			}else{
				insere_navio_tres(tabuleiro, linhas, colunas, id_navio);
			}
		}else{
			insere_navio_tres(tabuleiro, linhas, colunas, id_navio);
		}
	}else if(direcao == 2){
		if(a_coluna-2 >= 0){
			if (tabuleiro[a_linha][a_coluna-1] == -1 && tabuleiro[a_linha][a_coluna-2] == -1){
				tabuleiro[a_linha][a_coluna] = id_navio;
				tabuleiro[a_linha][a_coluna-1] = id_navio;
				tabuleiro[a_linha][a_coluna-2] = id_navio;
			}else{
				insere_navio_tres(tabuleiro, linhas, colunas, id_navio);
			}
		}else{
			insere_navio_tres(tabuleiro, linhas, colunas, id_navio);
		}
	}
}

void insere_navio_dois(int **tabuleiro, int linhas, int colunas, int id_navio){
	int a_coluna, a_linha;
	int direcao;
	a_linha = n_aleatorio(linhas)-1;
	a_coluna = n_aleatorio(colunas)-1;
	while((tabuleiro[a_linha][a_coluna] != -1)){
		a_linha = n_aleatorio(linhas)-1;
		a_coluna = n_aleatorio(colunas)-1;
	}

	direcao = n_aleatorio(2);
	
	if (direcao == 1){
		if(a_linha-1 >= 0){
			if(tabuleiro[a_linha-1][a_coluna] == -1){
				tabuleiro[a_linha][a_coluna] = id_navio;
				tabuleiro[a_linha-1][a_coluna] = id_navio;
			}else{
				insere_navio_dois(tabuleiro, linhas, colunas, id_navio);
			}
		}else{
			insere_navio_dois(tabuleiro, linhas, colunas, id_navio);
		}
	}else if(direcao == 2){
		if(a_coluna-1 >= 0){
			if (tabuleiro[a_linha][a_coluna-1] == -1){
				tabuleiro[a_linha][a_coluna] = id_navio;
				tabuleiro[a_linha][a_coluna-1] = id_navio;
			}else{
				insere_navio_dois(tabuleiro, linhas, colunas, id_navio);
			}
		}else{
			insere_navio_dois(tabuleiro, linhas, colunas, id_navio);
		}
	}
}

void insere_navio(int **tabuleiro, int n_navios[], int linhas, int colunas){
	int id_navio = 10;
	for (int i = 0; i < n_navios[3]; i++){
		insere_navio_cinco(tabuleiro,linhas,colunas, id_navio);
		id_navio++;
	}
	for (int i = 0; i < n_navios[2]; i++){
		insere_navio_quatro(tabuleiro,linhas,colunas, id_navio);
		id_navio++;
	}
	for (int i = 0; i < n_navios[1]; i++){
		insere_navio_tres(tabuleiro,linhas,colunas, id_navio);
		id_navio++;
	}
	for (int i = 0; i < n_navios[0]; i++){
		insere_navio_dois(tabuleiro,linhas,colunas, id_navio);
		id_navio++;
	}
}

int** alocar_matriz(int linhas,int colunas){

	int **m = (int**)malloc(linhas * sizeof(int*));

	for (int i = 0; i < linhas; i++){
		m[i] = (int*) malloc(colunas * sizeof(int));
		for (int j = 0; j < colunas; j++){
			m[i][j] = -1;
		}
	}
	return m;
}

void imprime_matriz(int **tabuleiro, int linhas, int colunas){
	for (int k = 0; k < colunas; k++){
		if(k+1 >= 10){
			printf("%d  ", k+1);
		}else{
			printf(" %d  ", k+1);
		}
		if(k == colunas-1){
			printf("\n");
		}
	}
	for(int i=0; i < linhas; i++){
		for(int j=0; j < colunas; j++){
			if(tabuleiro[i][j] == -1){
				printf("[~] ");
			}else if(tabuleiro[i][j] >= 10){
				printf("[N] ");
			}else if(tabuleiro[i][j] == 2){
				printf("[X] ");
			}
			else if(tabuleiro[i][j] == 3){
				printf("[*] ");
			}
			if (j == colunas-1){
				printf(" %d\n", i+1);
			}
		}
	}
}

void imprime_matriz_adversario(int **tabuleiro, int linhas, int colunas){
	for (int k = 0; k < colunas; k++){
		if(k+1 >= 10){
			printf("%d  ", k+1);
		}else{
			printf(" %d  ", k+1);
		}
		if(k == colunas-1){
			printf("\n");
		}
	}
	for(int i=0; i < linhas; i++){
		for(int j=0; j < colunas; j++){
			if(tabuleiro[i][j] == 2){
				printf("[X] ");
			}else if(tabuleiro[i][j] == 3){
				printf("[*] ");
			}else{
				printf("[?] ");
			}
			if (j == colunas-1){
				printf(" %d\n", i+1);
			}
		}
	}
}

int verifica_fim(int **tabuleiro, int linhas, int colunas){
	int cont = 0;
	for(int i=0; i < linhas; i++){
		for(int j=0; j < colunas; j++){
			if(tabuleiro[i][j] >= 10 ){
				cont++;
			}
		}
	}
	return cont;
}

int verifica_afundou(int **tabuleiro, int val, int linhas, int colunas){
	int cont = 0;
	for(int i=0; i < linhas; i++){
		for(int j=0; j < colunas; j++){
			if(tabuleiro[i][j] == val){
				cont++;
			}
		}
	}
	return cont;
}

int  verifica_redor(int **tabuleiro, int linhas, int colunas, int linha_acertada, int coluna_acertada, int *valor_navio, int *linha_nova, int *coluna_nova, int *direcao, int vetor_jogadas[]){
	int testa_lados = n_aleatorio(4);
	if(vetor_jogadas[0] == 1 && vetor_jogadas[1] == 1 && vetor_jogadas[2] == 1 && vetor_jogadas[3] == 1){
		vetor_jogadas[0] = 0;
		vetor_jogadas[1] = 0;
		vetor_jogadas[2] = 0;
		vetor_jogadas[3] = 0;
		return 90;
	}
	if(testa_lados == 1 && linha_acertada+1 < linhas){
		printf("%d\n", linha_acertada+1);
		if(tabuleiro[linha_acertada+1][coluna_acertada] != 3 && tabuleiro[linha_acertada+1][coluna_acertada] != 2){
			if(tabuleiro[linha_acertada+1][coluna_acertada] >= 10){
				printf("O computador acertou\n");
				*valor_navio = tabuleiro[linha_acertada+1][coluna_acertada];
				*linha_nova = linha_acertada+1;
				*coluna_nova = coluna_acertada;
				*direcao = 1;
				tabuleiro[linha_acertada+1][coluna_acertada] = 3;
				vetor_jogadas[0] = 0;
				vetor_jogadas[1] = 0;
				vetor_jogadas[2] = 0;
				vetor_jogadas[3] = 0;
				return 1;
			}else{
				printf("O computador errou\n");
				tabuleiro[linha_acertada+1][coluna_acertada] = 2;
				vetor_jogadas[0] = 0;
				vetor_jogadas[1] = 0;
				vetor_jogadas[2] = 0;
				vetor_jogadas[3] = 0;
				return 0;
			}
		}else{
			vetor_jogadas[0] = 1;
			verifica_redor(tabuleiro, linhas, colunas, linha_acertada, coluna_acertada, valor_navio, linha_nova, coluna_nova, direcao, vetor_jogadas);
		}
	}else if(testa_lados == 2 && linha_acertada-1 >= 0){
		printf("%d\n", linha_acertada-1);
		if(tabuleiro[linha_acertada-1][coluna_acertada] != 3 && tabuleiro[linha_acertada-1][coluna_acertada] != 2){
			if(tabuleiro[linha_acertada-1][coluna_acertada] >= 10){
				printf("O computador acertou\n");
				*valor_navio = tabuleiro[linha_acertada-1][coluna_acertada];
				*linha_nova = linha_acertada-1;
				*coluna_nova = coluna_acertada;
				*direcao = 1;
				tabuleiro[linha_acertada-1][coluna_acertada] = 3;
				vetor_jogadas[0] = 0;
				vetor_jogadas[1] = 0;
				vetor_jogadas[2] = 0;
				vetor_jogadas[3] = 0;
				return 1;
			}else{
				printf("O computador errou\n");
				tabuleiro[linha_acertada-1][coluna_acertada] = 2;
				vetor_jogadas[0] = 0;
				vetor_jogadas[1] = 0;
				vetor_jogadas[2] = 0;
				vetor_jogadas[3] = 0;
				return 0;
			}
		}else{
			vetor_jogadas[1] = 1;
			verifica_redor(tabuleiro, linhas, colunas, linha_acertada, coluna_acertada, valor_navio, linha_nova, coluna_nova, direcao, vetor_jogadas);
		}
	}else if(testa_lados == 3 && coluna_acertada+1 < colunas){
		printf("%d\n", coluna_acertada+1);
		if(tabuleiro[linha_acertada][coluna_acertada+1] != 3 && tabuleiro[linha_acertada][coluna_acertada+1] != 2){
			if(tabuleiro[linha_acertada][coluna_acertada+1] >= 10){
				printf("O computador acertou\n");
				*valor_navio = tabuleiro[linha_acertada][coluna_acertada+1];
				*linha_nova = linha_acertada;
				*coluna_nova = coluna_acertada+1;
				*direcao = 2;
				tabuleiro[linha_acertada][coluna_acertada+1] = 3;
				vetor_jogadas[0] = 0;
				vetor_jogadas[1] = 0;
				vetor_jogadas[2] = 0;
				vetor_jogadas[3] = 0;
				return 2;
			}else{
				printf("O computador errou\n");
				tabuleiro[linha_acertada][coluna_acertada+1] = 2;
				vetor_jogadas[0] = 0;
				vetor_jogadas[1] = 0;
				vetor_jogadas[2] = 0;
				vetor_jogadas[3] = 0;
				return 0;
			}
		}else{
			vetor_jogadas[2] = 1;
			verifica_redor(tabuleiro, linhas, colunas, linha_acertada, coluna_acertada, valor_navio, linha_nova, coluna_nova, direcao, vetor_jogadas);
		}
	}else if(testa_lados == 4 && coluna_acertada-1 >= 0){
		printf("%d\n", coluna_acertada-1);
		if(tabuleiro[linha_acertada][coluna_acertada-1] != 3 && tabuleiro[linha_acertada][coluna_acertada-1] != 2){
			if(tabuleiro[linha_acertada][coluna_acertada-1] >= 10){
				printf("O computador acertou\n");
				*valor_navio = tabuleiro[linha_acertada][coluna_acertada-1];
				*linha_nova = linha_acertada;
				*coluna_nova = coluna_acertada-1;
				*direcao = 2;
				tabuleiro[linha_acertada][coluna_acertada-1] = 3;
				vetor_jogadas[0] = 0;
				vetor_jogadas[1] = 0;
				vetor_jogadas[2] = 0;
				vetor_jogadas[3] = 0;
				return 2;
			}else{
				printf("O computador errou\n");
				tabuleiro[linha_acertada][coluna_acertada-1] = 2;
				vetor_jogadas[0] = 0;
				vetor_jogadas[1] = 0;
				vetor_jogadas[2] = 0;
				vetor_jogadas[3] = 0;
				return 0;
			}
		}else{
			vetor_jogadas[3] = 1;
			verifica_redor(tabuleiro, linhas, colunas, linha_acertada, coluna_acertada, valor_navio, linha_nova, coluna_nova, direcao, vetor_jogadas);
		}
	}else{
		return 90;
	}
}

int joga_vertical(int **tabuleiro, int linhas, int colunas, int linha_acertada, int coluna_acertada, int *valor_navio, int *linha_nova, int *coluna_nova, int origem, int testa_lados, int vetor_jogadas[], int *direcao){
	if(testa_lados == 0){
		testa_lados = n_aleatorio(2);
	}
	int navio_antigo = *valor_navio;
	if(testa_lados == 1 && linha_acertada+1 < linhas){
		if(tabuleiro[linha_acertada+1][coluna_acertada] != 3 && tabuleiro[linha_acertada+1][coluna_acertada] != 2){
			if(tabuleiro[linha_acertada+1][coluna_acertada] >= 10){
				printf("O computador acertou\n");
				*valor_navio = tabuleiro[linha_acertada+1][coluna_acertada];
				*linha_nova = linha_acertada+1;
				*coluna_nova = coluna_acertada;
				tabuleiro[linha_acertada+1][coluna_acertada] = 3;
				if(navio_antigo == *valor_navio){
					return 1;
				}else{
					return 4;
				}
			}else{
				printf("O computador errou\n");
				tabuleiro[linha_acertada+1][coluna_acertada] = 2;
				return 0;
			}
		}else{
			if(origem == 1){
				joga_vertical(tabuleiro, linhas, colunas, linha_acertada, coluna_acertada, valor_navio, linha_nova, coluna_nova, 2, 2, vetor_jogadas, direcao);
			}else{
				return 9;
			}
		}
	}else if(testa_lados == 2 && linha_acertada-1 >= 0){
		if(tabuleiro[linha_acertada-1][coluna_acertada] != 3 && tabuleiro[linha_acertada-1][coluna_acertada] != 2){
			if(tabuleiro[linha_acertada-1][coluna_acertada] >= 10){
				printf("O computador acertou\n");
				*valor_navio = tabuleiro[linha_acertada-1][coluna_acertada];
				*linha_nova = linha_acertada-1;
				*coluna_nova = coluna_acertada;
				tabuleiro[linha_acertada-1][coluna_acertada] = 3;
				if(navio_antigo == *valor_navio){
					return 1;
				}else{
					return 4;
				}
			}else{
				printf("O computador errou\n");
				tabuleiro[linha_acertada-1][coluna_acertada] = 2;
				return 0;
			}
		}else{
			if(origem == 1){
				joga_vertical(tabuleiro, linhas, colunas, linha_acertada, coluna_acertada, valor_navio, linha_nova, coluna_nova, 2, 1, vetor_jogadas, direcao);
			}else{
				return 9;
			}
		}
	}else{
		verifica_redor(tabuleiro, linhas, colunas, linha_acertada, coluna_acertada, valor_navio, linha_nova, coluna_nova, direcao, vetor_jogadas);
	}
}

int joga_horizontal(int **tabuleiro, int linhas, int colunas, int linha_acertada, int coluna_acertada, int *valor_navio, int *linha_nova, int *coluna_nova, int origem, int testa_lados, int vetor_jogadas[], int *direcao){
	if(testa_lados == 0){
		testa_lados = n_aleatorio(2);
	}
	int navio_antigo = *valor_navio;
	if(testa_lados == 1 && coluna_acertada+1 < colunas){
		if(tabuleiro[linha_acertada][coluna_acertada+1] != 3 && tabuleiro[linha_acertada][coluna_acertada+1] != 2){
			if(tabuleiro[linha_acertada][coluna_acertada+1] >= 10){
				printf("O computador acertou\n");
				*valor_navio = tabuleiro[linha_acertada][coluna_acertada+1];
				*linha_nova = linha_acertada;
				*coluna_nova = coluna_acertada+1;
				tabuleiro[linha_acertada][coluna_acertada+1] = 3;
				if(navio_antigo == *valor_navio){
					return 1;
				}else{
					return 4;
				}
			}else{
				printf("O computador errou\n");
				tabuleiro[linha_acertada][coluna_acertada+1] = 2;
				return 0;
			}
		}else{
			if(origem == 1){
				joga_horizontal(tabuleiro, linhas, colunas, linha_acertada, coluna_acertada, valor_navio, linha_nova, coluna_nova, 2, 2, vetor_jogadas, direcao);
			}else{
				return 9;
			}
		}
	}else if(testa_lados == 2 && coluna_acertada-1 >= 0){
		if(tabuleiro[linha_acertada][coluna_acertada-1] != 3 && tabuleiro[linha_acertada][coluna_acertada-1] != 2){
			if(tabuleiro[linha_acertada][coluna_acertada-1] >= 10){
				printf("O computador acertou\n");
				*valor_navio = tabuleiro[linha_acertada][coluna_acertada-1];
				*linha_nova = linha_acertada;
				*coluna_nova = coluna_acertada-1;
				tabuleiro[linha_acertada][coluna_acertada-1] = 3;
				if(navio_antigo == *valor_navio){
					return 1;
				}else{
					return 4;
				}
			}else{
				printf("O computador errou\n");
				tabuleiro[linha_acertada][coluna_acertada-1] = 2;
				return 0;
			}
		}else{
			if(origem == 1){
				joga_horizontal(tabuleiro, linhas, colunas, linha_acertada, coluna_acertada, valor_navio, linha_nova, coluna_nova, 2, 1, vetor_jogadas, direcao);
			}else{
				return 9;
			}
		}
	}else{
		verifica_redor(tabuleiro, linhas, colunas, linha_acertada, coluna_acertada, valor_navio, linha_nova, coluna_nova, direcao, vetor_jogadas);
	}
}

bool ja_atirou(int x, int y, int linhas, int colunas, int **m){
	if((x-1 < 0 || x-1 >= linhas || y-1 < 0 || y-1 >= colunas)){
		return false;
	}else{
		if(m[x-1][y-1] == 3 || m[x-1][y-1] == 2){
			return false;
		}else{
			return true;
		}
	}
	return true;
}

void jogo_sozinho(){
	time_t start = time(NULL); 
	int n_navios[4], linhas, colunas, valor_navio;

	printf("Escreva o numero de linhas e colunas:\n");
	scanf("%d", &linhas);
	scanf("%d", &colunas);

	int **tabuleiro = alocar_matriz(linhas, colunas);

	for (int i = 0; i < 4; ++i)	{
		printf("Escreva o numero de navios com %d pecas\n", i+2);
		scanf("%d", &n_navios[i]);
	}

	int celulas_navio = (n_navios[0]*2) + (n_navios[1]*3) + (n_navios[2]*4) + (n_navios[3]*5);

	while(celulas_navio > (linhas*colunas*0.5)){
		printf("Os navios ocupam mais da metade do tabuleiro\n");
		for (int i = 0; i < 4; ++i)	{
			printf("Escreva o numero de navios com %d pecas\n", i+2);
			scanf("%d", &n_navios[i]);
		}

		celulas_navio = (n_navios[0]*2) + (n_navios[1]*3) + (n_navios[2]*4) + (n_navios[3]*5);
	}

	insere_navio(tabuleiro, n_navios, linhas, colunas);

	int linha_tiro, coluna_tiro;
	while(true){ 
		time_t diff = (time(NULL) - start);

		printf("Tempo: %ds\n", diff);

		printf("Digite a linha que voce quer disparar\n");
		scanf(" %d", &linha_tiro);
		printf("Digite a coluna que voce quer disparar\n");
		scanf("%d", &coluna_tiro);
		while((linha_tiro <= 0 || linha_tiro > linhas || coluna_tiro <= 0 || coluna_tiro >colunas) || !(ja_atirou(linha_tiro, coluna_tiro,linhas, colunas, tabuleiro))){
			printf("Posicao invalida\n");
			printf("Digite a linha que voce quer disparar\n");
			scanf(" %d", &linha_tiro);
			printf("Digite a coluna que voce quer disparar\n");
			scanf("%d", &coluna_tiro);
		}

		if(tabuleiro[linha_tiro-1][coluna_tiro-1] == -1){
			printf("Voce errou.\n");
			tabuleiro[linha_tiro-1][coluna_tiro-1] = 2;
		}else if(tabuleiro[linha_tiro-1][coluna_tiro-1] >= 10){
			valor_navio = tabuleiro[linha_tiro-1][coluna_tiro-1];
			printf("Voce acertou!!\n");
			tabuleiro[linha_tiro-1][coluna_tiro-1] = 3;
			if (verifica_afundou(tabuleiro, valor_navio, linhas, colunas) == 0){
				printf("Voce afundou o navio!\n");
			}
		}

		imprime_matriz_adversario(tabuleiro, linhas, colunas);

		if(verifica_fim(tabuleiro, linhas, colunas) == 0){
			printf("Voce destruiu todos os navios do inimigo\n");
			break;
		}
	}
}

void jogo_com_computador(){
	time_t start = time(NULL); 
	int n_navios[4], linhas, colunas, valor_navio_player = 5, valor_navio_comp, vetor_jogadas[4];

	printf("Escreva o numero de linhas e colunas:\n");
	scanf("%d", &linhas);
	scanf("%d", &colunas);

	int **tabuleiro_player = alocar_matriz(linhas, colunas);
	int	**tabuleiro_comp = alocar_matriz(linhas, colunas);
	int	**jogadas_comp = alocar_matriz(linhas, colunas);
	
	for (int i = 0; i < 4; ++i)	{
		printf("Escreva o numero de navios com %d pecas\n", i+2);
		scanf("%d", &n_navios[i]);
	}

	int celulas_navio = (n_navios[0]*2) + (n_navios[1]*3) + (n_navios[2]*4) + (n_navios[3]*5);

	while(celulas_navio > (linhas*colunas*0.5)){
		printf("Os navios ocupam mais da metade do tabuleiro\n");
		for (int i = 0; i < 4; ++i)	{
			printf("Escreva o numero de navios com %d pecas\n", i+2);
			scanf("%d", &n_navios[i]);
		}

		celulas_navio = (n_navios[0]*2) + (n_navios[1]*3) + (n_navios[2]*4) + (n_navios[3]*5);
	}

	insere_navio(tabuleiro_player, n_navios, linhas, colunas);
	insere_navio(tabuleiro_comp, n_navios, linhas, colunas);
	
	int aux = 0, coluna_comp, linha_comp;
	int comp_acertou = 0, chute, direcao = 0, linha_nova = -1, coluna_nova = -1, jogou_vertical = 5, jogou_horizontal = 5, testa_lados, valido, coluna_tiro, linha_tiro, linha_acertada, coluna_acertada;
	while(true){
		if(aux%2 == 0){
			imprime_matriz_adversario(tabuleiro_comp, linhas, colunas);
			printf("----------------------------------------------\n");
			imprime_matriz(tabuleiro_player, linhas, colunas);
			
			time_t diff = time(NULL) - start;
			printf("Tempo: %ds\n", diff);

			printf("Digite a linha que voce quer disparar\n");
			scanf(" %d", &linha_tiro);
			printf("Digite a coluna que voce quer disparar\n");
			scanf("%d", &coluna_tiro);
			while((linha_tiro-1 < 0 || linha_tiro-1 >= linhas || coluna_tiro-1 < 0 || coluna_tiro-1 >= colunas) || !(ja_atirou(linha_tiro, coluna_tiro,linhas, colunas, tabuleiro_comp))){
				printf("Posicao invalida\n");
				printf("Digite a linha que voce quer disparar\n");
				scanf(" %d", &linha_tiro);
				printf("Digite a coluna que voce quer disparar\n");
				scanf("%d", &coluna_tiro);
			}

			if(tabuleiro_comp[linha_tiro-1][coluna_tiro-1] == -1){
				printf("Voce errou.\n");
				tabuleiro_comp[linha_tiro-1][coluna_tiro-1] = 2;
			}else if(tabuleiro_comp[linha_tiro-1][coluna_tiro-1] >= 10){
				valor_navio_comp = tabuleiro_comp[linha_tiro-1][coluna_tiro-1];
				printf("Voce acertou!!\n");
				tabuleiro_comp[linha_tiro-1][coluna_tiro-1] = 3;
				if (verifica_afundou(tabuleiro_comp, valor_navio_comp, linhas, colunas) == 0){
					printf("Voce afundou o navio!\n");
				}
			}

			if(verifica_fim(tabuleiro_comp, linhas, colunas) == 0){
				printf("Voce destruiu todos os navios do inimigo\n");
				break;
			}

		}else{
			printf("Vez do Computador\n");

			if(verifica_afundou(tabuleiro_player, valor_navio_player, linhas, colunas) == 0){
				linha_tiro = n_aleatorio(linhas);
				coluna_tiro = n_aleatorio(colunas);

				while(tabuleiro_player[linha_tiro-1][coluna_tiro-1] == 2 || tabuleiro_player[linha_tiro-1][coluna_tiro-1] == 3){
					linha_tiro = n_aleatorio(linhas);
					coluna_tiro = n_aleatorio(colunas);
				}
				if(tabuleiro_player[linha_tiro-1][coluna_tiro-1] == -1){
					comp_acertou = 0;
					printf("O computador errou.\n");
					tabuleiro_player[linha_tiro-1][coluna_tiro-1] = 2;
					jogadas_comp[linha_tiro-1][coluna_tiro-1] = 2;
				}else if(tabuleiro_player[linha_tiro-1][coluna_tiro-1] >= 10){
					comp_acertou = 1;
					jogadas_comp[linha_tiro-1][coluna_tiro-1] = 2;
					valor_navio_player = tabuleiro_player[linha_tiro-1][coluna_tiro-1];
					printf("O computador acertou!!\n");
					tabuleiro_player[linha_tiro-1][coluna_tiro-1] = 3;
					linha_acertada = linha_tiro-1;
					coluna_acertada = coluna_tiro-1;
				}
			}else{
				if(comp_acertou == 4){
					direcao = verifica_redor(tabuleiro_player, linhas, colunas, linha_nova, coluna_nova, &valor_navio_player, &linha_nova, &coluna_nova, &direcao, vetor_jogadas);
					if(direcao == 90){
							linha_tiro = n_aleatorio(linhas);
							coluna_tiro = n_aleatorio(colunas);

							while(tabuleiro_player[linha_tiro-1][coluna_tiro-1] == 2 || tabuleiro_player[linha_tiro-1][coluna_tiro-1] == 3){
								linha_tiro = n_aleatorio(linhas);
								coluna_tiro = n_aleatorio(colunas);
							}
							if(tabuleiro_player[linha_tiro-1][coluna_tiro-1] == -1){
								comp_acertou = 0;
								printf("O computador errou.\n");
								tabuleiro_player[linha_tiro-1][coluna_tiro-1] = 2;
								jogadas_comp[linha_tiro-1][coluna_tiro-1] = 2;
							}else if(tabuleiro_player[linha_tiro-1][coluna_tiro-1] >= 10){
								comp_acertou = 1;
								valor_navio_player = tabuleiro_player[linha_tiro-1][coluna_tiro-1];
								printf("O computador acertou!!\n");
								tabuleiro_player[linha_tiro-1][coluna_tiro-1] = 3;
								linha_acertada = linha_tiro-1;
								coluna_acertada = coluna_tiro-1;
							}
						}
				}else if(direcao == 1 && comp_acertou == 1 && (linha_nova+1 <= linhas-1 && linha_nova-1 >=0)){
					if(tabuleiro_player[linha_nova+1][coluna_nova] != 3 && tabuleiro_player[linha_nova+1][coluna_nova] != 2){
						comp_acertou = joga_vertical(tabuleiro_player, linhas, colunas, linha_nova, coluna_nova, &valor_navio_player, &linha_nova, &coluna_nova, 1, 0, vetor_jogadas, &direcao);
						if(comp_acertou == 9){
							comp_acertou = joga_horizontal(tabuleiro_player, linhas, colunas, linha_nova, coluna_nova, &valor_navio_player, &linha_nova, &coluna_nova, 1, 0, vetor_jogadas, &direcao);
						}
						if(comp_acertou == 1){
							direcao = 2;
						}
					}else if (tabuleiro_player[linha_nova-1][coluna_nova] != 3 && tabuleiro_player[linha_nova-1][coluna_nova] != 2){
						comp_acertou = joga_vertical(tabuleiro_player, linhas, colunas, linha_nova, coluna_nova, &valor_navio_player, &linha_nova, &coluna_nova, 1, 0, vetor_jogadas, &direcao);
						if(comp_acertou == 9){
							comp_acertou = joga_horizontal(tabuleiro_player, linhas, colunas, linha_nova, coluna_nova, &valor_navio_player, &linha_nova, &coluna_nova, 1, 0, vetor_jogadas, &direcao);
						}
						if(comp_acertou == 1){
							direcao = 2;
						}
					}else{
						comp_acertou = joga_vertical(tabuleiro_player, linhas, colunas, linha_acertada, coluna_acertada, &valor_navio_player, &linha_nova, &coluna_nova, 1, 0, vetor_jogadas, &direcao);
						if(comp_acertou == 9){
							comp_acertou = joga_horizontal(tabuleiro_player, linhas, colunas, linha_nova, coluna_nova, &valor_navio_player, &linha_nova, &coluna_nova, 1, 0, vetor_jogadas, &direcao);
						}
						if(comp_acertou == 1){
							direcao = 2;
						}
					}
				}else if(direcao == 2 && comp_acertou == 1 && (coluna_nova+1 <= colunas-1 && coluna_nova-1 >=0)){
					if(tabuleiro_player[linha_nova][coluna_nova+1] != 3 && tabuleiro_player[linha_nova][coluna_nova+1] != 2){
						comp_acertou = joga_horizontal(tabuleiro_player, linhas, colunas, linha_nova, coluna_nova, &valor_navio_player, &linha_nova, &coluna_nova, 1, 0, vetor_jogadas, &direcao);
						if(comp_acertou == 9){
							comp_acertou = joga_horizontal(tabuleiro_player, linhas, colunas, linha_nova, coluna_nova, &valor_navio_player, &linha_nova, &coluna_nova, 1, 0, vetor_jogadas, &direcao);
						}
						if(comp_acertou == 1){
							direcao = 1;
						}
					}else if (tabuleiro_player[linha_nova][coluna_nova-1] != 3 && tabuleiro_player[linha_nova][coluna_nova-1] != 2){
						comp_acertou = joga_horizontal(tabuleiro_player, linhas, colunas, linha_nova, coluna_nova, &valor_navio_player, &linha_nova, &coluna_nova, 1, 0, vetor_jogadas, &direcao);
						if(comp_acertou == 9){
							comp_acertou = joga_horizontal(tabuleiro_player, linhas, colunas, linha_nova, coluna_nova, &valor_navio_player, &linha_nova, &coluna_nova, 1, 0, vetor_jogadas, &direcao);
						}
						if(comp_acertou == 1){
							direcao = 1;
						}
					}else{
						comp_acertou = joga_horizontal(tabuleiro_player, linhas, colunas, linha_acertada, coluna_acertada, &valor_navio_player, &linha_nova, &coluna_nova, 1, 0, vetor_jogadas, &direcao);
						if(comp_acertou == 9){
							comp_acertou = joga_horizontal(tabuleiro_player, linhas, colunas, linha_nova, coluna_nova, &valor_navio_player, &linha_nova, &coluna_nova, 1, 0, vetor_jogadas, &direcao);
						}
						if(comp_acertou == 1){
							direcao = 1;
						}
					}
				}else if(direcao == 1 && comp_acertou == 0){
					comp_acertou = joga_vertical(tabuleiro_player, linhas, colunas, linha_acertada, coluna_acertada, &valor_navio_player, &linha_nova, &coluna_nova, 1, 0, vetor_jogadas, &direcao);
					if(comp_acertou == 9){
						direcao = verifica_redor(tabuleiro_player, linhas, colunas, linha_nova, coluna_nova, &valor_navio_player, &linha_nova, &coluna_nova, &direcao, vetor_jogadas);
						if(direcao == 90){
							linha_tiro = n_aleatorio(linhas);
							coluna_tiro = n_aleatorio(colunas);

							while(tabuleiro_player[linha_tiro-1][coluna_tiro-1] == 2 || tabuleiro_player[linha_tiro-1][coluna_tiro-1] == 3){
								linha_tiro = n_aleatorio(linhas);
								coluna_tiro = n_aleatorio(colunas);
							}
							if(tabuleiro_player[linha_tiro-1][coluna_tiro-1] == -1){
								comp_acertou = 0;
								printf("O computador errou.\n");
								tabuleiro_player[linha_tiro-1][coluna_tiro-1] = 2;
								jogadas_comp[linha_tiro-1][coluna_tiro-1] = 2;
							}else if(tabuleiro_player[linha_tiro-1][coluna_tiro-1] >= 10){
								comp_acertou = 1;
								valor_navio_player = tabuleiro_player[linha_tiro-1][coluna_tiro-1];
								printf("O computador acertou!!\n");
								tabuleiro_player[linha_tiro-1][coluna_tiro-1] = 3;
								linha_acertada = linha_tiro-1;
								coluna_acertada = coluna_tiro-1;
							}
						}
					}
				}else if(direcao == 2 && comp_acertou == 0){
					comp_acertou = joga_horizontal(tabuleiro_player, linhas, colunas, linha_acertada, coluna_acertada, &valor_navio_player, &linha_nova, &coluna_nova, 1, 0, vetor_jogadas, &direcao);
					if(comp_acertou == 9){
						direcao = verifica_redor(tabuleiro_player, linhas, colunas, linha_nova, coluna_nova, &valor_navio_player, &linha_nova, &coluna_nova, &direcao, vetor_jogadas);
						if(direcao == 90){
							linha_tiro = n_aleatorio(linhas);
							coluna_tiro = n_aleatorio(colunas);

							while(tabuleiro_player[linha_tiro-1][coluna_tiro-1] == 2 || tabuleiro_player[linha_tiro-1][coluna_tiro-1] == 3){
								linha_tiro = n_aleatorio(linhas);
								coluna_tiro = n_aleatorio(colunas);
							}
							if(tabuleiro_player[linha_tiro-1][coluna_tiro-1] == -1){
								comp_acertou = 0;
								printf("O computador errou.\n");
								tabuleiro_player[linha_tiro-1][coluna_tiro-1] = 2;
								jogadas_comp[linha_tiro-1][coluna_tiro-1] = 2;
							}else if(tabuleiro_player[linha_tiro-1][coluna_tiro-1] >= 10){
								comp_acertou = 1;
								valor_navio_player = tabuleiro_player[linha_tiro-1][coluna_tiro-1];
								printf("O computador acertou!!\n");
								tabuleiro_player[linha_tiro-1][coluna_tiro-1] = 3;
								linha_acertada = linha_tiro-1;
								coluna_acertada = coluna_tiro-1;
							}
						}
					}
				}else if(direcao == 1){
					comp_acertou = joga_vertical(tabuleiro_player, linhas, colunas, linha_nova, coluna_nova, &valor_navio_player, &linha_nova, &coluna_nova, 1, 0, vetor_jogadas, &direcao);
					if(comp_acertou == 9){
						direcao = verifica_redor(tabuleiro_player, linhas, colunas, linha_nova, coluna_nova, &valor_navio_player, &linha_nova, &coluna_nova, &direcao, vetor_jogadas);
						if(direcao == 90){
							linha_tiro = n_aleatorio(linhas);
							coluna_tiro = n_aleatorio(colunas);

							while(tabuleiro_player[linha_tiro-1][coluna_tiro-1] == 2 || tabuleiro_player[linha_tiro-1][coluna_tiro-1] == 3){
								linha_tiro = n_aleatorio(linhas);
								coluna_tiro = n_aleatorio(colunas);
							}
							if(tabuleiro_player[linha_tiro-1][coluna_tiro-1] == -1){
								comp_acertou = 0;
								printf("O computador errou.\n");
								tabuleiro_player[linha_tiro-1][coluna_tiro-1] = 2;
								jogadas_comp[linha_tiro-1][coluna_tiro-1] = 2;
							}else if(tabuleiro_player[linha_tiro-1][coluna_tiro-1] >= 10){
								comp_acertou = 1;
								valor_navio_player = tabuleiro_player[linha_tiro-1][coluna_tiro-1];
								printf("O computador acertou!!\n");
								tabuleiro_player[linha_tiro-1][coluna_tiro-1] = 3;
								linha_acertada = linha_tiro-1;
								coluna_acertada = coluna_tiro-1;
							}
						}
					}
				}else if(direcao == 2){
					comp_acertou = joga_horizontal(tabuleiro_player, linhas, colunas, linha_nova, coluna_nova, &valor_navio_player, &linha_nova, &coluna_nova, 1, 0, vetor_jogadas, &direcao);
					if(comp_acertou == 9){
						direcao = verifica_redor(tabuleiro_player, linhas, colunas, linha_nova, coluna_nova, &valor_navio_player, &linha_nova, &coluna_nova, &direcao, vetor_jogadas);
						if(direcao == 90){
							linha_tiro = n_aleatorio(linhas);
							coluna_tiro = n_aleatorio(colunas);

							while(tabuleiro_player[linha_tiro-1][coluna_tiro-1] == 2 || tabuleiro_player[linha_tiro-1][coluna_tiro-1] == 3){
								linha_tiro = n_aleatorio(linhas);
								coluna_tiro = n_aleatorio(colunas);
							}
							if(tabuleiro_player[linha_tiro-1][coluna_tiro-1] == -1){
								comp_acertou = 0;
								printf("O computador errou.\n");
								tabuleiro_player[linha_tiro-1][coluna_tiro-1] = 2;
								jogadas_comp[linha_tiro-1][coluna_tiro-1] = 2;
							}else if(tabuleiro_player[linha_tiro-1][coluna_tiro-1] >= 10){
								comp_acertou = 1;
								valor_navio_player = tabuleiro_player[linha_tiro-1][coluna_tiro-1];
								printf("O computador acertou!!\n");
								tabuleiro_player[linha_tiro-1][coluna_tiro-1] = 3;
								linha_acertada = linha_tiro-1;
								coluna_acertada = coluna_tiro-1;
							}
						}
					}
				}else if(linha_acertada+1 <= linhas-1 && linha_acertada-1 >= 0 && coluna_acertada+1 <= colunas-1 && coluna_acertada-1 >= 0){
					if((tabuleiro_player[linha_acertada+1][coluna_acertada] == 3 || tabuleiro_player[linha_acertada+1][coluna_acertada] == 2) && (tabuleiro_player[linha_acertada-1][coluna_acertada] == 3 || tabuleiro_player[linha_acertada-1][coluna_acertada] == 2)
					&& (tabuleiro_player[linha_acertada][coluna_acertada+1] == 3 || tabuleiro_player[linha_acertada][coluna_acertada+1] == 2) && (tabuleiro_player[linha_acertada][coluna_acertada-1] == 3 || tabuleiro_player[linha_acertada][coluna_acertada-1] == 2)){
						linha_tiro = n_aleatorio(linhas);
						coluna_tiro = n_aleatorio(colunas);

						while(tabuleiro_player[linha_tiro-1][coluna_tiro-1] == 2 || tabuleiro_player[linha_tiro-1][coluna_tiro-1] == 3){
							linha_tiro = n_aleatorio(linhas);
							coluna_tiro = n_aleatorio(colunas);
						}
						if(tabuleiro_player[linha_tiro-1][coluna_tiro-1] == -1){
							comp_acertou = 0;
							printf("O computador errou.\n");
							tabuleiro_player[linha_tiro-1][coluna_tiro-1] = 2;
							jogadas_comp[linha_tiro-1][coluna_tiro-1] = 2;
						}else if(tabuleiro_player[linha_tiro-1][coluna_tiro-1] >= 10){
							comp_acertou = 1;
							valor_navio_player = tabuleiro_player[linha_tiro-1][coluna_tiro-1];
							printf("O computador acertou!!\n");
							tabuleiro_player[linha_tiro-1][coluna_tiro-1] = 3;
							linha_acertada = linha_tiro-1;
							coluna_acertada = coluna_tiro-1;
						}
					}else{
						direcao = verifica_redor(tabuleiro_player, linhas, colunas, linha_acertada, coluna_acertada, &valor_navio_player, &linha_nova, &coluna_nova, &direcao, vetor_jogadas);
					}
				}else if(direcao == 90){
					linha_tiro = n_aleatorio(linhas);
					coluna_tiro = n_aleatorio(colunas);

					while(tabuleiro_player[linha_tiro-1][coluna_tiro-1] == 2 || tabuleiro_player[linha_tiro-1][coluna_tiro-1] == 3){
						linha_tiro = n_aleatorio(linhas);
						coluna_tiro = n_aleatorio(colunas);
					}
					if(tabuleiro_player[linha_tiro-1][coluna_tiro-1] == -1){
						comp_acertou = 0;
						printf("O computador errou.\n");
						tabuleiro_player[linha_tiro-1][coluna_tiro-1] = 2;
						jogadas_comp[linha_tiro-1][coluna_tiro-1] = 2;
					}else if(tabuleiro_player[linha_tiro-1][coluna_tiro-1] >= 10){
						comp_acertou = 1;
						valor_navio_player = tabuleiro_player[linha_tiro-1][coluna_tiro-1];
						printf("O computador acertou!!\n");
						tabuleiro_player[linha_tiro-1][coluna_tiro-1] = 3;
						linha_acertada = linha_tiro-1;
						coluna_acertada = coluna_tiro-1;
					}
				}else if(comp_acertou == 1){
					direcao = verifica_redor(tabuleiro_player, linhas, colunas, linha_acertada, coluna_acertada, &valor_navio_player, &linha_nova, &coluna_nova, &direcao, vetor_jogadas);
					
					if(direcao == 90){
						linha_tiro = n_aleatorio(linhas);
						coluna_tiro = n_aleatorio(colunas);

						while(tabuleiro_player[linha_tiro-1][coluna_tiro-1] == 2 || tabuleiro_player[linha_tiro-1][coluna_tiro-1] == 3){
							linha_tiro = n_aleatorio(linhas);
							coluna_tiro = n_aleatorio(colunas);
						}
						if(tabuleiro_player[linha_tiro-1][coluna_tiro-1] == -1){
							comp_acertou = 0;
							printf("O computador errou.\n");
							tabuleiro_player[linha_tiro-1][coluna_tiro-1] = 2;
							jogadas_comp[linha_tiro-1][coluna_tiro-1] = 2;
						}else if(tabuleiro_player[linha_tiro-1][coluna_tiro-1] >= 10){
							comp_acertou = 1;
							valor_navio_player = tabuleiro_player[linha_tiro-1][coluna_tiro-1];
							printf("O computador acertou!!\n");
							tabuleiro_player[linha_tiro-1][coluna_tiro-1] = 3;
							linha_acertada = linha_tiro-1;
							coluna_acertada = coluna_tiro-1;
						}
					}
				}else if(comp_acertou == 0 || comp_acertou == 9){
					linha_tiro = n_aleatorio(linhas);
					coluna_tiro = n_aleatorio(colunas);

					while(tabuleiro_player[linha_tiro-1][coluna_tiro-1] == 2 || tabuleiro_player[linha_tiro-1][coluna_tiro-1] == 3){
						linha_tiro = n_aleatorio(linhas);
						coluna_tiro = n_aleatorio(colunas);
					}
					if(tabuleiro_player[linha_tiro-1][coluna_tiro-1] == -1){
						comp_acertou = 0;
						printf("O computador errou.\n");
						tabuleiro_player[linha_tiro-1][coluna_tiro-1] = 2;
						jogadas_comp[linha_tiro-1][coluna_tiro-1] = 2;
					}else if(tabuleiro_player[linha_tiro-1][coluna_tiro-1] >= 10){
						comp_acertou = 1;
						valor_navio_player = tabuleiro_player[linha_tiro-1][coluna_tiro-1];
						printf("O computador acertou!!\n");
						tabuleiro_player[linha_tiro-1][coluna_tiro-1] = 3;
						linha_acertada = linha_tiro-1;
						coluna_acertada = coluna_tiro-1;
					}
				}
				if(verifica_afundou(tabuleiro_player, valor_navio_player, linhas, colunas) == 0){
					valor_navio_player = 5;
					direcao = 0;
					comp_acertou = 0;
				}
			}
			if(verifica_fim(tabuleiro_player, linhas, colunas) == 0){
				printf("O computador destruiu todos os seus navios\n");
				break;
			}
		}
		aux++;
	}
}

void main(){
	srand(time(NULL));
	int tipo_jogo;	
	
	printf("Digite 1 para jogar sozinho ou 2 para jogar com o computador\n");
	scanf("%d", &tipo_jogo);

	switch(tipo_jogo){
		case 1:
			jogo_sozinho();
			break;
		case 2:
			jogo_com_computador();
			break;
		default:
			printf("Tipo de jogo inválido\n");
			return;
			break; 	
	}
}