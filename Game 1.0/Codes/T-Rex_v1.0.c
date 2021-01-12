#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <string.h>
// criando estrutura e ranking propriamente dito
struct rank
{
    char nome[10];
    int pontuacao;
};

// criando o array com os ranking e um auxiliar para passar os valores pro principal
struct rank ranking[10], gameOverData, auxRank[10];

FILE *dadosRanking;


const int time_dino = 50;
const int time_cactus = 50;

unsigned int score = 0;
unsigned long score_time = 0;
unsigned long animation_time = 0;

int a = 90;
int b = 90;

char cactus_xB[] = {0, 0, 0, 0, 0, 0, 0};
char cactus_xA[] = {0, 0, 0, 0, 0, 0, 0};
char cactus_y[] = {26, 27, 28, 29, 30, 31, 32};

char dino_x[] = {22, 21, 21, 21, 21, 14, 13, 13, 13, 16, 16, 16, 17, 17, 18};
char dino_y[] = {18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32};


int menuSelected = 1, pausaSelected = 1, standardPoints = 0;

void carregaRanking();
void pegaPontuacao(int pontos);
void arquivamentoRanking();
void mostraRanking();
void DesenhaDino();
void DesenhaMenu(int opcao);
void desenhaJogoPausa(int opcao);
void mostraCreditos();
void mostraControles(char volta, int pontosPausa);
void MostraGameOver();
void draw_dino();
void draw_dino_up(int y);
void draw_dino_down(int y);
void animation_dino_legs();
void ground();
void draw_cactusA();
void draw_cactusB();
void draw_time_score();
void set_dino(int x);
void resetDinoX(int x);
int colisao();
void gotoxy(int x, int y);
void delay(int ms);
void set_cactus(int x, int cactus);
void cactus(int time);
void setup();
void jump(char on_ground);
void engine();
void game(int pontosAtuais);
void selecionadoPausa(int acaoPausa, int pontosPausa);
void selectingPausaJogo(int pontosPausa);
void pausa(int pontosPausa);
void selecionadoMenu(int opcao);
void selectingMenu();
void menu();


/* ------------ desenhos.c ----------- */

void DesenhaDino()
{
    printf("            %c%c%c%c%c%c\n          %c%c%c%c%c%c%c%c%c%c%c\n          %c%c%c%c%c%c%c%c%c%c%c\n          %c%c%c%c%c%c%c%c%c%c%c\n          %c%c%c%c%c%c\n          %c%c%c%c%c%c%c%c\n       %c%c%c%c%c%c%c\n%c    %c%c%c%c%c%c%c%c%c%c%c\n%c%c  %c%c%c%c%c%c%c%c%c%c %c\n%c%c%c%c%c%c%c%c%c%c%c%c\n  %c%c%c%c%c%c%c%c%c%c\n     %c%c%c  %c%c\n     %c%c    %c\n      %c%c   %c%c\n", 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 254, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221, 221);
}

