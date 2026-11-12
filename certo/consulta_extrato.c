
#include <stdio.h>

void consulta_extrato() {

    FILE *carteira;
    FILE *extrato;

    char nome[50];
    char cpf[20];
    char linha[200];
    float reais, bitcoin, ethereum, ripple;
    int senha, senha_arquivo;

    // Abrir arquivo da carteira para conferir a senha
    carteira = fopen("carteira.txt", "r");

    if (carteira == NULL) {
        printf("Erro ao abrir o arquivo da carteira!\n");
        return;
    }

    fgets(nome, 50, carteira);
    fgets(cpf, 20, carteira);

    fscanf(carteira, "%f", &reais);
    fscanf(carteira, "%f", &bitcoin);
    fscanf(carteira, "%f", &ethereum);
    fscanf(carteira, "%f", &ripple);
    fscanf(carteira, "%d", &senha_arquivo);

    fclose(carteira);

    //Solicitar 
    printf("\nDigite sua senha (6 dígitos): ");
    scanf("%d", &senha);

    //Verificar
    if (senha == senha_arquivo) {

        //
        extrato = fopen("extrato.txt", "r");

        if (extrato == NULL) {
            printf("Erro ao abrir o arquivo do extrato!\n");
            return;
        }

        printf("\n***** EXTRATO *****\n");

        // Ler e mostrar cada linha do extrato
        while (fgets(linha, 200, extrato) != NULL) {
            printf("%s", linha);
        }

        fclose(extrato);

    } else {

        printf("\nSenha incorreta!\n");

    }
}

