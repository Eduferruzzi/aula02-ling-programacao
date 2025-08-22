/*
 * Crie uma calculadora de Índice de Massa Corporal (IMC) que forneça classificação personalizada 
 * e recomendações baseadas em idade, sexo e resultado do IMC.
 */

#include <stdio.h>

int main() {
    float peso, altura, imc;
    int idade, resultado;
    char sexo;

    // Pega os dados do usuário
    do
    {
        printf("Digite seu peso (kg): ");
        resultado = scanf("%f", &peso);
        if (resultado != 1) {
            printf("Entrada invalida. Por favor, digite um numero.\n");
            while (getchar() != '\n');  // Limpa o buffer
        } else if (peso <= 0) {
            printf("Peso deve ser maior que zero. Tente novamente.\n");
            resultado = 0; // Reseta o loop
        }
    } while (resultado != 1);

    do
    {
        printf("Digite sua altura (m): ");
        resultado = scanf("%f", &altura);
        if (resultado != 1) {
            printf("Entrada invalida. Por favor, digite um numero.\n");
            while (getchar() != '\n');  // Limpa o buffer
        } else if (altura <= 0) {
            printf("Altura deve ser maior que zero. Tente novamente.\n");
            resultado = 0; // Reseta o loop
        }
    } while (resultado != 1);

    do
    {
        printf("Digite sua idade: ");
        resultado = scanf("%d", &idade);
        if (resultado != 1) {
            printf("Entrada invalida. Por favor, digite um numero.\n");
            while (getchar() != '\n');  // Limpa o buffer
        } else if (idade <= 0) {
            printf("Idade deve ser maior que zero. Tente novamente.\n");
            resultado = 0; // Reseta o loop
        }
    } while (resultado != 1);

    do
    {
        printf("Digite seu sexo (M/F, m/f): ");
        resultado = scanf(" %c", &sexo);
        if (resultado != 1) {
            printf("Entrada invalida. Por favor, digite M ou F.\n");
            while (getchar() != '\n');  // Limpa o buffer
        } else if (sexo != 'M' && sexo != 'F' && sexo != 'm' && sexo != 'f') {
            printf("Sexo deve ser M(m) ou F(f). Tente novamente.\n");
            resultado = 0; // Reseta o loop
        }
    } while (resultado != 1);

    // Calcula o IMC
    imc = peso / (altura * altura);

    // Exibe o resultado
    printf("Seu IMC e: %.2f. Classificacao: ", imc);
    if (imc < 18.5) {
        printf("Abaixo do peso\n");
    } else if (imc < 25) {
        printf("Peso normal\n");
    } else if (imc < 30) {
        printf("Sobrepeso\n");
    } else if (imc < 35) {
        printf("Obesidade I\n");
    } else if (imc < 40) {
        printf("Obesidade II\n");
    } else {
        printf("Obesidade III\n");
    }

    if ((sexo == 'M' || sexo == 'm') && imc >= 25) {
        printf("Recomendacao: Faca exercicios de forca.\n");
    } else if ((sexo == 'F' || sexo == 'f') && imc >= 25) {
        printf("Recomendacao: Faca exercicios aerobicos.\n");
    }

    if (idade >= 60 && imc < 18.5) {
        printf("Recomendacao: Consulte um geriatra.\n");
    } else if (idade <= 25 && imc >= 30) {
        printf("Recomendacao: Consulte um nutricionista.\n");
    }

    return 0;
}