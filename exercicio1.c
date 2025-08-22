/*
 * Desenvolva um programa que simule o sistema de pontuação de um videogame. 
 * O programa deve permitir que o usuário insira a pontuação inicial de um jogador
 * e simule diferentes eventos que modificam essa pontuação usando operadores aritméticos 
 * e de atribuição.
 */

#include <stdio.h>

int main() {
    // Declara as variáveis
    int pontuacaoInicial, pontuacao;

    // Solicita e valida a pontuação inicial garantindo que seja um número positivo
    int resultado;
    do {
        printf("Digite a pontuacao inicial do jogador (deve ser positiva): ");
        resultado = scanf("%d", &pontuacaoInicial);
        if (resultado != 1 || pontuacaoInicial <= 0) {
            printf("Entrada invalida! Tente novamente.\n");
            while(getchar() != '\n'); // Limpa o buffer
        }
    } while (resultado != 1 || pontuacaoInicial <= 0);

    // Inicializa a pontuação atual
    pontuacao = pontuacaoInicial;
    printf("Pontuacao inicial: %d\n", pontuacaoInicial);

    // Ganhou uma fase, pontuacao = pontuacao + 50
    pontuacao += 50;
    printf("Ganhou uma fase, a pontuacao aumento em 50: %d\n", pontuacao);

    // Coletou um item especial, pontuacao = pontuacao * 2
    pontuacao *= 2;
    printf("Coletou um item especial, a pontuacao dobrou: %d\n", pontuacao);

    // Perdeu uma vida, pontuacao = pontuacao - 30
    pontuacao -= 30;
    printf("Perdeu uma vida, a pontuacao diminuiu em 30: %d\n", pontuacao);

    // Ganhou um bônus de tempo, pontuacao = pontuacao + 15
    pontuacao += 15;
    printf("Bonus de tempo, a pontuacao aumentou em 15: %d\n", pontuacao);

    // Penalidade por dificuldade, pontuacao = pontuacao / 3
    pontuacao /= 3;
    printf("Penalidade por dificuldade, a pontuacao foi reduzida para: %d\n", pontuacao);

    // Ganhou um bônus de 100 pontos, pontuacao = pontuacao + 100
    pontuacao += 100;
    printf("Bonus final, a pontuacao aumentou em 100: %d\n", pontuacao);

    printf("Pontuacao final do jogador: %d\n", pontuacao);
    printf("A diferenca entre a pontuacao final e a inicial e: %d\n", pontuacao - pontuacaoInicial);

    return 0;
}