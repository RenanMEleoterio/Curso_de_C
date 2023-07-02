#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char jogadas[9];
char chutes[9];

void abertura(){

    printf("▄▄▄▄   ▓██████  ███▄    █     ██▒   █▓ ██▓ ███▄    █ ▓█████▄  ▒█████   ▐██▌  ▐██▌          \n");
    printf("▓█████▄ ▓█   ▀  ██ ▀█   █    ▓██░   █▒▓██▒ ██ ▀█   █ ▒██▀ ██▌▒██▒  ██▒ ▐██▌  ▐██▌          \n");
    printf("▒██▒ ▄██▒███   ▓██  ▀█ ██▒    ▓██  █▒░▒██▒▓██  ▀█ ██▒░██   █▌▒██░  ██▒ ▐██▌  ▐██▌          \n");
    printf("▒██░█▀  ▒▓█  ▄ ▓██▒  ▐▌██▒     ▒██ █░░░██░▓██▒  ▐▌██▒░▓█▄   ▌▒██   ██░ ▓██▒  ▓██▒          \n");
    printf("░▓█  ▀█▓░▒████▒▒██░   ▓██░      ▒▀█░  ░██░▒██░   ▓██░░▒████▓ ░ ████▓▒░ ▒▄▄   ▒▄▄           \n");
    printf("░▒▓███▀▒░░ ▒░ ░░ ▒░   ▒ ▒       ░ ▐░  ░▓  ░ ▒░   ▒ ▒  ▒▒▓  ▒ ░ ▒░▒░▒░  ░▀▀▒  ░▀▀▒          \n");
    printf("▒░▒   ░  ░ ░  ░░ ░░   ░ ▒░      ░ ░░   ▒ ░░ ░░   ░ ▒░ ░ ▒  ▒   ░ ▒ ▒░  ░  ░  ░  ░          \n");
    printf(" ░    ░    ░      ░   ░ ░         ░░   ▒ ░   ░   ░ ░  ░ ░  ░ ░ ░ ░ ▒      ░     ░          \n");
    printf(" ░         ░  ░         ░          ░   ░           ░    ░        ░ ░   ░     ░             \n");
    printf("      ░                           ░                   ░                                    \n");
    
}

int escolhePalavra(){ 

    FILE * arq;
    arq = fopen("jogadas.txt", "r");
    if(arq == 0){
        printf("ERRO! ao abrir o banco de dados");
        exit(1);
    }

    int numeroDeJogadas;
    fscanf(arq, "%d", &numeroDeJogadas);
    srand(time(0));
    int randomico = rand() % 3;

    for(int i = 0; i <= randomico;i++){
        fscanf(arq, "%s", jogadas);
    }

    fclose(arq);
    return randomico;

}

int joga(){

    int chute;
    int aceita = 0;
    do
    {
        printf("Possíveis jogadas:\n\n");
        printf("[1] Pedra [2] Papel [3] Tesoura\n\n");
        printf("Digite sua jogada: ");
        scanf("%d", &chute);
        if(chute > 0 && chute <= 3){
            aceita = 1;
        }else{
            printf("\nJogava INVÁLIDA! Chute os números exibidos!\n");
        }
        printf("\n");
    } while (!aceita);
    
    return chute - 1;
}

int escolheChute(){

    FILE * arq;
    arq = fopen("jogadas.txt", "r");
    if(arq == 0){
        printf("ERRO! ao abrir o banco de dados");
        exit(1);
    }

    int numeroDeJogadas;
    int resposta = joga();

    fscanf(arq, "%d", &numeroDeJogadas);

    for(int i = 0; i <= resposta; i++){
        fscanf(arq, "%s", chutes);
    }

    fclose(arq);
    return resposta;
}

void exibeResultado(){
    abertura();
    int randomico = escolhePalavra();
    int resposta = escolheChute();
    int empate = resposta == randomico;
    if (empate){
        printf("Deu empate!\n\n");
    }else if (resposta == 1 && randomico == 0)
    {
        printf("Você VENCEU!! PARABÉNS.\n\n");
    }else if (resposta == 0 && randomico == 2)
    {
        printf("Você VENCEU!! PARABÉNS.\n\n");
    }else if (resposta == 2 && randomico == 1)
    {
        printf("Você VENCEU!! PARABÉNS.\n\n");
    }else if (resposta == 1 && randomico == 2)
    {
        printf("Você PERDEU!! Tente novamente.\n\n");
    }else if (resposta == 0 && randomico == 1)
    {
        printf("Você PERDEU!! Tente novamente.\n\n");
    }else if (resposta == 2 && randomico == 0)
    {
        printf("Você PERDEU!! Tente novamente.\n\n");
    }
    
    printf("A sua jogada foi %s e a do computador foi %s.\n\n", chutes, jogadas);
    printf("FIM DE JOGO\n\n");
}
   
int main()
{   
    exibeResultado();
       
    return 0;
}