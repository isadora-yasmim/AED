/*Isadora Yasmim da Silva - 202403076*/

struct NO{
	int info;
	struct NO *esq;
	struct NO *dir;
};

typedef struct NO *ArvBin;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, int valor);
int insere_EmLargura(ArvBin *raiz, int valor);
void desenheArvore(ArvBin *raiz, char TipoArv);
void desenheSubarvore(ArvBin *raizAbsoluta, ArvBin *raiz, int espacos, char separator[], char TipoArv);
struct NO* searchFatherEmLargura(ArvBin *raiz, int el);
struct NO* searchFather (ArvBin *raiz, int el);
int remove_ArvBin(ArvBin *raiz, int valor);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBinIter(ArvBin *raiz, int valor, int *info);
int consulta_ArvBin(ArvBin *raiz, int valor, int *info);
int consulta_ArvBinRec(ArvBin *raiz, int valor, int *info);
int consulta_ArvBin_rec(struct NO *raiz, int valor, int *info);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);
void visitaEmLargura(ArvBin *raiz);
int totalNO_ArvBin_Iter(ArvBin *raiz);
int altura_ArvBin_Iter(ArvBin *raiz);

