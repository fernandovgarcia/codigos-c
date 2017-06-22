#include <stdio.h>
#include <math.h>

int fatorial(int x){
	if (x<=1){
		return 1;
	}else{
		x=x*fatorial(x-1);
		return x;
	}
}

long double potencia(int base, int expoente){
	long double resultado;
	int i;

	resultado = 1;
	
	if(expoente == 0){ 
		return 1;
	}

	for(i = 0;i < expoente; i++){
		resultado = resultado * base;
	}
	return resultado;
}

void main(){
	int i, limite;

	long double x;

	printf("Informe o ângulo em graus que deseja ter o seno:\n");
	scanf("%Lf", &x);

	printf("Informe o limite:\n");
	scanf("%i", &limite); 

	int expden = 1;
	
	x = x*3.14159265/180;

	long double sen = x; 

	for(i=0; i<=limite; i++){
		expden += 2;
		
		if (i % 2 == 0){
			sen -= potencia(x, expden)/fatorial(expden);
		}else{
			sen += potencia(x, expden)/fatorial(expden);
		}
	}
	printf("O seno é %Lf\n", sen);
}

