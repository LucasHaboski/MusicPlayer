#include <stdio.h>   // Funções de auxilio.
#include <stdlib.h>  // Funções de auxilio.
#include <string.h>  // Funções de auxilio.
#include <windows.h> // Uso da função Sleep().
#include <stdbool.h> // Validações com booleanos.
#include <conio.h>   // Uso do getch() para pegar a escolha do usuário sem ele precisar dar enter.
#include "visual.h"

// Struct das informações do usuário.
typedef struct
{
    char email[100];
    char nomeCompleto[100];
    char cpf[12];
    int idade;
    char nomeUsuario[50];
    char senha[30];
} User;


// Menu sobre o aplicativo.
void sobreAplicativo()
{
    cabecalhoSobreAplicativo();
    char opcao;

    do
    {
        printf(">> ");
        opcao = getch();

        if (opcao != '0')
        {
            printf("Opcao invalida, tente novamente.\n");
        }

    } while (opcao != '0');
}

// Parte interna do aplicativo.
void parteInterna()
{
    cabecalhoParteInterna();
    char opcao;

    do
    {
        printf(">> ");
        opcao = getch();

        if (opcao != '0')
        {
            printf("Opcao invalida, tente novamente.\n");
        }

    } while (opcao != '0');
}

// Função que acessa uma conta já cadastrada.
void acessarConta(int *acessou)
{
    FILE *file;
    User usuario;
    char email[100], senha[30];
    bool usuarioEncontrado = false;

    // Tenta abrir o arquivo binário com os usuários cadastrados.
    file = fopen("usuarios.dat", "rb");
    if (!file)
    {
        *acessou = 1;
        return;
    }

    do
    {
        // Cabeçalho do menu de login
        cabecalho();
        printf(">> Login -> E-mail: ");
        scanf("%s", email);
        getchar();

        printf(">> Login -> Senha: ");
        scanf("%s", senha);
        getchar();

        // Procura pelo usuário no arquivo
        usuarioEncontrado = false;
        while (fread(&usuario, sizeof(User), 1, file))
        {
            if (strcmp(usuario.email, email) == 0 && strcmp(usuario.senha, senha) == 0)
            {
                usuarioEncontrado = true;
                break;
            }
        }

        fclose(file);

        if (usuarioEncontrado)
        {
            printf(">> Bem-vindo novamente, %s! Voce sera redirecionado em instantes.\n\n", usuario.nomeUsuario);
            *acessou = 2;
            Sleep(3000);
            break;
        }
        else
        {
            printf(">> Email ou senha incorretos!\n\n");
            printf(">> Aperte 0 para voltar ao menu ou qualquer outra tecla para tentar novamente.\n>> ");
            char opcao = getch();
            if (opcao == '0')
            {
                return;
            }
        }
    } while (true);
}

