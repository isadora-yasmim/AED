#include <stdio.h>

int main() {
	int ano,mes,i,j=0,valor=0,contagemTempMax=31,diasComTempMax[contagemTempMax], tempMaxima=0, somaTemperaturas=0;
	float mediaTemperaturas;
	printf("\n\nEntre com o ano da medicao das temperaturas: ");
	scanf("%d", &ano);
	while ((ano<2000)||(ano>2024)){
	    printf("\n\nAno deve ser maior ou igual a 2000 e menor ou igual a 2024");
	    printf("\n\nEntre com o ano da medicao das temperaturas: ");
	    scanf("%d", &ano);
	}
	printf("\n\nEntre com o mes da medicao das temperaturas: ");
	scanf("%d", &mes);
	while ((mes<1)||(mes>12)){
	    printf("\n\nMes deve ser maior do que zero e menor ou igual a 12");
    	printf("\n\nEntre com o mes da medicao das temperaturas: ");
	    scanf("%d", &mes);
	}

	printf("\n\nTemperaturas medidas (em graus Celsius):");

	if ((mes==1)||(mes==3)||(mes==5)||(mes==7)||(mes==8)||(mes==10)||(mes==12)) {
	    //meses com 31 dias
		int dia[31];
		for(i=0; i<31; i++) {
			printf("\n\nDia %d: ", i+1);
			scanf("%d", &dia[i]);
			while((dia[i]<-70)||(dia[i]>60)){
			    printf("\n\nTemperatura deve ser maior ou igual a -70 graus e menor ou igual a 60 graus");
			    printf("\n\nDia %d: ", i+1);
			    scanf("%d", &dia[i]);
			}
			somaTemperaturas+=dia[i];
			if (dia[i]>tempMaxima) {
				tempMaxima=dia[i];
				int valor = 0; // Valor para inicialização
                for (int i = 0; i < 31; i++) {
                    diasComTempMax[i] = valor;
                }
			    diasComTempMax[j++] = i + 1;  // Armazenar o primeiro dia com a nova máxima
    		} else {
    		    if (dia[i] == tempMaxima) {
    			diasComTempMax[j++] = i + 1;  // Armazenar dias adicionais com a mesma máxima
    		    }
			}
		}
		mediaTemperaturas=(float)somaTemperaturas/31;
		printf("\n\nA maior temperatura maxima do mes foi de %d e aconteceu nos dias: ", tempMaxima);
		for (i = 0; i < contagemTempMax; i++) {
		    if (diasComTempMax[i]!= 0){
            printf("%d ", diasComTempMax[i]);
		    }
        }
		printf("\n\nA temperatura maxima media no mes foi de: %.1f graus Celsius", mediaTemperaturas);
	} else {
	    //meses com 30 dias
		if((mes==4)||(mes==6)||(mes==9)||(mes==11)) {
			int dia[30];
			for(i=0; i<30; i++) {
				printf("\n\nDia %d: ", i+1);
				scanf("%d", &dia[i]);
				while((dia[i]<-70)||(dia[i]>60)){
    			    printf("\n\nTemperatura deve ser maior ou igual a -70 graus e menor ou igual a 60 graus");
    			    printf("\n\nDia %d: ", i+1);
    			    scanf("%d", &dia[i]);
    			}
				somaTemperaturas+=dia[i];
				if (dia[i]>tempMaxima) {
				tempMaxima=dia[i];
				for (int i = 0; i < 30; i++) {
                    diasComTempMax[i] = valor;
                }
			    diasComTempMax[j++] = i + 1;  // Armazenar o primeiro dia com a nova máxima
        		} else {
        		    if (dia[i] == tempMaxima) {
        			diasComTempMax[j++] = i + 1;  // Armazenar dias adicionais com a mesma máxima
        		    }
    			}
			}
			mediaTemperaturas=(float)somaTemperaturas/30;
			printf("\n\nA maior temperatura maxima do mes foi de %d e aconteceu nos dias: ", tempMaxima);
			for (i = 0; i < contagemTempMax; i++) {
                if (diasComTempMax[i]!= 0){
                printf("%d ", diasComTempMax[i]);
                }
            }
			printf("\n\nA temperatura maxima media no mes foi de: %.1f graus Celsius", mediaTemperaturas);

		} else {
			//fevereiro em ano bissexto
			if ((mes==2)&&(ano%4==0)){
    			int dia[29];
    			for(i=0; i<29; i++) {
    				printf("\n\nDia %d: ", i+1);
    				scanf("%d", &dia[i]);
    				while((dia[i]<-70)||(dia[i]>60)){
        			    printf("\n\nTemperatura deve ser maior ou igual a -70 graus e menor ou igual a 60 graus");
        			    printf("\n\nDia %d: ", i+1);
        			    scanf("%d", &dia[i]);
        			}
    				somaTemperaturas+=dia[i];
    				if (dia[i]>tempMaxima) {
        				tempMaxima=dia[i];
        				for (int i = 0; i < 29; i++) {
                            diasComTempMax[i] = valor;
                        }
    			        diasComTempMax[j++] = i + 1;  // Armazenar o primeiro dia com a nova máxima
            		} else {
            		    if (dia[i] == tempMaxima) {
            			diasComTempMax[j++] = i + 1;  // Armazenar dias adicionais com a mesma máxima
            		    }
        			}
    			}
    			mediaTemperaturas=(float)somaTemperaturas/29;
    			printf("\n\nA maior temperatura maxima do mes foi de %d e aconteceu nos dias: ", tempMaxima);
    			for (i = 0; i < contagemTempMax; i++) {
                    if (diasComTempMax[i]!= 0){
                    printf("%d ", diasComTempMax[i]);
                    }
                }
    			printf("\n\nA temperatura maxima media no mes foi de: %.1f graus Celsius", mediaTemperaturas);
    		}else{
		    //fevereiro em ano não bissexto
		    if (mes==2){
			int dia[28];
			for(i=0; i<28; i++) {
				printf("\n\nDia %d: ", i+1);
				scanf("%d", &dia[i]);
				while((dia[i]<-70)||(dia[i]>60)){
    			    printf("\n\nTemperatura deve ser maior ou igual a -70 graus e menor ou igual a 60 graus");
    			    printf("\n\nDia %d: ", i+1);
    			    scanf("%d", &dia[i]);
    			}
				somaTemperaturas+=dia[i];
				if (dia[i]>tempMaxima) {
				tempMaxima=dia[i];
				for (int i = 0; i < 28; i++) {
                    diasComTempMax[i] = valor;
                }
			    diasComTempMax[j++] = i + 1;  // Armazenar o primeiro dia com a nova máxima
        		} else {
        		    if (dia[i] == tempMaxima) {
        			diasComTempMax[j++] = i + 1;  // Armazenar dias adicionais com a mesma máxima
        		    }
    			}
			}
			mediaTemperaturas=(float)somaTemperaturas/28;
			printf("\n\nA maior temperatura maxima do mes foi de %d e aconteceu nos dias: ", tempMaxima);
			for (i = 0; i < contagemTempMax; i++) {
                if (diasComTempMax[i]!= 0){
                printf("%d ", diasComTempMax[i]);
                }
            }
			printf("\n\nA temperatura maxima media no mes foi de: %.1f graus Celsius", mediaTemperaturas);
    		}
		}
	}
	}


	return 0;
}