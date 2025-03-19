#include <stdio.h>
#include <stdlib.h>

// Função para verificar se um elemento pertence a um conjunto
int pertence(int lista[], int tamanho, int elemento) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == elemento) {
            return 1;
        }
    }
    return 0;
}

// Função para calcular a união de dois conjuntos
int uniao(int A[], int NUM_A, int B[], int NUM_B, int resultado[]) {
    int tamanho = 0;

    // Adiciona todos os elementos de A
    for (int i = 0; i < NUM_A; i++) {
        resultado[tamanho++] = A[i];
    }

    // Adiciona os elementos de B que não estão em A
    for (int i = 0; i < NUM_B; i++) {
        if (!pertence(A, NUM_A, B[i])) {
            resultado[tamanho++] = B[i];
        }
    }

    return tamanho;
}

// Função para calcular a interseção de dois conjuntos
int intersecao(int A[], int NUM_A, int B[], int NUM_B, int resultado[]) {
    int tamanho = 0;

    for (int i = 0; i < NUM_A; i++) {
        if (pertence(B, NUM_B, A[i])) {
            resultado[tamanho++] = A[i];
        }
    }

    return tamanho;
}

// Função para calcular a diferença entre dois conjuntos (A - B)
int diferenca(int A[], int NUM_A, int B[], int NUM_B, int resultado[]) {
    int tamanho = 0;

    for (int i = 0; i < NUM_A; i++) {
        if (!pertence(B, NUM_B, A[i])) {
            resultado[tamanho++] = A[i];
        }
    }

    return tamanho;
}

// Função para ler um conjunto de números
int lerConjunto(int lista[], int tamanho) {
    int elementosLidos = 0;
    for (int i = 0; i < tamanho; i++) {
        if (scanf("%d", &lista[i]) == 1) {
            elementosLidos++;
        }
    }
    return elementosLidos;
}

// Função para verificar se há elementos repetidos
int verificarRepetidos(int lista[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (lista[i] == lista[j]) {
                return 1;  // Encontrou um elemento repetido
            }
        }
    }
    return 0;  // Não há repetidos
}

// Função para imprimir um conjunto
void imprimirConjunto(int lista[], int tamanho) {
    if (tamanho == 0) {
        printf("\n\nvazio");
    } else {
        for (int i = 0; i < tamanho; i++) {
            printf("%d ", lista[i]);
        }
    }
    printf("\n");
}

int main() {
    int NUM_A, NUM_B, elementosLidos;
    int *A = NULL, *B = NULL;

    // Leitura do conjunto A
    do {
        printf("\n\nEntre com o numero de elementos do conjunto A: ");
        scanf("%d", &NUM_A);
        if (NUM_A <= 0) {
            printf("\n\nO numero de elementos do conjunto A deve ser maior do que zero");
        }
    } while (NUM_A <= 0);

    A = (int *)malloc(NUM_A * sizeof(int));

    do {
        printf("\n\nEntre com os elementos do conjunto A: ");
        elementosLidos = lerConjunto(A, NUM_A);
        if (elementosLidos != NUM_A) {
            printf("\n\nO conjunto nao pode ter elementos repetidos");
        } else if (verificarRepetidos(A, NUM_A)) {
            printf("\n\nO conjunto nao pode ter elementos repetidos");
        }
    } while (elementosLidos != NUM_A || verificarRepetidos(A, NUM_A));

    // Leitura do conjunto B
    do {
        printf("\n\nEntre com o numero de elementos do conjunto B: ");
        scanf("%d", &NUM_B);
        if (NUM_B <= 0) {
            printf("\n\nO numero de elementos do conjunto B deve ser maior do que zero");
        }
    } while (NUM_B <= 0);

    B = (int *)malloc(NUM_B * sizeof(int));

    do {
        printf("\n\nEntre com os elementos do conjunto B: ");
        elementosLidos = lerConjunto(B, NUM_B);
        if (elementosLidos != NUM_B) {
            printf("\n\nO conjunto nao pode ter elementos repetidos");
        } else if (verificarRepetidos(B, NUM_B)) {
            printf("\n\nO conjunto nao pode ter elementos repetidos");
        }
    } while (elementosLidos != NUM_B || verificarRepetidos(B, NUM_B));

    // Arrays para armazenar os resultados
    int uniaoAB[NUM_A + NUM_B], intersecaoAB[NUM_A], diferencaAB[NUM_A], diferencaBA[NUM_B];

    // Cálculo da união, interseção e diferenças
    int tamUniao = uniao(A, NUM_A, B, NUM_B, uniaoAB);
    int tamIntersecao = intersecao(A, NUM_A, B, NUM_B, intersecaoAB);
    int tamDiferencaAB = diferenca(A, NUM_A, B, NUM_B, diferencaAB);
    int tamDiferencaBA = diferenca(B, NUM_B, A, NUM_A, diferencaBA);

    // Imprimindo os resultados
    printf("\n\nConjunto uniao: ");
    imprimirConjunto(uniaoAB, tamUniao);

    printf("\n\nConjunto interseccao: ");
    imprimirConjunto(intersecaoAB, tamIntersecao);

    printf("\n\nConjunto diferenca entre A e B: ");
    imprimirConjunto(diferencaAB, tamDiferencaAB);

    printf("\n\nConjunto diferenca entre B e A: ");
    imprimirConjunto(diferencaBA, tamDiferencaBA);

    // Liberação da memória
    free(A);
    free(B);

    return 0;
}
