// JK faz vaquinha para proteção animal

#include <stdio.h>

int main(){
	float Meta, Doacao, Soma = 0;
	printf("Meta da vaquinha: ");
	scanf("%f",&Meta);
	do{
	  printf("Valor da doacao: ");
	  scanf("%f",&Doacao);
	  Soma = Soma + Doacao;}
	while (Soma<Meta);
    if (Soma > Meta){
        printf("A meta foi ultrapassada! Valor: %.2f", Soma);
    }
    else{
        printf("O valor da meta foi obtido! Valor: %.2f", Soma);
    }
    return 0;
}