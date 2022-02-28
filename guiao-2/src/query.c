#define __USE_XOPEN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include "../libs/query.h"
#include "../libs/users.h"
#include "../libs/commits.h"
#include "../libs/repos.h"
#include "../libs/auxiliar.h"






//------------------------------- QUERY 1

void query1 (int x) {
    clock_t begin = clock();
    //determina o nome do ficheiro
    char text[100];
    sprintf(text, "../guiao-2/saida/command_%d.txt", x);
    FILE *fp = fopen (text, "w+");
    if (!fp) printf("Não existe ficheiro.\n");
    
    INFO_USER users = data_User();
    int size = get_Size_U(users);
    GH_USER * arr_U = get_Array_U(users);
    
    int bot = 0, user = 0, organization = 0;

    for(int i = 0; i< size; i++){
    
        char * s = get_Type(arr_U[i]);

        if (!strcmp(s, "Organization")) organization++;
        if (!strcmp(s, "Bot")) bot++;
        if (!strcmp(s, "User")) user++;
    }

    fprintf (fp, "Bot: %d\nOrganization: %d\nUser: %d\n",bot,organization,user);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Query 1 concluída.\n");
    printf("Tempo de execução: %f segundos.\n\n",time_spent);
    fclose(fp);
}



//------------------------------- QUERY 2

void query2(int x){
    clock_t begin = clock();
    char text[100];
    int maximo = 100;
    int i=0, colab = 0;
    int *aux_id = malloc (maximo * sizeof(int));
    sprintf(text, "../guiao-2/saida/command_%d.txt", x);
    FILE *fp = fopen (text, "w+");
    if (!fp) printf("Não existe ficheiro.\n");

    INFO_USER users = data_User();
    int sizeU = get_Size_U(users);
    GH_USER * arrU = get_Array_U(users);

    INFO_COMMIT commits = data_Commit();
    int sizeC = get_Size_C(commits);
    GH_COMMIT * arrC = get_Array_C(commits);


    INFO_REPOS repos = data_Repos();
    int sizeR = get_Size_R(repos);

    quicksort_AUTHORID(arrC, 0, sizeC);
    

    for (int j = 0; j < sizeU; j++){
        long  r = binarySearch(arrC, get_ID(arrU[j]), 0, sizeC-1);
        if(r == -1){
            
            if (i == maximo) {
                maximo += maximo * 0.4;
                aux_id = realloc(aux_id, maximo * sizeof(int));
            }
            aux_id[i] = get_ID(arrU[j]);
            i++;
        }
        else colab++;    
        }
    
    
    quicksort_COMMITERID(arrC, 0, sizeC);
    

    for (int k = 0; k < i; k++){
        if (binarySearch_C_COMMITER(arrC, 0, sizeC - 1, aux_id[k]) != -1) colab++;
        
    }
    
    float final = (float)colab / (float)sizeR;

    fprintf(fp, "%0.2f", final);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Query 2 concluída.\n");
    printf("Tempo de execução: %f segundos.\n\n",time_spent);

    
    fclose(fp);

}



//------------------------------- QUERY 3

