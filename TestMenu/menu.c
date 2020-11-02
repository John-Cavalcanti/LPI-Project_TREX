#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int menuSelected = 1;

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
        printf("\n\n\n\n                                            -> Press 1 to Start\n");
        printf("                                               Press 2 to Ranking\n");
        printf("                                               Press 3 to Controls\n");
        printf("                                               Press 4 to Credits\n");
        printf("                                               Press 5 to Exit\n\n\n\n");
        DesenhaDino();
    }
    else if (opcao == 2)
    {
        printf("  _____           ____    _____  __  __    ____    _   _   _   _   _   _   ___   _   _    ____\n");
        printf(" |_   _|         |  _ \\  | ____| \\ \\/ /   |  _ \\  | | | | | \\ | | | \\ | | |_ _| | \\ | |  / ___|\n");
        printf("   | |    _____  | |_) | |  _|    \\  /    | |_) | | | | | |  \\| | |  \\| |  | |  |  \\| | | |  _\n");
        printf("   | |   |_____| |  _ <  | |___   /  \\    |  _ <  | |_| | | |\\  | | |\\  |  | |  | |\\  | | |_| |\n");
        printf("   |_|           |_| \\_\\ |_____| /_/\\_\\   |_| \\_\\  \\___/  |_| \\_| |_| \\_| |___| |_| \\_|  \\____|\n");
        printf("\n\n\n\n                                               Press 1 to Start\n");
        printf("                                            -> Press 2 to Ranking\n");
        printf("                                               Press 3 to Controls\n");
        printf("                                               Press 4 to Credits\n");
        printf("                                               Press 5 to Exit\n\n\n\n");
        DesenhaDino();
    }
    else if (opcao == 3)
    {
        printf("  _____           ____    _____  __  __    ____    _   _   _   _   _   _   ___   _   _    ____\n");
        printf(" |_   _|         |  _ \\  | ____| \\ \\/ /   |  _ \\  | | | | | \\ | | | \\ | | |_ _| | \\ | |  / ___|\n");
        printf("   | |    _____  | |_) | |  _|    \\  /    | |_) | | | | | |  \\| | |  \\| |  | |  |  \\| | | |  _\n");
        printf("   | |   |_____| |  _ <  | |___   /  \\    |  _ <  | |_| | | |\\  | | |\\  |  | |  | |\\  | | |_| |\n");
        printf("   |_|           |_| \\_\\ |_____| /_/\\_\\   |_| \\_\\  \\___/  |_| \\_| |_| \\_| |___| |_| \\_|  \\____|\n");
        printf("\n\n\n\n                                               Press 1 to Start\n");
        printf("                                               Press 2 to Ranking\n");
        printf("                                            -> Press 3 to Controls\n");
        printf("                                               Press 4 to Credits\n");
        printf("                                               Press 5 to Exit\n\n\n\n");
        DesenhaDino();
    }
    else if (opcao == 4)
    {
        printf("  _____           ____    _____  __  __    ____    _   _   _   _   _   _   ___   _   _    ____\n");
        printf(" |_   _|         |  _ \\  | ____| \\ \\/ /   |  _ \\  | | | | | \\ | | | \\ | | |_ _| | \\ | |  / ___|\n");
        printf("   | |    _____  | |_) | |  _|    \\  /    | |_) | | | | | |  \\| | |  \\| |  | |  |  \\| | | |  _\n");
        printf("   | |   |_____| |  _ <  | |___   /  \\    |  _ <  | |_| | | |\\  | | |\\  |  | |  | |\\  | | |_| |\n");
        printf("   |_|           |_| \\_\\ |_____| /_/\\_\\   |_| \\_\\  \\___/  |_| \\_| |_| \\_| |___| |_| \\_|  \\____|\n");
        printf("\n\n\n\n                                               Press 1 to Start\n");
        printf("                                               Press 2 to Ranking\n");
        printf("                                               Press 3 to Controls\n");
        printf("                                            -> Press 4 to Credits\n");
        printf("                                               Press 5 to Exit\n\n\n\n");
        DesenhaDino();
    }
    else if (opcao == 5)
    {
        printf("  _____           ____    _____  __  __    ____    _   _   _   _   _   _   ___   _   _    ____\n");
        printf(" |_   _|         |  _ \\  | ____| \\ \\/ /   |  _ \\  | | | | | \\ | | | \\ | | |_ _| | \\ | |  / ___|\n");
        printf("   | |    _____  | |_) | |  _|    \\  /    | |_) | | | | | |  \\| | |  \\| |  | |  |  \\| | | |  _\n");
        printf("   | |   |_____| |  _ <  | |___   /  \\    |  _ <  | |_| | | |\\  | | |\\  |  | |  | |\\  | | |_| |\n");
        printf("   |_|           |_| \\_\\ |_____| /_/\\_\\   |_| \\_\\  \\___/  |_| \\_| |_| \\_| |___| |_| \\_|  \\____|\n");
        printf("\n\n\n\n                                               Press 1 to Start\n");
        printf("                                               Press 2 to Ranking\n");
        printf("                                               Press 3 to Controls\n");
        printf("                                               Press 4 to Credits\n");
        printf("                                            -> Press 5 to Exit\n\n\n\n");
        DesenhaDino();
    }
}

void selecionado(int opcao)
{
    system("cls");

    /* int opcao;

    opcao = menuSelected; */

    switch (opcao)
    {
    case 1:
        printf("\nTem jogo ainda n rei");
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
        selecionado(menuSelected);
        break;
    default:
        menu();
        break;
    }
}

void menu()
{
    DesenhaMenu(menuSelected);
    selectingMenu();
}

int main()
{
    //mudar a cor
    system("mode con: lines=29 cols=82");
    system("color a");

    //botar o jogo em tela cheia (modificar isso depois pra apenas redimensionar pra 800x800)
    keybd_event ( VK_MENU, 0x36, 0, 0 );
    keybd_event ( VK_RETURN, 0x1C, 0, 0 );
    keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 );
    keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );

    while (1)
    {
        menu();
    }
}
