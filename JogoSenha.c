#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int cor[4];
}combinacao;

int main(void){
    combinacao z;
    int a;
    int i,j,k,l,chances,chances_2, dificuldade;
    int tentativa[4];
    int nseq,nseqepos;
    
    
    /* gerando a senha aleatoria */
    srand(time(NULL));

    for (i = 0; i < 4; i++){
        a=rand() % 10;
        z.cor[i]=a;
    }
    
    printf("|REGRAS:                                                                                |\n");
    printf("|1: O jogador tera entre 8 e 12 tentativas dependendo da dificuldade escolhida;         |\n");
    printf("|2: O jogador tera que digitar um numero de cada vez da sua tentativa de senha;         |\n");
    printf("|3: Apos a tentativa de senha, o jogo retornara a analise da senha da seguinte forma:   |\n");
    printf("|          O jogo retornara um frase dizendo primeiro quantos numeros estao na posicao  |\n");
    printf("|          correta, e depois quantos números apenas existem na sequencia;               |\n");
    printf("|4: O jogador vencera caso descubra a senha dentro do numero de tentativas.             |\n");
    printf("\n");
    printf("                                      (SENHA)\n");
    printf("\n");
    printf("Selecione a dificuldade: 1-FACIL  |  2-MEDIO  |  3-DIFICIL \n");
    
    scanf("%d",&dificuldade);
    
    /* escolhendo a dificuldade */
    switch(dificuldade){
        case 1:
            chances=12;
            break;
        case 2:
            chances=10;
            break;
        case 3:
            chances=8;
            break;
        default:
            printf("dificuldade invalida\n");
            break;
    }

    /* jogando-> digitando os numeros da tentativa */
    chances_2=chances;
    for(i=0; i<chances;i++){
        printf("insira os numeros da sequencia(0 a 9) \n");
        for(j=0;j<4;j++){
            scanf("%d",&tentativa[j]);
        }
        nseqepos=0;
        nseq=0;
        for ( k = 0; k < 4; k++ ){
                if (tentativa[k] == z.cor[k]){
                    nseqepos=nseqepos+1;
                }
                for ( j = 0; j < 4; j++ ){
                    if(tentativa[j] == z.cor[k]){
                        nseq=nseq+1; 
                        break;      
                    }
                }

            }
        printf("numeros na senha e na ordem %d numeros na senha %d\n",nseqepos,nseq);
        printf("voce ainda tem %d chances\n",chances_2-1);
        if(nseqepos==4){
            printf("parabens voce acertou a senha, a senha era (%d|%d|%d|%d)\n",z.cor[0],z.cor[1],z.cor[2],z.cor[3]);
            break;
        }
        chances_2-=1;
    }
    if(chances_2==0){
        printf("infelizmente voce nao acertou a senha, a senha era (%d|%d|%d|%d)\n",z.cor[0],z.cor[1],z.cor[2],z.cor[3]);
    }
    printf("\n\nDeseja jogar novamente? 1-Sim, 2-Nao :\n");
    scanf("%d",&l);

    if (l == 1){
        main();
    }
    return 0;
}