void DesenhaMenu(int opcao)
{
    system("cls");

    if (opcao == 1)
    {
        printf("  _____           ____    _____  __  __    ____    _   _   _   _   _   _   ___   _   _    ____\n");
        printf(" |_   _|         |  _ \\  | ____| \\ \\/ /   |  _ \\  | | | | | \\ | | | \\ | | |_ _| | \\ | |  / ___|\n");
        printf("   | |    _____  | |_) | |  _|    \\  /    | |_) | | | | | |  \\| | |  \\| |  | |  |  \\| | | |  _\n");
        printf("   | |   |_____| |  _ <  | |___   /  \\    |  _ <  | |_| | | |\\  | | |\\  |  | |  | |\\  | | |_| |\n");
        printf("   |_|           |_| \\_\\ |_____| /_/\\_\\   |_| \\_\\  \\___/  |_| \\_| |_| \\_| |___| |_| \\_|  \\____|\n");
        printf("\ncontrole = setas\nSelecionar = Enter\n                                                        ");
        printf("\n\n\n\n                                         -> Start game\n");
        printf("                                            Ranking\n");
        printf("                                            Controls\n");
        printf("                                            Credits\n");
        printf("                                            Exit\n\n\n\n");
        DesenhaDino();
    }
    else if (opcao == 2)
    {
        printf("  _____           ____    _____  __  __    ____    _   _   _   _   _   _   ___   _   _    ____\n");
        printf(" |_   _|         |  _ \\  | ____| \\ \\/ /   |  _ \\  | | | | | \\ | | | \\ | | |_ _| | \\ | |  / ___|\n");
        printf("   | |    _____  | |_) | |  _|    \\  /    | |_) | | | | | |  \\| | |  \\| |  | |  |  \\| | | |  _\n");
        printf("   | |   |_____| |  _ <  | |___   /  \\    |  _ <  | |_| | | |\\  | | |\\  |  | |  | |\\  | | |_| |\n");
        printf("   |_|           |_| \\_\\ |_____| /_/\\_\\   |_| \\_\\  \\___/  |_| \\_| |_| \\_| |___| |_| \\_|  \\____|\n");
        printf("\ncontrole = setas\nSelecionar = Enter\n                                                        ");
        printf("\n\n\n\n                                            Start game\n");
        printf("                                         -> Ranking\n");
        printf("                                            Controls\n");
        printf("                                            Credits\n");
        printf("                                            Exit\n\n\n\n");
        DesenhaDino();
    }
    else if (opcao == 3)
    {
        printf("  _____           ____    _____  __  __    ____    _   _   _   _   _   _   ___   _   _    ____\n");
        printf(" |_   _|         |  _ \\  | ____| \\ \\/ /   |  _ \\  | | | | | \\ | | | \\ | | |_ _| | \\ | |  / ___|\n");
        printf("   | |    _____  | |_) | |  _|    \\  /    | |_) | | | | | |  \\| | |  \\| |  | |  |  \\| | | |  _\n");
        printf("   | |   |_____| |  _ <  | |___   /  \\    |  _ <  | |_| | | |\\  | | |\\  |  | |  | |\\  | | |_| |\n");
        printf("   |_|           |_| \\_\\ |_____| /_/\\_\\   |_| \\_\\  \\___/  |_| \\_| |_| \\_| |___| |_| \\_|  \\____|\n");
        printf("\ncontrole = setas\nSelecionar = Enter\n                                                        ");
        printf("\n\n\n\n                                            Start game\n");
        printf("                                            Ranking\n");
        printf("                                         -> Controls\n");
        printf("                                            Credits\n");
        printf("                                            Exit\n\n\n\n");
        DesenhaDino();
    }
    else if (opcao == 4)
    {
        printf("  _____           ____    _____  __  __    ____    _   _   _   _   _   _   ___   _   _    ____\n");
        printf(" |_   _|         |  _ \\  | ____| \\ \\/ /   |  _ \\  | | | | | \\ | | | \\ | | |_ _| | \\ | |  / ___|\n");
        printf("   | |    _____  | |_) | |  _|    \\  /    | |_) | | | | | |  \\| | |  \\| |  | |  |  \\| | | |  _\n");
        printf("   | |   |_____| |  _ <  | |___   /  \\    |  _ <  | |_| | | |\\  | | |\\  |  | |  | |\\  | | |_| |\n");
        printf("   |_|           |_| \\_\\ |_____| /_/\\_\\   |_| \\_\\  \\___/  |_| \\_| |_| \\_| |___| |_| \\_|  \\____|\n");
        printf("\ncontrole = setas\nSelecionar = Enter\n                                                        ");
        printf("\n\n\n\n                                            Start game\n");
        printf("                                            Ranking\n");
        printf("                                            Controls\n");
        printf("                                         -> Credits\n");
        printf("                                            Exit\n\n\n\n");
        DesenhaDino();
    }
    else if (opcao == 5)
    {
        printf("  _____           ____    _____  __  __    ____    _   _   _   _   _   _   ___   _   _    ____\n");
        printf(" |_   _|         |  _ \\  | ____| \\ \\/ /   |  _ \\  | | | | | \\ | | | \\ | | |_ _| | \\ | |  / ___|\n");
        printf("   | |    _____  | |_) | |  _|    \\  /    | |_) | | | | | |  \\| | |  \\| |  | |  |  \\| | | |  _\n");
        printf("   | |   |_____| |  _ <  | |___   /  \\    |  _ <  | |_| | | |\\  | | |\\  |  | |  | |\\  | | |_| |\n");
        printf("   |_|           |_| \\_\\ |_____| /_/\\_\\   |_| \\_\\  \\___/  |_| \\_| |_| \\_| |___| |_| \\_|  \\____|\n");
        printf("\ncontrole = setas\nSelecionar = Enter\n                                                        ");
        printf("\n\n\n\n                                            Start game\n");
        printf("                                            Ranking\n");
        printf("                                            Controls\n");
        printf("                                            Credits\n");
        printf("                                         -> Exit\n\n\n\n");
        DesenhaDino();
    }
}

