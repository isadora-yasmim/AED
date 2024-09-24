
#include <stdio.h>

#define MAXLOTES 9999999;
#define MAXFORNOS  5;
typedef struct dados_aco
{
	int forno;
	float PC;
	int dureza;
	int resistencia;
	int pureza;
} dado_aco;


int main() {
	int numlotes, i, resultado,teste1, teste2, teste3, lotes_por_forno, soma_pureza, maiorpureza,menorpureza,fornomenorpureza, fornomaiorpureza;
	float grau_medio_pureza;
	printf("\n\nEntre com o numero de lotes produzidos: ");
	scanf("%d", &numlotes);

	maiorpureza=0;
	menorpureza=0;
	dado_aco lotes[numlotes];

	printf("\n\nEntre com uma linha para cada lote produzido com os dados separados por um espaco em branco e na seguinte ordem: numero do forno, percentual de carbono (PC), dureza Rockwell (DR) e resistencia a tracao (RT)");

	for (i=0; i<numlotes; i++) {
		lotes[i].forno=0;
		lotes[i].PC=0.0;
		lotes[i].dureza=0;
		lotes[i].resistencia=0;
	}



	for (i=0; i<numlotes; i++) {
		printf("\nLote %d: ", i+1);
		scanf("%d %f %d %d",&lotes[i].forno, &lotes[i].PC, &lotes[i].dureza, &lotes[i].resistencia);
	}

	printf("\n\nGrau de pureza dos lotes produzidos");


	for (i=0; i<numlotes; i++) {

		teste1=0;
		teste2=0;
		teste3=0;

		if (lotes[i].PC<7) {
			teste1=1;
		}
		if (lotes[i].dureza>50) {
			teste2=1;
		}
		if (lotes[i].resistencia>80000) {
			teste3=1;
		}

		if (teste1==1 && teste2==1 && teste3==1) {
			resultado=10;
		} else if (teste1==1 && teste2==1 && teste3==0) {
			resultado=9;
		} else if (teste1==1 && teste3==1 && teste2==0) {
			resultado=8;
		} else if (teste2==1 && teste3==1 && teste1==0) {
			resultado=7;
		} else if(teste1==1 && teste2==0 && teste3==0) {
			resultado=6;
		} else if(teste1==0 && teste2==1 && teste3==0) {
			resultado=5;
		} else if(teste1==0 && teste2==0 && teste3==1) {
			resultado=4;
		} else if(teste1==0 && teste2==0 && teste3==0) {
			resultado=0;
		}

		printf("\nLote %d: %d", i+1, resultado);

		lotes[i].pureza = resultado;
		if (resultado>=maiorpureza) {
			maiorpureza= resultado;
		}
		if (resultado<=menorpureza) {
			menorpureza= resultado;
		}

	}



	printf("\n\nEstatisticas");

	lotes_por_forno=0;
	grau_medio_pureza=0.0;
	soma_pureza=0;

	for (i=0; i<5; i++) {
		if (lotes[i-1].forno==lotes[i].forno) {
			lotes_por_forno++;
			soma_pureza+=lotes[i].pureza;
		}
		if (lotes_por_forno > 0) {
			grau_medio_pureza = soma_pureza / lotes_por_forno;
		} else {
			grau_medio_pureza = 0;  // ou outro valor padrC#o apropriado
		}
		printf("\nForno %d: %d lote(s) com grau medio de pureza de %.1f", i+1, lotes_por_forno, grau_medio_pureza);
	}

	printf("\n\nFornos que produziram lote(s) com maior grau de pureza (grau %d): ", maiorpureza);

	for (i=0; i<numlotes; i++) {
		if (lotes[i].pureza==maiorpureza) {
			fornomaiorpureza= lotes[i].forno;
			printf("%d ", fornomaiorpureza);
		}

	}

	printf("\n\nFornos que produziram lote(s) com menor grau de pureza (grau %d): ", menorpureza);
	for (i=0; i<numlotes; i++) {
		if (lotes[i].pureza==menorpureza) {
			fornomenorpureza= lotes[i].forno;
			printf("%d ", fornomenorpureza);
		}

	}



	return 0;
}
