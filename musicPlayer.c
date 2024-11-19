#include <stdio.h> // Funções de auxilio.
#include <stdlib.h> // Funções de auxilio.
#include <windows.h> // Uso da função Sleep();
#include <stdbool.h> // Validações com booleanos.
#include <conio.h> // Uso do getch() para pegar a escolha do usuário sem ele precisar dar enter.

// Struct das informações do usuário.
typedef struct {
    char email[100];
    char nomeCompleto[100];
    char cpf[12];
    int idade;
    char nomeUsuario[50];
    char senha[30];
} User;

// Struct para os admins.
typedef struct {
    char emailAdmin[100];
    char nomeAdmin[50];
    char senhaAdmin[30];
} Admin;

// Cabeçalho - Intro: será mostrada somente na primeira abertura do programa.
void cabecalhoIntro(){
    printf("\033[H\033[J");
    printf("======================================================================================================\n"); Sleep(100);
    printf("|                                                                                                    |\n"); Sleep(100);
    printf("|                                                                                   !                |\n"); Sleep(100);
    printf("|                                                                                   |    |~/         |\n"); Sleep(100);
    printf("|                                                                                   |   _|~          |\n"); Sleep(100);
    printf("|                                                                     .============.|  (_|   |~/     |\n"); Sleep(100);
    printf("|                                                                   .-;____________;|.      _|~      |\n"); Sleep(100);
    printf("|      _____         _                                              | [_________I__] |     (_|       |\n"); Sleep(100);
    printf("|     | ____|       | |                                             |  ''''' (_) (_) |               |\n"); Sleep(100);                   
    printf("|     | |   ______  | |_ _   _ _ __   ___ ___                       | .=====..=====. |               |\n"); Sleep(100);                   
    printf("|     | |  |______| | __| | | | '_ | / _ | __|                      | |:::::||:::::| |               |\n"); Sleep(100);                   
    printf("|     | |___        | |_| |_| | | | |  __|__ |                      | '=====''=====' |               |\n"); Sleep(100);
    printf("|     |_____|       |__||__,__|_| |_||___|___/                      '----------------'               |\n"); Sleep(100);
    printf("|                                                                                                    |\n"); Sleep(100);
    printf("======================================================================================================\n"); Sleep(200);  
}

// Cabeçalho: será mostrado toda vez que o menu inicial precisar ser atualizado.
void cabecalho(){
    printf("\033[H\033[J");
    printf("======================================================================================================\n");
    printf("|                                                                                                    |\n");
    printf("|                                                                                   !                |\n");
    printf("|                                                                                   |    |~/         |\n");
    printf("|                                                                                   |   _|~          |\n");
    printf("|                                                                     .============.|  (_|   |~/     |\n");
    printf("|                                                                   .-;____________;|.      _|~      |\n");
    printf("|      _____         _                                              | [_________I__] |     (_|       |\n");
    printf("|     | ____|       | |                                             |  ''''' (_) (_) |               |\n");                   
    printf("|     | |   ______  | |_ _   _ _ __   ___ ___                       | .=====..=====. |               |\n");                   
    printf("|     | |  |______| | __| | | | '_ | / _ | __|                      | |:::::||:::::| |               |\n");                   
    printf("|     | |___        | |_| |_| | | | |  __|__ |                      | '=====''=====' |               |\n");
    printf("|     |_____|       |__||__,__|_| |_||___|___/                      '----------------'               |\n");
    printf("|                                                                                                    |\n");
    printf("======================================================================================================\n");
    Sleep(200);  
}

// Menu de escolhas será atualizado enquanto o usuário estiver navegando pelo menu inicial.
void escolhas(){
    printf("|                                                                                                    |\n");
    printf("|              [1] Login                                                                             |\n");
    printf("|              [2] Criar Conta                                                                       |\n");
    printf("|              [3] Entrar como convidado                                                             |\n");
    printf("|              [4] Entrar como administrador                                                         |\n");
    printf("|              [5] Sobre o aplicativo                                                                |\n");
    printf("|                                                                                                    |\n");
    printf("|              [0] Sair                                                                              |\n");
    printf("|                                                                                                    |\n");
    printf("======================================================================================================\n");
}