void desenhaJogoPausa(int opcao)
{
    system("cls");

    //int pausaSelected = 1;

    if (opcao == 1)
    {
        printf("\n\n\n\n\n                             -> Voltar para o jogo \n");
        printf("                                Controles \n");
        printf("                                Menu principal  \n");
        printf("                                Sair do Jogo\n");
    }
    else if (opcao == 2)
    {
        printf("\n\n\n\n\n                                Voltar para o jogo \n");
        printf("                             -> Controles\n");
        printf("                                Menu principal  \n");
        printf("                                Sair do Jogo\n");
    }
    else if (opcao == 3)
    {
        printf("\n\n\n\n\n                                Voltar para o jogo \n");
        printf("                                Controles\n");
        printf("                             -> Menu principal  \n");
        printf("                                Sair do Jogo\n");
    }
    else if (opcao == 4)
    {
        printf("\n\n\n\n\n                                Voltar para o jogo \n");
        printf("                                Controles\n");
        printf("                                Menu principal  \n");
        printf("                             -> Sair do Jogo\n");
    }
}

void mostraCreditos()
{
    printf("\n              Jogo feito por :\n\n\n");
    printf("                -Gabriel Pereira     \n");
    printf("                -Bernardo Diniz             \n");
    printf("                -Jo%co Victor Pereira S.     \n", 134);
    printf("                -Riquelme Lopes             ");
    printf("\n                                            \n\n\n");
    printf("              Aperte qualquer tecla para voltar ao menu");
    getch();
    menu();
}

void mostraControles(char volta, int pontosPausa)
{
    printf("\n\n\n\n\n                        Apenas 2 comandos in-game:\n\n\n");
    printf("                          Barra de Espa%co - Pular\n", 135);
    printf("                                        P - Pausar\n\n\n");
    printf("                        Aperte qualquer tecla para voltar");
    getch();
    if (volta == 'm')
    {
        menu();
    }
    else
        pausa(pontosPausa);
}

void MostraGameOver()
{
    system("cls");

    gotoxy(15, 10);
    printf("       ____      _      __  __   _____      ___   __     __  _____   ____  \n");
    gotoxy(15, 11);
    printf("      / ___|    / \\    |  \\/  | | ____|    / _ \\  \\ \\   / / | ____| |  _ \\  \n");
    gotoxy(15, 12);
    printf("     | |  _    / _ \\   | |\\/| | |  _|     | | | |  \\ \\ / /  |  _|   | |_) |  \n");
    gotoxy(15, 13);
    printf("     | |_| |  / ___ \\  | | |  | | |___    | |_| |   \\ V /   | |___  |  _ <   \n");
    gotoxy(15, 14);
    printf("      \\____| /_/   \\_\\ |_|  |_| |_____|    \\___/     \\_/    |_____| |_| \\_\\  \n");
}

void carregaRanking()
{
    int i, j;
    dadosRanking = fopen("ranking.txt", "r");

    if ((dadosRanking = fopen("ranking.txt", "r")) == NULL)
    {
        printf("Nao foi possivel abrir o arquivo ranking.txt\n");
        printf("reinicie o programa\n");
        printf("Aperte qualquer tecla para voltar ao menu principal");
        getch();
        menu();
    }

    for (i = 0; (fread(&ranking[i], sizeof(struct rank), 1, dadosRanking) == 1); i++)
    {
        auxRank[i] = ranking[i];
    }

    fclose(dadosRanking);

    for (j = 0; j < 10; j++)
    {
        ranking[j] = auxRank[j];
    }
}

