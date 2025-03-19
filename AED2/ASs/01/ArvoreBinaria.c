/*Isadora Yasmim da Silva - 202403076*/
/*As funcoes consultaIntervalarArvBinIter e consultaIntervalarArvBinRec se encontram  a partir da linha 316*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArvoreBinaria.h"
#include "Fila.h"

ArvBin* cria_ArvBin()
{
	ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
	if (raiz != NULL)
		*raiz = NULL;
	return raiz;
}

void libera_NO(struct NO* no)
{
	if (no == NULL)
		return;
	libera_NO(no->esq);
	libera_NO(no->dir);
	free(no);
	no = NULL;
}

void libera_ArvBin(ArvBin* raiz)
{
	if (raiz == NULL)
		return;
	libera_NO(*raiz);	// Desaloca mem�ria de cada n�
	free(raiz);	// Desaloca mem�ria da raiz
}

int insere_ArvBin(ArvBin* raiz, int valor)
{
	if (raiz == NULL)
		return 0;

	struct NO* novo;
	novo = (struct NO*) malloc(sizeof(struct NO));

	if (novo == NULL)
		return 0;

	novo->info = valor;
	novo->dir = NULL;
	novo->esq = NULL;

	if (*raiz == NULL)
		*raiz = novo;
	else {
		struct NO* atual = *raiz;
		struct NO* ant = NULL;
		while (atual != NULL){
			ant = atual;
			if (valor == atual->info){
				free(novo);
				return 0;	// Elemento j� existe na �rvore
			}

			if (valor > atual->info)
				atual = atual->dir;
			else
				atual = atual->esq;
		}
		if (valor > ant->info)
			ant->dir = novo;
		else
			ant->esq = novo;
	}
	return 1;
}


int insere_EmLargura(ArvBin *raiz, int valor)
{
	if (raiz == NULL)
		return 0;

	struct NO* novo;
	novo = (struct NO*) malloc(sizeof(struct NO));
	if (novo == NULL)
		return 0;
	novo->info = valor;
	novo->dir = NULL;
	novo->esq = NULL;

	if (*raiz == NULL)
		*raiz = novo;
	else {	
		struct NO *q;
		Fila* f = cria_Fila(); // fila auxiliar
		insere_Fila(f, *raiz); // Insere raiz na fila

		do {
			if (consulta_Fila(f, &q)) {
				remove_Fila(f); // Retira n� q da fila
				if (q != NULL) {
					if (q->esq == NULL) {
						q->esq = novo;
						break;
					}

					insere_Fila(f, q->esq); // Insere sub�rvore esq. na fila
					if (q->dir == NULL) {
						q->dir = novo;
						break;
					}
					insere_Fila(f, q->dir); // Insere sub�rvore dir. na fila
				}
			}
		} while (!Fila_vazia(f));  
	}
	return 1;
}


struct NO* remove_atual(struct NO* atual)
{
	struct NO *no1, *no2;
	if (atual->esq == NULL){
		no2 = atual->dir;
		free(atual);
		return no2;
	}
	no1 = atual;
	no2 = atual->esq;

	while (no2->dir != NULL){
		no1 = no2;
		no2 = no2->dir;
	}
	// no2 � o n� anterior a r na ordem e-r-d
	// no1 � o pai de no2
	if (no1 != atual){
		no1->dir = no2->esq;
		no2->esq = atual->esq;
	}
	no2->dir = atual->dir;
	free(atual);

	return no2;
}

int remove_ArvBin(ArvBin *raiz, int valor)
{
	if (raiz == NULL)
		return 0;
		
	struct NO* ant = NULL;
	struct NO* atual = *raiz;
	
	while (atual != NULL){
		if (valor == atual->info) {
			if (atual == *raiz)
				*raiz = remove_atual(atual);
			else {
				if (ant->dir == atual)
					ant->dir = remove_atual(atual);
				else
					ant->esq = remove_atual(atual);
			}
			return 1;
		}
		ant = atual;
		if (valor > atual->info)
			atual = atual->dir;
		else
			atual = atual->esq;
	}
	return 0;
}

int estaVazia_ArvBin(ArvBin *raiz)
{
	if (raiz == NULL)
		return 1;
	if (*raiz == NULL)
		return 1;
	return 0;
}

int totalNO_ArvBin(ArvBin *raiz)
{
	if (raiz == NULL)
		return 0;
	if (*raiz == NULL)
		return 0;

	int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
	int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
	return(alt_esq + alt_dir + 1);
}

int totalNO_ArvBin_Iter(ArvBin *raiz)
{
	struct NO *q;
	Fila* f = cria_Fila(); // Fila auxiliar
	insere_Fila(f, *raiz); // Insere raiz na fila
	int cont = 0;
	do {
		if (consulta_Fila(f, &q)) {
			remove_Fila(f); // Retira n� q da fila
			if (q != NULL) {
				cont++;
				insere_Fila(f, q->esq); // Insere sub-�rvore esq. na fila
				insere_Fila(f, q->dir); // Insere sub-�rvore dir. na fila
			}
		}
	} while (!Fila_vazia(f));  
	return cont;
}

int altura_ArvBin(ArvBin *raiz)
{
	if (raiz == NULL)
		return 0;
	if (*raiz == NULL)
		return 0;
	
	int alt_esq = altura_ArvBin(&((*raiz)->esq));
	int alt_dir = altura_ArvBin(&((*raiz)->dir));
	if (alt_esq > alt_dir)
		return (alt_esq + 1);
	else
		return(alt_dir + 1);
}

int altura_ArvBin_Iter(ArvBin *raiz)
{
	struct NO *q;
	Fila* f = cria_Fila();
	
	insere_Fila(f, *raiz); // Insere raiz na fila
	int contEsq = 0;
	int contDir = 0;
	int alturaJaCalc;

	do {
		if (consulta_Fila(f, &q)) {
			remove_Fila(f); // Retira n� q da fila 
			alturaJaCalc = 0;
			if (q != NULL) {
				if (q->esq != NULL) {
					if (!alturaJaCalc) {
						contEsq++;
						alturaJaCalc = 1;
					}
				}

				insere_Fila(f, q->esq); // Insere sub�rvore esq. na fila

				if (q->dir != NULL) {
					if (!alturaJaCalc) {
						contDir++;
						alturaJaCalc = 1;
					}
				}
				insere_Fila(f, q->dir); // Insere sub�rvore dir. na fila             
			}
		}
	} while (!Fila_vazia(f));  

	if (contDir > contEsq)
		return contDir;
	else
		return contEsq;
}

int consulta_ArvBin(ArvBin *raiz, int valor, int *info) 
{
	if (raiz == NULL || *raiz == NULL)
		return 0;
	return consulta_ArvBin_rec(*raiz, valor, info);
}


int consulta_ArvBinIter(ArvBin *raiz, int valor, int *info)
{
	if (raiz == NULL)
		return 0;
	struct NO* atual = *raiz;

	while (atual != NULL) {
		if (valor == atual->info) {
			*info = atual->info;
			return 1;
		}
		if (valor > atual->info)
			atual = atual->dir;
		else
			atual = atual->esq;
	}
	return 0;
}

int consulta_ArvBin_rec(struct NO *raiz, int valor, int *info) 
{
	if (raiz == NULL)
		return 0;

	if (valor == raiz->info) {
		*info = raiz->info;
		return 1;
	}

	if (valor > raiz->info)
		return consulta_ArvBin_rec(raiz->dir, valor, info);
	else
		return consulta_ArvBin_rec(raiz->esq, valor, info);
}

/*Implementa��o das fun��es de consulta intervalar*/

