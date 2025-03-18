/*Isadora Yasmim da Silva - 202403076*/

#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

int main()
{
	int N, dados[] = {4, 2, 6, 1, 3, 5, 7};
	N = sizeof(dados)/sizeof(dados[0]);

	ArvBin* raiz = cria_ArvBin();
	int i, q, info;

	for(i=0; i < N; i++)
		insere_ArvBin(raiz, dados[i]);

	desenheArvore(raiz, 'B'); // Desenho de árvore binária de Busca

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
	if (consulta_ArvBinIter(raiz, q, &info))
		printf("Elemento %i encontrado na arvore!", info);
	else
		printf("Elemento %i NAO encontrado na arvore!", q);

	printf("\n\nResultado pesquisa recursiva pelo elemento %d:\n", q);
	if (consulta_ArvBin(raiz, q, &info))
		printf("Elemento %i encontrado na arvore!", info);
	else
		printf("Elemento %i NAO encontrado na arvore!", q);

	libera_ArvBin(raiz);

	printf("\n\nPressione alguma tecla para encerrar!\n");
	system("pause > nul");
	
	return 0;
}

