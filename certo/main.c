//Giovanna Portella - RA=22126042-5
#include <stdio.h>
#include <stdlib.h>

void consulta_saldo();
void consulta_extrato();
void depositar();
void sacar();
void comprar();
void vender();
void cotacao_atualizada();

int main(int argc, char *argv[]) {
    float cpf;
    int senha;
    int opcao;

    //Login

    printf("Digite seu CPF (apenas numeros): ");
    scanf("%f", &cpf);

    printf("Digite sua senha (6 digitos): ");
    scanf("%d", &senha);

    if (cpf >= 10000000000 && cpf <= 99999999999) {

        if (senha >= 100000 && senha <= 999999) {

            printf("\nLogin realizado com sucesso!\n");
            

            // Menu 
            printf("\n***** MENU *****\n");
            printf("1 - Consultar saldo\n");
            printf("2 - Consultar extrato\n");
            printf("3 - Depositar\n");
            printf("4 - Sacar\n");
            printf("5 - Comprar criptomoedas\n");
            printf("6 - Vender criptomoedas\n");
            printf("7 - Atualizar cotacao\n");
            printf("8 - Sair\n");

            // Escolher
            printf("\nEscolha uma opcao: ");
            scanf("%d", &opcao);

            // Executar 
            switch (opcao) {
                case 1:
                    consulta_saldo();
                    break;

                case 2:
    				consulta_extrato();
    				break;

                case 3:
    				depositar();
    				break;
                case 4:
    				sacar();
    				break;

                case 5:
                    comprar();
                    break;

                case 6:
                    vender();
                    break;

                case 7:
                   	cotacao_atualizada();
                    break;

                case 8:
                    printf("Programa encerrado\n");
                    break;

                default:
                    printf("Opcao invalida!\n");
                    break;
            }

        } else {
            printf("\nSenha invalida!\n");
        }

    } else {
        printf("\nCPF invalido!\n");
    }

    system("pause");
    return 0;
}


