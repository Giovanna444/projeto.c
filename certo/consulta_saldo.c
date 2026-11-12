#include <stdio.h>

void consulta_saldo() {

    FILE *carteira;
    char nome[50];
    char cpf[20];
    float reais, bitcoin, ethereum, ripple;
    int senha, senha_carteira;

    carteira = fopen("carteira.txt", "r");

    if (carteira == NULL) {
        printf("Erro ao abrir a carteira!\n");
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
    fscanf(carteira, "%d", &senha_carteira);

    fclose(carteira);

    printf("\nDigite sua senha (6 digitos): ");
    scanf("%d", &senha);

    if (senha == senha_carteira) {

        printf("\nCARTEIRA\n");

        printf("Nome: %s\n", nome);
        printf("CPF: %s\n", cpf);
        printf("Reais: R$ %.2f\n", reais);
        printf("Bitcoin: %.4f\n", bitcoin);
        printf("Ethereum: %.2f\n", ethereum);
        printf("Ripple: %.2f\n", ripple);

    } else {
        printf("\nSenha incorreta!\n");
    }
}