// Validação de CPF
bool validarCPF(const char *cpf)
{
    int i, soma, resto, digito1, digito2;
    int pesos1[9] = {10, 9, 8, 7, 6, 5, 4, 3, 2};
    int pesos2[10] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
    int cpfRep = 0;

    // Verificar se o CPF tem 11 dígitos.
    if (strlen(cpf) != 11)
    {
        return false;
    }

    // Verificar se todos os caracteres são dígitos.
    for (i = 0; i < 11; i++)
    {
        if (cpf[i] < '0' || cpf[i] > '9')
        {
            return false;
        }
    }

    // Verifica se o CPF não tem dígitos repetidos.
    for (i = 1; i < 11; i++)
    {
        if (cpf[i] == cpf[0])
        {
            cpfRep++;
        }
    }
    if (cpfRep == 10)
    {
        return false;
    }

    // Calcular o primeiro dígito verificador.
    soma = 0;
    for (i = 0; i < 9; i++)
    {
        soma += (cpf[i] - '0') * pesos1[i];
    }
    resto = soma % 11;
    if (resto < 2)
    {
        digito1 = 0;
    }
    else
    {
        digito1 = 11 - resto;
    }

    // Calcular o segundo dígito verificador.
    soma = 0;
    for (i = 0; i < 9; i++)
    {
        soma += (cpf[i] - '0') * pesos2[i];
    }
    soma += digito1 * pesos2[9];
    resto = soma % 11;
    if (resto < 2)
    {
        digito2 = 0;
    }
    else
    {
        digito2 = 11 - resto;
    }

    // Verificar se os dígitos verificadores estão corretos.
    if (cpf[9] - '0' == digito1 && cpf[10] - '0' == digito2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Validação de Senha
bool validarSenha(const char *senha)
{
    int i;
    bool temNumero = false;

    // Verificar se a senha tem mais de 6 caracteres
    if (strlen(senha) <= 5)
    {
        return false;
    }

    // Verificar se a senha contém pelo menos um número
    for (i = 0; senha[i] != '\0'; i++)
    {
        if (isdigit(senha[i]))
        {
            temNumero = true;
            break;
        }
    }

    // Retornar true se a senha for válida, caso contrário, false
    return temNumero;
}

// Validação do Email
bool validarEmail(const char *email)
{
    int i, arrobaI = -1, ultimoPontoI = -1;
    int tamanho = strlen(email);

    // Verifica se Email não é muito pequeno < (xxxxx@xxxxx.xxx) ex q funciona: (ryann@ctunes.com)
    if (tamanho < 13)
    {
        return false;
    }

    for (i = 0; i < tamanho; i++)
    {
        char l = email[i];

        if (!isalnum(l) && l != '@' && l != '.' && l != '_' && l != '-')
        {
            return false;
        } // Verifica se tem caracteres invalidos (isalnum é para verificar alfanumericos)

        // Pegar posição do '@'
        if (l == '@')
        {
            if (arrobaI != -1)
            {
                return false;
            } // Vê se tem mais de um '@' no email
            arrobaI = i;
        }

        // Pegar posição do ultimo '.'
        if (l == '.')
        {
            ultimoPontoI = i;
        }
    }

    if (arrobaI == -1 || ultimoPontoI == -1)
    {
        return false;
    } // Falta @ ou .
    if (arrobaI < 3)
    {
        return false;
    } // Tem que ter pelo menos 5 caracters no nome do email
    if (ultimoPontoI < arrobaI + 6)
    {
        return false;
    } // Tem que ter pelo menos 5 caracteres entre o '@' e o '.'| ex: (ctunes, gmail, yahoo, etc.) funcionam
    if (ultimoPontoI >= (tamanho - 2))
    {
        return false;
    } // Tem que ter pelo menos 2 caracteres depois do ultimo ponto| ex: (.com, .br) funcionam

    return true;
}

// Função que cadastra uma nova conta de usuário.
void cadastrarConta(User **vet, int *quantidade, int *capacidade)
{
    // Abrindo o file para realizar a adição dos dados de cada nova conta cadastrada.
    FILE *file = fopen("usuarios.dat", "ab");

    // Caso não ache o arquivo 'usuarios.dat', mostra uma mensagem de erro.
    if (!file)
    {
        perror("Erro ao abrir arquivo");
        return;
    }

    // Se a quantidade de cadastros for maior ou igual a capacidade de usuários, uma realocação de memória com os novos valores será feita.
    if (*quantidade >= *capacidade)
    {
        *capacidade *= 2;
        *vet = (User *)realloc(*vet, *capacidade * sizeof(User));
    }

    // Variável para possibilitar o cadastro de um novo usuário.
    char continuar;

    // Cadastrando um novo usuário
    do
    {
        infoCadastro();
        printf("==> Cadastrando um novo usuario.\n");

        // Validação do Email
        bool validacaoEmail = true;
        do
        {
            printf(">> Cadastro -> E-mail: ");
            scanf("%s", (*vet)[*quantidade].email);
            if ((*vet)[*quantidade].email[0] == '0')
            {
                return;
            }

            validacaoEmail = validarEmail((*vet)[*quantidade].email);
            if (!validacaoEmail)
            {
                printf(">> ERRO! Email invalido. Tente novamente.\n");
            }
        } while (!validacaoEmail);
        getchar();

        printf(">> Cadastro -> Nome completo: ");
        fgets((*vet)[*quantidade].nomeCompleto, sizeof((*vet)[*quantidade].nomeCompleto), stdin);

        // Validação do CPF
        bool validacaoCPF = true;
        do
        {
            printf(">> Cadastro -> CPF: ");
            scanf("%s", (*vet)[*quantidade].cpf);

            // Chama uma função que valida o CPF.
            validacaoCPF = validarCPF((*vet)[*quantidade].cpf);
            if (!validacaoCPF)
            {
                printf(">> ERRO! CPF invalido. Tente novamente.\n");
            }
        } while (!validacaoCPF);
        getchar();

        // Validação de Idade
        do
        {
            printf(">> Cadastro -> Idade: ");
            scanf("%d", &(*vet)[*quantidade].idade);

            if ((*vet)[*quantidade].idade < 18)
            {
                printf(">> ERRO! Para criar conta devera ser maior de idade.\n");
            }
        } while ((*vet)[*quantidade].idade < 18);
        getchar();

        printf(">> Cadastro -> Nome de usuario: ");
        scanf("%[^\n]s", (*vet)[*quantidade].nomeUsuario);
        getchar();

        // Validação da senha
        bool validacaoSenha = true;
        do
        {
            printf(">> Cadastro -> Senha: ");
            scanf("%s", (*vet)[*quantidade].senha);

            // Chama uma função que valida o CPF.
            validacaoSenha = validarSenha((*vet)[*quantidade].senha);
            if (!validacaoSenha)
            {
                printf(">> ERRO! Senha precisa ter pelo menos 1 numero e mais de 5 caracteres!\n");
            }
        } while (!validacaoSenha);
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
    
    // Limpa a tela.
    system("cls");
}

// Função que acessa o programa como administrador.
void acessarAdmin(int *adminAcessou)
{
    char email[50], senha[25];
    char opcao;

    cabecalho();

    do
    {
        // Login -> E-mail e Senha
        printf(">> Login -> E-mail: ");
        scanf("%s", email);
        getchar();

        printf(">> Login -> Senha: ");
        scanf("%s", senha);
        getchar();

        // Valida o login do administrador
        if (strcmp(email, "admin@ctunes.com") == 0 && strcmp(senha, "admin") == 0)
        {
            printf(">> Acesso garantido ao admin!\n");
            *adminAcessou = 1;
            Sleep(2000);

            char opAdmin = -1;

            escolhasAdmin();

            do
            {
                printf(">> ");
                opAdmin = getch();

                switch (opAdmin)
                {
                case '1':
                    printf("Opcao 1 selecionada.\n");
                    break;
                case '2':
                    printf("Opcao 2 selecionada.\n");
                    break;
                case '3':
                    printf("Opcao 3 selecionada.\n");
                    break;
                case '4':
                    printf("Opcao 4 selecionada.\n");
                    break;
                case '0':
                    printf("Saindo...\n");
                    Sleep(2000);
                    return;
                default:
                    escolhasAdminErrada();
                    break;
                }
            } while (opAdmin != '0');

            return;
        }
        else
        {
            printf(">> Acesso negado ao admin!\n\n");
            printf(">> Aperte 0 para voltar ou qualquer outra tecla para tentar novamente: ");
            opcao = getch();

            if (opcao == '0')
            {
                return;
            }
        }
    } while (true);
}

// Parte principal do programa.
int main()
{

    // Intro para quando o programa for aberto pela primeira vez e menu de escolha para o usuário.
    cabecalhoIntro();
    
    cabecalho();
    escolhas();

    // Declarando variáveis iniciais e alocando memória para os usuários.
    int qnt = 0;
    int capacidade = 4;

    User *vetUsers;
    vetUsers = (User *)calloc(capacidade, sizeof(User));

    char opcao = -1;
    int acessou = 0;
    int adminAcessou = 0;
    do
    {
        // Pegando a resposta do user sem precisar dar enter
        printf(">> ");
        opcao = getch();
        
        // Switch-case para as opções disponíveis ao usuário.
        switch (opcao)
        {
        // Finalizar o progama.
        case '0':
            finalizarPrograma();
            break;

        // Fazer o login.
        case '1':
    
            acessarConta(&acessou);
            if (acessou == 0)
            {
                cabecalho();
                escolhas();
            } else if (acessou == 1){
                nenhumaContaCadastrada();
            } else {
                parteInterna();
                cabecalho();
                escolhas();
            }
            break;

        // Criar uma nova conta.
        case '2':
            cadastrarConta(&vetUsers, &qnt, &capacidade);
            cabecalho();
            escolhas();
            break;

        // Entrar como convidado.
        case '3':
            acessarConvidado();
            parteInterna();
            cabecalho();
            escolhas();
            break;

        // Entrar como administrador.
        case '4':
            acessarAdmin(&adminAcessou);
            if (adminAcessou == 0)
            {
                escolhasAdmin();
            }
            cabecalho();
            escolhas();
            break;

        case '5':
            sobreAplicativo();
            cabecalho();
            escolhas();
            break;

        // Caso o usuário digite qualquer outra coisa que não esteja nas opções.
        default:
            escolhaErrada();
            break;
        }
    } while (opcao != '0');

    return 0;
}