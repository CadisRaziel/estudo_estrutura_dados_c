#include <stdio.h>
#include <stdlib.h>

int main() {
    //Tudo aqui é CONSTANTE (menos o loop) !!!
    //Constantes -> O(1)

    //Matriz 3x3
    int matriz[3][3] = {
       //C C C 
        {0,1,2}, //L  0
        {3,4,5}, //L  1
        {6,7,8}, //L  2
    }; 

    //Acesso
    printf("Linha[1] - Coluna[2] : %d\n", matriz[1][2]);
    
    //Atualizando
    matriz[0][0] = 99;
    printf("Linha[0] - Coluna[0] : %d\n", matriz[0][0]);

    //Loop matriz -> O(n*m) (n = linhas, m = colunas)
     for(int i = 0; i < 3; i++) {
         for(int j = 0; j < 3; j++) {
            printf("[%d][%d]\n", i, j, matriz[i][j]);
        }
    }

    return 0;
}