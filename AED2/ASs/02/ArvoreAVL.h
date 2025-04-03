
typedef struct NO* ArvAVL;

ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);
//int insere_ArvAVL(ArvAVL *raiz, int data);
int insere_ArvAVL(ArvAVL *raiz, char *data);
//int remove_ArvAVL(ArvAVL *raiz, int valor);
int remove_ArvAVL(ArvAVL *raiz, char *valor);
int estaVazia_ArvAVL(ArvAVL *raiz);
int altura_ArvAVL(ArvAVL *raiz);
int totalNO_ArvAVL(ArvAVL *raiz);
//int consulta_ArvAVL(ArvAVL *raiz, int valor);
int consulta_ArvAVL(ArvAVL *raiz, char *valor);
void preOrdem_ArvAVL(ArvAVL *raiz);
void emOrdem_ArvAVL(ArvAVL *raiz);
void posOrdem_ArvAVL(ArvAVL *raiz);

// 26/03/2025 - 18h14
void desenheArvore(ArvAVL *raiz, char TipoArv);
void desenheSubarvore(ArvAVL *raizAbsoluta, ArvAVL *raiz, int espacos, char separator[], char TipoArv);
//struct NO* searchFatherEmLargura(ArvAVL *raiz, int el);
struct NO* searchFatherEmLargura(ArvAVL *raiz, char *el);
//struct NO* searchFather (ArvAVL *raiz, int el);
struct NO* searchFather (ArvAVL *raiz, char *el);
