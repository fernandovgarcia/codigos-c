#include <stdio.h>

void main(){
	int numero, centena, dezena, unidade;

	printf("Informe um numero inteiro\n");
	scanf("%d", &numero);

	if (numero < 100){
		dezena = numero / 10;
		unidade = numero % 10;

		printf("A soma dos dígitos é: %d\n", unidade+dezena);
	}else if(numero > 100 && numero < 1000){

		unidade = numero%10;
		centena = (numero/10)/10;
		dezena = (numero/10)%10;

		printf("A soma dos dígitos é: %d\n", unidade+dezena+centena);
	}else{
		printf("O número deve ser menor que 1000\n");
	}
}