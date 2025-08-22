/*
 * Crie um programa que calcule a média de um estudante com base em três notas
 * e determine seu conceito final. 
 * O programa também deve verificar se o aluno está aprovado considerando média e frequência.
 */

#include <stdio.h>

int main() {
    // Declaração das variáveis
    float nota1, nota2, nota3, media;
    int frequencia;

    // Recebe todas as notas e a frequência garantindo que as entradas sejam válidas
    int resultado;
    do {
        printf("Digite as 3 notas (0-10), separadas por espacos: ");
        resultado = scanf("%f %f %f", &nota1, &nota2, &nota3);
        if (resultado != 3 || nota1 < 0 || nota1 > 10 || nota2 < 0 || nota2 > 10 || nota3 < 0 || nota3 > 10) {
            printf("Entrada invalida! Tente novamente.\n");
            while(getchar() != '\n'); // Limpa o buffer
        }
    } while (resultado != 3 || nota1 < 0 || nota1 > 10 || nota2 < 0 || nota2 > 10 || nota3 < 0 || nota3 > 10);

    do {
        printf("Digite a frequencia do aluno (em porcentagem, 0-100): ");
        resultado = scanf("%d", &frequencia);
        if (resultado != 1 || frequencia < 0 || frequencia > 100) {
            printf("Entrada invalida! Tente novamente.\n");
            while(getchar() != '\n'); // Limpa o buffer
        }
    } while (resultado != 1 || frequencia < 0 || frequencia > 100);

    // Calcula a média
    media = (nota1 + nota2 + nota3) / 3;
    printf("Media obtida: %.2f\n", media);

    // Determina o conceito
    if(media < 5) {
        printf("Conceito obtido: D\n");
    } else if(media < 7) {
        printf("Conceito obtido: C\n");
    } else if(media < 9) {
        printf("Conceito obtido: B\n");
    } else {
        printf("Conceito obtido: A\n");
    }

    // Determina se o aluno está aprovado
    if(media >= 5 && frequencia >= 75) {
        printf("Aprovado! Media %.2f >= 5.00 e frequencia %d%% >= 75%%\n", media, frequencia);
    } else {
        printf("Aluno reprovado! Motivo: ");
        if (media < 5) {
            printf("Media %.2f < 5.00", media);
        }
        if (media < 5 && frequencia < 75) {
            printf(" e ");
        }
        if (frequencia < 75) {
            printf("Frequencia %d%% < 75%%", frequencia);
        }
        printf("\n");
    }

    return 0;
}