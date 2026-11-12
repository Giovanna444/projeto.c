
#include <stdio.h>

void sacar() {

    FILE *carteira;

    char nome[50];
    char cpf[20];
    float reais, bitcoin, ethereum, ripple;
    float valor;
    int senha_arquivo;

    // 
    carteira = fopen("carteira.txt", "r");

    if (carteira == NULL) {
        printf("Erro ao abrir o arquivo da carteira!\n");
        return;
    }

    //pessoal
    fgets(nome, 50, carteira);
    fgets(cpf, 20, carteira);
    //saldo
    fscanf(carteira, "%f", &reais);
    fscanf(carteira, "%f", &bitcoin);
    fscanf(carteira, "%f", &ethereum);
    fscanf(carteira, "%f", &ripple);
    fscanf(carteira, "%d", &senha_arquivo);

    fclose(carteira);

printf("\n***** SALDO ATUAL *****\n");
printf("Saldo em reais: R$ %.2f\n", reais);

printf("\nDigite o valor que deseja sacar: R$ ");
scanf("%f", &valor);

    //verificar
    if (valor <= 0) {
        printf("\nValor invalido!\n");
        return;
    }

    if (valor > reais) {
        printf("\nSaldo insuficiente para sacar!\n");
        return;
    }

    //subtrair
    reais = reais - valor;

    //atualizar
    carteira = fopen("carteira.txt", "w");

    if (carteira == NULL) {
        printf("Erro ao atualizar a carteira!\n");
        return;
    }

    //gravar
    fprintf(carteira, "%s\n", nome);
    fprintf(carteira, "%s\n", cpf);
    fprintf(carteira, "%.2f\n", reais);
    fprintf(carteira, "%.4f\n", bitcoin);
    fprintf(carteira, "%.2f\n", ethereum);
    fprintf(carteira, "%.2f\n", ripple);
    fprintf(carteira, "%d\n", senha_arquivo);

    fclose(carteira);

    //saldos atualizados
    printf("\n***** SAQUE REALIZADO *****\n");

    printf("Valor sacado: R$ %.2f\n", valor);
    printf("Nome: %s\n", nome);
    printf("CPF: %s\n", cpf);
    printf("Saldo em reais: R$ %.2f\n", reais);
    printf("Bitcoin: %.4f\n", bitcoin);
    printf("Ethereum: %.2f\n", ethereum);
    printf("Ripple: %.2f\n", ripple);
}

