#include <stdio.h>

int main(){
    float valorSaldo, novoSaldo, restoSaque;
    int valorSaque;
    int  cem, cinquenta,vinte, dez, cinco, dois;
    int  ncem, ncinquenta,nvinte, ndez, ncinco, ndois;
    do{
      printf("\n\nEntre com o saldo da conta a ser sacada (em reais): ");
      scanf("%f", &valorSaldo); 
      if(valorSaldo<=0){
          printf("\n\nValor do saldo invalido");
      }
    }while(valorSaldo<=0);
    
    do{
        printf("\n\nEntre com o valor do saque (em reais): ");
        if (scanf("%d", &valorSaque) != 1) {
            break;
        }else if (valorSaque>valorSaldo){
              printf("\n\nSaldo insuficiente para valor desejado");
              valorSaque=0;
        }else if(valorSaque<=0){
              printf("\n\nValor do saque invalido");
              valorSaque=0;
        }else if((valorSaque==1)||(valorSaque==3)){
            printf("\n\nValor do saque incompativel com notas disponiveis");
        }
        }while((valorSaque<=0)||(valorSaque>valorSaldo)||(valorSaque==1||valorSaque==3));
    
    
    if (valorSaque>0 ){
        
        novoSaldo=valorSaldo-valorSaque;
       
        
        //Opção 1 de saque(menor número de cédulas)
        
        cem = valorSaque/100;
        cinquenta = (valorSaque-100*cem)/50;
        vinte = (valorSaque-100*cem-50*cinquenta)/20;
        dez = (valorSaque-100*cem-50*cinquenta-20*vinte)/10;
        cinco = (valorSaque-100*cem-50*cinquenta-20*vinte-10*dez)/5;
        dois = (valorSaque-100*cem-50*cinquenta-20*vinte-10*dez-5*cinco)/2;
        
        
        
        //Opção 2 de saque(maior número de cédulas)
        if(valorSaque%2==0){
          ndois= valorSaque/2;
        }else {
            ndois= (valorSaque-5)/2;
            ncinco= (valorSaque-2*ndois)/5;
            ndez=(valorSaque-2*ndois-5*ncinco)/10;
            nvinte=(valorSaque-2*ndois-5*ncinco- 10*ndez)/20;
            ncinquenta=(valorSaque-2*ndois-5*ncinco- 10*ndez-20*nvinte)/50;
            ncem=(valorSaque-2*ndois-5*ncinco- 10*ndez-20*nvinte-50*ncinquenta)/100;
        }
        //ncinco= (valorSaque-2*ndois)/5;
        //ndez=(valorSaque-2*ndois-5*ncinco)/10;
        //nvinte=(valorSaque-2*ndois-5*ncinco- 10*ndez)/20;
        //ncinquenta=(valorSaque-2*ndois-5*ncinco- 10*ndez-20*nvinte)/50;
       // ncem=(valorSaque-2*ndois-5*ncinco- 10*ndez-20*nvinte-50*ncinquenta)/100;
        
        
        printf("\n\n\n\nRESULTADOS");
        printf("\n\nValor atualizado do saldo (em reais): %.2f", novoSaldo);
        printf("\n\n\n\nOpcao de saque 1 (menor quantidade possivel de cedulas):");
        
        if (cem>0){
            printf("\n\nCedulas de 100 reais: %d", cem);
        }
        if (cinquenta>0){
            printf("\n\nCedulas de 50 reais: %d", cinquenta);
        }
        if (vinte>0){
            printf("\n\nCedulas de 20 reais: %d", vinte);
        }
        if (dez>0){
            printf("\n\nCedulas de 10 reais: %d", dez);
        }
        if (cinco>0){
            printf("\n\nCedulas de 5 reais: %d", cinco);
        }
        if (dois>0){
            printf("\n\nCedulas de 2 reais: %d", dois);
        }
        
        
        
        printf("\n\n\n\nOpcao de saque 2 (maior quantidade possivel de cedulas):");
        
        if (ndois>0){
            printf("\n\nCedulas de 2 reais: %d", ndois);
        }
        if (ncinco>0){
            printf("\n\nCedulas de 5 reais: %d", ncinco);
        }
        if (ndez>0){
            printf("\n\nCedulas de 10 reais: %d", ndez);
        }
        if (nvinte>0){
            printf("\n\nCedulas de 20 reais: %d", nvinte);
        }
        if (ncinquenta>0){
            printf("\n\nCedulas de 50 reais: %d", ncinquenta);
        }
        if (ndez>0){
            printf("\n\nCedulas de 100 reais: %d", ndez);
        }
    }
    
    return 0;
}