void query3(int x){
    clock_t begin = clock();
    char text[100];
    int maximo = 100;
    int i = 0, colab = 0;
    int *aux_id = malloc (maximo * sizeof(int));
    int *aux_colaboradores = malloc(maximo * sizeof(int));

    sprintf(text, "../guiao-2/saida/command_%d.txt", x);
    FILE *fp = fopen (text, "w+");
    if (!fp) printf("Não existe ficheiro.\n");

    
    INFO_USER users = data_User();
    int sizeU = get_Size_U(users);
    GH_USER * arrU = get_Array_U(users); 

    INFO_COMMIT commits = data_Commit();
    int sizeC = get_Size_C(commits);
    GH_COMMIT * arrC = get_Array_C(commits);    
    
    INFO_REPOS repos = data_Repos();
    int sizeR = get_Size_R(repos);
    GH_REPOS * arrR = get_Array_R(repos);

    quicksort_AUTHORID(arrC, 0, sizeC);  // ordena os array pelo o author_id
    


    for (int j = 0; j < sizeU; j++){
        int  r = binarySearch(arrC, get_ID(arrU[j]), 0, sizeC - 1);
        char * s = get_Type(arrU[j]);   


        if((r == -1) && (!strcmp(s, "Bot"))) 
        {                                       
            if (i == maximo)                            
                {                                      
                maximo += maximo;
                aux_id = realloc(aux_id, maximo * sizeof(int));
                } 
                
            aux_id[i] = get_ID(arrU[j]);          
            i++;
        }
        
        else if ((r != -1) && (!strcmp(s, "Bot"))) {          
            if (colab == maximo) {
                colab += maximo;                            
                aux_colaboradores = realloc(aux_colaboradores, maximo * sizeof(int));
            } 
            aux_colaboradores[colab] = get_ID(arrU[j]);
            colab++;
        }
    }
    
    
    quicksort_COMMITERID(arrC, 0, sizeC); 


    for (int k = 0; k < i; k++)
        {

        char * c = get_Type(arrU[k]);
        if ((binarySearch_C_COMMITER(arrC, 0, sizeC - 1, aux_id[k]) != -1) && (!strcmp(c, "Bot"))) {
            aux_colaboradores[colab] = get_ID(arrU[k]);
            colab++;
            }

        }
    
    quicksort_REPOS (arrR,0,sizeR);
    int total = 0;
    for (int curry = 0; curry < colab; curry++){
        if (binarySearch_REPOS(arrR,0,sizeR-1,aux_colaboradores[curry]) != -1) total++;
        }

    fprintf(fp, "%d", total);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Query 3 concluída.\n");
    printf("Tempo de execução: %f segundos.\n\n",time_spent);

    fclose(fp);
}



//------------------------------- QUERY 4

void query4 (int x) {
    clock_t begin = clock();
    char text[100];
    sprintf(text, "../guiao-2/saida/command_%d.txt", x);
    FILE *fp = fopen (text, "w+");
    if (!fp) printf("Não existe ficheiro.\n");
    
    INFO_USER users = data_User();
    int sizeU = get_Size_U(users);

    INFO_COMMIT commits = data_Commit();
    int sizeC = get_Size_C(commits);

    float i = (float)sizeU / (float)sizeC;

    fprintf(fp, "%0.2f", i);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Query 4 concluída.\n");
    printf("Tempo de execução: %f segundos.\n\n",time_spent);

    fclose(fp);

}



//------------------------------- QUERY 5