void pegaPontuacao(int pontos)
{
    system("cls");

    int i, points, antecessor, sucessor, j;
    char name[10];
    gameOverData.pontuacao = pontos;

    do
    {
        if (strlen(gameOverData.nome) > 3)
        {
            system("cls");
            //
            printf("\n\n\n\n\n\n\n                             Sua pontua%cao final : %d\n", 135, gameOverData.pontuacao);
            printf("                             Seu nome deve conter 3 d%cgitos !!\n\n                             Digite novamente: ", 161);
        }
        else
        { //
            printf("\n\n\n\n\n\n\n                             Sua pontua%cao final : %d\n\n", 135, gameOverData.pontuacao);
            printf("                             Digite seu nome\n                             Deve conter 3 d%cgitos: ", 161);
        }

        scanf("%s", &gameOverData.nome);

    } while (strlen(gameOverData.nome) > 3);

    for (i = 9; i >= 0; i--)
    {
        if (ranking[i].pontuacao != 0)
        {

            if (ranking[i].pontuacao >= gameOverData.pontuacao)
            {
                sucessor = i + 1;

                if (i == 9)
                {
                    break;
                }
                else
                {
                    for (j = 9; j > sucessor; j--)
                    {
                        ranking[j] = ranking[j - 1];
                    }

                    ranking[sucessor] = gameOverData;
                    break;
                }
            }
            else if (ranking[i].pontuacao < gameOverData.pontuacao)
            {
                if (i == 0)
                {
                    sucessor = i + 1;

                    if (i == 9)
                    {
                        ranking[i] = gameOverData;
                        break;
                    }
                    else
                    {
                        for (j = 9; j >= sucessor; j--)
                        {
                            ranking[j] = ranking[j - 1];
                        }

                        ranking[j] = gameOverData;
                        break;
                    }
                }
                else
                {
                    continue;
                }
            }
        }
        else if (ranking[i].pontuacao == 0 && i == 0)
        {
            ranking[i] = gameOverData;
        }
        else
        {
            continue;
        }
    }

    arquivamentoRanking();
}

void arquivamentoRanking()
{
    int ind;
    dadosRanking = fopen("ranking.txt", "w");

    if ((dadosRanking = fopen("ranking.txt", "w")) == NULL)
    {
        printf("Nao foi possivel abrir o arquivo ranking.txt\n");
        printf("reinicie o programa\n");
        printf("Aperte qualquer tecla para voltar ao menu principal");
        getch();
        menu();
    }

    fwrite(ranking, sizeof(struct rank), 10, dadosRanking);

    fclose(dadosRanking);
}

void mostraRanking()
{
    system("cls");

    int j;

    dadosRanking = fopen("ranking.txt", "r");

    if ((dadosRanking = fopen("ranking.txt", "r")) == NULL)
    {
        printf(" ________________________________________\n");
        printf("| POSICAO |     NOME     |    PONTUACAO\t |\n");
        printf("|---------|--------------|---------------|\n");
        for (j = 0; j < 10; j++)
        {
            delay(90);

            printf("|   %02d \t  |\t%s\t |\t%03d\t |\n", j + 1, "aaa", 0);
        }
        printf("|_________|______________|_______________|");
    }
    else
    {
        printf(" ________________________________________\n");
        printf("| POSICAO |     NOME     |    PONTUACAO\t |\n");
        printf("|---------|--------------|---------------|\n");
        for (j = 0; (fread(&ranking[j], sizeof(struct rank), 1, dadosRanking) == 1); j++)
        {
            delay(90);
            if (ranking[j].pontuacao == 0)
            {
                printf("|   %02d \t  |\t%s\t |\t%03d\t |\n", j + 1, "aaa", 0);
            }
            else
            {
                printf("|   %02d \t  |\t%s\t |\t%03d\t |\n", j + 1, ranking[j].nome, ranking[j].pontuacao);
            }
        }
        printf("|_________|______________|_______________|");
    }

    fclose(dadosRanking);

    printf("\n\n\nPressione qualquer tecla para voltar ao menu.\n");
    getch();
    menu();
}

void draw_time_score()
{

    if (clock() - score_time >= 80)
    {
        score_time = clock();
        gotoxy(80, 4);
        printf("SCORE: %d", score);
        score += 1;
    }
}

