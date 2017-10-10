#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool verifica(int n){
	int r, q, soma;
	r = n%100;
	q = n/100;
	soma = r + q;
	if (pow(soma, 2) == n)
	{
		return true;
	}else{
		return false;
	}
}
void main(){
	for(int i = 1000; i <= 9999; i++){
		if(verifica(i)){
			printf("%d\n", i);
		}
	}
}