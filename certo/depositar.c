#include <stdio.h>

void depositar() {

    FILE *carteira;

    char nome[50];
    char cpf[20];
    float reais, bitcoin, ethereum, ripple;
    float valor;
    int senha_arquivo;

    // 
    carteira = fopen("carteira.txt", "r");

    if (carteira == NULL) {
        printf("Erro ao abrir a carteira!\n");
        return;
    }

    //pessoal
    fgets(nome, 50, carteira);
    fgets(cpf, 20, carteira);
    //saldos
    fscanf(carteira, "%f", &reais);
    fscanf(carteira, "%f", &bitcoin);
    fscanf(carteira, "%f", &ethereum);
    fscanf(carteira, "%f", &ripple);
    fscanf(carteira, "%d", &senha_arquivo);

    fclose(carteira);

    //solicitar
    printf("\nDigite o valor que deseja depositar: R$ ");
    scanf("%f", &valor);

    if (valor <= 0) {
        printf("\nValor invalido!\n");
        return;
    }

    //Soma
    reais = reais + valor;

    //atualizar
    carteira = fopen("carteira.txt", "w");

    if (carteira == NULL) {
        printf("Erro ao atualizar o arquivo da carteira!\n");
        return;
    }

    //atualizar
    fprintf(carteira, "%s\n", nome);
    fprintf(carteira, "%s\n", cpf);
    fprintf(carteira, "%.2f\n", reais);
    fprintf(carteira, "%.4f\n", bitcoin);
    fprintf(carteira, "%.2f\n", ethereum);
    fprintf(carteira, "%.2f\n", ripple);
    fprintf(carteira, "%d\n", senha_arquivo);

    fclose(carteira);

    // Mostrar atualizado
    printf("\n***** DADOS ATUALIZADOS *****\n");
    printf("Valor depositado: R$ %.2f\n", valor);
    printf("Nome: %s\n", nome);
    printf("CPF: %s\n", cpf);
    printf("Saldo em reais: R$ %.2f\n", reais);
    printf("Bitcoin: %.4f\n", bitcoin);
    printf("Ethereum: %.2f\n", ethereum);
    printf("Ripple: %.2f\n", ripple);
}
