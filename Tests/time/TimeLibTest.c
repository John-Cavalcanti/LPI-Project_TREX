#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

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
        printf(" J\\ ");
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

void maybeStop()
{
    switch (getch())
    {
    case 49:
        break;
    case 50:
        exit(0);
        break;
    }
}

void printarAnima()
{
    int x = 0, moment;
    /* time_t start, end;
    long unsigned t; */

    //start = time(NULL);

    for (x = 0; !kbhit() && x < 500; x++)
    {
        /* end = time(NULL);
        moment = difftime(end, start); */

        moment = x;
        //printf("%.1f",moment);

        if (moment % 2 == 0)
        {
            desenha_cara(1);
        }
        else if (moment % 2 != 0)
        {
            desenha_cara(2);
        }
        else
        {
            desenha_cara(0);
        }

        // funcao delay pra determinar um tempo antes de cumprir proxima acao
        delay(500);

        system("cls");
    }
    maybeStop();
}

int main(void)
{
    while (1)
    {
        printarAnima();
    }
}