#define __USE_XOPEN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../libs/usersg1.h"
#include "../libs/commitsg1.h"



struct commit1 { 
    char *repo_id;
    char *author_id;
    char *committer_id;
    char *commit_at;
    char *message;
};



//funcao do tamanho da struct
int get_sizeC (){
    int c = sizeof(struct commit1);
    return c;
}


GH_COMMIT1 separate_c1 (char *string) {
    GH_COMMIT1 user = malloc(sizeof(struct commit1));
    char *linha = strdup(string);
    user->repo_id = strdup(strsep(&linha, ";"));
    user->author_id = strdup(strsep(&linha, ";"));
    user->committer_id = strdup(strsep(&linha, ";"));
    user->commit_at = strdup(strsep(&linha, ";"));
    user->message = strdup(strsep(&linha, "\n"));
    return user;
}


int uservalid_c (GH_COMMIT1 user){
    int x = 0;

    x = numvalid(user->repo_id) + numvalid(user->author_id) + numvalid(user->committer_id) + datevalid(user->commit_at) + stringvalid(user->message);

    return x;
}

