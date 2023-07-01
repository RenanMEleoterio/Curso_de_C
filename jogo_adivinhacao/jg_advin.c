/*
Projeto jogo de adivinhação, feito durante o curso do alura
Desenvolvido por Renan Miranda Eleotério (vulgo RM)
Data de início:27/05/23
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // imprime o cabecalho do jogo

    printf(" _______                                            __                  __                        \n");
    printf("|       \\                                          |  \\                |  \\                    \n");
    printf("| $$$$$$$\\  ______   ______ ____         __     __  \\$$ _______    ____| $$  ______             \n");
    printf("| $$__/ $$ /      \\ |      \\    \\       |  \\   /  \\|  \\|       \\  /      $$ /      \\      \n");
    printf("| $$    $$|  $$$$$$\\| $$$$$$\\$$$$\\       \\$$\\ /  $$| $$| $$$$$$$\\|  $$$$$$$|  $$$$$$\\      \n");
    printf("| $$$$$$$\\| $$    $$| $$ | $$ | $$        \\$$\\  $$ | $$| $$  | $$| $$  | $$| $$  | $$          \n");
    printf("| $$__/ $$| $$$$$$$$| $$ | $$ | $$         \\$$ $$  | $$| $$  | $$| $$__| $$| $$__/ $$            \n");
    printf("| $$    $$ \\$$     \\| $$ | $$ | $$          \\$$$   | $$| $$  | $$ \\$$    $$ \\$$    $$        \n");
    printf(" \\$$$$$$$   \\$$$$$$$ \\$$  \\$$  \\$$           \\$     \\$$ \\$$   \\$$  \\$$$$$$$  \\$$$$$$   \n");
    printf("\n\n");                                                                                   


    int segundos = time(0);
    srand(segundos);
    int numeroSecreto = rand() % 100;
    int chute;
    int contador = 0;
    float pontos = 1000;
    int acertou = 0;
    int nivel = 0;
    printf("Escolha o nivel de dificuldade:\n\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);
    int numeroTentativas;

    switch (nivel)
    {
        case 1:
                numeroTentativas = 20;
            break;

        case 2:
            numeroTentativas = 15;
            break;
    
        default:
            numeroTentativas = 6;
            break;
    }

    for(contador = 1; contador <= numeroTentativas; contador++)
    {
        printf("Tentativa %d\n", contador);
        printf("\nDigite o seu palpite. ");
        scanf("%d", &chute);
        if (chute < 0)
        {
            printf("\nNosso jogo não aceita números negativos!\n\n");
            continue;
        }

        acertou = (chute == numeroSecreto);
        int maior = (chute > numeroSecreto);
        if (acertou)
        {
            break;
        }
        else if (maior)
        {
            printf("\nO seu chute foi maior que o número secreto.\n\n");
        }
        else
        {
            printf("\nO seu chute foi menor que o número secreto.\n\n");
        }
        float pontosPerdidos = abs(chute - numeroSecreto) / 2.0;

        pontos = pontos - pontosPerdidos;
    }
    if(acertou){
        printf("\nParabéns, você acertou o número!\n\n");
        printf("Vocẽ gastou %d tentativas para acertar.\n\n", contador);
        printf("A sua pontuação foi de %.2f\n\n", pontos);
        printf("\n\n");
        printf("00000000000000000000000000000000000000\n");
        printf("00000000000000__________00000000000000\n");
        printf("00000000000________________00000000000\n");
        printf("000000000____________________000000000\n");
        printf("00000000______00______00______00000000\n");
        printf("0000000______0000____0000______0000000\n");
        printf("0000000______0000____0000______0000000\n");
        printf("0000000_______00______00_______0000000\n");
        printf("0000000________________________0000000\n");
        printf("0000000______0__________0______0000000\n");
        printf("00000000______00______00______00000000\n");
        printf("000000000_______000000_______000000000\n");
        printf("00000000000________________00000000000\n");
        printf("00000000000000___________0000000000000\n");
        printf("00000000000000000000000000000000000000\n");
        printf("00000000000000000000000000000000000000\n");
    }else{
        printf("Você errou! Tente novamente\n");
        printf("\n\n");
        printf("                $$$$\n");
        printf("              $$    $$\n");
        printf("              $$    $$\n");
        printf("              $$    $$\n");
        printf("              $$    $$\n");
        printf("              $$    $$\n");
        printf("          $$$$$$    $$$$$$\n");
        printf("        $$    $$    $$    $$$$\n");
        printf("        $$    $$    $$    $$  $$\n");
        printf("$$$$$$__$$    $$    $$    $$    $$\n");
        printf("$$    $$$$                $$    $$\n");
        printf("$$      $$                      $$\n");
        printf("  $$    $$                      $$\n");
        printf("  $$$   $$                      $$\n");
        printf("    $$                          $$\n");
        printf("     $$$                        $$\n");
        printf("      $$                      $$$\n");
        printf("       $$$                    $$\n");
        printf("        $$                   $$\n");
        printf("        $$$                 $$$\n");
        printf("          $$                $$\n");
        printf("          $$$$$$$$$$$$$$$$$$$$\n");
    }

    return 0;
}
