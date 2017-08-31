#include <stdio.h>

void main(){
	int numero, dezena, unidade;

	printf("Informe um numero inteiro\n");
	scanf("%d", &numero);

	if (numero < 100){
		dezena = numero / 10;
		unidade = numero % 10;

		printf("O número ao contrário é: %d%d\n", unidade, dezena);
	}else{
		printf("O número deve ser menor que 100\n");
	}
}