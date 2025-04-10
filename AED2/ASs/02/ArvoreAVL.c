#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreAVL.h" //inclui os Prot�tipos
#include "Fila.h"

struct NO {
    //int info;
    char *info;
    int altura;
    struct NO *esq;
    struct NO *dir;
};

ArvAVL* cria_ArvAVL(){
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvAVL(ArvAVL* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada n�
    free(raiz);//libera a raiz
}

int altura_NO(struct NO* no){
    if(no == NULL)
        return -1;
    else
    return no->altura;
}

int fatorBalanceamento_NO(struct NO* no){
    return labs(altura_NO(no->esq) - altura_NO(no->dir));
}

int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

int estaVazia_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

void preOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        //printf("%d\n",(*raiz)->info);
        //printf("No %d: %d\n",(*raiz)->info,fatorBalanceamento_NO(*raiz));
        printf("No %s: %d\n",(*raiz)->info, altura_NO(*raiz));
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void emOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvAVL(&((*raiz)->esq));
        printf("%s ",(*raiz)->info);
        //printf("No %d: H(%d) fb(%d)\n",(*raiz)->info,altura_NO(*raiz),fatorBalanceamento_NO(*raiz));
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void posOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        printf("%s ", (*raiz)->info);
    }
}

//int consulta_ArvAVL(ArvAVL *raiz, int valor){
int consulta_ArvAVL(ArvAVL *raiz, char *valor) {
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        //if (valor == atual->info){
		  if (strcmp(valor, atual->info) == 0) {
            return 1;
        }
        //if (valor > atual->info)
        if (strcmp(valor, atual->info) > 0)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

//=================================
void RotacaoLL(ArvAVL *A){//LL
    //printf("RotacaoLL\n");
    struct NO *B;
    B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = *A;
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->esq),(*A)->altura) + 1;
    *A = B;
}

void RotacaoRR(ArvAVL *A){//RR
    //printf("RotacaoRR\n");
    struct NO *B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->dir),(*A)->altura) + 1;
    (*A) = B;
}

void RotacaoLR(ArvAVL *A){//LR
    RotacaoRR(&(*A)->esq);
    RotacaoLL(A);
}

void RotacaoRL(ArvAVL *A){//RL
    RotacaoLL(&(*A)->dir);
    RotacaoRR(A);
}

//int insere_ArvAVL(ArvAVL *raiz, int valor) {
int insere_ArvAVL(ArvAVL *raiz, char *valor) {
    int res;
    if(*raiz == NULL){//�rvore vazia ou n� folha
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL)
            return 0;

        //novo->info = valor;
        novo->info = strdup(valor);
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;
    //if (valor < atual->info){
	 if (strcmp(valor, atual->info) < 0) {
        if ((res = insere_ArvAVL(&(atual->esq), valor)) == 1){
            if (fatorBalanceamento_NO(atual) >= 2){
                //if (valor < (*raiz)->esq->info ) {
					 if (strcmp(valor, (*raiz)->esq->info) < 0) {
                    RotacaoLL(raiz);
                }
					 else {
                    RotacaoLR(raiz);
                }
            }
        }
    }
	 else {
        //if (valor > atual->info){
		  if (strcmp(valor, atual->info) > 0){
            if((res = insere_ArvAVL(&(atual->dir), valor)) == 1){
                if(fatorBalanceamento_NO(atual) >= 2){
                    //if ((*raiz)->dir->info < valor) {
						  if (strcmp((*raiz)->dir->info, valor) < 0){
                        RotacaoRR(raiz);
                    }
						  else {
                        RotacaoRL(raiz);
                    }
                }
            }
        }
		  else {
            printf("Valor duplicado!!\n");
            return 0;
        }
    }

    atual->altura = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;

    return res;
}

