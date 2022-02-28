#define __USE_XOPEN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../libs/users.h"
#include "../libs/repos.h"
#include "stdint.h"


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

//funcao do tamanho da struct
int get_sizeR (){
    int c = sizeof(struct repos);
    return c;
}




GH_REPOS separate_r (char *linha) {
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

int wikivalid (char *type) {
    if (!strcmp (type, "True") || !strcmp (type, "False")) return 0;
    else return 1;
    
}

int uservalid_r (GH_REPOS user){
    int x = 0;

    x = numvalid(user->id) + numvalid(user->owner_id) + stringvalid(user->full_name) + stringvalid (user->license) + wikivalid(user->has_wiki) + stringvalid (user->description) + stringvalid (user->language) + stringvalid (user->default_branch) + datevalid (user->created_at) + datevalid (user->updated_at) + numvalid(user->forks_count) + numvalid(user->open_issues) + numvalid(user->stargazers_count) + numvalid (verifica(user->size));
    return x;
}

void show_user_r(FILE *stream, GH_REPOS k){
    fprintf(stream, "%d;%d;%s;%s;%s;%s;%s;%s;%s;%s;%d;%d;%d;%s", atoi(k->id), atoi(k->owner_id), k->full_name, k->license,k->has_wiki, k->description, k->language, k-> default_branch, k->created_at,k->updated_at, atoi(k->forks_count), atoi(k->open_issues), atoi(k->stargazers_count), k->size);
    
}

