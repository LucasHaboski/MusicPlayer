#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // sleep
#include <stdbool.h> // Validar cpf e retornar true ou false (ai mais é inutil sla o que) tmj👍🏾
#include <conio.h> // Usar o getch() para pegar a resposta do user sem ter que dar enter, viadagem? Sim👍🏾
  
void cabecalhoIntro() {
    printf("\033[H\033[J");
    printf("==============================================================================================================\n");
    usleep(100000);
    printf("|                                                                                                            |\n");
    usleep(100000);
    printf("|                                                                                       !                    |\n");
    usleep(100000);
    printf("|                                                                                       |    |~/             |\n");
    usleep(100000);
    printf("|                                                                                       |   _|~              |\n");
    usleep(100000);
    printf("|                                                                         .============.|  (_|   |~/         |\n");
    usleep(100000);
    printf("|                                                                       .-;____________;|.      _|~          |\n");
    usleep(100000);
    printf("|     _____         _                                                   | [_________I__] |     (_|           |\n");
    usleep(100000);
    printf("|    | ____|       | |                                                  |  ''''' (_) (_) |                   |\n");
    usleep(100000);                   
    printf("|    | |   ______  | |_ _   _ _ __   ___ ___                            | .=====..=====. |                   |\n");
    usleep(100000);                   
    printf("|    | |  |______| | __| | | | '_ | / _ | __|                           | |:::::||:::::| |                   |\n");
    usleep(100000);                   
    printf("|    | |___        | |_| |_| | | | |  __|__ |                           | '=====''=====' |                   |\n");
    usleep(100000);
    printf("|    |_____|       |__||__,__|_| |_||___|___/                           '----------------'                   |\n");
    usleep(100000);
    printf("==============================================================================================================\n");
    usleep(400000);  
}

void cabecalho() {
    printf("\033[H\033[J");
    printf("==============================================================================================================\n");
    printf("|                                                                                                            |\n");
    printf("|                                                                                       !                    |\n");
    printf("|                                                                                       |    |~/             |\n");
    printf("|                                                                                       |   _|~              |\n");
    printf("|                                                                         .============.|  (_|   |~/         |\n");
    printf("|                                                                       .-;____________;|.      _|~          |\n");
    printf("|     _____         _                                                   | [_________I__] |     (_|           |\n");
    printf("|    | ____|       | |                                                  |  ''''' (_) (_) |                   |\n");                   
    printf("|    | |   ______  | |_ _   _ _ __   ___ ___                            | .=====..=====. |                   |\n");                   
    printf("|    | |  |______| | __| | | | '_ | / _ | __|                           | |:::::||:::::| |                   |\n");                   
    printf("|    | |___        | |_| |_| | | | |  __|__ |                           | '=====''=====' |                   |\n");
    printf("|    |_____|       |__||__,__|_| |_||___|___/                           '----------------'                   |\n");
    printf("==============================================================================================================\n");
    usleep(200000);  
}

void escolhas(){
    printf("|                                                                                                            |\n");
    printf("|   [1] Login                                                                                                |\n");
    printf("|                                                                                                            |\n");
    printf("|   [2] Criar Conta                                                                                          |\n");
    printf("|                                                                                                            |\n");
    printf("|   [3] Entrar como convidado                                                                                |\n");
    printf("|                                                                                                            |\n");
    printf("|   [4] Sobre o aplicativo                                                                                   |\n");
    printf("|                                                                                                            |\n");
    printf("|   [5] Sair                                                                                                 |\n");
    printf("|                                                                                                            |\n");
    printf("==============================================================================================================\n");
}

typedef struct {
    char email[100];
    char nome [100];
    char cpf [12];
    int idade;
    char nomeUser [50];
    char senha[30];
} User;

bool validaCPF(const char *cpf) {
    int cpfNum[11]; // Transformar a string em numérico
    int i, mult, somaVerificador1 = 0, somaVerificador2 = 0, cpfRep=0;

    // Validar se o user não digitou algo alem de numeros
    for (i = 0; i < 11; i++) {
        if (cpf[i] < '0' || cpf[i] > '9') {
            printf("CPF INVALIDO! Deve conter apenas o numero do CPF!");
            return false;
        }
        cpfNum[i] = cpf[i] - '0'; // transformando string em numero
    }

    // Protegendo de cpfs que funcionam seguindo a lógica de baixo mas não deveriam ex: (111.111.111-11 ou 222.222.222-22) vcs entenderam
    for (i = 1; i < 11; i++) {
        if(cpfNum[i] == cpfNum[0]){ cpfRep++; }
    }
    if(cpfRep == 10){return false;}
    

    // Fazendo a soma e contas para o primeiro digito verificador xxx.xxx.xxx-Ox
    for (i = 0, mult = 10; i < 9 && mult >= 2; i++, mult--) { somaVerificador1 += (cpfNum[i] * mult); }

    int primeiroVerificador = 11 - (somaVerificador1 % 11);

    if (primeiroVerificador >= 10) { primeiroVerificador = 0; }

    // Fazendo a soma e contas para o segundo digito verificador xxx.xxx.xxx-xO
    if (primeiroVerificador == cpfNum[9]) {

        for (i = 0, mult = 11; i < 10 && mult >= 2; i++, mult--) { somaVerificador2 += (cpfNum[i] * mult); }

        int segundoVerificador = 11 - (somaVerificador2 % 11);

        if (segundoVerificador >= 10) { segundoVerificador = 0; }

        if (segundoVerificador == cpfNum[10]) { return true; }

    }

    return false;
}

bool criarConta(User **vet, int *quantidade, int *capacidade){
    
    if (*quantidade >= *capacidade){
        *capacidade *= 2;
        *vet = (User *) realloc (*vet, *capacidade * sizeof(User));
    }

    cabecalho();
    
    printf("E-mail: ");
    scanf("%s", (*vet)[*quantidade].email);

    getchar();

    printf("Nome completo: ");
    fgets((*vet)[*quantidade].nome, 100, stdin);
    (*vet)[*quantidade].nome[strcspn((*vet)[*quantidade].nome, "\n")] = '\0';

    printf("CPF (Apenas os numeros): ");
    scanf("%s", (*vet)[*quantidade].cpf);

    printf("Idade: ");
    scanf("%d", &(*vet)[*quantidade].idade);

    printf("Nome de Usuario: ");
    scanf("%s", (*vet)[*quantidade].nomeUser);

    printf("Senha: ");
    scanf("%s", (*vet)[*quantidade].senha);
    
    bool cpfV = validaCPF((*vet)[*quantidade].cpf);

    if(cpfV) {
        printf("e um CPF valido");
        return true;
    }else {printf("Esse CPF nao e valido!");}

    (*quantidade)++;
    return true;

}

int main() {

    cabecalhoIntro();
    escolhas();

    User *vetUsers; // Por enquanto depois tem q ver com faz com FILE
    int qnt = 0;
    int capacidade = 4;

    vetUsers = (User *) calloc (capacidade, sizeof(User));

    char opcao;

    opcao = getch(); // Pegando resposta do user sem precisar dar enter

    switch(opcao) {
        case '1':
            printf("aaa");
            break;
        case '2':
            criarConta(&vetUsers, &qnt, &capacidade);
            break;
        case '3':
            printf("teste num2 ");
            break;
        case '4':
            printf("teste num2 ");
            break;
        case '5':
            printf("\n\nFinalizando o programa...\n");
            usleep(1000000);
            exit(0);
            break;
        default:
            printf("Voce digitou um numero errado!");
            break;

    }

    free(vetUsers);
    return 0;
}