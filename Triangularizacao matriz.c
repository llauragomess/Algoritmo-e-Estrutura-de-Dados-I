#include <stdio.h>
#include <stdlib.h>
#define quantidade_linha 4
#define quantidade_coluna 4
int main(){

    int i, j;

    /*printf("\nInsira a quantidade de linha da matriz: \n");
    scanf("%d", &quantidade_linha);
    printf("\nInsira a quantidade de coluna da matriz: \n");
    scanf("%d", &quantidade_coluna);
    */
    int matriz[quantidade_linha][quantidade_coluna];

    /*for(i=0; i<quantidade_linha; i++){
        for(j=0; j<quantidade_coluna; j++){
            printf("\nDigite o valor da posicao Matriz[%d][%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }*/

    matriz[0][0] = 5;
    matriz[0][1] = -2;
    matriz[0][2] = 6;
    matriz[0][3] = 1;
    matriz[1][0] = 0;
    matriz[1][1] = 3;
    matriz[1][2] = 7;
    matriz[1][3] = -4;
    matriz[2][0] = 0;
    matriz[2][1] = 0;
    matriz[2][2] = 4;
    matriz[2][3] = 5;
    matriz[3][0] = 0;
    matriz[3][1] = 0;
    matriz[3][2] = 0;
    matriz[3][3] = 2;

    int vetor_resultado[quantidade_linha];
    printf("\nInsira o vetor resultado:\n");
    for(i=0; i<quantidade_linha; i++){
        scanf("%d", &vetor_resultado[i]); 
    }
   
  
    printf("\nMatriz inserida: \n");
    for(i=0; i<quantidade_linha; i++){
        printf(" ");
        for(j=0; j<quantidade_coluna; j++){
            printf("%d ",matriz[i][j]);
        }
        printf(" \n");
    }


    printf("\nVetor resultado:\n");
    for(i=0; i<quantidade_linha; i++){
        printf(" %d", vetor_resultado[i]);
    }
    //encontrar o vetor de x
	//soma = (vetor_resultado[1] - matriz[1][0] * vetor_x[0])/matriz[1][1];
    int vetor_x[quantidade_linha];
    int aux=0;

    for(i = quantidade_linha - 1; i>=0; i--){
    	vetor_x[i] = vetor_resultado[i];
        for(j = quantidade_linha -1; j>i; j--){
            vetor_x[i] -= matriz[i][j] * vetor_x[j];
        }
        vetor_x[i] /= matriz[i][i];
    }
    
    
    printf("\nVetor de X: ");
    for(i=0; i<quantidade_linha; i++){
        printf(" %d ", vetor_x[i]);
    }

    return 0;

}
