#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <stdint.h>
#include "../libs/funcoes.h"
#include "../libs/queries.h"
#include "../libs/maing1.h"
#include "../libs/print.h"
#include "../libs/users.h"
#include "../libs/commits.h"
#include "../libs/repos.h"



/*
* Função responsável pelo menu
*/
void init(){
    int choice;
    for (choice = 0; choice <= 13; choice++){
        switch (choice)
        {
        case 0:
            separador();
            espaco();
            printf("%s\n",frases(0));
            espaco();
            separador();
            break;
        case 1:
            espaco();
            printf("%s\n",frases(1));
            espaco();
            separador();
            break;
        case 2:
            printf("%s\n",frases(2));
            separador();
            break;
        case 3:
            printf("%s\n",frases(3));
            separador();
            break;
        case 4:
            printf("%s\n",frases(4));
            separador();
            break;
        case 5:
            printf("%s\n",frases(5));
            separador();
            break;
        case 6:
            espaco();
            printf("%s\n",frases(6));
            espaco();
            separador();
            break;
        case 7:
            printf("%s\n",frases(7));
            separador();
            break;
        case 8:
            printf("%s\n",frases(8));
            separador();
            break;
        case 9:
            printf("%s\n",frases(9));
            separador();
            break;
        case 10:
            printf("%s\n",frases(10));
            separador();
            break;
        case 11:
            printf("%s\n",frases(11));
            separador();
            break;
        case 12:
            printf("%s\n",frases(12));
            separador();
            break;
        case 13:
            printf("%s\n",frases(13));
            separador();
            break;

        
        default:
            break;
        }
    }
}



/*
 * Função responśavel pelo menu 
*/
void menu (ARR_TYPE users, ARRDUP colaborator, REPOSALL repos){

    int escolha; 	
    	init();
        do{
        printf("Insira opção:\n");
        scanf("%d",&escolha);
         switch (escolha)
        {
            case 1:
                query1(users);
                break;
            case 2:
                query2(colaborator, repos);
                break;
            case 3:
                query3(colaborator);
                break;
            case 4:
                query4(users);
                break;
            /* Queries Parametrizáveis */
            case 5:
                printf("Dados indisponíveis.\n\n");
                break;
            case 6:
                printf("Dados indisponíveis.\n\n");
                break;
            case 7:
                funcao7();
                break;
            case 8:
                printf("Dados indisponíveis.\n\n");
                break;
            case 9:
                printf("Dados indisponíveis.\n\n");
                break;
            case 10:
                printf("Dados indisponíveis.\n\n");
                break;                              
            case 11:
            printf("Menu encerrado.\n"); 
                break;
                default: printf("Escolha inválida. Escolha novamente.\n");
        }
           int ch;
         while ((ch = getchar()) != '\n' && ch != EOF); // limpa o input do teclado para nao permitir loops
        }   
        while (escolha != 11);
}


int main(int argc, char **argv){
    char text[100];
    int i = 1,j;
    if (access("../guiao-3/saida/users-ok.csv", F_OK) != 0){
        clock_t begin = clock();
        maing1();
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Tempo de execução a filtrar ficheiros: %f segundos.\n\n",time_spent);
    }

    clock_t begin = clock();
    printf("Analisando ficheiros...\n");
    ARR_TYPE users = sum_Type();
    ARRDUP colaborator = colabor();
    REPOSALL repos = allrepos();
    printf("Análise completa\n\n");

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo de execução a analisar ficheiros: %f segundos.\n\n",time_spent);

    if (argc == 1) menu(users, colaborator, repos);

    if (argc == 2) {
            char *file = argv[1];
            char * linha;
            char data[11];
            int n;
            sprintf(text,"../guiao-3/entrada/%s",file);
            FILE *f = fopen(text, "r+");
            if(!f) {printf("Não existe ficheiro.\n"); return -1;}

            char buffer[80];
            char *buffer2 = buffer;
            
            while (fgets(buffer2, 40, f)){
                    switch (buffer[0])
                {
                case '1':
                query1(users);
                printf("\n");
                break;
    
                case '2':
                query2(colaborator, repos);
                printf("\n");
                break;

                case '3':
                query3(colaborator);
                printf("\n");
                break;
    
                case '4':
                query4(users);
                printf("\n");
                break;

                case '7':
                linha = strdup(buffer2);
                sscanf(linha,"%d %s", &n, data);
                printf("%s\n",data);
                j = query7(linha);
                FILE *f = fopen("../guiao-3/saida/validq7.csv","r+");
                if(!f) {printf("ERRO\n"); return 0;}
                pages(f, j);
                fclose(f);
                printf("\n");
                break;

                default:
                    break;
            }

            i++;
        }
        return 0;
    }
    return 0;
}