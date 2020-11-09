#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/* O RANKING ESTA TOTALMENTE FUNCIONAL
   POREM FALTA SALVA-LO EM FILES PARA
   MANIPULAR E LER  
*/

struct rank
{
    char nome[10];
    int pontuacao;
};

// criando o array com os ranking e um auxiliar para passar os valores pro principal
struct rank ranking[10], gameOverData;

//declarando as funcoes pra evitar erros e warnings
void pegaPontuacao();
void menuRanking();
void mostraRanking();

int main()
{
    system("cls");

    menuRanking();

    return 0;
}

void menuRanking()
{
    system("cls");

    printf("prototitpo de ranking\n\n");
    printf("1. adicionar uma pontuacao\n");
    printf("2. mostra ranking\n");
    printf("3. sair");

    switch (getch())
    {
    case 49:
        pegaPontuacao();
        break;
    case 50:
        mostraRanking();
        break;
    case 51:
        exit(0);
    default:
        menuRanking();
    }
}

// pega os valores, ordena e coloca no array de pontuacoes
void pegaPontuacao()
{
    system("cls");

    int i, points, antecessor, sucessor, j;
    char name[10];

    do
    {
        if (strlen(gameOverData.nome) > 3)
        {
            system("cls");

            printf("Seu nome deve ter 3 digitos\nDigite novamente: ");
        }
        else{
            printf("Digite seu nome: ");
        }

        scanf("%s", &gameOverData.nome);

    } while (strlen(gameOverData.nome) > 3);

    printf("Digite sua pontuacao: ");
    scanf("%d", &gameOverData.pontuacao);

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

    printf("\n\nPressione qualquer tecla para voltar ao menu.\n");
    getch();
    menuRanking();
}

// o nome da funcao se autoafirma no que faz
void mostraRanking()
{
    system("cls");

    int i;

    printf(" ________________________________________\n");
    printf("| POSICAO |     NOME     |    PONTUACAO\t |\n");
    printf("|---------|--------------|---------------|\n");

    for (i = 0; i < 10; i++)
    {
        if (ranking[i].pontuacao == 0)
        {
            printf("|   %02d \t  |\t%s\t |\t%03d\t |\n", i + 1, "aaa", 0);
        }
        else
        {
            printf("|   %02d \t  |\t%s\t |\t%03d\t |\n", i + 1, ranking[i].nome, ranking[i].pontuacao);
        }
    }
    printf("|_________|______________|_______________|");

    printf("\n\nPressione qualquer tecla para voltar ao menu.\n");
    getch();
    menuRanking();
}
