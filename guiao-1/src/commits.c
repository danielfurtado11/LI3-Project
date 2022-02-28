#define __USE_XOPEN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../libs/users.h"
#include "../libs/commits.h"



struct commit { 
    char *repo_id;
    char *author_id;
    char *committer_id;
    char *commit_at;
    char *message;
};



//funcao do tamanho da struct
int get_sizeC (){
    int c = sizeof(struct commit);
    return c;
}


GH_COMMIT separate_c (char *linha) {
    GH_COMMIT user = malloc(sizeof(struct commit));
    user->repo_id = strdup(strsep(&linha, ";"));
    user->author_id = strdup(strsep(&linha, ";"));
    user->committer_id = strdup(strsep(&linha, ";"));
    user->commit_at = strdup(strsep(&linha, ";"));
    user->message = strdup(strsep(&linha, ";"));
    return user;
}

void show_commit(FILE *stream, GH_COMMIT k){
    fprintf(stream, "%d;%d;%d;%s;%s", atoi(k->repo_id), atoi(k->author_id), atoi(k->committer_id), k->commit_at, k->message);
}

int uservalid_c (GH_COMMIT user){
    int x = 0;

    x = numvalid(user->repo_id) + numvalid(user->author_id) + numvalid(user->committer_id) + datevalid(user->commit_at) + stringvalid(user->message);

    return x;
}

