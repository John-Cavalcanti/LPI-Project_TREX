#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void DesenhaMenu()
{
    printf("  _____           ____    _____  __  __    ____    _   _   _   _   _   _   ___   _   _    ____\n"); printf(" |_   _|         |  _ \\  | ____| \\ \\/ /   |  _ \\  | | | | | \  | | | \\ | | |_ _| | \\ | |  / ___|\n");  printf("   | |    _____  | |_) | |  _|    \\  /    | |_) | | | | | |  \\| | |  \\| |  | |  |  \\| | | |  _\n"); printf("   | |   |_____| |  _ <  | |___   /  \\    |  _ <  | |_| | | |\\  | | |\\  |  | |  | |\\  | | |_| |\n"); printf("   |_|           |_| \\_\\ |_____| /_/\\_\\   |_| \\_\\  \\___/  |_| \\_| |_| \\_| |___| |_| \\_|  \\____|\n");
    printf("\n\n\n\n                                               Press 1 to Start\n"); printf("                                               Press 2 to Ranking\n"); printf("                                               Press 3 to Controls\n"); printf("                                               Press 4 to Credits\n"); printf("                                               Press 5 to Exit\n");
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

    char opcao;

    DesenhaMenu();
    opcao = getch();

    switch(opcao)
    {
        case 49:
            printf("\nTem jogo ainda n rei");
            break;

        case 50:
            printf("\nTbm n tem ranking kk");
            break;

        case 51:
            printf("\nPutz esse jogo n tem nd msm kk");
            break;

        case 52:
            printf("\nJaja esse jogo fica pronto pode relaxar");
            break;

        case 53:
            printf("\nAte a proxima!");
            exit(0);



    }
}