void query5 (int x, int n, char *data1, char *data2) {
    clock_t begin = clock();
    char text[100];

    sprintf(text, "../guiao-2/saida/command_%d.txt", x);
    FILE *fp = fopen (text, "w+");
    if (!fp) printf("Não existe ficheiro.\n");
    
    int maximo = 100, j = 0;
    int *aux_id = malloc (maximo * sizeof(int));

    INFO_USER users = data_User();
    int sizeU = get_Size_U(users);
    GH_USER * arrU = get_Array_U(users); 

    INFO_COMMIT commits = data_Commit();
    int sizeC = get_Size_C(commits);
    GH_COMMIT * arrC = get_Array_C(commits); 



    for(int i = 0; i< sizeC; i++){

    char *act = get_Commit_at(arrC[i]);
    int r = dateq5(data1, data2, act);

    if ( r == 1) {

        if (j == maximo) {
            maximo += maximo;
            aux_id = realloc(aux_id, maximo * sizeof(int));
            }


        aux_id[j] = get_Committer_ID(arrC[i]);
        j++;
        }
    }

    quicksort(aux_id, 0, j);

    int l = j;
    int b;
    int max;
    int g;
    char *login;

    while (n>0) {
        max = mostFrequent(aux_id, l);
        b = l;
        l = remove_occurences(max, aux_id, l);
        b = b - l;

        for(g = 0; sizeU; g++){

            if (max == get_ID(arrU[g])) {
                login = get_Login(arrU[g]); 
                break;
            }
        }

    fprintf(fp, "%d;%s;%d\n",get_ID(arrU[g]), login, b);
        n--;

    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Query 5 concluída.\n");
    printf("Tempo de execução: %f segundos.\n\n",time_spent);

    fclose(fp);

    }



//------------------------------- QUERY 6

void query6(int x, int n, char *language1){
    clock_t begin = clock();
    char text[100];
    sprintf(text, "../guiao-2/saida/command_%d.txt", x);
    FILE *fp = fopen (text, "w+");
    if (!fp) printf("Não existe ficheiro.\n");
    char *language = remove_last(language1);

    int maximo = 100, i = 0, max = 100;
    int *aux_id = malloc (maximo * sizeof(int));
    int *aux_commit = malloc(max * sizeof(int));

    INFO_USER users = data_User();
    int sizeU = get_Size_U(users);
    GH_USER * arrU = get_Array_U(users); 

    INFO_COMMIT commits = data_Commit();
    int sizeC = get_Size_C(commits);
    GH_COMMIT * arrC = get_Array_C(commits);    
    
    INFO_REPOS repos = data_Repos();
    int sizeR = get_Size_R(repos);
    GH_REPOS * arrR = get_Array_R(repos);

    for (int j = 0; j < sizeR; j++){
        char *lang = get_language(arrR[j]);

        if (!strcmp(lang,language)){


            if (i == maximo)
                {                                      
                maximo += maximo;
                aux_id = realloc(aux_id, maximo * sizeof(int));
                }

                aux_id[i] = get_ID_R(arrR[j]);
                i++;
        } 
    }

    int v = 0;

    for(int f = 0; f<i; f++){
        int val = aux_id[f];
        for(int c = 0; c < sizeC; c++){
            int rep = get_Rep_ID(arrC[c]);
            if (val == rep) {

                if (v == max) {
                max += max;
                aux_commit = realloc(aux_commit, max * sizeof(int));
                }

                aux_commit[v++] = get_Committer_ID(arrC[c]);
            }
        }
    }


    quicksort(aux_commit, 0, v);

    int l=v, b,freq;
    
    while (n>0) {
        freq = mostFrequent(aux_commit, l);
        b = l; // tamanho antigo do array
        l = remove_occurences(freq, aux_commit, l); // devolve o tamanho novo do array
        b = b-l; // nº de ocorrencias que aparece

        quicksortUSER(arrU,0,sizeU);
        char *log = binarySearch_U_Login(arrU,0,sizeU, freq);



        fprintf(fp,"%d;%s;%d\n",freq,log, b);
        n--;
    }

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Query 6 concluída.\n");
    printf("Tempo de execução: %f segundos.\n\n",time_spent);

    fclose(fp);

}



//------------------------------- QUERY 7

void query7(int x, char *data) {

    clock_t begin = clock();
    char text[100];

    sprintf(text, "../guiao-2/saida/command_%d.txt", x);
    FILE *fp = fopen (text, "w+");
    if (!fp) printf("Não existe ficheiro.\n");
    
    INFO_COMMIT commits = data_Commit();
    int sizeC = get_Size_C(commits);
    GH_COMMIT * arrC = get_Array_C(commits);    
    
    INFO_REPOS repos = data_Repos();
    int sizeR = get_Size_R(repos);
    GH_REPOS * arrR = get_Array_R(repos);

   
    int j = 0, maximo =100;
    int *aux_id = malloc (maximo * sizeof(int));

    for(int i = 0; i < sizeC; i++){

        char  *act = get_Commit_at(arrC[i]);
        int r = dateq7(data, act);

        if (r == 1){
        
        if (j == maximo) {
            maximo += maximo;
            aux_id = realloc(aux_id, maximo * sizeof(int));
            }
            
        aux_id[j] = get_Rep_ID(arrC[i]);
        j++;
        }    
    }
    quicksort(aux_id, 0, j);
    j = remove_duplicate(aux_id, j);

    quicksort_R_ID(arrR,0,sizeR);

    for(int k = 0; k<j; k++){
    char * desc = binarySearch_R_DESC(arrR, 0, sizeR-1,aux_id[k]);
    fprintf(fp,"%d;%s\n", aux_id[k], desc);
    }


    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Query 7 concluída.\n");
    printf("Tempo de execução: %f segundos.\n\n",time_spent);
    fclose(fp);
}












































