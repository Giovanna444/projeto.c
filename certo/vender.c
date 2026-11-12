
#include <stdio.h>

void vender() {

    FILE *carteira;

    char nome[50];
    char cpf[20];
    float reais, bitcoin, ethereum, ripple;
    float quantidade, cotacao, taxa, valor, total;
    int senha, senha_arquivo;
    int opcao;

    
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

    
    printf("\nDigite sua senha (6 digitos): ");
    scanf("%d", &senha);

    
    if (senha != senha_arquivo) {
        printf("\nSenha incorreta!\n");
        return;
    }

    //cotacoes
    printf("\n***** COTACOES *****\n");
    printf("Bitcoin: R$ 407202.19\n");
    printf("Ethereum: R$ 11432.98\n");
    printf("Ripple: R$ 5.77\n");

    //opcoes de venda
    printf("\n***** VENDER CRIPTOMOEDAS *****\n");
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

    //saldo da criptomoeda escolhida
    switch (opcao) {

        case 1:
            printf("\nBitcoin disponivel: %.8f\n", bitcoin);
            break;

        case 2:
            printf("\nEthereum disponivel: %.8f\n", ethereum);
            break;

        case 3:
            printf("\nRipple disponivel: %.8f\n", ripple);
            break;
    }

   
    printf("\nQuanto deseja vender? ");
    scanf("%f", &quantidade);

    if (quantidade <= 0) {
        printf("\nQuantidade invalida!\n");
        return;
    }

    // Verificar
    if (opcao == 1 && quantidade > bitcoin) {
        printf("\nQuantidade de Bitcoin insuficiente!\n");
        return;
    }

    if (opcao == 2 && quantidade > ethereum) {
        printf("\nQuantidade de Ethereum insuficiente!\n");
        return;
    }

    if (opcao == 3 && quantidade > ripple) {
        printf("\nQuantidade de Ripple insuficiente!\n");
        return;
    }

    //valor da venda
    valor = quantidade * cotacao;

    //taxa de venda
    taxa = valor * taxa;

    //valor recebido
    total = valor - taxa;

    //atualizar carteira
    reais = reais + total;

    if (opcao == 1) {
        bitcoin = bitcoin - quantidade;
    }

    if (opcao == 2) {
        ethereum = ethereum - quantidade;
    }

    if (opcao == 3) {
        ripple = ripple - quantidade;
    }

    
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

    //resultado da venda
    printf("\n***** VENDA REALIZADA *****\n");

    printf("Quantidade vendida: %.8f\n", quantidade);
    printf("Valor: R$ %.2f\n", valor);
    printf("Taxa: R$ %.2f\n", taxa);
    printf("Total: R$ %.2f\n", total);

    printf("\n***** DADOS ATUALIZADOS *****\n");
    printf("Nome: %s\n", nome);
    printf("CPF: %s\n", cpf);
    printf("Saldo em reais: R$ %.2f\n", reais);
    printf("Bitcoin: %.8f\n", bitcoin);
    printf("Ethereum: %.8f\n", ethereum);
    printf("Ripple: %.8f\n", ripple);
}