// O menu de escolhas será mostrado atualizado sempre que o usuário digitar uma opção que não esteja presente no switch-case.
void escolhaErrada(){
    system("cls");
    cabecalho();
    printf("|                                                                                                    |\n");
    printf("|                    Voce selecionou uma opcao errada. Por favor, tente novamente!                   |\n");
    printf("|                                                                                                    |\n");
    printf("|              [1] Login                                                                             |\n");
    printf("|              [2] Criar Conta                                                                       |\n");
    printf("|              [3] Entrar como convidado                                                             |\n");
    printf("|              [4] Entrar como administrador                                                         |\n");
    printf("|              [5] Sobre o aplicativo                                                                |\n");
    printf("|                                                                                                    |\n");
    printf("|              [0] Sair                                                                              |\n");
    printf("|                                                                                                    |\n");
    printf("======================================================================================================\n");
}

// Caso nenhuma conta tenha sido cadastrada ainda ou o arquivo "usuário.dat" não exista, essa função será utilizada.
void nenhumaContaCadastrada(){
    system("cls");
    cabecalho();
    printf("|                                                                                                    |\n");
    printf("|                Nao existem contas criadas ainda. Por favor, cadastre uma nova conta!               |\n");
    printf("|                                                                                                    |\n");
    printf("|              [1] Login                                                                             |\n");
    printf("|              [2] Criar Conta                                                                       |\n");
    printf("|              [3] Entrar como convidado                                                             |\n");
    printf("|              [4] Entrar como administrador                                                         |\n");
    printf("|              [5] Sobre o aplicativo                                                                |\n");
    printf("|                                                                                                    |\n");
    printf("|              [0] Sair                                                                              |\n");
    printf("|                                                                                                    |\n");
    printf("======================================================================================================\n");
}

// Função que será usada para as escolhas do administrador.
void escolhasAdmin(){
    system("cls");
    cabecalho();
    printf("|                                                                                                    |\n");
    printf("|              [1] Listar usuarios                                                                   |\n");
    printf("|              [2] Excluir uma conta                                                                 |\n");
    printf("|              [3] Desativar uma conta                                                               |\n");
    printf("|              [4] Procurar por um usuario                                                           |\n");
    printf("|              [5] Cadastrar um novo administrador                                                   |\n");
    printf("|                                                                                                    |\n");
    printf("|              [0] Sair                                                                              |\n");
    printf("|                                                                                                    |\n");
    printf("======================================================================================================\n");
}

// Para caso o admin escolha uma opção errada.
void escolhasAdminErrada(){
    system("cls");
    cabecalho();
    printf("|                                                                                                    |\n");
    printf("|                    Voce selecionou uma opcao errada. Por favor, tente novamente!                   |\n");
    printf("|                                                                                                    |\n");
    printf("|              [1] Listar usuarios                                                                   |\n");
    printf("|              [2] Excluir uma conta                                                                 |\n");
    printf("|              [3] Desativar uma conta                                                               |\n");
    printf("|              [4] Procurar por um usuario                                                           |\n");
    printf("|              [5] Cadastrar um novo administrador                                                   |\n");
    printf("|                                                                                                    |\n");
    printf("|              [0] Sair                                                                              |\n");
    printf("|                                                                                                    |\n");
    printf("======================================================================================================\n");
}

// Caso o usuário digite a opção '0' no menu inicial o programa finaliza.
void finalizarPrograma(){
    cabecalho();
    printf("|                                                                                                    |\n");
    printf("|                                 Muito obrigado e ate uma proxima vez!                              |\n");
    printf("|                                                                                                    |\n");
    printf("======================================================================================================\n");
    Sleep(500);
    exit(0); // Finaliza o programa
}

// Informações para o cadastro de um novo usuário.
void infoCadastro(){
    cabecalho();
    printf("|                                                                                                    |\n");
    printf("|                     Digite o numero '0' no campo 'E-mail' para voltar ao menu.                     |\n");
    printf("|                                                                                                    |\n");
    printf("======================================================================================================\n");
}

// Função que acessa uma conta já cadastrada.
void acessarConta(){
    // Abre o file 'usuarios.dat'
    FILE *file = fopen("usuarios.dat", "rb");
    
    // Caso não ache printa uma mensagem de erro na tela informando que nenhuma conta foi cadastrada ainda.
    if (!file) {
        nenhumaContaCadastrada();
        return;
    }

    // Requerindo E-mail e Senha de acesso para o usuário.
    User usuario;
    char email[100], senha[30];

    // Flag para validar se o usuario foi encontrado no file.
    bool usuarioEncontrado = false;

    cabecalho();

    // Login -> E-mail e Senha
    printf(">> Login -> E-mail: ");
    scanf("%s", email);
    getchar();

    printf(">> Login -> Senha: ");
    scanf("%s", senha);
    getchar();

    // Lê os dados do arquivo binário
    while (fread(&usuario, sizeof(User), 1, file)) {

        // Usando o 'strcmp' para comparar se o E-mail e a Senha do usuário são iguais aos que foram feitos na leitura.
        if (strcmp(usuario.email, email) == 0 && strcmp(usuario.senha, senha) == 0) {
            usuarioEncontrado = true;
            break;
        }
    }

    // Fecha o file.
    fclose(file);

    // Se o usuário e a senha forem encontrados, então uma mensagem de boas vindas aparece ao usuário.
    if (usuarioEncontrado) {
        printf(">> Bem-vindo novamente, %s!\n\n", usuario.nomeUsuario);
    }
    // Caso contrário, uma mensagem de erro aparece e o usuário tem que tentar logar novamente.
    else {
        printf(">> Email ou senha incorretos!\n\n");
    }
}

