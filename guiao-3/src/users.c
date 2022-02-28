#define __USE_XOPEN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include "../libs/users.h"

struct user { 
    char *public_repos;
    char *id;
    char *followers;
    char *followers_list;
    char *type; 
    char *following_list;
    char *public_gists;
    char *created_at;
    char *following;
    char *login;
};

struct arrayType {
    int bot;
    int organizator;
    int user;
};



GH_USER separate (char *linha) {
    GH_USER user = malloc(sizeof(struct user));
    user->id = strdup(strsep(&linha, ";"));
    user->login = strdup(strsep(&linha, ";"));
    user->type = strdup(strsep(&linha, ";"));
    user->created_at = strdup(strsep(&linha, ";"));
    user->followers = strdup(strsep(&linha, ";"));
    user->followers_list = strdup(strsep(&linha, ";"));
    user->following = strdup(strsep(&linha, ";"));
    user->following_list = strdup(strsep(&linha, ";"));
    user->public_gists = strdup(strsep(&linha, ";"));
    user->public_repos = strdup(strsep(&linha, ";"));
    return user;
}


// Função do ID
int get_ID(GH_USER user){
    int id =  atoi(strdup(user->id));
    return id;
}

// Função do Type
char * get_Type(GH_USER user){   
    char *type = strdup (user->type);
    return type; 
}


ARR_TYPE sum_Type(){

    FILE *f  = fopen("../guiao-3/saida/users-ok.csv", "r+");
    if (!f){printf("ERRO\n"); return 0;}

    FILE *fp = fopen("../guiao-3/saida/bots.txt", "w+");
    if(!fp) {printf("Não foi possível criar ficheiro\n"); return 0;}

    char buffer[700000], *buffer2;
    ARR_TYPE type = malloc((sizeof(struct arrayType)));
    type->bot = 0;
    type->user = 0;
    type->organizator = 0;
    
    fgets(buffer, 700000, f); // eliminar a primeira linha desnecessária
    while(fgets(buffer, 700000, f)) // Saca a linha
    {
        buffer2 = buffer;  // Colocar buffer2 a apontar para o buffer

        GH_USER new = malloc(sizeof(GH_USER));
        new = separate(buffer2);

        char *s = get_Type(new);
        if (!strcmp(s, "Organization")) type->organizator++;
        if (!strcmp(s, "Bot")) {
            fprintf(fp, "%d\n",get_ID(new));
            type->bot++;
        }
        if (!strcmp(s, "User")) type->user++;   
    }



        fclose(f);
        fclose(fp);
        return type;
    }



// Função nº de Bots
int get_Bot(ARR_TYPE user){
    int bot = user->bot;
    return bot;
}

// Função nº de User
int get_User(ARR_TYPE user){
    int users = user->user;
    return users;
}

// Função nº de Organizadores
int get_Org (ARR_TYPE user){
    int org = user->organizator;
    return org;
}





