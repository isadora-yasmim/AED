/*Isadora Yasmim da Silva - 202403076*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "fila.h"

Fila* cria_Fila()
{
	Fila *fi;
	fi = (Fila*) malloc(sizeof(struct fila));
	
	if (fi != NULL) {
		fi->qtd = 0;
		fi->inicio = 0;
		fi->final = 0;
	}
	return fi;
}

void libera_Fila(Fila* fi)
{
	free(fi);
}

int insere_Fila(Fila* fi, struct NO *al)
{
	if (fi == NULL)
		return 0;
	Elem *no = (Elem*) malloc(sizeof(Elem));
	
	if(no == NULL)
		return 0;
	no->dados = al;
	no->prox = NULL;
	
	if (fi->final == NULL)	// Fila vazia
		fi->inicio = no;
	else
		fi->final->prox = no;
		
	fi->final = no;
	fi->qtd++;
	return 1;
}

int insere_inicio_Fila(Fila* fi, struct NO *al)
{
	if (fi == NULL)
		return 0;
	Elem *no = (Elem*) malloc(sizeof(Elem));
	
	if(no == NULL)
		return 0;
	no->dados = al;
	no->prox = fi->inicio;
	fi->inicio = no;
	if (fi->final == NULL) // Fila vazia
		fi->final = no;      

	fi->qtd++;
	return 1;
}

int remove_Fila(Fila* fi)
{
	if (fi == NULL)
		return 0;
	if (fi->inicio == NULL)	// Fila vazia
		return 0;
		
	Elem *no = fi->inicio;
	fi->inicio = fi->inicio->prox;
	if (fi->inicio == NULL)	// Fila ficou vazia
		fi->final = NULL;
	free(no);
	fi->qtd--;
	return 1;
}

int Fila_cheia(Fila* fi)
{
	if (fi == NULL)
		return -1;
	else
		return (fi->qtd == MAX);
}

int Fila_vazia(Fila* fi)
{
	if (fi == NULL)
		return -1;
	return (fi->qtd == 0);
}


int consulta_Fila(Fila* fi, struct NO **al)
{
	if (fi == NULL)
		return 0;
	if (fi->inicio == NULL)	// Fila vazia
		return 0;
	*al = fi->inicio->dados;
	return 1;
}

