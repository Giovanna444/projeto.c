
#include <stdio.h>

void comprar() {

    FILE *carteira;

    char nome[50];
    char cpf[20];
    float reais, bitcoin, ethereum, ripple;
    float valor, cotacao, taxa, quantidade, total;
    int senha, senha_arquivo;
    int opcao;

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

    //senha
    printf("\nDigite sua senha (6 digitos): ");
    scanf("%d", &senha);

    //verificar 
    if (senha != senha_arquivo) {
        printf("\nSenha incorreta!\n");
        return;
    }

    //cotacoes
    printf("\n***** COTACOES *****\n");

    printf("Bitcoin: R$ 427809.00\n");
    printf("Ethereum: R$ 16108.00\n");
    printf("Ripple: R$ 2.57\n");

    //opcoes de compra
    printf("\n***** COMPRAR CRIPTOMOEDAS *****\n");
    printf("1 - Bitcoin\n");
    printf("2 - Ethereum\n");
    printf("3 - Ripple\n");

    printf("\nEscolha uma opcao: ");
    scanf("%d", &opcao);

    //cotacao e taxa
    switch (opcao) {

       	case 1:
    	cotacao = 407202.19;
    	taxa = 0.02;
    	break;

		case 2:
    	cotacao = 11432.98;
    	taxa = 0.01;
    	break;

		case 3:
    	cotacao = 5.77;
    	taxa = 0.01;
    	break;

    default:
        printf("\nOpcao invalida!\n");
        return;
    }

    //
    printf("\nSaldo disponivel: R$ %.2f\n", reais);
    printf("Quanto deseja em reais? R$ ");
    scanf("%f", &valor);

    if (valor <= 0) {
        printf("\nValor invalido!\n");
        return;
    }

    //taxa e valor total
    taxa = valor * taxa;
    total = valor + taxa;

    //verificar saldo
    if (total > reais) {
        printf("\nSaldo insuficiente!\n");
        printf("Valor da compra com taxa: R$ %.2f\n", total);
        return;
    }

    //quantidade de criptomoedas
    quantidade = valor / cotacao;

    //Atualizar 
    reais = reais - total;

    switch (opcao) {

        case 1:
            bitcoin = bitcoin + quantidade;
            break;

        case 2:
            ethereum = ethereum + quantidade;
            break;

        case 3:
            ripple = ripple + quantidade;
            break;
    }

    //atualizar os dados
    carteira = fopen("carteira.txt", "w");

    if (carteira == NULL) {
        printf("Erro ao atualizar a carteira!\n");
        return;
    }

    //dados atualizados
    fprintf(carteira, "%s\n", nome);
    fprintf(carteira, "%s\n", cpf);
    fprintf(carteira, "%.2f\n", reais);
    fprintf(carteira, "%.8f\n", bitcoin);
    fprintf(carteira, "%.8f\n", ethereum);
    fprintf(carteira, "%.8f\n", ripple);
    fprintf(carteira, "%d\n", senha_arquivo);

    fclose(carteira);

    //atualizado
    printf("\n***** COMPRA *****\n");

    printf("Valor da compra: R$ %.2f\n", valor);
    printf("Taxa de compra: R$ %.2f\n", taxa);
    printf("Total descontado: R$ %.2f\n", total);

    printf("\n***** DADOS ATUALIZADOS *****\n");

    printf("Nome: %s\n", nome);
    printf("CPF: %s\n", cpf);
    printf("Saldo em reais: R$ %.2f\n", reais);
    printf("Bitcoin: %.8f\n", bitcoin);
    printf("Ethereum: %.8f\n", ethereum);
    printf("Ripple: %.8f\n", ripple);
}