int consultaIntervalarArvBinIter(ArvBin *raiz, int valor, int *info)
{
	if (raiz == NULL)
		return 0;
	struct NO* atual = *raiz;

	
	return 0;
}

int consultaIntervalarArvBinRec(struct NO *raiz, int valor, int *info) 
{
	if (raiz == NULL)
		return 0;


}


void preOrdem_ArvBin(ArvBin *raiz)
{
	if (raiz == NULL)
		return;

	if (*raiz != NULL) {
		printf("%d, ",(*raiz)->info);
		preOrdem_ArvBin(&((*raiz)->esq));
		preOrdem_ArvBin(&((*raiz)->dir));
	}
}

void emOrdem_ArvBin(ArvBin *raiz)
{
	if (raiz == NULL)
		return;

	if (*raiz != NULL) {
		emOrdem_ArvBin(&((*raiz)->esq));
		printf("%d, ",(*raiz)->info);
		emOrdem_ArvBin(&((*raiz)->dir));
	}
}

void posOrdem_ArvBin(ArvBin *raiz)
{
	if (raiz == NULL)
		return;

	if (*raiz != NULL) {
		posOrdem_ArvBin(&((*raiz)->esq));
		posOrdem_ArvBin(&((*raiz)->dir));
		printf("%d, ",(*raiz)->info);
	}
}

