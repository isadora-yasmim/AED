#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

int main()
{
    ArvAVL* avl;
    int res,i;
    //int N = 10, dados[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    char *dados[] = {"aviao","bicileta","cavalo","amora","avionica","dado","datilografia","elefante","elefantatisco"};
    int N = sizeof(dados)/sizeof(dados[0]);
    
    avl = cria_ArvAVL();

    for(i=0;i<N;i++) {
        res = insere_ArvAVL(avl,dados[i]);
    }
    
    printf("\nAVL tree:\n");
    desenheArvore(avl, 'B'); // Desenho de árvore binária de Busc
    
    printf("\nPercurso em ordem:\n");
    emOrdem_ArvAVL(avl);
    printf("\n\n");
    
    char palavra[60];
    printf("Palavra a consultar: ");
    scanf("%s", palavra);
    
    if (consulta_ArvAVL(avl, palavra) == 1)
    	printf("\"%s\" encontrada na AVL\n", palavra);
    else
    	printf("\"%s\" NAO encontrada na AVL\n", palavra);

    //remove_ArvAVL(avl, 7);

    libera_ArvAVL(avl);
    
    system("pause > nul");
    return 0;
}
