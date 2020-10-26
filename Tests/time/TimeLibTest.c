#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int flag = 1;

void desenha_cara(int x)
{
    if (x == 1)
    {
        printf(" O \n");
        printf(")|\\\n");
        printf("/ )");
    }
    else if (x == 2)
    {
        printf(" O \n");
        printf("/|)\n");
        printf(" J\\");
    }
    else
    {
        printf(" O \n");
        printf("/|\\\n");
        printf("/ \\ ");
    }
}

//essa função determina um delay para a proxima ação acontecer
// exemplo : delay(200); pausa as ações em 200 milisegundos e depois continua
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

    // testes antigos nao mais utilizados
    /* time_t start, end;
    long unsigned t; */

    //start = time(NULL);

    //  seleção para iniciar as animações ou parar o programa
    selection();

    /*  1 - declara como x = 0

        2 - condicoes : 
          1a : enquanto não tenha nenhum "keybordhit" no teclado

          2a : vai repetir o programa sem parar ate 500 repetições
               apenas exemplo

          3a : enquanto flag = 0 for verdadeiro executa a função,
               isso é feito para quando apertarmos "2" na seleção
               o programa muda a flag para "1" e a condição não 
               eh verdadeira, então o loop encerra e o programa fecha
               como determinado nas condições da seleção   

        3 - incrementa o x para continuar executando o loop caso
            todas as condições sejam satisfeitas           
    */

    //     1                          2                      3
    for (x = 0;       !kbhit() && x < 500 && flag == 0;     x++)
    {
        /* end = time(NULL);
        moment = difftime(end, start); */
        system("cls");

        moment = x;
        //printf("%.1f",moment);

        if (moment == 0)
        {
            desenha_cara(0);
        }
        else if (moment % 2 == 0)
        {
            desenha_cara(1);
        }
        else //if (moment % 2 != 0)
        {
            desenha_cara(2);
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