// Validação de CPF
bool validarCPF(const char* cpf){
    int i, soma, resto, digito1, digito2;
    int pesos1[9] = {10, 9, 8, 7, 6, 5, 4, 3, 2};
    int pesos2[10] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
    int cpfRep = 0;

    // Verificar se o CPF tem 11 dígitos.
    if (strlen(cpf) != 11) {
        return false;
    }

    // Verificar se todos os caracteres são dígitos.
    for (i = 0; i < 11; i++) {
        if (cpf[i] < '0' || cpf[i] > '9') {
            return false;
        }
    }

    // Verifica se o CPF não tem dígitos repetidos.
    for (i = 1; i < 11; i++) {
        if(cpf[i] == cpf[0]){ cpfRep++; }
    }
    if(cpfRep == 10){return false;}

    // Calcular o primeiro dígito verificador.
    soma = 0;
    for (i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * pesos1[i];
    }
    resto = soma % 11;
    if (resto < 2) {
        digito1 = 0;
    } else {
        digito1 = 11 - resto;
    }

    // Calcular o segundo dígito verificador.
    soma = 0;
    for (i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * pesos2[i];
    }
    soma += digito1 * pesos2[9];
    resto = soma % 11;
    if (resto < 2) {
        digito2 = 0;
    } else {
        digito2 = 11 - resto;
    }

    // Verificar se os dígitos verificadores estão corretos.
    if (cpf[9] - '0' == digito1 && cpf[10] - '0' == digito2) {
        return true;
    } else {
        return false;
    }
}

// Validação de Senha
bool validarSenha(const char* senha) {
    int i;
    bool temNumero = false;

    // Verificar se a senha tem mais de 6 caracteres
    if (strlen(senha) <= 5) {
        return false;
    }

    // Verificar se a senha contém pelo menos um número
    for (i = 0; senha[i] != '\0'; i++) {
        if (isdigit(senha[i])) {
            temNumero = true;
            break;
        }
    }

    // Retornar true se a senha for válida, caso contrário, false
    return temNumero;
}

// Função que cadastra uma nova conta de usuário.
void cadastrarConta(User **vet, int *quantidade, int *capacidade){
    // Abrindo o file para realizar a adição dos dados de cada nova conta cadastrada.
    FILE *file = fopen("usuarios.dat", "ab");

    // Caso não ache o arquivo 'usuarios.dat', mostra uma mensagem de erro.
    if (!file) {
        perror("Erro ao abrir arquivo");
        return;
    }

    // Se a quantidade de cadastros for maior ou igual a capacidade de usuários, uma realocação de memória com os novos valores será feita.
    if (*quantidade >= *capacidade){
        *capacidade *= 2;
        *vet = (User *) realloc (*vet, *capacidade * sizeof(User));
    }

    // Variável para possibilitar o cadastro de um novo usuário.
    char continuar;

    // Cadastrando um novo usuário
    do {
        infoCadastro();
        printf("==> Cadastrando um novo usuario.\n");

        printf(">> Cadastro -> E-mail: ");
        scanf("%s", (*vet)[*quantidade].email);
        if ((*vet)[*quantidade].email[0] == '0') { return; }
        getchar();

        printf(">> Cadastro -> Nome completo: ");
        fgets((*vet)[*quantidade].nomeCompleto, sizeof((*vet)[*quantidade].nomeCompleto), stdin);

        // Validação do CPF
        bool validacaoCPF = true;
        do{
            printf(">> Cadastro -> CPF: ");
            scanf("%s", (*vet)[*quantidade].cpf);

            // Chama uma função que valida o CPF.
            validacaoCPF = validarCPF((*vet)[*quantidade].cpf);
            if (!validacaoCPF) {
                printf(">> ERRO! CPF invalido. Tente novamente.\n");
            }
        } while(!validacaoCPF);
        getchar();

        printf(">> Cadastro -> Idade: ");
        scanf("%d", &(*vet)[*quantidade].idade);
        getchar();

        printf(">> Cadastro -> Nome de usuario: ");
        scanf("%[^\n]s", (*vet)[*quantidade].nomeUsuario);
        getchar();

        // Validação da senha
        bool validacaoSenha = true;
        do{
            printf(">> Cadastro -> Senha: ");
            scanf("%s", (*vet)[*quantidade].senha);

            // Chama uma função que valida o CPF.
            validacaoSenha = validarSenha((*vet)[*quantidade].senha);
            if (!validacaoSenha) {
                printf(">> ERRO! Senha precisa ter pelo menos 1 numero e mais de 5 caracteres!\n");
            }
        } while(!validacaoSenha);
        getchar();

        // Salva os dados de cada novo usuário no file usando a função fwrite();
        fwrite(&(*vet)[*quantidade], sizeof(User), 1, file);
        printf("\n>> Conta criada com sucesso!");

        // Pergunta se o usuário deseja cadastrar outra conta
        printf("\n>> Deseja cadastrar outra conta? (s/n): ");
        continuar = getch();

    } while (continuar == 's' || continuar == 'S');

    // Ponteiro de quantidade de usuários incrementa em 1
    (*quantidade)++;

    // Fechamento do file.
    fclose(file);
}

