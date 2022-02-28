#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include "../libs/print.h"


/* Array com strings necessárias */
char *statica[] = {"+---------------------------------------------Query 1-------------------------------------------+",
                   "+---------------------------------------------Query 2-------------------------------------------+",
                   "+---------------------------------------------Query 3-------------------------------------------+",
                   "+---------------------------------------------Query 4-------------------------------------------+",
                   "+---------------------------------------------Query 7-------------------------------------------+",};



/*
* Array com as frase necessárias
*/
char *frase[] = {"|                                              Menu                                             |",
                "|                                      Queries estatisticas                                     |",
                "| 1  | Quantidade de Bots, Organizações e Utilizadores                                          |",
                "| 2  | Número médio de utilizadores por repositório                                             |",
                "| 3  | Quantidade de repositório com Bots                                                       |",
                "| 4  | Quantidade média de commits por Utilizadores                                             |",
                "|                                     Queries parametrizaveis                                   |",
                "| 5  | Top N Utilizadores mais ativos entre duas datas                                          |",
                "| 6  | Top N Utilizadores com mais commits em repositórios numa determinada linguagem           |",
                "| 7  | Repositórios inativos a partir de uma determinada data                                   |",
                "| 8  | Top N linguagens mais utilizadas a patir de uma determinada datas                        |",
                "| 9  | Top N Utilizadores com mais commits em repositórios cujo dono é seu amigo                |",
                "| 10 | Top N Utilizadores com maiores mensagens de commits por repositórios                     |",
                "| 11 | Sair                                                                                     |"};


char * frases(int x){
    char * string = strdup(frase[x]);
    return string; 
}



/* Função de printar a query 1 */
void print1(int bots, int org, int user){
    printf("%s\n",statica[0]);
    espaco_queryestatistica();
    printf("                                              Bots:%d\n",bots);
    printf("                                              Organizations:%d\n",org);
    printf("                                              Users:%d\n",user);
    espaco_queryestatistica();
    separador();
}


/* Função de printar a query 2*/
void print2(float i){
    printf("%s\n",statica[1]);
    espaco_queryestatistica();
    printf("                               Número médio de utilizadores por repositório:%0.2f\n",i);
    espaco_queryestatistica();
    separador();
}


/* Função de printar a query 3*/
void print3(int x){
    printf("%s\n",statica[2]);
    espaco_queryestatistica();
    printf("                                Quantidade de repositório com Bots:%d\n",x);
    espaco_queryestatistica();
    separador();
}


/* Função de printar a query 4 */
void print4(float i){
    printf("%s\n",statica[3]);
    espaco_queryestatistica();
    printf("                               Quantidade média de commits por Utilizadores:%0.2f\n",i);
    espaco_queryestatistica();
    separador();
}


/* Função responsável pelo os separados */
void separador(){
    printf("+-----------------------------------------------------------------------------------------------+\n");
}


/* Função responsável pelo os espaços */
void espaco(){
    printf("|                                                                                               |\n");
}


/* Função responśavel pelo os espaços nas queries estatisticas */
void espaco_queryestatistica(){
    printf("                                                                                                 \n");
}


/* Função para a cor vermelha */
void red () {
  printf("\033[1;31m");
}


/* Função para dar reset a cor */
void reset(){
    printf("\033[0m");

}




int pages(FILE *f, int i) {
    char buffer[200000];
    int pag = i/5; // Número de páginas
    int j, x = 1; // página atual
    char escolha[30];

    printf("\n");
    
    // Caso o número de páginas seja 1 ou seja existam menos de 5 linhas em cada ficheiro
    if (pag == 0) {
        printf("%s\n",statica[4]);
        while (i>0){
            fgets(buffer,20000,f);
            printf("%s", buffer);
            i--;
        }
        separador();
        rewind(f);
    }


    while (x>=1 && x <= pag) {

        for(j = 1; j<=i; j++){

            fgets(buffer,20000,f);

            if (pag == 0) {
            printf("%s",statica[4]);
            while (i>0){
            fgets(buffer,20000,f);
            printf("%s", buffer);
            i--;
        }
        separador();
        rewind(f);
    }

            if (x*5-4 == j) {
                printf("%s\n",statica[4]);
                printf("%s", buffer);

                fgets(buffer,200000,f);
                printf("%s",buffer);

                fgets(buffer,200000,f);
                printf("%s",buffer);

                fgets(buffer,200000,f);
                printf("%s",buffer);

                fgets(buffer,200000,f);
                printf("%s",buffer);

                j = i;
                
            }

        }
        rewind(f);

        printf("+------------------------------------------Página %d de %d---------------------------------------+\n",x,pag);
        red();
        puts("P     ->Pŕoximo\nA     ->Anterior\nS<N> ->Saltar para página \nE     ->Exit\n");
        reset();
        printf("Insira Opção: ");
        scanf("%s",escolha);

        if (strcmp(escolha, "P") == 0) x++;
        else if (strcmp(escolha, "A") == 0) x--;
        else if (strcmp(escolha, "E") == 0) {printf("Regressou ao menu.\n\n");return 0;}
        else if (escolha[0] == 'S') {
            x = atoi(&escolha[1]);
        }
        printf("\n\n");
    }

    return 0;
}


