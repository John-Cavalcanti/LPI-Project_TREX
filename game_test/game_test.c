#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

const int time_dino = 50;
const int time_cactus = 50;

unsigned int score;
unsigned long score_time = 0;
unsigned long animation_time = 0;

int a = 90;
int b = 90;

char cactus_xB[] =  {0, 0, 0, 0, 0, 0, 0};
char cactus_xA[] =  {0, 0, 0, 0, 0, 0, 0};
char cactus_y[] =  {26, 27, 28, 29, 30, 31, 32};

char dino_x[] = {22, 21, 21, 21, 21, 14, 13, 13, 13, 16, 16, 16, 17, 17, 18};
char dino_y[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32};

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(int ms)
{
    clock_t timeDelay = ms + clock();
    while (timeDelay > clock());
}

void draw_time_score()
{

    if(clock() - score_time >= 100)
    {
        score_time = clock();
        gotoxy(80, 4);
        printf("SCORE: %d", score);
        score += 1;
    }
}

void set_cactus(int x, int cactus)
{
    switch(cactus)
    {
        case 1:
            for (int i = 0; i < 7; ++i)
            {
                cactus_xA[i] = x;
            }
            break;

        case 2:
            for (int i = 0; i < 7; ++i)
            {
                cactus_xB[i] = x;
            }
            break;
    }
}

void draw_cactusA()
{
    int x = -1;

    if(cactus_xA[3] == 10)
    {
        gotoxy(cactus_xA[0], cactus_y[0]);
        printf("      ");
        gotoxy(cactus_xA[1], cactus_y[1]);
        printf("         ");
        gotoxy(cactus_xA[2], cactus_y[2]);
        printf("         ");
        gotoxy(cactus_xA[3], cactus_y[3]);
        printf("         ");
        gotoxy(cactus_xA[4], cactus_y[4]);
        printf("         ");
        gotoxy(cactus_xA[5], cactus_y[5]);
        printf("         ");
        gotoxy(cactus_xA[6], cactus_y[6]);
        printf("         ");

        set_cactus(a, 1);

    }
    else
    {
        int i;
        for (i = 0; i < 7; ++i)
        {
            cactus_xA[i] += x;
        }

        gotoxy(cactus_xA[0], cactus_y[0]);
        printf("    _ ");
        gotoxy(cactus_xA[1], cactus_y[1]);
        printf(" _ ( )   ");
        gotoxy(cactus_xA[2], cactus_y[2]);
        printf("( \\| | _");
        gotoxy(cactus_xA[2] + 8, cactus_y[2]);
        printf(" ");
        gotoxy(cactus_xA[3], cactus_y[3]);
        printf(" \\,. |/ )");
        gotoxy(cactus_xA[3] + 9, cactus_y[3]);
        printf(" ");
        gotoxy(cactus_xA[4], cactus_y[4]);
        printf("   |  /'");
        gotoxy(cactus_xA[4] + 8, cactus_y[4]);
        printf(" ");
        gotoxy(cactus_xA[5], cactus_y[5]);
        printf("   | |");
        gotoxy(cactus_xA[5] + 6, cactus_y[5]);
        printf(" ");
        gotoxy(cactus_xA[6], cactus_y[6]);
        printf("   | |");
        gotoxy(cactus_xA[6] + 6, cactus_y[6]);
        printf(" ");
    }
}

void draw_cactusB()
{
    int x = -1;

    if(cactus_xB[3] == 4)
    {
        gotoxy(cactus_xB[0], cactus_y[0]);
        printf("      ");
        gotoxy(cactus_xB[1], cactus_y[1]);
        printf("         ");
        gotoxy(cactus_xB[2], cactus_y[2]);
        printf("         ");
        gotoxy(cactus_xB[3], cactus_y[3]);
        printf("         ");
        gotoxy(cactus_xB[4], cactus_y[4]);
        printf("         ");
        gotoxy(cactus_xB[5], cactus_y[5]);
        printf("         ");
        gotoxy(cactus_xB[6], cactus_y[6]);
        printf("         ");

        if(score >= 10 && cactus_xA[3] <= 40)
        {
            if(cactus_xA[3] >= 40){
                set_cactus(b, 2);
            }
        }
    }
    else
    {
        int i;
        for (i = 0; i < 7; ++i)
        {
            cactus_xB[i] += x;
        }

        gotoxy(cactus_xB[0], cactus_y[0]);
        printf("    _ ");
        gotoxy(cactus_xB[1], cactus_y[1]);
        printf(" _ ( )   ");
        gotoxy(cactus_xB[2], cactus_y[2]);
        printf("( \\| | _");
        gotoxy(cactus_xB[2] + 8, cactus_y[2]);
        printf(" ");
        gotoxy(cactus_xB[3], cactus_y[3]);
        printf(" \\,. |/ )");
        gotoxy(cactus_xB[3] + 9, cactus_y[3]);
        printf(" ");
        gotoxy(cactus_xB[4], cactus_y[4]);
        printf("   |  /'");
        gotoxy(cactus_xB[4] + 8, cactus_y[4]);
        printf(" ");
        gotoxy(cactus_xB[5], cactus_y[5]);
        printf("   | |");
        gotoxy(cactus_xB[5] + 6, cactus_y[5]);
        printf(" ");
        gotoxy(cactus_xB[6], cactus_y[6]);
        printf("   | |");
        gotoxy(cactus_xB[6] + 6, cactus_y[6]);
        printf(" ");
    }
}

