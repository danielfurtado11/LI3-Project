#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include "../libs/print.h"
#include "../libs/funcoes.h"
#include "../libs/queries.h"
#include "../libs/users.h"



/* Print da querie 7*/
void funcao7(){
        char data[11];
        printf("Insira a data pretendida neste formato (YYYY-MM-DD):\n");
        scanf("%s",data);
        if(data[4]!= '-' || data[7]!='-'){
            printf("Data apresentada encontra-se inválida\n");
            return;
        }
        else {
            int i =query7(data);
            FILE *f = fopen("../guiao-3/saida/validq7.csv","r+");
            if(!f) {printf("ERRO\n"); return ;}
            pages(f, i);
            fclose(f);
        }
}


