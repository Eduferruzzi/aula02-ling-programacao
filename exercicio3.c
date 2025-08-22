/*
 * Desenvolva um simulador de caixa eletrônico que permita 
 * ao usuário realizar operações bancárias básicas. 
 * O sistema deve manter o controle do saldo e validar todas as operações.
 */

#include <stdio.h>

void consultarSaldo(float saldo);
void realizarDeposito(float *saldo);
void realizarSaque(float *saldo);
void realizarTransferencia(float *saldo);

int main() {
    // Declaração das variáveis
    int opcao, chave = 1, resultado;
    float saldo = 1000;

    // Loop principal do caixa eletrônico
    while (chave == 1) {
        // Exibe o menu de opções
        printf("Selecione uma opcao:\n");
        printf("1. Consultar saldo\n");
        printf("2. Realizar deposito\n");
        printf("3. Realizar saque\n");
        printf("4. Tranferencia entre contas\n");
        printf("5. Sair do sistema\n");
        printf("Opcao: ");
        resultado = scanf("%d", &opcao);
        if (resultado != 1) {
            printf("Entrada invalida! Por favor, digite um numero.\n");
            while (getchar() != '\n');  // Limpa o buffer de entrada
            continue;
        }

        switch (opcao) {
            case 1:
                consultarSaldo(saldo);
                break;
            case 2:
                realizarDeposito(&saldo);
                break;
            case 3:
                realizarSaque(&saldo);
                break;
            case 4:
                realizarTransferencia(&saldo);
                break;
            case 5:
                chave = 0;
                printf("Saindo!\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }

    return 0;
}

void consultarSaldo(float saldo) {
    printf("Saldo atual: %.2f\n", saldo);
}

void realizarDeposito(float *saldo) {
    int resultado;
    float valor;
    printf("Digite o valor a ser depositado (Valor minimo: R$0.01), digite 0 para cancelar: ");
    resultado = scanf("%f", &valor);
    if (resultado != 1) {
        printf("Entrada invalida! Por favor, digite um numero.\n");
        while (getchar() != '\n');  // Limpa o buffer de entrada
        realizarDeposito(saldo);
    }
    if (valor >= 0.01) {
        *saldo += valor;
        printf("Deposito realizado com sucesso! Saldo atual: %.2f\n", *saldo);
    } else if (valor == 0) {
        printf("Deposito cancelado.\n");
        return;
    } else {
        printf("Valor invalido!\n");
        realizarDeposito(saldo);
    }
}

void realizarSaque(float *saldo) {
    int resultado;
    float valor;
    printf("Digite o valor a ser sacado (R$0.01 a R$500.00), digite 0 para cancelar: ");
    resultado = scanf("%f", &valor);
    if (resultado != 1) {
        printf("Entrada invalida! Por favor, digite um numero.\n");
        while (getchar() != '\n');  // Limpa o buffer de entrada
        realizarSaque(saldo);
    }
    if (valor >= 0.01 && valor <= 500 && valor <= *saldo) {
        *saldo -= valor;
        printf("Saque realizado com sucesso! Saldo atual: %.2f\n", *saldo);
    } else if (valor == 0) {
        printf("Saque cancelado.\n");
        return;
    } else if (valor > 500 || valor < 0.01) {
        printf("Valor invalido! O valor minimo para saque e R$0.01 e o valor maximo e R$500.00.\n");
        realizarSaque(saldo);
    } else {
        printf("Saldo insuficiente!\n");
        realizarSaque(saldo);
    }
}

void realizarTransferencia(float *saldo) {
    int resultado;
    float valor;
    printf("Digite o valor a ser transferido (Valor minimo: R$0.01), a taxa e de 1%% (minimo R$2.00), digite 0 para cancelar: ");
    resultado = scanf("%f", &valor);
    if (resultado != 1) {
        printf("Entrada invalida! Por favor, digite um numero.\n");
        while (getchar() != '\n');  // Limpa o buffer de entrada
        realizarTransferencia(saldo);
    }
    if (valor >= 0.01 && valor <= *saldo) {
        float taxa = valor * 0.01;
        if (taxa < 2.00) {
            taxa = 2.00;
        }
        *saldo -= (valor + taxa);
        printf("Transferencia realizada com sucesso! Saldo atual: %.2f\n", *saldo);
    } else if (valor == 0) {
        printf("Transferencia cancelada.\n");
        return;
    } else if (valor < 0.01) {
        printf("Valor invalido! O valor minimo para transferencia e R$0.01.\n");
        realizarTransferencia(saldo);
    } else {
        printf("Saldo insuficiente!\n");
        realizarTransferencia(saldo);
    }
}
