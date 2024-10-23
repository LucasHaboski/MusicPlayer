#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //sleep
#include <stdbool.h> //Validar cpf e retornar true ou false (ai mais é inutil sla o que) tmj👍🏾

void cabecalho() {
    printf("\033[H\033[J");

    printf(" _____         _                        \n");
    usleep(100000);
    printf("| ____|       | |                       \n");
    usleep(100000);
    printf("| |   ______  | |_ _   _ _ __   ___ ___ \n");
    usleep(100000);
    printf("| |  |______| | __| | | | '_ | / _ | __|\n");
    usleep(100000);
    printf("| |___        | |_| |_| | | | |  __|__ | \n");
    usleep(100000);
    printf("|_____|       |__||__,__|_| |_||___|___/ \n");
    usleep(100000);
    printf("                 \n");
    usleep(100000);
    printf("                !\n");
    usleep(100000);
    printf("                |\n");
    usleep(100000);
    printf("                |    |~/\n");
    usleep(100000);
    printf("                |   _|~\n");
    usleep(100000);
    printf("  .============.|  (_|   |~/\n");
    usleep(100000);
    printf(".-;____________;|.      _|~\n");
    usleep(100000);
    printf("| [_________I__] |     (_|\n");
    usleep(100000);
    printf("|  ''''' (_) (_) |\n");
    usleep(100000);
    printf("| .=====..=====. |\n");
    usleep(100000);
    printf("| |:::::||:::::| |\n");
    usleep(100000);
    printf("| '=====''=====' |\n");
    usleep(100000);
    printf("'----------------'\n");
    usleep(100000);  
}

void validaCPF(char *cpf) {
    int cpfNum[11]; // Transformar a string em numérico
    int i, mult, somaVerificador1 = 0, somaVerificador2 = 0;

    // Validar se o user não digitou algo alem de numeros
    for (i = 0; i < 11; i++) {
        if (cpf[i] < '0' || cpf[i] > '9') {
            printf("CPF INVALIDO! Deve conter apenas o numero do CPF!");
            return;
        }
        cpfNum[i] = cpf[i] - '0'; // transformando string em numero
    }

    for (i = 0, mult = 10; i < 9 && mult >= 2; i++, mult--) {
        somaVerificador1 += (cpfNum[i] * mult);
    }
    printf("Primeira soma = %d\n", somaVerificador1);
    printf("Primeira divisao por 11 = %d\n", somaVerificador1 % 11);
    printf("Verificando o digito verificador = %d\n", 11 - (somaVerificador1 % 11));

    int primeiroVerificador = 11 - (somaVerificador1 % 11);

    if (primeiroVerificador >= 10) {
        primeiroVerificador = 0;
    }

    if (primeiroVerificador == cpfNum[9]) {
        printf("\n DEU CERTO! \n");

        for (i = 0, mult = 11; i < 10 && mult >= 2; i++, mult--) {
            somaVerificador2 += (cpfNum[i] * mult);
        }

        printf("Segunda soma = %d\n", somaVerificador2);
        printf("Segunda divisao por 11 = %d\n", somaVerificador2 % 11);
        printf("Verificando o segundo digito verificador = %d\n", 11 - (somaVerificador2 % 11));

        int segundoVerificador = 11 - (somaVerificador2 % 11);

        if (segundoVerificador >= 10) {
            segundoVerificador = 0;
        }

        if (segundoVerificador == cpfNum[10]) {
            printf("\nCARALHO DEU CERTO!\n");
        }
    }
}

int main() {
    cabecalho();

    char *cpf;
    int tamanho = 11;

    cpf = (char *) calloc(tamanho + 1, sizeof(char));

    if (cpf == NULL) {
        printf("Erro na alocação de memória!!!!");
        return 1;
    }

    //Depois isso aqui vai pra dentro de cadastro de usuario, calma ae paizao

    printf("CPF (somente numeros): ");
    scanf("%11s", cpf); //biriri para ler no maximo 11 chars

    validaCPF(cpf);

    free(cpf);

    return 0;
}