struct NO* procuraMenor(struct NO* atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

//int remove_ArvAVL(ArvAVL *raiz, int valor)
int remove_ArvAVL(ArvAVL *raiz, char *valor)
{
	if (*raiz == NULL){// valor n�o existe
	    printf("valor n�o existe!!\n");
	    return 0;
	}

   int res;
	//if (valor < (*raiz)->info) {
	if (strcmp(valor, (*raiz)->info) < 0) {
	    if ((res = remove_ArvAVL(&(*raiz)->esq,valor)) == 1){
            if (fatorBalanceamento_NO(*raiz) >= 2){
                if (altura_NO((*raiz)->dir->esq) <= altura_NO((*raiz)->dir->dir))
                    RotacaoRR(raiz);
                else
                    RotacaoRL(raiz);
            }
	    }
	}

	// if((*raiz)->info < valor) {
	if (strcmp((*raiz)->info, valor) < 0) {
	    if((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1){
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq) )
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
	    }
	}

	//if((*raiz)->info == valor) {
	if (strcmp((*raiz)->info, valor) == 0) {
	    if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)) {// n� tem 1 filho ou nenhum
			struct NO *oldNode = (*raiz);
			if((*raiz)->esq != NULL)
      		*raiz = (*raiz)->esq;
         else
         	*raiz = (*raiz)->dir;
			free(oldNode);
		}
		else { // n� tem 2 filhos
			struct NO* temp = procuraMenor((*raiz)->dir);
			//(*raiz)->info = temp->info;
			(*raiz)->info = strdup(temp->info);
			remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);
         if (fatorBalanceamento_NO(*raiz) >= 2) {
				if (altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq))
					RotacaoLL(raiz);
				else
					RotacaoLR(raiz);
			}
		}
		if (*raiz != NULL)
      	(*raiz)->altura = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;
		return 1;
	}

	(*raiz)->altura = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;

	return res;
}


// 26/03/2025 - 18h15
void desenheArvore(ArvAVL *raiz, char TipoArv)
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

	//printf("Arvore AVL:\n");
	printf("%s (R)\n", (*raiz)->info);
	desenheSubarvore(raiz, &((*raiz)->esq), 0, separador, TipoArv);
	desenheSubarvore(raiz, &((*raiz)->dir), 0, separador, TipoArv);
}

void desenheSubarvore(ArvAVL *raizAbsoluta, ArvAVL *raiz, int espacos, char separator[], char TipoArv)
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
			printf("%s%s (E)\n", separator, (*raiz)->info);
		else
			printf("%s%s (D)\n", separator, (*raiz)->info);
		desenheSubarvore(raizAbsoluta, &((*raiz)->esq), espacos+4, separator, TipoArv);
		desenheSubarvore(raizAbsoluta, &((*raiz)->dir), espacos+4, separator, TipoArv);
	}
}


//struct NO* searchFatherEmLargura(ArvAVL *raiz, int valor)
struct NO* searchFatherEmLargura(ArvAVL *raiz, char *valor)
{
	struct NO *noPai = NULL;
	struct NO *q;
	Fila* f = cria_Fila();
	insere_Fila(f, *raiz); // Insere raiz na fila
	
	do {
		if (consulta_Fila(f, &q)) {
			remove_Fila(f); // Retira n� q da fila
			if (q != NULL) {
				//if (q->esq != NULL && q->esq->info == valor) {
				if (q->esq != NULL && strcmp(q->esq->info, valor) == 0) {
					noPai = q;
					break;
				}
				insere_Fila(f, q->esq); /* insere sub-�rvore esq. na fila */

				//if (q->esq != NULL && q->dir->info == valor) {
				if (q->esq != NULL && strcmp(q->dir->info, valor) == 0) {
					noPai = q;
					break;
				}
				insere_Fila(f, q->dir); /* insere sub-�rvore dir. na fila */
			}
		}
	} while (!Fila_vazia(f));
	
	return noPai;
}

//struct NO* searchFather(ArvAVL *raiz, int el) 
struct NO* searchFather(ArvAVL *raiz, char *el) 
{
	struct NO* p = *raiz;
	struct NO* prev = NULL; 

	//while (p != NULL && p->info != el) {  // Localiza o n� p com a chave el
	while (p != NULL && strcmp(p->info, el) != 0) {  // Localiza o n� p com a chave el	
		prev = p;                           
		//if (p->info < el)
		if (strcmp(p->info, el) < 0)
			p = p->dir;
		else 
			p = p->esq;
	}
	//if (p != NULL && p->info == el) {
	if (p != NULL && strcmp(p->info, el) == 0) {
		return prev;
	}

	return NULL;
}
