#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //Imprime o cabecalho do Jogo
    //printf("====================================\n");
    //printf("* Bem vindo ao jogo de adivinhacao *\n");
    //printf("====================================\n");
    printf("\n\n");
    printf("  /\\_/\\  (                              \n");
    printf(" ( ^.^ ) _)                               \n");
    printf("   \\ /  (           Bem vindo ao          \n");
    printf(" ( | | )         Jogo de Adivinhacao!     \n");
    printf("(__d b__)                                 \n\n");

    

    //Variaveis
    int segundos = time(0);
    srand(segundos);
    
    int numerogrande = rand();
    int numerosecreto = numerogrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int nivel;
    printf("Escolha o nivel de dificuldade:\n");
    printf("(1) Facil\n");
    printf("(2) Medio\n");
    printf("(3) Dificil\n");
    scanf("%d",&nivel);
    
    int numerodetentativas = 0;

    switch(nivel){
        case 1:
            numerodetentativas = 20;
            break;
        case 2:
            numerodetentativas = 15;
            break;
        case 3:
            numerodetentativas = 6;
            break;
        default:
            printf("Digite um nivel de dificuldade correto!!!");
            break;
    }

    int acertou = 0;

    //for(int i=1; i<= NUMERO_DE_TENTATIVAS;i++)
    for(int i = 1; i <= numerodetentativas; i++){
        printf("Tentativa %d\n",tentativas);
        printf("Qual e o seu chute? ");
        scanf("%d", &chute);
        printf("\nSeu chute foi %d\n",chute);

        if(chute < 0){
            printf("Voce nao pode chutar numeros negativos!!");
            continue;
        }

        //Booleanos, verdadeiro==1, falso==0
        acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);

        //O programa falara se o numero chutado e maior ou menor do que o numero secreto
        if(acertou){
            break;

        }else if(maior){
            printf("\nSeu chute foi maior que o numero secreto!\nTente novamente!\n");
        }else{
            printf("\nSeu chute foi menor que o numero secreto!\nTente novamente!\n");
        }
        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }
    
    if(acertou){
        printf("\n\n");
        printf("         /\\_____/\\       \n");
        printf("        /  o   o  \\      \n");
        printf("       ( ==  ^  == )     \n");
        printf("        )         (      \n");
        printf("       (           )     \n");
        printf("      ( (  )   (  ) )    \n");
        printf("     (__(__)___(__)__)   \n");
        printf("\n\n");
        printf("\nVoce ganhou!!\n");
        printf("Voce acertou em %d tentativas\n",tentativas);
        printf("Total de pontos %.2f",pontos);
    }else {
        printf("\nVoce Perdeu!!\n");
        printf("\nTente Novamente!\n");
    }
;
}
