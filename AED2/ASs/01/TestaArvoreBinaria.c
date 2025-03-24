/*Isadora Yasmim da Silva - 202403076*/

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main() {
    int N, dados[] = {4, 2, 6, 1, 3, 5, 7};
    N = sizeof(dados) / sizeof(dados[0]);

    ArvBin* raiz = cria_ArvBin();
    int i, q, info, antecessor, sucessor;

    for (i = 0; i < N; i++)
        insere_ArvBin(raiz, dados[i]);

    desenheArvore(raiz, 'B'); // Desenho de �rvore bin�ria de Busca

    printf("\n\nPercurso em-ordem:\n");
    emOrdem_ArvBin(raiz);

    printf("\n\nPercurso em pre-ordem:\n");
    preOrdem_ArvBin(raiz);

    printf("\n\nPercurso pos-ordem:\n");
    posOrdem_ArvBin(raiz);

    printf("\n\nPercurso largura:\n");
    visitaEmLargura(raiz);

    printf("\n\nTotal de nos da arvore (rec): %i\n", totalNO_ArvBin(raiz));
    printf("Total de nos da arvore (iter): %i\n", totalNO_ArvBin_Iter(raiz));
    printf("\nAltura da arvore (rec): %i\n", altura_ArvBin(raiz));
    printf("Altura da arvore (iter): %i\n", altura_ArvBin_Iter(raiz));

    printf("\nElemento a pesquisar: ");
    scanf("%d", &q);

    printf("\n\nResultado pesquisa iterativa pelo elemento %d:\n", q);
    if (consultaIntervalarArvBinIter(raiz, q, &antecessor, &sucessor)) {
        printf("Elemento %d encontrado na arvore!\n", q);
    } else {
        if (antecessor != -1)
            printf("Elemento antecessor %d encontrado na arvore.\n", antecessor);
        if (sucessor != -1)
            printf("Elemento sucessor %d encontrado na arvore.\n", sucessor);
    }

    printf("\nResultado pesquisa recursiva pelo elemento %d:\n", q);
    if (consultaIntervalarArvBinRec(*raiz, q, &antecessor, &sucessor)) {
        printf("Elemento %d encontrado na arvore!\n", q);
    } else {
        if (antecessor != -1)
            printf("Elemento antecessor %d encontrado na arvore.\n", antecessor);
        if (sucessor != -1)
            printf("Elemento sucessor %d encontrado na arvore.\n", sucessor);
    }

    libera_ArvBin(raiz);

    printf("\n\nPressione alguma tecla para encerrar!\n");
    system("pause > nul");

    return 0;
}

