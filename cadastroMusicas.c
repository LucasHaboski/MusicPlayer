#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include "Visual.h"

void CadastrarMusica(FILE *pont_arq) {
    char nome[150], cantor[150], tempo[150], nota[150], genero[150];
    
    fflush(stdin);
    // Nome da musica
    printf("| Digite o nome da musica:\n");
    gets(nome);
    fprintf(pont_arq, "%s,", nome);

    // Nome do cantor
    printf("\n\n| Digite o nome da Banda ou artista:\n");
    gets(cantor);
    fprintf(pont_arq, "%s,", cantor);

    // Tempo da musica
    printf("\n\n| Digite quanto tempo dura a musica | Ex (00:03:25) |\n:");
    gets(tempo);
    fprintf(pont_arq, "%s,", tempo);

    // Gênero da musica
    printf("\n\n| Digite o genero da musica:\n");
    gets(genero);
    fprintf(pont_arq, "%s,", genero);

    // Nota
    printf("\n\n| De sua nota para a musica:\n");
    gets(nota);
    fprintf(pont_arq, "%s/10,\n", nota);

    Loading();

    // Mensagem de confirmação
    printf("| Cadastro concluido com sucesso!   :) \n");
    Sleep(1500);
    system("cls");
}

char MenuContinuacao() {
    char opcao;
    do {
        printf("| Deseja cadastrar mais uma musica?");
        printf("\n\n S - Sim \n N - Nao\n\n Opcao: ");
        
        opcao = toupper(getch());
        printf("%c\n", opcao);

        if (opcao != 'S' && opcao != 'N') {
            printf("Opcao invalida!\n");
            Sleep(1500);
            system("cls");
        }
    } while (opcao != 'S' && opcao != 'N');
    
    return opcao;
}

void MenuFinal() {
    char opcao;
    do {
        printf("| Digite 'M' para voltar ao menu principal: ");
        
        opcao = toupper(getch());
        printf("%c\n", opcao);
        
        if (opcao == 'M') {
            system("cls");
            printf("Voltando ao menu principal...\n");
            Sleep(1500);
            system("MenuDois.exe");
        } else {
            printf("Opcao invalida!\n");
            Sleep(1500);
            system("cls");
        }
    } while (opcao != 'M');
}

int main() {

    system("color 6F");

    FILE *pont_arq;
    pont_arq = fopen("Cadastros.txt", "a");
    
    if (pont_arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    char opcao;
    do {
        CadastrarMusica(pont_arq);
        opcao = MenuContinuacao();
        
        if (opcao == 'N') {
            MenuFinal();
            break;
        }

        system("cls");
    } while (opcao == 'S');

    fclose(pont_arq);
    return 0;
}