void visitaEmLargura(ArvBin *raiz)
{
	struct NO *q;
	Fila* f = cria_Fila(); // fila auxiliar
	insere_Fila(f, *raiz); // Insere raiz na fila
	do {
		if (consulta_Fila(f, &q)) {
			remove_Fila(f); // Retira n� q da fila
			if (q != NULL) { 
				printf("%d, ", q->info);
				insere_Fila(f, q->esq); // Insere sub-�rvore esq. na fila
				insere_Fila(f, q->dir); // Insere sub-�rvore dir. na fila
			}
		}
	} while (!Fila_vazia(f));  
}


void desenheArvore(ArvBin *raiz, char TipoArv)
{
	char separador[10];
	separador[0] = ' ';
	separador[1] = 192;
	separador[2] = 196;
	separador[3] = 196;
	separador[4] = '\0';

	strcpy(separador, " |__");

	if (raiz == NULL)
		return;

	if (*raiz == NULL) {
		printf("�rvore vazia!");
		return;
	}

	printf("Arvore Binaria de Busca:\n");
	printf("%i (R)\n", (*raiz)->info);
	desenheSubarvore(raiz, &((*raiz)->esq), 0, separador, TipoArv);
	desenheSubarvore(raiz, &((*raiz)->dir), 0, separador, TipoArv);
}

void desenheSubarvore(ArvBin *raizAbsoluta, ArvBin *raiz, int espacos, char separator[], char TipoArv)
{
	int e;
	struct NO *noPai;

	if (*raiz != NULL) {
		for (e=1; e<=espacos; e++)
			printf(" ");

		if (TipoArv == 'B')
			noPai = searchFather(raizAbsoluta, (*raiz)->info);
		else  // TipoArv == 'D'
			noPai = searchFatherEmLargura(raizAbsoluta, (*raiz)->info);


		if (noPai->esq == *raiz)
			printf("%s%d (E)\n", separator, (*raiz)->info);
		else
			printf("%s%d (D)\n", separator, (*raiz)->info);
		desenheSubarvore(raizAbsoluta, &((*raiz)->esq), espacos+4, separator, TipoArv);
		desenheSubarvore(raizAbsoluta, &((*raiz)->dir), espacos+4, separator, TipoArv);
	}
}

struct NO* searchFatherEmLargura(ArvBin *raiz, int valor)
{
	struct NO *noPai = NULL;
	struct NO *q;
	Fila* f = cria_Fila();
	insere_Fila(f, *raiz); // Insere raiz na fila
	
	do {
		if (consulta_Fila(f, &q)) {
			remove_Fila(f); // Retira n� q da fila
			if (q != NULL) {
				if (q->esq != NULL && q->esq->info == valor) {
					noPai = q;
					break;
				}
				insere_Fila(f, q->esq); /* insere sub-�rvore esq. na fila */

				if (q->esq != NULL && q->dir->info == valor) {
					noPai = q;
					break;
				}
				insere_Fila(f, q->dir); /* insere sub-�rvore dir. na fila */
			}
		}
	} while (!Fila_vazia(f));
	
	return noPai;
}

struct NO* searchFather(ArvBin *raiz, int el) 
{
	struct NO* p = *raiz;
	struct NO* prev = NULL; 

	while (p != NULL && p->info != el) {  // Localiza o n� p com a chave el
		prev = p;                           
		if (p->info < el)
			p = p->dir;
		else 
			p = p->esq;
	}
	if (p != NULL && p->info == el) {
		return prev;
	}

	return NULL;
}