void cactus(int time)
{

    if(score >= 100)
    {
        draw_cactusA();
        draw_cactusB();
    }
    else
    {
        draw_cactusA();
    }

    delay(time);
}

void draw_dino()
{
    gotoxy(dino_x[0], dino_y[0]);
    printf("%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[1], dino_y[1]);
    printf("%c%c%c%c%c%c%c%c%c%c%c", 221, 221, 221, 254, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[2], dino_y[2]);
    printf("%c%c%c%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[3], dino_y[3]);
    printf("%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[4], dino_y[4]);
    printf("%c%c%c%c%c%c%c%c%c",  221, 221, 221, 221, 221, 221, 221, 221,221);
    gotoxy(dino_x[5], dino_y[5]);
    printf("%c     %c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[6], dino_y[6]);
    printf("%c%c    %c%c%c%c%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[7], dino_y[7]);
    printf("%c%c%c  %c%c%c%c%c%c%c%c%c%c  %c", 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[8], dino_y[8]);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[9], dino_y[9]);
    printf("%c%c%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[10], dino_y[10]);
    printf("%c%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221);
    //legs
    gotoxy(dino_x[11], dino_y[11]);
    printf("%c%c%c  %c%c%c", 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[12], dino_y[12]);
    printf("%c%c   %c%c", 221, 221, 221, 221);
    gotoxy(dino_x[13], dino_y[13]);
    printf("%c%c    %c", 221, 221, 221);
    gotoxy(dino_x[14], dino_y[14]);
    printf("%c%c   %c%c", 221, 221, 221, 221);

}

void draw_dino_up(int y)
{
    int i;
    for(i = 0; i <= 15; i++)
        dino_y[i] -= y;

    gotoxy(dino_x[0], dino_y[0]);
    printf("%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[0], dino_y[0] + y);
    printf("                ");
    gotoxy(dino_x[1], dino_y[1]);
    printf("%c%c%c%c%c%c%c%c%c%c%c", 221, 221, 221, 254, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[1], dino_y[1] + y);
    printf("                      ");
    gotoxy(dino_x[2], dino_y[2]);
    printf("%c%c%c%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[2], dino_y[2] + y);
    printf("                      ");
    gotoxy(dino_x[3], dino_y[3]);
    printf("%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[3], dino_y[3] + y);
    printf("            ");
    gotoxy(dino_x[4], dino_y[4]);
    printf("%c%c%c%c%c%c%c%c%c",  221, 221, 221, 221, 221, 221, 221, 221,221);
    gotoxy(dino_x[4], dino_y[4] + y);
    printf("                  ");
    gotoxy(dino_x[5], dino_y[5]);
    printf("%c     %c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[5], dino_y[5] + y);
    printf("                     ");
    gotoxy(dino_x[6], dino_y[6]);
    printf("%c%c    %c%c%c%c%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[6], dino_y[6] + y);
    printf("                                ");
    gotoxy(dino_x[7], dino_y[7]);
    printf("%c%c%c  %c%c%c%c%c%c%c%c%c%c  %c", 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[7], dino_y[7] + y);
    printf("                                ");
    gotoxy(dino_x[8], dino_y[8]);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[8], dino_y[8] + y);
    printf("                          ");
    gotoxy(dino_x[9], dino_y[9]);
    printf("%c%c%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[9], dino_y[9] + y);
    printf("                    ");
    gotoxy(dino_x[10], dino_y[10]);
    printf("%c%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[10], dino_y[10] + y);
    printf("                  ");

    //legs
    gotoxy(dino_x[11], dino_y[11]);
    printf("%c%c%c  %c%c%c", 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[11], dino_y[11] + y);
    printf("              ");
    gotoxy(dino_x[12], dino_y[12]);
    printf("%c%c   %c%c", 221, 221, 221, 221);
    gotoxy(dino_x[12], dino_y[12] + y);
    printf("           ");
    gotoxy(dino_x[13], dino_y[13]);
    printf("%c%c    %c", 221, 221, 221);
    gotoxy(dino_x[13], dino_y[13] + y);
    printf("          ");
    gotoxy(dino_x[14], dino_y[14]);
    printf("%c%c   %c%c", 221, 221, 221, 221);
    gotoxy(dino_x[14], dino_y[14] + y);
    printf("           ");
}

void draw_dino_down(int y)
{
    int i;
    for(i = 0; i <= 15; i++)
        dino_y[i] += y;


    gotoxy(dino_x[0], dino_y[0] - y);
    printf("                ");
    gotoxy(dino_x[1], dino_y[1] - y);
    printf("                      ");
    gotoxy(dino_x[2], dino_y[2] - y);
    printf("                      ");
    gotoxy(dino_x[3], dino_y[3] - y);
    printf("            ");
    gotoxy(dino_x[4], dino_y[4] - y);
    printf("                  ");
    gotoxy(dino_x[5], dino_y[5] - y);
    printf("                     ");
    gotoxy(dino_x[6], dino_y[6] - y);
    printf("                                ");
    gotoxy(dino_x[7], dino_y[7] - y);
    printf("                                ");
    gotoxy(dino_x[8], dino_y[8] - y);
    printf("                          ");
    gotoxy(dino_x[9], dino_y[9] - y);
    printf("                    ");
    gotoxy(dino_x[10], dino_y[10] - y);
    printf("                  ");
    //legs
    gotoxy(dino_x[11], dino_y[11] + y);
    printf("              ");
    gotoxy(dino_x[12], dino_y[12] + y);
    printf("           ");
    gotoxy(dino_x[13], dino_y[13] + y);
    printf("          ");
    gotoxy(dino_x[14], dino_y[14] + y);
    printf("           ");

    gotoxy(dino_x[0], dino_y[0]);
    printf("%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[1], dino_y[1]);
    printf("%c%c%c%c%c%c%c%c%c%c%c", 221, 221, 221, 254, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[2], dino_y[2]);
    printf("%c%c%c%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[3], dino_y[3]);
    printf("%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[4], dino_y[4]);
    printf("%c%c%c%c%c%c%c%c%c",  221, 221, 221, 221, 221, 221, 221, 221,221);
    gotoxy(dino_x[5], dino_y[5]);
    printf("%c     %c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[6], dino_y[6]);
    printf("%c%c    %c%c%c%c%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[7], dino_y[7]);
    printf("%c%c%c  %c%c%c%c%c%c%c%c%c%c  %c", 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[8], dino_y[8]);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[9], dino_y[9]);
    printf("%c%c%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[10], dino_y[10]);
    printf("%c%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221);

    //legs
    gotoxy(dino_x[11], dino_y[11]);
    printf("%c%c%c  %c%c%c", 221, 221, 221, 221, 221, 221);
    gotoxy(dino_x[12], dino_y[12]);
    printf("%c%c   %c%c", 221, 221, 221, 221);
    gotoxy(dino_x[13], dino_y[13]);
    printf("%c%c    %c", 221, 221, 221);
    gotoxy(dino_x[14], dino_y[14]);
    printf("%c%c   %c%c", 221, 221, 221, 221);
    //ground
    gotoxy(17, 33);
    printf("------------");

}

void animation_dino_legs()
{
    if(clock() - animation_time >= 250)
    {
        animation_time = clock();
        gotoxy(dino_x[11], dino_y[11]);
        printf("%c%c%c  %c%c%c", 221, 221, 221, 221, 221, 221);
        gotoxy(dino_x[12], dino_y[12]);
        printf("%c%c   %c%c", 221, 221, 221, 221);
        gotoxy(dino_x[13], dino_y[13]);
        printf("      %c", 221);
        gotoxy(dino_x[14], dino_y[14]);
        printf("     %c%c", 221, 221);

    }
    else
    {

        gotoxy(dino_x[11], dino_y[11]);
        printf("%c%c%c  %c%c%c", 221, 221, 221, 221, 221, 221);
        gotoxy(dino_x[12], dino_y[12]);
        printf("%c%c   %c%c", 221, 221, 221, 221);
        gotoxy(dino_x[13], dino_y[13]);
        printf("%c%c    ", 221, 221);
        gotoxy(dino_x[14], dino_y[14]);
        printf("%c%c     ", 221, 221);
    }
}

void ground()
{
    int i;
    for(i = 0; i < 100; i++)
    {
        gotoxy(0+i, 33);
        printf("-");
    }

}

void setup()
{
    system("mode con: lines=40 cols=100");
    system("color a");
    system("cls");
    set_cactus(a, 1);
    set_cactus(b, 2);
    draw_dino();
    ground();
    score = 0;
}

int colisao()
{
    int i;
    for(i = 26; i <= 32; i++)
    {
        if(cactus_xA[i] == dino_y[i] || cactus_xB[i] == dino_y[i])
            return 1;
        else
            return 0;
    }
}

void jump(char on_ground)
{
    if(on_ground == 1 && (cactus_xA[3] <= dino_y[10] || (cactus_xB[3] <= dino_y[10] && cactus_xB[3] != 4 && cactus_xB[3] <= 5)) && colisao())
    {
        system("cls");
        printf("Game Over!\n");
        system("pause");
        system("cls");
        setup();
    }
    else if(on_ground == 1)
    {
        animation_dino_legs();
        cactus(time_cactus);
        draw_time_score();
    }

    else
    {

        int i;
        for(i = 0; i < 15; i++)
        {
            draw_dino_up(1);
            cactus(0);
            draw_time_score();
            delay(time_dino - 1);
        }

        for(i = 0; i < 15; i++)
        {
            draw_dino_down(1);;
            cactus(0);
            draw_time_score();
            delay(time_dino - 1);
        }
    }
}

int main()
{
    char key;
    setup();

    while(1)
    {
        while(!kbhit())
        {
            jump(1);
        }

        key = getch();

        if(key == ' ')
        {
            jump(0);
        }

    }
    return 0;
}