void draw_cactusA()
{
    int x = -1;

    if (cactus_xA[3] == 5)
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
    if (cactus_xB[3] == 5)
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
        set_cactus(b, 2);

        /* if (score >= 10 && cactus_xA[3] <= 40)
        {
            if (cactus_xA[3] >= 40)
            {
                set_cactus(b, 1);
            }
        } */
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
    printf("%c%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221);
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
    for (i = 0; i < 15; i++)
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
    printf("%c%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221);
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
    for (i = 0; i < 15; i++)
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
    printf("%c%c%c%c%c%c%c%c%c", 221, 221, 221, 221, 221, 221, 221, 221, 221);
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
    gotoxy(dino_x[14], 33);
    printf("-----------");
}

void animation_dino_legs()
{
    if (clock() - animation_time >= 250)
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
    for (i = 0; i < 100; i++)
    {
        gotoxy(0 + i, 33);
        printf("-");
    }
}

void set_dino(int x)
{
    int i;
    for (i = 0; i < 15; ++i)
    {
        dino_x[i] -= x;
    }
}

void resetDinoX(int x)
{
    int j;
    for (j = 0; j < 15; ++j)
    {
        dino_x[j] += x;
    }
}

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
    while (timeDelay > clock())
        ;
}

void set_cactus(int x, int cactus)
{
    switch (cactus)
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

void cactus(int time)
{

    if (score >= 150)
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

void setup()
{
    system("mode con: lines=40 cols=100");
    system("color a");
    system("cls");
    set_cactus(a, 1);
    set_cactus(b, 2);
    draw_dino();
    ground();
}

int colisao()
{
    int i, j;
    for (i = 0; i < 7; i++)
    {
        for (j = 7; j < 13; j++)
        {
            if (cactus_xA[i] < 15 + dino_x[j] || cactus_xB[i] < 15 + dino_x[j])
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}

void jump(char on_ground)
{
    if (on_ground == 1 && colisao())
    {
        resetDinoX(10);

        int saveScore;
        delay(500);
        MostraGameOver();
        delay(1000);
        printf("\n\n\n                        Aperte qualquer botao para continuar");
        getch();
        saveScore = score;
        pegaPontuacao(saveScore);
        mostraRanking();

        menu();
    }
    else if (on_ground == 1)
    {
        animation_dino_legs();
        cactus(time_cactus);
        draw_time_score();
    }
    else
    {

        int i;
        for (i = 0; i < 15; i++)
        {
            draw_dino_up(1);
            cactus(0);
            draw_time_score();
            delay(time_dino - 1);
        }

        for (i = 0; i < 15; i++)
        {
            draw_dino_down(1);
            cactus(0);
            draw_time_score();
            delay(time_dino - 1);
        }
    }
}

void engine()
{
    char key;
    int pontos;
    key = getch();

    if (key == ' ')
    {
        jump(0);
    }
    else if (key == 112)
    {
        pontos = score;
        pausa(pontos);
    }
}

void game(int pontosAtuais)
{
    set_dino(10);
    setup();

    score = pontosAtuais;

    while (1)
    {
        while (!kbhit())
        {
            jump(1);
        }

        engine();
    }
}

void selecionadoPausa(int acaoPausa, int pontosPausa)
{
    system("cls");

    char pause = 'p';

    switch (acaoPausa)
    {
    case 1:
        resetDinoX(10);
        game(pontosPausa); //jogo para alterar
        break;

    case 2:
        mostraControles(pause, pontosPausa);
        break;

    case 3:
        resetDinoX(10);
        menu();
        break;

    case 4:
        MostraGameOver();
        delay(1000);
        exit(0);
        break;
    }
}

void selectingPausaJogo(int pontosPausa)
{

    switch (getch())
    {
    case 72:
        if (pausaSelected > 1)
        {
            pausaSelected--;
            desenhaJogoPausa(pausaSelected);
            break;
        }
        else
        {
            desenhaJogoPausa(pausaSelected);
            break;
        }
    case 80:
        if (pausaSelected < 4)
        {
            pausaSelected++;
            desenhaJogoPausa(pausaSelected);
            break;
        }
        else
        {
            desenhaJogoPausa(pausaSelected);
            break;
        }
    case 13:
        selecionadoPausa(pausaSelected, pontosPausa);
        break;
    default:
        desenhaJogoPausa(pausaSelected);
        break;
    }
}

void pausa(int pontosPausa)
{
    while (1)
    {
        desenhaJogoPausa(pausaSelected);
        selectingPausaJogo(pontosPausa);
    }
}

void selecionadoMenu(int opcao)
{
    system("cls");
    char men = 'm';

    switch (opcao)
    {
    case 1:
        game(0);
        break;

    case 2:
        mostraRanking();
        break;

    case 3:
        mostraControles(men, standardPoints);
        break;

    case 4:
        mostraCreditos();
        break;

    case 5:
        //certeza();
        MostraGameOver();
        delay(1000);
        exit(0);
    }
}

void selectingMenu()
{

    switch (getch())
    {
    case 72:
        if (menuSelected > 1)
        {
            menuSelected--;
            DesenhaMenu(menuSelected);
            break;
        }
        else
        {
            DesenhaMenu(menuSelected);
            break;
        }
    case 80:
        if (menuSelected < 5)
        {
            menuSelected++;
            DesenhaMenu(menuSelected);
            break;
        }
        else
        {
            DesenhaMenu(menuSelected);
            break;
        }
    case 13:
        selecionadoMenu(menuSelected);
        break;
    default:
        menu();
        break;
    }
}

void menu()
{
    if ((dadosRanking = fopen("ranking.txt", "r")) != NULL)
    {
        carregaRanking();
    }

    while (1)
    {
        DesenhaMenu(menuSelected);
        selectingMenu();
    }
}