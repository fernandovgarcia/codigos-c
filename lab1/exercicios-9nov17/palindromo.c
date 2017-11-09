#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool palindromo(char s[]){
  int i,j;
  i=0;
  j=strlen(s)-1;
  while(i<j){
    while(s[i] == ' '){
      i++;
    }
    while (s[j] == ' '){
      j--;
    }
    if(s[i] != s[j]) return false;
    i++;
    j--;
  }
  return true;
}
void tira_enter_do_final(char s[]){
  int p = strlen(s)-1;
  if (s[p] == '\n'){
    s[p] = '\0';
  }
}
int main(){
  char f[82];
  printf("Digite uma frase\n");
  fgets(f,82,stdin);
  tira_enter_do_final(f);
  if (palindromo(f)){
    printf("A frase e' um palindromo\n");
  }else{
    printf("A frase nao e' um palindromo\n");
  }
  //isalpha('a') funcao com a biblioteca ctype
}