// Função que acessa o programa como convidado.
void acessarConvidado(){
    cabecalho();
    printf("|                                                                                                    |\n");
    printf("|                Seja vem vindo convidado! Voce sera redirecionado em instantes.                     |\n");
    printf("|                                                                                                    |\n");
    printf("======================================================================================================\n"); Sleep(3500);
}

// Função que acessa o programa como administrador.
void acessarAdmin(){
    // Abre o file 'usuarios.dat'
    FILE *fileAdmin = fopen("admin.dat", "rb");
    
    // Requerindo E-mail e Senha de acesso para o admin.
    Admin adm;
    char emailAdm[100], senhaAdm[30];

    // Flag para validar se o admin foi encontrado no file.
    bool adminEncontrado = false;

    cabecalho();

    // Login -> E-mail e Senha
    printf(">> Login -> E-mail: ");
    scanf("%s", emailAdm);
    getchar();

    printf(">> Login -> Senha: ");
    scanf("%s", senhaAdm);
    getchar();

    // Lê os dados do arquivo binário
    while (fread(&adm, sizeof(Admin), 1, fileAdmin)) {

        // Usando o 'strcmp' para comparar se o E-mail e a Senha do admin são iguais aos que foram feitos na leitura.
        if (strcmp(adm.emailAdmin, emailAdm) == 0 && strcmp(adm.senhaAdmin, senhaAdm) == 0) {
            adminEncontrado = true;
            break;
        }
    }

    // Fecha o file.
    fclose(fileAdmin);

    // Se o usuário e a senha forem encontrados, então uma mensagem de boas vindas aparece ao usuário.
    if (adminEncontrado) {
        printf(">> Acesso garantido ao admin %s!\n\n", adm.nomeAdmin);
    }
    // Caso contrário, uma mensagem de erro aparece e o usuário tem que tentar logar novamente.
    else {
        printf(">> Administrador nao encontrado!\n\n");
    }
}

int main(){

    // Intro para quando o programa for aberto pela primeira vez e menu de escolha para o usuário.
    cabecalhoIntro();
    escolhas();

    // Declarando variáveis iniciais e alocando memória para os usuários.
    int qnt = 0;
    int capacidade = 4;

    User *vetUsers;
    vetUsers = (User *) calloc (capacidade, sizeof(User));

    // Pegando o input do usuário.
    char opcao = -1;
    
    do{
        // Pegando o input do usuário.
        printf(">> ");
        char opcao;

        opcao = getch(); // Pegando resposta do user sem precisar dar enter

        // Switch-case para as opções disponíveis ao usuário.
        switch(opcao) {
            // Finalizar o progama.
            case '0':
                finalizarPrograma();
                break;
            
            // Fazer o login.
            case '1':
                acessarConta();
                break;
            
            // Criar uma nova conta.
            case '2':
                cadastrarConta(&vetUsers, &qnt, &capacidade);
                system("cls");
                cabecalho();
                escolhas();
                break;
            
            // Entrar como convidado.
            case '3':
                acessarConvidado();
                break;

            // Entrar como administrador.
            case '4':
                acessarAdmin();
                break;

            // Sobre nós.
            case '5':
                printf("Voce acessou a opcao '5'!\n");
                break;

            // Caso o usuário digite qualquer outra coisa que não esteja nas opções.
            default:
                escolhaErrada();
                break;
        }
    } while(opcao != '0');

    return 0;
}