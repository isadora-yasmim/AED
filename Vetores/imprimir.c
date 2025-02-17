#include <stdio.h>

/*
    Aula 100:Como imprimir o conteúdo de um vetor?
*/
int main () {
    int vetor1[5];
    int vetor2[]={1,2,3,4,5,6};
    //os índices: 0 1 2 3 4 5 
    int vetor3[4]={1,2};
    int vetor4[8]={0};
    int vetor5[3]={1,2,3};

    char vetor6[100];
    char vetor7[5]={'a','b','c','d','e'};

    float vetor8[3]={1.1,1.2,1.3};

//imprimir uma posição específica
    printf("%d", vetor2[0]);
    printf("%d", vetor2[1]);

    printf("\n\n");
//imprimir varios elementos de um vetor
    int i;
    for(i=0;i<4;i++){
        printf("%d ", vetor3[i]);
    }

    printf("\n\n");

    for(i=0; i<5; i++){
        printf("%c ", vetor7[i]);
    }
    return 0;
}