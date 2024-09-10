#include <stdio.h>
#include <stdlib.h>
#include <float.h>

// comparação para ordenar em ordem decrescente
int compare(const void *a, const void *b) {
    float f1 = *(const float *)a;
    float f2 = *(const float *)b;
    if (f1 > f2) return 1;
    else if (f1 < f2) return -1;
    else return 0;
}

#define NUM_NOTAS 4

// Verificar se todas as notas estão no intervalo válido
int notas_invalidas(float notas[], int num_notas) {
    for (int i = 0; i < num_notas; i++) {
        if (notas[i] < 0.0 || notas[i] >= 10.0) {
            return 1; 
        }
    }
    return 0; 
}

// Função para limpar o buffer de entrada
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}  // Consumir caracteres até o final da linha ou EOF
}

int main() {
    int TotAlunos;
    printf("\n\nEntre com o numero de alunos da turma: ");
    scanf("%d", &TotAlunos);
    while((TotAlunos<=0)||(TotAlunos>50)){
        printf("\n\nO numero de alunos na turma deve ser maior do que zero e menor ou igual a 50");
        printf("\n\nEntre com o numero de alunos da turma: ");
        scanf("%d", &TotAlunos);
    }
    
    float notas[NUM_NOTAS];
    double mediasAlunos[TotAlunos];
    float  somaMedias=0.0, mediaGeral=0.0, maiorMedia=0.0, menorMedia=9.9;
    int tipo=0,j=0, w=0 ,alunosMaiorMedia[TotAlunos], alunosMenorMedia[TotAlunos], i;
    
    notas[0]= -1.0;
    notas[1]= -1.0;
    notas[2]= -1.0;
    notas[3]= -1.0;
    
    for(i=0;i<TotAlunos;i++){
        do {
        printf("\n\nNotas aluno %d: ", i + 1);
        if (scanf("%f%f%f%f", &notas[0], &notas[1], &notas[2], &notas[3]) != 4) {
            limpar_buffer();  // Limpar o buffer após entrada inválida
        } else if (notas_invalidas(notas, NUM_NOTAS)) {
            printf("\n\nTodas as notas do aluno devem ser maiores ou iguais a zero e menores ou iguais a 10");
        }
    } while (notas_invalidas(notas, NUM_NOTAS));
        qsort(notas, 4, sizeof(float), compare);
        //printf("%f%f%f%f", notas[0], notas[1], notas[2], notas[3]);
       
        //indentificar qual média deve ser feita
        if((notas[2]!= notas[3])&&(notas[1]!=notas[0])){
            tipo= 4;
        }
        if ((notas[0]!= notas[1])&&(notas[2]==notas[3])){
            tipo=5;
        }
        if ((notas[0]== notas[1])&&(notas[2]!=notas[3])){
            tipo=6;
        }
        
        if((notas[2]== notas[1])&&(notas[1]!=notas[0])&&(notas[2]==notas[3])){
            tipo= 2;
        }
        if((notas[2]!= notas[3])&&(notas[1]==notas[2])&&(notas[1]==notas[0])){
            tipo= 1;
        }
        if((notas[2]== notas[3])&&(notas[1]==notas[0])){
            tipo= 3;
        }
       
        switch(tipo){
            case 1:
                // 1 maior e 3 iguais
                mediasAlunos[i]=((notas[3]*4.0)+(notas[2]*2.0)+(notas[1]*2.0)+(notas[0]*2.0))/10.0;
                printf("\nMedia final do aluno %d: %.1f",i+1,mediasAlunos[i]);
                break;
            case 2:
                //1 menor e 3 iguais
                mediasAlunos[i]=((notas[0]*1.0)+(notas[1]*3.0)+(notas[2]*3.0)+(notas[3]*3.0))/10.0;
                printf("\nMedia final do aluno %d: %.1f",i+1,mediasAlunos[i]);
                break;
            case 3:
                //Todas as notas iguais
                mediasAlunos[i]=((notas[0]*2.5)+(notas[1]*2.5)+(notas[2]*2.5)+(notas[3]*2.5))/10.0;
                printf("\nMedia final do aluno %d: %.1f",i+1,mediasAlunos[i]);
                break;
            case 4:
                //Todas diferentes
                mediasAlunos[i]=((notas[0]*1.0)+(notas[1]*2.0)+(notas[2]*3.0)+(notas[3]*4.0))/10.0;
                printf("\nMedia final do aluno %d: %.1f",i+1,mediasAlunos[i]);
                break;
            case 5:
                //Havendo 2 maiores iguais e 2 menores diferentes
                mediasAlunos[i]=((notas[0]*1.0)+(notas[1]*2.0)+(notas[2]*3.0)+(notas[3]*3.8))/10.0;
                printf("\nMedia final do aluno %d: %.1f",i+1,mediasAlunos[i]);
                break;
            case 6:
                //Havendo 2 menores iguais e 2 maiores diferentes
                mediasAlunos[i]=((notas[0]*1.0)+(notas[1]*2.0)+(notas[2]*3.0)+(notas[3]*3.75))/10.0;
                printf("\nMedia final do aluno %d: %.1f",i+1,mediasAlunos[i]);
                break;
        }
        somaMedias+=mediasAlunos[i];
        
        if (mediasAlunos[i]>maiorMedia){
            maiorMedia= mediasAlunos[i];
            for(int i = 0; i<TotAlunos; i++){
                 alunosMaiorMedia[i]=0;
            }
            alunosMaiorMedia[j++]=i+1;
        }else{
            if(mediasAlunos[i]==maiorMedia){
                alunosMaiorMedia[j++]=i+1;
            }
        }
        
        if(mediasAlunos[i]==menorMedia){
            alunosMenorMedia[w++]=i+1;
        }else{
            if (mediasAlunos[i]<menorMedia){
            menorMedia= mediasAlunos[i];
            for(int i = 0; i<TotAlunos; i++){
                 alunosMenorMedia[i]=0;
            }
            alunosMenorMedia[w++]=i+1;
            }
        }
            
            
        
        
    }
    
    mediaGeral=somaMedias/(float)TotAlunos;
    printf("\n\nMedia geral da turma: %.1f", mediaGeral);
    printf("\n\nMaior media da turma: %.1f (Alunos:", maiorMedia);
    for (i = 0; i < TotAlunos; i++) {
        if (TotAlunos==1){
            printf(" 1"); 
        }else{
		    if (alunosMaiorMedia[i]!= 0){
            printf(" %d", alunosMaiorMedia[i]);
		    }
        }
    }
    printf(")");

    printf("\n\nMenor media da turma: %.1f (Alunos:", menorMedia);
    for (i = 0; i < TotAlunos; i++) {
        if (TotAlunos==1){
            printf(" 1"); 
        }else{
		    if (alunosMenorMedia[i]!= 0){
            printf(" %d", alunosMenorMedia[i]);
		    }
        }
    }
    printf(")");
    


    return 0;
}