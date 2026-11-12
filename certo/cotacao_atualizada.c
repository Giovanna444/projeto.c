
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cotacao_atualizada() {

    FILE *cotacoes;

    float bitcoin, ethereum, ripple;
    float variacao;
    float bitcoin_antigo, ethereum_antigo, ripple_antigo;

   
    cotacoes = fopen("cotacoes.txt", "r");

    if (cotacoes == NULL) {
        printf("Erro ao abrir o arquivo das cotacoes!\n");
        return;
    }

    // Ler cotacoes anteriores
    fscanf(cotacoes, "%f", &bitcoin);
    fscanf(cotacoes, "%f", &ethereum);
    fscanf(cotacoes, "%f", &ripple);

    fclose(cotacoes);

    //valores anteriores
    bitcoin_antigo = bitcoin;
    ethereum_antigo = ethereum;
    ripple_antigo = ripple;

    
    srand(time(NULL));

    //variacao do Bitcoin
    variacao = (rand() % 1001 - 500) / 10000.0;
    bitcoin = bitcoin * (1 + variacao);

    // Gerar variacao do Ethereum
    variacao = (rand() % 1001 - 500) / 10000.0;
    ethereum = ethereum * (1 + variacao);

    // Gerar variacao do Ripple
    variacao = (rand() % 1001 - 500) / 10000.0;
    ripple = ripple * (1 + variacao);

    
    cotacoes = fopen("cotacoes.txt", "w");

    if (cotacoes == NULL) {
        printf("Erro ao atualizar as cotacoes!\n");
        return;
    }

    //Gravar
    fprintf(cotacoes, "%.2f\n", bitcoin);
    fprintf(cotacoes, "%.2f\n", ethereum);
    fprintf(cotacoes, "%.2f\n", ripple);

    fclose(cotacoes);

    //cotacoes anteriores e atualizadas
    printf("\n***** COTACOES ATUALIZADAS *****\n");
    printf("\nBitcoin:\n");
    printf("Cotacao anterior: R$ %.2f\n", bitcoin_antigo);
    printf("Nova cotacao: R$ %.2f\n", bitcoin);

    printf("\nEthereum:\n");
    printf("Cotacao anterior: R$ %.2f\n", ethereum_antigo);
    printf("Nova cotacao: R$ %.2f\n", ethereum);

    printf("\nRipple:\n");
    printf("Cotacao anterior: R$ %.2f\n", ripple_antigo);
    printf("Nova cotacao: R$ %.2f\n", ripple);
}

