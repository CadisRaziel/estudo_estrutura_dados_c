#include <stdio.h>
#include <stdlib.h>

int main() {
    //Tudo aqui é CONSTANTE !!!
    //Constantes -> O(1)

    //Criando um vetor de 5 posições
    int numeros[5] = {1, 2, 3, 4, 5};
    
    //acesso
    printf("valor : %d\n", numeros[2]);
    
    //Atualizando valor
    numeros[2] = 90;
    printf("atualizando valor : %d\n", numeros[2]);


    //Loop (tempo constante N)
    for(int i = 0; i < 5; i++) {
        printf("%d, ", numeros[i]);
    }

    return 0;
}