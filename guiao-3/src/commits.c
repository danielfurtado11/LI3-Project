#define __USE_XOPEN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include "../libs/commits.h"
#include "../libs/auxiliar.h"

struct commit { 
    char *repo_id;
    char *author_id;
    char *committer_id;
    char *commit_at;
    char *message;
};

struct colab {
    int *author;
    int sizea;
};

struct datevalid {
    int year;
    int month;
    int day;
};


// Coloca a data na struct
DATEV sep_datevalid(char *linha) {
    DATEV date = malloc(sizeof(struct datevalid));
    char * string  = strdup(linha);
    date->year = atoi(strsep(&string, "-"));
    date->month = atoi(strsep(&string, "-"));
    date->day = atoi(strsep(&string, "\0"));
  return date;
}


// verifica se a data é fora do limite
int compareDatas (DATEV dfixa, DATEV dfile){
    int year = dfixa->year - dfile->year;
    int month = dfixa->month - dfile->month;
    int day = dfixa->day - dfile->day;

    if (year > 0 ) return 0;
    else if (year == 0 && month > 0) return 0;
    else if (year == 0 && month == 0 && day > 0) return 0;
    else return 1;
}


// Funções sobre a struct dos Commits
GH_COMMIT separate_c (char *string) {
    char *linha = strdup(string);
    GH_COMMIT user = malloc(sizeof(struct commit));
    user->repo_id = strdup(strsep(&linha, ";"));
    user->author_id = strdup(strsep(&linha, ";"));
    user->committer_id = strdup(strsep(&linha, ";"));
    user->commit_at = strdup(strsep(&linha, ";"));
    user->message = strdup(strsep(&linha, ";"));
    return user;
}

int get_Author_ID (GH_COMMIT commit){
    int authorID = atoi (strdup(commit->author_id));
    return authorID;
}

int get_Committer_ID (GH_COMMIT commit){
    int commitID = atoi(strdup(commit->committer_id));
    return commitID;
}

char * get_Commit_at(GH_COMMIT commit){
    char * commitat = strdup(commit->commit_at);
    return commitat; 
}

int get_Rep_ID(GH_COMMIT commit){
    int rep_ID = atoi(strdup(commit->repo_id));
    return rep_ID;
}


ARRDUP colabor(){
    FILE *f  = fopen("../guiao-3/saida/commits-ok.csv", "r+");
    if (!f){printf("ERRO\n"); return 0;}


    char buffer[700000], *buffer2;
    COLAB colaborator = malloc((sizeof(struct colab)));
    colaborator->author = malloc(300 * sizeof(int));
    int maximo = 300;
    colaborator->sizea = 0;
    int sa;

    fgets(buffer, 700000, f);
    while(fgets(buffer, 700000, f)) 
    {
        buffer2 = buffer;  // Colocar buffer2 a apontar para o buffer

        GH_COMMIT new = malloc(sizeof(GH_COMMIT));
        new = separate_c(buffer2);


            if(maximo == colaborator->sizea) {
                maximo += maximo *0.5;
                colaborator->author = (int *) realloc(colaborator->author, maximo * sizeof(int));
            }

            sa = colaborator->sizea++;
            colaborator->author[sa]= get_Author_ID(new);


            if(maximo == colaborator->sizea) {
                maximo += maximo *0.5;
                colaborator->author = (int *) realloc(colaborator->author, maximo * sizeof(int));
            }
        
            sa = colaborator->sizea++;
            colaborator->author[sa]= get_Committer_ID(new);
    }

    int commits = sa/2;
    quicksort(colaborator->author,0,colaborator->sizea);
    ARRDUP new = remove_duplicate1(colaborator->author,colaborator->sizea);

    fclose(f);
    FILE *fp = fopen("../guiao-3/saida/ncommits.txt","w+");
    if(!fp) printf("Não foi possível criar ficheiro.\n");

    fprintf(fp, "%d\n", commits);
    fclose(fp);

    return new;
}


// Verifica se a data está dentro dos parâmetros e coloca o repos_ID num array caso passe da data
ARRDUP readCommits(DATEV datainput){
     FILE *f  = fopen("../guiao-3/saida/commits-ok.csv", "r+");
    if (!f){printf("ERRO\n"); return 0;}


    char buffer[700000], *buffer2;
    COLAB colaborator = malloc((sizeof(struct colab)));
    colaborator->author = malloc(300 * sizeof(int));
    int maximo = 300;
    colaborator->sizea = 0;
    int sa;
    int x;

    fgets(buffer, 700000, f);

    while(fgets(buffer, 700000, f)) 
    {
        buffer2 = buffer;  // Colocar buffer2 a apontar para o buffer

        GH_COMMIT new = malloc(sizeof(GH_COMMIT));
        new = separate_c(buffer2);
        char * date = get_Commit_at(new);
        DATEV datafile = sep_datevalid(date);
        x = compareDatas(datainput,datafile);

            if(maximo == colaborator->sizea) {
                maximo += maximo *0.5;
                colaborator->author = (int *) realloc(colaborator->author, maximo * sizeof(int));
            }

            if(x == 1)
            {
            sa = colaborator->sizea++;
            colaborator->author[sa]= get_Rep_ID(new);
            }


    }
    quicksort(colaborator->author,0,colaborator->sizea);
    ARRDUP new = remove_duplicate1(colaborator->author,colaborator->sizea);

    fclose(f);

    return new;

}