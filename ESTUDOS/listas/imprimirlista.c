//imprimir uma lista encadeada em c

#include <stdio.h>

//definindo a lista
typedef struct nó{
    int valor;
    struct nó *proximo;
}Nó;

//procedimento para inserir um elemento no inicio da lista

void Inserir_no_inicio (Nó **lista,  int num){
    //-----------------Nó **lista---- os dois * significam que estamos usando ponteiro com ponteiro, ou seja, apenas os endereços

    Nó *novo = malloc(sizeof(Nó));
    //Nó *novo = malloc(sizeof(Nó));------Alocação de memória para o novo nó que está sendo inserido

    if(novo){//if(novo)----se houver algum valor em "novo", então-verdadeiro
        //verifica se a alocação ocorreu de maneira correta, para evitar erro de memória

        novo-> valor = num;//o valor do novo nó é o num que colocamos como parÂmetro lá no início da função
        novo->proximo = *lista;//o próximo valor é o início da lista(o que acabamos de inserir assume a primeira posição e o que estava em primeiro vai para próximo)
        *lista = novo;//o início da lista atual passa a ser o novo nó
    }else{
        printf("Erro ao alocar memória!\n");
    }
}

int main () {

    
}