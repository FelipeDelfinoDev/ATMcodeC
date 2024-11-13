#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float saldo = 0;
int outraTransacao;
int valorSaque = 0;

void outraTransacaoFuncao(){
	printf("\nVoce deseja fazer outra transacao? 1. SIM / 2. NAO: ");
	scanf("%d", &outraTransacao);
	
	if (outraTransacao == 1){
		transacao();
	}
}

void transacao(){
	int escolha;
	printf(" 1. SAQUE \n 2. DEPOSITO \n 3. SALDO \n");
	printf("Digite a opcao a ser atendida: ");
	scanf("%d", &escolha);
	
	switch(escolha){
		case 1: {
			
			float valorSaque2;
			
			printf("Insira o valor do saque: ");
			scanf("%f", &valorSaque2);
			
			valorSaque = (int)valorSaque2;
			
			if (valorSaque < 0){
				
			printf("Quantia invalida");
			outraTransacaoFuncao();
			
			} else if (valorSaque > saldo){
			printf("Saldo insuficiente\n");
			outraTransacaoFuncao();
			
			} else {
				
			saqueFuncao();
			saldo -= valorSaque;
			printf("Voce retirou R$ %.2f e seu novo saldo R$ %.2f \n", ((float)valorSaque), saldo);
			outraTransacaoFuncao();
			
			}
			break;
		}
		
		case 2: {
			
			float valorDeposito;
			printf("Insira o valor a ser depositado: R$ ");
			scanf("%f", &valorDeposito);
			int valorDeposito2 = (int)valorDeposito;
			saldo += valorDeposito2;
			
			printf("Agradecemos pelo deposito, seu novo saldo e R$ %.2f \n", saldo);
			
			outraTransacaoFuncao();
			break;
		}
		
		case 3:
			printf("seu saldo e: R$ %.2f \n", saldo);
			outraTransacaoFuncao();
			break;
	
		default:	
			outraTransacaoFuncao();
			break;
		
	}
}


void saqueFuncao(){
	int n100 = 0, n50 = 0, n20 = 0, n10 = 0, n5 = 0, n2 = 0, n1 = 0, resto = 0;
	int valor = valorSaque;
	
	
	n100 = valor / 100;
	resto = valor - (n100 * 100);
	
	n50 = resto / 50;
	resto = resto - (n50 * 50);
	
	n20 = resto / 20;
	resto = resto - (n20 * 20);
	
	n10 = resto / 10;
	resto = resto - (n10 * 10);
	
	n5 = resto / 5;
	resto = resto - (n5 * 5);
	
	n2 = resto / 2;
	resto = resto - (n2 * 2);
	
	n1 = resto / 1;
	resto = resto - (n1 * 1);
	
	printf("\nnotas de R$100,00 [%d] \n", n100);
	printf("notas de R$50,00 [%d] \n", n50);
	printf("notas de R$20,00 [%d]\n", n20);
	printf("notas de R$10,00 [%d] \n", n10);
	printf("notas de R$5,00 [%d] \n", n5);
	printf("notas de R$2,00 [%d] \n", n2);
	printf("notas de R$1,00 [%d] \n", n1);
	
}

int main(){
	
	transacao();
	
	return 0;	
}