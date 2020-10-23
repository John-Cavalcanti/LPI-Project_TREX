#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
void desenha_cara(int x)
{
    if (x = 1)
    {
        printf(" O \n");
        printf(")|\\\n");
        printf("/ )");
    }
    else if (x = 2)
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
} */

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
    while(timeDelay > clock());
}

int main(void)
{

}
