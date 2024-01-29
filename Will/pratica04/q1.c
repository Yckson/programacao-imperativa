// JK evitar "estouro" de cartão de crédito
#include <stdio.h>

void ValidaCompra(float *L, int *numCompra){ //Modificado

    float D;
    printf("Debito: ");
    scanf("%f",&D);
    if (*L - D >= 0){
        printf("Compra possivel! \n");
        *L = *L - D;
        *numCompra += 1; //Modificado
        printf("Numero da compra atual: %d\n", *numCompra);
    }
    else{
        printf("Compra ""estourarah"" o cartao! \n");
    }

    printf("Limite restante: %.2f \n\n",*L);

}


int main(){
    float Limite; int numCompra; //Modificado
    printf("Limite do cartao: ");
    scanf("%f",&Limite);

    numCompra = 0; //Modificado
    while (Limite>0)
        ValidaCompra(&Limite, &numCompra); //Modificado
    printf("Seu limite de compras acabou!");
return 0;}