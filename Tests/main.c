#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int flag = 1;

void DesenhaDino(int x)
{
    if (x == 1)
    {
        printf("            %c%c%c%c%c%c\n          %c%c%c%c%c%c%c%c%c%c%c\n          %c%c%c%c%c%c%c%c%c%c%c\n          %c%c%c%c%c%c%c%c%c%c%c\n          %c%c%c%c%c%c\n          %c%c%c%c%c%c%c%c\n       %c%c%c%c%c%c%c\n%c    %c%c%c%c%c%c%c%c%c%c%c\n%c%c  %c%c%c%c%c%c%c%c%c%c %c\n%c%c%c%c%c%c%c%c%c%c%c%c\n  %c%c%c%c%c%c%c%c%c%c\n     %c%c%c  %c%c\n           %c\n           %c%c\n", 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 254
               , 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221,  221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221);
    }

    else if (x == 2)
    {
        printf("            %c%c%c%c%c%c\n          %c%c%c%c%c%c%c%c%c%c%c\n          %c%c%c%c%c%c%c%c%c%c%c\n          %c%c%c%c%c%c%c%c%c%c%c\n          %c%c%c%c%c%c\n          %c%c%c%c%c%c%c%c\n       %c%c%c%c%c%c%c\n%c    %c%c%c%c%c%c%c%c%c%c%c\n%c%c  %c%c%c%c%c%c%c%c%c%c %c\n%c%c%c%c%c%c%c%c%c%c%c%c\n  %c%c%c%c%c%c%c%c%c%c\n     %c%c%c  %c%c\n     %c%c    \n      %c%c   \n", 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 254
               , 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221,  221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221);
    }
    else
    {
       printf("            %c%c%c%c%c%c\n          %c%c%c%c%c%c%c%c%c%c%c\n          %c%c%c%c%c%c%c%c%c%c%c\n          %c%c%c%c%c%c%c%c%c%c%c\n          %c%c%c%c%c%c\n          %c%c%c%c%c%c%c%c\n       %c%c%c%c%c%c%c\n%c    %c%c%c%c%c%c%c%c%c%c%c\n%c%c  %c%c%c%c%c%c%c%c%c%c %c\n%c%c%c%c%c%c%c%c%c%c%c%c\n  %c%c%c%c%c%c%c%c%c%c\n     %c%c%c  %c%c\n     %c%c    %c\n      %c%c   %c%c\n", 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 254
               , 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221,  221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221);
    }
}

void delay(ms)
{
    clock_t timeDelay = ms + clock();
    while (timeDelay > clock())
        ;
}

// seleção entre 1 e 2 para executar as ações no menu
// 49 = 1, 50 = 2
void selection()
{
    switch (getch())
    {
    case 49:
        flag = 0;
        break;
    case 50:
        exit(0);
        break;
    }
}

//apenas imprime o menu inicial
void menuTeste()
{

    system("cls");
    printf("\n\n1 - inicia animacao\n");
    printf("2 - para animacao depois de iniciada / termina execucao");
}

// faz as animacoes
void movements()
{
    int x = 0, moment;

    selection();

    for (x = 0;       !kbhit() && x < 500 && flag == 0;     x++)
    {
        system("cls");

        moment = x;


        if (moment == 0)
        {
            DesenhaDino(0);
        }
        else if (moment % 2 == 0)
        {
            DesenhaDino(1);
        }
        else
        {
            DesenhaDino(2);
        }

        // funcao delay pra determinar um tempo antes de cumprir proxima acao
        delay(250);
    }
}

int main(void)
{
    //imprime o menu e continua para os movimentos
    menuTeste();

    while (1)
    {
        movements();
    }

    return 0;
}
