#include "../libs/commits.h"
#include "../libs/users.h"
#include "../libs/repos.h"
#include "../libs/print.h"
#include "../libs/auxiliar.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void query1 (ARR_TYPE users) {


    FILE *f0 = fopen ("../guiao-3/saida/q1output.txt", "w+");
    FILE *fp = fopen ("../guiao-3/saida/q1.txt", "w+");
    if (!fp) printf("Não existe ficheiro.\n");

    int bots = get_Bot(users);
    int org = get_Org(users);
    int user = get_User(users);

    print1(bots,org,user);


    fprintf (fp, "%d\n%d\n%d\n",user,org,bots);
    fprintf (f0, "Bot: %d\nOrganization: %d\nUser: %d\n",bots,org,user);
    fclose(f0);
    fclose(fp);
}



void query2(ARRDUP clb, REPOSALL new){

    FILE *f0 = fopen ("../guiao-3/saida/q2output.txt", "w+");
    int sizeR = getsizeR(new);
    
    int colab = get_SIZE_ARR(clb);
    
    float final = (float)colab / (float)sizeR;
    fprintf(f0, "%0.2f", final);
    fclose(f0);
    print2(final);
}




void query3(ARRDUP new) {

    FILE *f0 = fopen ("../guiao-3/saida/q3output.txt", "w+");
    FILE*fp = fopen("../guiao-3/saida/bots.txt","r+");
    if(!fp) {
        sum_Type();
        fp = fopen("../guiao-3/saida/bots.txt", "r+");
    }
    if(!fp) {printf("ERRO\n"); return;}
    char buffer[20], *buffer2;


    int *arr1 = get_ARR_DUP(new);
    int colab = get_SIZE_ARR(new); 

    int c = 0;
    
    while(fgets(buffer, 20, fp)){
        buffer2 = buffer;

        int id = atoi(buffer2);

        int i = binarySearch(arr1,id,0,colab);
        if(i != -1) c++;
    }
    fprintf(f0, "%d", c);
    fclose(f0);
    print3(c);
}




void query4(ARR_TYPE users) {

    int user;
    int commits;
    FILE *f0 = fopen("../guiao-3/saida/q4output.txt", "w+");

    user = get_User(users);

    FILE *fp = fopen("../guiao-3/saida/ncommits.txt", "r+");
    if(!fp) colabor();
    
    char buffer1[70], *buffer3;
    fgets(buffer1, 700000, fp);
    buffer3 = buffer1;
    commits = atoi(buffer3);
    fclose(fp);

    float i = (float)user / (float)commits;
    fprintf(f0, "%0.2f", i);
    fclose(f0);
    print4(i);
}



int query7(char * data){

    char buffer[700000], *buffer2;
    int id, x, c = 0;
    DATEV datainput = sep_datevalid(data);
    ARRDUP dates = readCommits(datainput);
    int *arr = get_ARR_DUP(dates);
    int size = get_SIZE_ARR(dates);

    FILE *f = fopen("../guiao-3/saida/reposid.csv","r+");
    if(!f) {printf("Não existe ficheiro.\n"); return 0;}
    FILE *fp = fopen("../guiao-3/saida/validq7.csv","w+");
    if(!fp) {printf("Não existe ficheiro.\n"); return 0;}

    while (fgets(buffer,700000,f)){
        buffer2 = buffer;
        char *string = strdup(buffer2);
        char *linha = strdup(buffer2);
        id = atoi((strsep(&linha,";")));
        x = binarySearch(arr,id,0,size);
        if(x == -1) {
            fprintf(fp,"%s",string); 
            c++;
        }   
    }
    fclose(fp);
    fclose(f);
    return c;
}
