#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

int menuSelected = 1, flag = 0, pausaSelected = 1;

/* ----------- ANIMACOES ------------ */

void delay(int ms)
{
    clock_t timeDelay = ms + clock();
    while (timeDelay > clock())
        ;
}

/* ------------ ANIMACOES ----------- */

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
        printf(" -> Voltar para o jogo \n");
        printf("    Controles \n");
        printf("    Menu principal  \n");
        printf("    Sair do Jogo\n");
    }
    else if (opcao == 2)
    {
        printf("    Voltar para o jogo \n");
        printf(" -> Controles\n");
        printf("    Menu principal  \n");
        printf("    Sair do Jogo\n");
    }
    else if (opcao == 3)
    {
        printf("    Voltar para o jogo \n");
        printf("    Controles\n");
        printf(" -> Menu principal  \n");
        printf("    Sair do Jogo\n");
    }
    else if (opcao == 4)
    {
        printf("    Voltar para o jogo \n");
        printf("    Controles\n");
        printf("    Menu principal  \n");
        printf(" -> Sair do Jogo\n");
    }
}

/* ------------- PROTOTIPO DO JOGO ------------------- */

void selection()
{
    system("cls");

    switch (getch())
    {
    case 112:
        //flag = 1;
        pausa();
        break;
    case 50:
        printf("ate mais !!");
        exit(0);
        break;
    default:
        gamePrototype();
    }
}

void gamePrototype()
{

    int x = 0, moment;

    for (x = 0; !kbhit() && flag == 0; x++)
    {
        system("cls");

        printf("2 - sair p - pausa\n\n");

        moment = x;

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

        delay(250);
    }

    selection();
}

/* ----------- PAUSA DO JOGO ------------- */

void selecionadoPausa(int acaoPausa)
{
    system("cls");

    switch (acaoPausa)
    {
    case 1:
        flag = 0;
        gamePrototype();
        break;

    case 2:
        /* todo
           MostraControles();
        */
        exit(0);
        break;

    case 3:
        menu();
        break;

    case 4:
        printf("\nAte mais");
        exit(0);
        break;
    }
}

void selectingPausaJogo()
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
        selecionadoPausa(pausaSelected);
        break;
    default:
        desenhaJogoPausa(pausaSelected);
        break;
    }
}

void pausa()
{
    while (1)
    {
        desenhaJogoPausa(pausaSelected);
        selectingPausaJogo();
    }
}

/* ------------------ MENU PRINCIPAL ---------------------- */

void selecionadoMenu(int opcao)
{
    system("cls");

    /* int opcao;

    opcao = menuSelected; */

    switch (opcao)
    {
    case 1:
        printf("\nTem jogo ainda n rei");
        gamePrototype();
        exit(0);
        break;

    case 2:
        printf("\nTbm n tem ranking kk");
        exit(0);
        break;

    case 3:
        printf("\nPutz esse jogo n tem nd msm kk");
        exit(0);
        break;

    case 4:
        printf("\nJaja esse jogo fica pronto pode relaxar");
        exit(0);
        break;

    case 5:
        printf("\nAte a proxima!");
        exit(0);
    }
}

int selectingMenu()
{
    /* codigos para as setas

       ^ - 72
       v - 80
       > - 26
       < - 27

     */

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
    while (1)
    {
        DesenhaMenu(menuSelected);
        selectingMenu();
    }
}

/* ----------------- MAIN ----------------- */

int main()
{
    //mudar a cor
    system("MODE con cols=100 lines=35 ");
    system("color a");

    //botar o jogo em tela cheia (modificar isso depois pra apenas redimensionar pra 800x800)
    /*  keybd_event(VK_MENU, 0x36, 0, 0);
    keybd_event(VK_RETURN, 0x1C, 0, 0);
    keybd_event(VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0); */

        menu();
    
}
