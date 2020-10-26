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

/* int main(void)
{

    time_t start, end;
    long unsigned t;

    start = time(NULL);

    for (t = 0; t <= 1000; t++)
    {
        system("cls");
        end = time(NULL);
        printf("%.1f segs\n", difftime(end, start));

    }

    return 0;
}
 */

void delay(ms)
{
    clock_t timeDelay = ms + clock();
    while (timeDelay > clock())
        ;
}

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

void menuTeste()
{
    system("cls");
    printf("\n\n1 - inicia animacao\n");
    printf("2 - para animacao depois de iniciada / termina execucao");
}

/* void printarAnima()
{
    
    movements(); 
}
 */
void movements()
{
    int x = 0, moment;

    // testes antigos nao mais utilizados
    /* time_t start, end;
    long unsigned t; */

    //start = time(NULL);




    selection();


    for (x = 0; !kbhit() && x < 500 && flag == 0; x++)
    {
        /* end = time(NULL);
        moment = difftime(end, start); */
        system("cls");

        moment = x;
        //printf("%.1f",moment);
        
        if(moment == 0)
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

    menuTeste();

    while (1)
    {
        movements();
    }

    return 0;
}

