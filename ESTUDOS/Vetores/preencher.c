#include <stdio.h>
/*
    Aula 101: Como preencher um vetor pelo teclado?
    Aula 102: Como alterar o conteudo de um vetor?
*/

int main (){

    int i;
    int vetor[10];

//preencher um vetor pelo teclado
    for (i=0; i<10; i++){
        printf("Digite o valor da posicao %d: ", i);
        scanf("%d", &vetor[i]);
    }
 
    printf("\n\n");
    
//imprimir o vetor preenchido
    for (i=0; i<10; i++){
        printf("%d ", vetor[i]);
    }


    return 0;
}