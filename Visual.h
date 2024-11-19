/*Bibliotecas usadas para o funcionamento do codigo*/

#include <stdio.h>
#include <windows.h>


void Loading () /*Funcao visual para fazer a troca de executaveis*/
{
	int i;

	for(i = 1; i < 3; i++)
	{
		system("cls");
		printf("Loading. ");
		Sleep(125);
		system("cls");
		printf("Loading.. ");
		Sleep(125);
		system("cls");
		printf("Loading...  ");
		Sleep(125);
		system("cls");
	}
}

