#define __USE_XOPEN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../libs/usersg1.h"
#include "../libs/reposg1.h"
#include "stdint.h"


struct repos1 { 
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
    int c = sizeof(struct repos1);
    return c;
}




GH_REPOS1 separate_r1 (char *string) {
    GH_REPOS1 user = malloc(sizeof(struct repos1));
    char *linha = strdup(string);
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
    user->size = strdup(strsep(&linha, "\n"));
    return user;
}

int wikivalid (char *type) {
    if (!strcmp (type, "True") || !strcmp (type, "False")) return 0;
    else return 1;
    
}

int uservalid_r (GH_REPOS1 user){
    int x = 0;

    x = numvalid(user->id) + numvalid(user->owner_id) + stringvalid(user->full_name) + stringvalid (user->license) + wikivalid(user->has_wiki) + stringvalid (user->description) + stringvalid (user->language) + stringvalid (user->default_branch) + datevalid (user->created_at) + datevalid (user->updated_at) + numvalid(user->forks_count) + numvalid(user->open_issues) + numvalid(user->stargazers_count) + numvalid (user->size);
    return x;
}

