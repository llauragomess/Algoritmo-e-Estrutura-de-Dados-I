#include <stdio.h>
#include <math.h>

int main(){
	int i, j;
    int k;
	int n = 3;
	
	float A[3][3];
    float B[3]= {1,2,3};

    float aux;
	
    A[0][0] = 3;
    A[0][1] = 2;
    A[0][2] = 4;
    A[1][0] = 1;
    A[1][1] = 1;
    A[1][2] = 2;
    A[2][0] = 4;
    A[2][1] = 3;
    A[2][2] = -2;
	
	printf("\nMatriz inserida: \n");
    for(i=0; i<n; i++){
        printf(" ");
        for(j=0; j<n; j++){
            printf("%0.2f ",A[i][j]);
        }
        printf(" \n");
    }
    printf("\nVetor B: ");
        for(i=0; i<n; i++){
            printf("\n%0.2f", B[i]);
        }

    for(i=0; i<n-1; i++){//percorrendo a matriz
        for(j = i+1; j<n; j++){
            aux = -A[j][i]/A[i][i];        
            A[j][i] = 0;
            for(k = i+1; k<n; k++){
                A[j][k] = A[j][k] + (aux * A[i][k]);
            }
             B[j] = B[j] + (aux * B[i]);
        } 
    }

	printf("\n\nMatriz inserida: \n");
    for(i=0; i<n; i++){
        printf(" ");
        for(j=0; j<n; j++){
            printf("%0.2f ",A[i][j]);
        }
        printf(" \n");
    }

    printf("\nVetor B: ");
    for(i=0; i<n; i++){
        printf("\n%0.2f", B[i]);
    }

    return 0;
}
