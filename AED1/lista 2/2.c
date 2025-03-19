#include <stdio.h>

#define MAX_VENDEDORES 10
#define MAX_DIAS 31
#define MAX_NOTAS 100

int main() {
	int mes, num_vendedores;
	float vendas[MAX_VENDEDORES][MAX_DIAS] = {0};
	float total_vendido_por_vendedor[MAX_VENDEDORES] = {0};
	float comissao_por_vendedor[MAX_VENDEDORES] = {0};
	int vendas_por_dia[MAX_DIAS] = {0};
	float valor_por_dia[MAX_DIAS] = {0};
	int total_vendas_no_mes = 0;
	float total_valor_vendido = 0;
	float total_comissoes = 0;
	int dias_no_mes = 31; // Inicializa com o mC!ximo de dias possC-veis
	int notas_fiscais_usadas[MAX_NOTAS] = {0};
	int num_notas_usadas = 0;


	do {
		printf("\n\nEntre com o mes em que as vendas foram realizadas: ");
		scanf("%d", &mes);
		if (mes < 1 || mes > 12) {
			printf("\n\nMes deve ser maior ou igual a 1 e menor ou igual a 12");
		}
	} while (mes < 1 || mes > 12);

	// Determina o nC:mero de dias conforme o mC*s que foi digitado
	dias_no_mes = (mes == 2) ? 28 : (mes == 4 || mes == 6 || mes == 9 || mes == 11) ? 30 : 31;


	do {
		printf("\n\nEntre com o numero de vendedores que trabalharam no mes: ");
		scanf("%d", &num_vendedores);
		if (num_vendedores < 1) {
			printf("\n\nNumero de vendedores deve ser maior do que zero");
		}
	} while (num_vendedores < 1 || num_vendedores > MAX_VENDEDORES);


	printf("\n\nEntre com as vendas. Para cada venda realizada no mes informar o numero da nota fiscal que a identifica, o codigo do vendedor responsavel, o dia do mes em que foi feita e o valor da venda em reais. Quando desejar finalizar a entrada de dados digite o numero zero para a nota fiscal.\n");

	while (1) {
		int nota_fiscal, codigo_vendedor, dia;
		float valor;

		printf("\nVenda: ");
		scanf("%d %d %d %f", &nota_fiscal, &codigo_vendedor, &dia, &valor);

		if (nota_fiscal == 0) break; // Finaliza as entradas

		// ValidaC'C#o do cC3digo do vendedor
		if (codigo_vendedor < 1 || codigo_vendedor > num_vendedores) {
			printf("\n\n\nCodigo do vendedor invalido");
		}

		// ValidaC'C#o do dia da venda
		if (dia < 1 || dia > dias_no_mes) {
			printf("\n\n\nDia da venda invalido");
		}

		// ValidaC'C#o do valor da venda
		if (valor <= 0) {
			printf("\n\n\nValor da venda invalida");

		}

		if (valor <= 0 || (dia < 1 || dia > dias_no_mes) || (codigo_vendedor < 1 || codigo_vendedor > num_vendedores)) {
			printf("\n\nInforme novamente os dados da venda");
			continue; // Ignora a venda invC!lida
		}

		// Verificar se a nota fiscal jC! foi utilizada
		int nota_repetida = 0;
		for (int i = 0; i < num_notas_usadas; i++) {
			if (notas_fiscais_usadas[i] == nota_fiscal) {
				nota_repetida = 1;
				break;
			}
		}

		if (nota_repetida == 0) {
			// Registrar a venda na matriz se a nota fiscal for vC!lida
			vendas[codigo_vendedor - 1][dia - 1] += valor;
			vendas_por_dia[dia - 1]++;
			valor_por_dia[dia - 1] += valor;
			total_vendido_por_vendedor[codigo_vendedor - 1] += valor;
			total_valor_vendido += valor;
			total_vendas_no_mes++;

			//MArca a nota fiscal como usada
			notas_fiscais_usadas[num_notas_usadas++] = nota_fiscal;
		} else if (nota_repetida == 1) {
			printf("\n\nNota fiscal repetida\nInforme novamente os dados da venda\n");
			continue; // Ignora a venda invC!lida
		}
	}

	// Calculo das comissC5es
	for (int i = 0; i < num_vendedores; i++) {
		float total_vendas_vendedor = total_vendido_por_vendedor[i];
		if (total_vendas_vendedor <= 2000) {
			comissao_por_vendedor[i] = total_vendas_vendedor * 0.05;
		} else if (total_vendas_vendedor < 5000) {
			comissao_por_vendedor[i] = total_vendas_vendedor * 0.07;
		} else {
			comissao_por_vendedor[i] = total_vendas_vendedor * 0.10;
		}
		total_comissoes += comissao_por_vendedor[i];
	}


	printf("\n\nRESUMO DE VENDAS POR VENDEDOR\n");
	for (int i = 0; i < num_vendedores; i++) {
		if (total_vendido_por_vendedor[i] > 0) {
			printf("\nVendedor %d\n", i + 1);
			for (int j = 0; j < dias_no_mes; j++) {
				if (vendas[i][j] > 0) {
					printf("dia %d: %.2f reais\n", j + 1, vendas[i][j]);
				}
			}
			printf("valor medio vendido por dia: %.2f reais\n", total_vendido_por_vendedor[i] / dias_no_mes);
			printf("valor da comissao (%.0f%%): %.2f reais\n", (total_vendido_por_vendedor[i] <= 2000) ? 5.0 : (total_vendido_por_vendedor[i] < 5000 ? 7.0 : 10.0), comissao_por_vendedor[i]);
		}
	}


	printf("\n\nRESUMO DE VENDAS POR DIA\n");
	for (int i = 0; i < dias_no_mes; i++) {
		if (vendas_por_dia[i] > 0) {
			printf("Dia %d: %d venda(s) com valor total de %.2f reais\n", i + 1, vendas_por_dia[i], valor_por_dia[i]);
		}
	}


	printf("\nRESUMO DE VENDAS NO MES\n");
	printf("quantidade de vendas: %d\n", total_vendas_no_mes);
	printf("valor total vendido: %.2f reais\n", total_valor_vendido);
	printf("valor total de comissoes pagas: %.2f reais\n", total_comissoes);

	return 0;
}
