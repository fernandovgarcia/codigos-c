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
	printf("Direcao %d -- Linha %d -- Coluna %d\n", direcao, a_linha, a_coluna);
	
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
	printf("Direcao %d -- Linha %d -- Coluna %d\n", direcao, a_linha, a_coluna);
	
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
	printf("Direcao %d -- Linha %d -- Coluna %d\n", direcao, a_linha, a_coluna);
	
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
	printf("Direcao %d -- Linha %d -- Coluna %d\n", direcao, a_linha, a_coluna);
	
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
	printf("navios com 5: %d\nnavios com 4: %d \n", n_navios[3], n_navios[2]);
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

	int **m = (int**)malloc(linhas * sizeof(int*)); //Aloca um Vetor de Ponteiros

	for (int i = 0; i < linhas; i++){ //Percorre as linhas do Vetor de Ponteiros
		m[i] = (int*) malloc(colunas * sizeof(int)); //Aloca um Vetor de Inteiros para cada posição do Vetor de Ponteiros.
		for (int j = 0; j < colunas; j++){ //Percorre o Vetor de Inteiros atual.
			m[i][j] = -1; //Inicializa com 0.
		}
	}
	return m; //Retorna o Ponteiro para a Matriz Alocada
}

void imprime_matriz(int **tabuleiro, int linhas, int colunas){
	for(int i=0; i < linhas; i++){
		for(int j=0; j < colunas; j++){
			if(tabuleiro[i][j] == -1){
				printf("[~]");
			}else if(tabuleiro[i][j] == 1){
				printf("[N]");
			}else if(tabuleiro[i][j] == 2){
				printf("[X]");
			}
			else if(tabuleiro[i][j] == 3){
				printf("[*]");
			}
			if (j == colunas-1){
				printf("\n");
			}
		}
	}
}

void imprime_matriz_adversario(int **tabuleiro, int linhas, int colunas){
	for(int i=0; i < linhas; i++){
		for(int j=0; j < colunas; j++){
			if(tabuleiro[i][j] == 2){
				printf("[X]");
			}
			else if(tabuleiro[i][j] == 3){
				printf("[*]");
			}else{
				printf("[?]");
			}
			if (j == colunas-1){
				printf("\n");
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

void jogo_sozinho(){
	time_t start = time(NULL); 
	int n_navios[4], linhas, colunas;

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

		printf("Digite a linha e a coluna que voce quer disparar\n");
		scanf("%d", &linha_tiro);
		scanf("%d", &coluna_tiro);

		while(tabuleiro[linha_tiro-1][coluna_tiro-1] == 2 || tabuleiro[linha_tiro-1][coluna_tiro-1] == 3){
			printf("Voce ja chutou essa posicao, digite a linha e a coluna que voce quer disparar novamente\n");
			scanf("%d", &linha_tiro);
			scanf("%d", &coluna_tiro);
		}

		if(tabuleiro[linha_tiro-1][coluna_tiro-1] == -1){
			printf("Voce errou.\n");
			tabuleiro[linha_tiro-1][coluna_tiro-1] = 2;
		}else if(tabuleiro[linha_tiro-1][coluna_tiro-1] >= 10){
			printf("Voce acertou!!\n");
			tabuleiro[linha_tiro-1][coluna_tiro-1] = 3;
		}

		imprime_matriz_adversario(tabuleiro, linhas, colunas);

		if(verifica_fim(tabuleiro, linhas, colunas) == 0){
			printf("Voce destruiu todos os navios do inimigo\n");
			break;
		}
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
			// jogo_com_computador();
			break;
		default:
			printf("Tipo de jogo inválido\n");
			return;
			break; 	
	}
}