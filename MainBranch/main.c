#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define DIMy 20
#define DIMx (DIMy * 6)
#define X 17
#define Y 17


void desenha_cara(int x)
{
    printf(" O \n");
    if (x >= 1)
    {
        int tam = x - 1;
        int i;
        char spaces[tam];

        for (i = 0; i <= tam; i++)
        {
            spaces[i] = 255;
        }
        printf("%s/|\\\n", spaces);
        printf("%s/ \\", spaces);
    }
    else
    {
        printf("/|\\\n");
        printf("/ \\");
    }
}

int main(void)
{
    int posX = X, posY = Y;
    int telax[DIMx], telay[DIMy];
    int x, y;

    for (y = 0; y < DIMy; y++)
    {
        telay[y] = y;
        for (x = 0; x < DIMx; x++)
        {

            telax[x] = x;
            if (y == DIMy - 1)
            {
                printf("#");
            }
            else if (telax[x] == posX && telay[y] == posY)
            {
                desenha_cara(posX);

                //  printf("%d %d",telax[x],telay[y]);
            }
            else
            {
                printf(" ");
            }

            //printf("%d%d ",telay[y],telax[x]);
        }
        printf("\n");
    }


    return 0;
}
