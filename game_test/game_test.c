#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

// Boa parte das variáveis desse código estão no escopo (global) do código para facilitar na manutenção deste.
int dino_x = 20;
int cactus_x = 80;
int cactus_y = 15;
int dino_y = 15;

//velocidade da movimentação do cacto 1 - EASY 2 - MEDIUM 3 - HARD
int velocity = 1;

unsigned int score = 0;
unsigned long score_time = 0;

const int time_dino = 101;
const int time_cactus = 100;


void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

/* 
 * Essa função realiza a computação da pontuação a cada 1 segundo.
 * Nota: A condição presente no if funciona semelhante a função delay
 */
void time_score() {

    if(clock() - score_time >= 1000) 
    {
        score_time = clock();
        gotoxy(45, 0);
        printf("SCORE: %d", score);
        score += 1;
    }
}

/*
 * Essa função configura a coloração do terminal e defini um layout. 
 * Além disso, imprime informações referentes aos componentes do jogo
 * (Coordenadas do dinossauro, o próprio e o score). 
 */
void setup()
{
    system("mode con: lines=29 cols=82");
    system("color a");
    gotoxy(0, 0);
    printf("X: %d | Y: %d", dino_x, dino_y);
    gotoxy(45, 0);
    printf("SCORE: 0");
    gotoxy(dino_x, dino_y);
    printf("A");
}

/*
 * Essa função realiza a ação de fazer com que o cacto possa mover-se
 * no jogo, através da adição de valores na coordena x do cacto. Além disso, 
 * verifica se o cacto chegou até chegou na coordena x = 0 e Caso aconteça irá 
 * imprimilo novamente na coordena x = 80;
 */

void cactus(int time)
{
    gotoxy(cactus_x, cactus_y);
    printf("*");
    gotoxy(cactus_x+velocity, cactus_y);
    printf(" ");

    if(cactus_x == 0)
    {
        cactus_x = 80;
        gotoxy(0, cactus_y);
        printf(" ");
    }

    if(score >= 15 && cactus_x == 80)
        velocity = 2;
    if(score >= 25 && cactus_x == 80)
        velocity = 4;

    cactus_x -= velocity;
    delay(time);

    gotoxy(70, 0);
    printf("C: %d", cactus_x); //x axis position cactus 

}

/*
 * Essa função realiza a ação de fazer com que o dinossauro possa pular
 * no jogo, através de laços de repetições que irão adiciona valores na 
 * coordenada y do dinossauro. Além disso, realiza a verificação para saber
 * se o dinossauro encontra-se no chão (on_ground) para que tal ação seja 
 * válida. Caso o contrário irá verificar se existe colisão. 
 * (Coordenadas do dinossauro, o próprio e o score). 
 */

void jump(char on_ground)
{
    if(cactus_x == dino_x && cactus_y == dino_y)
    {
        system("cls");
        printf("Game Over!\n");
        system("pause");
        system("cls");
        setup();
        cactus_x = 80;
        score = 0;
    }

    else if(on_ground == 1)
    {

        int i;
        for(i = 0; i < 3; i++)
        {
            dino_y -= 1;
            gotoxy(dino_x, dino_y);
            printf("A");
            gotoxy(dino_x, dino_y+1);
            printf(" ");
            gotoxy(0, 0);
            printf("X: %d | Y: %d", dino_x, dino_y);
            cactus(time_dino - time_cactus);
            delay(time_dino);
        }

        for(i = 0; i < 3; i++)
        {
            dino_y += 1;
            gotoxy(dino_x, dino_y);
            printf("A");
            gotoxy(dino_x, dino_y-1);
            printf(" ");
            gotoxy(0, 0);
            printf("X: %d | Y: %d", dino_x, dino_y);
            cactus(time_dino - time_cactus);
            delay(time_dino);
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
            jump(0);
            cactus(time_cactus);
            time_score();
        }

        key = getch();

        if(key == ' ')
        {
            jump(1);
            time_score();
        }

        
    }
}

//"É SÓ USAR A INTUIÇAO" - CIBORGUE JESUS, 2019
