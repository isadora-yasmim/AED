#include <stdio.h>
#include <stdlib.h>

#define MAX_TIMES 100
#define MAX_JOGOS 10000  

int main() {
	int n;  // Numero de times
	do {
		printf("\n\nEntre com o numero de times participantes: ");
		scanf("%d", &n);
		if(n<2) {
			printf("\n\nNumero de times participantes deve ser maior ou igual a 2");
		}
	} while(n<2);

	// Matrizes para armazenar os resultados dos jogos
	int vitorias[MAX_TIMES] = {0};    //vitorias de cada time
	int derrotas[MAX_TIMES] = {0};    //derrotas de cada time
	int empates[MAX_TIMES] = {0};     //empates de cada time

	int maxDiff = 0;  // maior diferenca de gols
	int jogosMaxDiff[MAX_JOGOS][2];  //jogos com a maior diferenca de gols
	int numJogosMaxDiff = 0;  //contador de jogos com maior diferenca de gols

	for (int mandante = 1; mandante <= n; mandante++) {
		for (int visitante = 1; visitante <= n; visitante++) {
			if (mandante != visitante) {
				int golsMandante, golsVisitante;
				do {
					printf("\n\nPlacar time%d x time%d: ", mandante, visitante);
					scanf("%d %d", &golsMandante, &golsVisitante);
					if ((golsVisitante<0)||(golsMandante<0)) {
						printf("\n\nNumero de gols de cada time no placar deve ser maior ou igual a zero");
					}
				} while((golsVisitante<0)||(golsMandante<0));
				
				if (golsMandante > golsVisitante) {
					vitorias[mandante - 1]++;
					derrotas[visitante - 1]++;
				} else if (golsMandante < golsVisitante) {
					vitorias[visitante - 1]++;
					derrotas[mandante - 1]++;
				} else if(golsMandante == golsVisitante) {
					empates[mandante - 1]++;
					empates[visitante - 1]++;
				}



				// diferenca de gols
				int diff = abs(golsMandante - golsVisitante);
				if (diff > maxDiff) {
					// se uma nova maior diferenca for encontrada, reseta a lista
					maxDiff = diff;
					numJogosMaxDiff = 0;
					jogosMaxDiff[numJogosMaxDiff][0] = mandante;
					jogosMaxDiff[numJogosMaxDiff][1] = visitante;
					numJogosMaxDiff++;
				} else if (diff == maxDiff) {
					// Se a diferenca for igual a maior encontrada, adiciona o jogo na lista
					jogosMaxDiff[numJogosMaxDiff][0] = mandante;
					jogosMaxDiff[numJogosMaxDiff][1] = visitante;
					numJogosMaxDiff++;
				}
			}
		}
	}

	//encontrar os times com mais vitorias, derrotas e empates
	int maxVitorias = 0, maxDerrotas = 0, maxEmpates = 0;

	for (int i = 0; i < n; i++) {
		if (vitorias[i] > maxVitorias) maxVitorias = vitorias[i];
		if (derrotas[i] > maxDerrotas) maxDerrotas = derrotas[i];
		if (empates[i] > maxEmpates) maxEmpates = empates[i];
	}

	// imprime times com mais vitorias
	printf("\n\nTime(s) com mais vitorias:");
	if(maxVitorias==0) {
		printf(" nao houve vitorias");
	}else{
    	for (int i = 0; i < n; i++) {
    		if (vitorias[i] == maxVitorias) {
    			printf(" %d ", i + 1);
    		}
    	}
    	printf(" com %d vitoria(s)", maxVitorias);
	}

	// imprime times com mais derrotas
	printf("\n\nTime(s) com mais derrotas:");
	if(maxDerrotas==0) {
		printf(" nao houve derrotas");
	}else{
    	for (int i = 0; i < n; i++) {
    		if (derrotas[i] == maxDerrotas) {
    			printf(" %d", i + 1);
    		}
    	}
    	printf(" com %d derrota(s)", maxDerrotas);
	}
	

	//imprime times com mais empates
	printf("\n\nTime(s) com mais empates:");
	if(maxEmpates==0) {
		printf(" nao houve empates");
	} else {
		for (int i = 0; i < n; i++) {
			if (empates[i] == maxEmpates) {
				printf(" %d ", i + 1);
			}
		}
		printf(" com %d empate(s)", maxEmpates);
	}

	//imprime os jogos com a maior diferenca de gols
	printf("\n\nMaior diferenca de gols foi de %d gol(s) no(s) jogo(s):", maxDiff);
	for (int i = 0; i < numJogosMaxDiff; i++) {
		printf(" time%d x time%d;", jogosMaxDiff[i][0], jogosMaxDiff[i][1]);
	}

	return 0;
}
