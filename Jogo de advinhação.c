#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

int main(){
	
	//fun��o para a aceita��o de acentos
	setlocale(LC_ALL, "Portuguese");

    //imprime cabecalho do jogo
    
    printf("         _____             _____        \n ");                     
    printf("        |   |             |   |       \n ");
	printf("       (_____)           (_____)      \n ");
    printf("        |   |  _   _   _  |   |       \n ");
    printf("        | O |_| |_| |_| |_| O |       \n ");
    printf("        |-  |          _  | - |       \n ");
    printf("        |   |   - _^_     |   |       \n ");
	printf("        |  _|      |    - |   |       \n ");
 	printf("        |   |   _______   |  -|       \n ");
   	printf("        |-  |_  |||||||   |   |       \n ");
  	printf("        |   |   |||||||   |-  |       \n ");
  	printf("        |___|___|||||||___|___|       \n ");
   
   
    printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de adivinha��o *\n");
    printf("******************************************\n\n");

	//declara��o de numero randomico
    int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();

	//declar��o de numero secreto
    int numerosecreto = numerogrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;;

    int nivel;
    printf("Qual o n�vel de dificuldade?\n");
    printf("(1) F�cil (2) M�dio (3) Dif�cil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int i;
    int numerodetentativas = 5;

	//switch case para definir o nivel de dificuldade 
    switch(nivel) {
        case 1:
            numerodetentativas = 20;
            break;

        case 2:
            numerodetentativas = 15;
            break;

        default:
            numerodetentativas = 5;
            break;
	}

	//la�o de repeti��o para realizar os chutes do usuario
    for(i=1; i <= numerodetentativas; i++) {

        printf("Tentativa %d\n", tentativas);
        printf("Qual � o seu chute? ");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0) {
            printf("Voc� n�o pode chutar n�meros negativos!\n");
            continue;
        }

		//variavel booleana "acertou"
		//dicas sobre o numero secreto
        acertou = (chute == numerosecreto);
        int maior = chute > numerosecreto;

        if(acertou){
            break;
        }

        else if(maior) {
            printf("Seu chute foi maior que o n�mero secreto\n");
        }

        else {
            printf("Seu chute foi menor que o n�mero secreto\n");
        }

        tentativas++;
		
		//calculo dos pontos perdidos usando variavel double
		//abs � o que transforma valores em modulo, evitando que fiquem negativos
        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
	}

    printf("Fim de jogo!\n");

    if(acertou) {
        printf("Voc� ganhou!\n");
        printf("Voc� acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    } else {
        printf("Voc� perdeu! Tente de novo!\n");
    }


}
