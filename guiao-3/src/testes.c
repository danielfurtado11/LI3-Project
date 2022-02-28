#define __USE_XOPEN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include "../libs/funcoes.h"
#include "../libs/queries.h"
#include "../libs/maing1.h"
#include "../libs/print.h"
#include "../libs/users.h"
#include "../libs/commits.h"
#include "../libs/repos.h"


void comparaficheiro(FILE *fp1, FILE *fp2, FILE *fp3, int x, double time_spent)
{
     /* Duas variaveis */
    char fp = getc(fp1);
    char fe = getc(fp2);
  
    // ERROR - variável que se foca nos erros
    // POS - variável que se foca na posição dos erros
    // LINE - variável que se foca na linha dos erros
    int error = 0;
    fprintf(fp3,"ERROS DA QUERIE %d\n",x);
    while (fp != EOF && fe != EOF)    /*  EOF - end of file */
    {
        if (fp != fe)
        {
            error++;
        }
  
        fp = getc(fp1);
        fe = getc(fp2);
    }
    fprintf(fp3,"Número total de erros : %d\ttempo de execução:%0.6f\n",error,time_spent);
}

void teste1(FILE *fp3,ARR_TYPE users){
    clock_t begin = clock();
    query1(users);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    FILE *fp1 = fopen("../guiao-3/expected/query1output.txt", "r+");   // mudar os ficheiros
    FILE *fp2 = fopen("../guiao-3/saida/q1output.txt", "r+");
  
    if (fp1 == NULL || fp2 == NULL)
    {
       printf("Erro ficheiros não abertos 1.\n");
       exit(0);
    }
  
    comparaficheiro(fp1, fp2,fp3,1,time_spent);
  
    /* Fechar os dois ficheiros*/
    fclose(fp1);
    fclose(fp2);
    return ;
}


void teste2(FILE *fp3, ARRDUP colaborator, REPOSALL repos){
    clock_t begin = clock();
    query2(colaborator, repos);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    FILE *fp1 = fopen("../guiao-3/expected/query2output.txt", "r");   // mudar os ficheiros
    FILE *fp2 = fopen("../guiao-3/saida/q2output.txt", "r");
  
    if (fp1 == NULL || fp2 == NULL)
    {
       printf("Erro ficheiros não abertos 2.\n");
       exit(0);
    }
  
    comparaficheiro(fp1, fp2,fp3,2,time_spent);
  
    /* Fechar os dois ficheiros*/
    fclose(fp1);
    fclose(fp2);
    return;
}

void teste3(FILE *fp3, ARRDUP colaborator){
    clock_t begin = clock();
    query3(colaborator);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    FILE *fp1 = fopen("../guiao-3/expected/query3output.txt", "r");   // mudar os ficheiros
    FILE *fp2 = fopen("../guiao-3/saida/q3output.txt", "r");
  
    if (fp1 == NULL || fp2 == NULL)
    {
       printf("Erro ficheiros não abertos 3.\n");
       exit(0);
    }
  
    comparaficheiro(fp1,fp2,fp3,3,time_spent);
  
    /* Fechar os dois ficheiros*/
    fclose(fp1);
    fclose(fp2);
    return;
}

void teste4(FILE *fp3, ARR_TYPE users){
    clock_t begin = clock();
    query4(users);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    FILE *fp1 = fopen("../guiao-3/expected/query4output.txt", "r");   // mudar os ficheiros
    FILE *fp2 = fopen("../guiao-3/saida/q4output.txt", "r");
  
    if (fp1 == NULL || fp2 == NULL)
    {
       printf("Erro ficheiros não abertos 4.\n");
       exit(0);
    }
  
    comparaficheiro(fp1, fp2,fp3,4,time_spent);
  
    /* Fechar os dois ficheiros*/
    fclose(fp1);
    fclose(fp2);
    return;
}









int main(){

    ARR_TYPE users = sum_Type();
    ARRDUP colaborator = colabor();
    REPOSALL repos = allrepos();
    FILE *fp = fopen ("../guiao-3/saida/erros.txt", "w+");
    if (!fp) printf("Erro ao mostrar os testes\n");
    printf("\n");
    teste1(fp, users);
    printf("\n");
    teste2(fp,colaborator, repos);
    printf("\n");
    teste3(fp,colaborator);
    printf("\n");
    teste4(fp, users);
    printf("\n");
}
