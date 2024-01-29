#include <stdio.h>


int main(){

    float ph;

    while(1){
        printf("Digite o ph da substancia (digite \"-1\" para sair): ");
        scanf("%f", &ph);

        if(ph == -1){
            break;
        }else{
            if (ph > 7)
            {
                printf("\nBASICA\n");
            }
            else if (ph < 7){
                printf("\nACIDA\n");
            }
            else{
                printf("\nNEUTRA\n");
            }
            
        }
    }



    return 0;
}