//incluindo bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>>

int main()

{
    //imprime cabecalho do jogo
    printf("----------------------------------\n");
    printf("|BEM VINDO AO JOGO DE ADIVINHACAO|\n");
    printf("----------------------------------\n\n");
	
	//declarando variaveis que vou utilizar 
	int chute; 
	int nivel; 
	int acertou; 
	int numerodetentativas; 
	
	//quantidade de pontos iniciais
	double pontos = 1000;
	
	//definindo numero randomico
	srand(time(0));
    int numerosecreto = rand() % 100;

	//variavel que vou utilizar como contador do for
	int i; 

	//escolhendo o nivel de dificuldade
	printf("\nEm qual nivel de dificuldade voce quer jogar?");
	printf("\n(1)Facil  (2)Medio  (3)Dificil: ");
	scanf("%d", &nivel);
	
	
	switch(nivel){
		case 1:
			numerodetentativas = 20;
			break;
		
		case 2:
			numerodetentativas = 15;
			break;
		
		default:
			numerodetentativas = 6;
			break;
	}
	
	// o loop principal do jogo
	for(i = 1; i <= numerodetentativas; i++){
		
    	printf("\nTentativa %d de %d\n", i, numerodetentativas);
    	
	    printf("Qual o chute? ");
	    scanf("%d", &chute);

		// quando o usuario chutar um numero negativo
	    if (chute <0){
	    	printf("voce nao pode chutar numeros negativos!\n\n");
	    	i--;
	    	continue;
	    }
	    
		int acertou = (chute == numerosecreto); 
	    int maior = (chute > numerosecreto);

		if(acertou){
			break;
		}else if(maior){
	    	printf("Seu chute foi maior que o numero secreto\n\n");
	    }else{
	    	printf("Seu chute foi menor que o numero secreto\n\n");
	    }
		
		//calculando pontos perdidos
		double pontosperdidos = abs(chute - numerosecreto) / (double)2;
		pontos = pontos - pontosperdidos; 
	    
	}
	
	printf("Fim de jogo\n\n");
		
	if(acertou){
		printf("Parabens! Voce acertou em %d tentativas\n\n", i);
	}else{
		printf("Voce teve %d tentativas e nao acertou", numerodetentativas);
	}
	
	printf("\nTotal de pontos: %.1f\n", pontos);	
			
}
		



