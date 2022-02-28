#define __USE_XOPEN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include "../libs/repos.h"


struct repos { 
    char *id;
    char *owner_id;
    char *full_name;
    char *license;
    char *has_wiki;
    char *description;
    char *language;
    char *default_branch;
    char *created_at;
    char *updated_at;
    char *forks_count;
    char *open_issues;
    char *stargazers_count;
    char *size;

};


struct reposall {
    int size;
};




GH_REPOS separate_r (char *string) {
    char *linha = strdup(string);
    GH_REPOS user = malloc(sizeof(struct repos));
    user->id = strdup(strsep(&linha, ";"));
    user->owner_id = strdup(strsep(&linha, ";"));
    user->full_name= strdup(strsep(&linha, ";"));
    user->license= strdup(strsep(&linha, ";"));
    user->has_wiki = strdup(strsep(&linha, ";"));
    user->description= strdup(strsep(&linha, ";"));
    user->language = strdup(strsep(&linha, ";"));
    user->default_branch = strdup(strsep(&linha, ";"));
    user->created_at = strdup(strsep(&linha, ";"));
    user->updated_at = strdup(strsep(&linha, ";"));
    user->forks_count = strdup(strsep(&linha, ";"));
    user->open_issues = strdup(strsep(&linha, ";"));
    user->stargazers_count = strdup(strsep(&linha, ";"));
    user->size = strdup(strsep(&linha, ";"));
    return user;
}



// Função do ID do Repositório
int get_ID_R (GH_REPOS repos){
    int id = atoi(strdup(repos->id));
    return id;
}

// Função do ID do Owner do Repositório
int get_Owner_ID (GH_REPOS repos){
    int own_ID = atoi(strdup(repos->owner_id));
    return own_ID;
}

// Função da Descrição do Repositório
char * get_Description (GH_REPOS repos){
    char *desc = strdup(repos->description);
    return desc;
}


// Coloca todos os reposID num ficheiro e a sua descrição e conta o número de linhas 
REPOSALL allrepos(){
    FILE *f = fopen("../guiao-3/saida/repos-ok.csv", "r+");
    if (!f) {printf("ERRO REPOS\n"); return 0;}

    FILE *fp = fopen("../guiao-3/saida/reposid.csv","w+");
    if (!fp) {printf("ERRO REPOS\n"); return 0;}


    char buffer[700000], *buffer2;
    REPOSALL repos = malloc(sizeof(struct reposall));
    repos->size = 0;

    fgets(buffer, 700000, f);
    while(fgets(buffer,700000, f)){

        buffer2 = buffer;

        GH_REPOS new = malloc(sizeof(GH_REPOS));
        new = separate_r(buffer2);

        int reposID = get_ID_R(new);
        repos->size++;
        char * desc = get_Description(new);
        fprintf(fp,"%d;%s\n", reposID, desc);
    }

    fclose(f);
    fclose(fp);
    return repos;
}

int getsizeR(REPOSALL repos){
    int x = repos->size;
    return x;
}
