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


struct arrayRepos{
    GH_REPOS *array;
    int max;
    int size;
};


int get_Size_R(INFO_REPOS repos){
    int size = repos->size;
    return size;
}

GH_REPOS * get_Array_R(INFO_REPOS repos){
    GH_REPOS *arr = repos->array;
    return arr;
}




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


// Função da linguagem utilizada
char * get_language(GH_REPOS repos){   
    char *rep = strdup (repos->language);
    return rep; 
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



INFO_REPOS initRepos(){
    INFO_REPOS users = malloc (sizeof(struct arrayRepos));
    users->array = malloc(500 * sizeof(GH_REPOS));
    users->max = 500;
    users->size = 0;
    return users;
}



void insertRepos (INFO_REPOS user, GH_REPOS new){

    if (user->max == user->size) {
        user->max += user->max; 
        user->array = (GH_REPOS *)realloc(user->array, user->max * sizeof(GH_REPOS));
        }
    int N = user->size++;
    user->array[N] = new; 
}




INFO_REPOS data_Repos(){

    FILE *f  = fopen("../guiao-2/entrada/users.csv", "r+");
    if (!f){printf("ERRO\n"); return 0;}

    char buffer[700000], *buffer2;
    INFO_REPOS utilizador = initRepos();

    fgets(buffer, 700000, f);
    while(fgets(buffer, 700000, f)) // Saca a linha
    {
        buffer2 = buffer;  // Colocar buffer2 a apontar para o buffer

        GH_REPOS new = malloc(sizeof(GH_REPOS));
        new = separate_r(buffer2);
        insertRepos(utilizador, new);
    }

return utilizador;
}





// Procura binária em um repositório pelo owner_id
int binarySearch_REPOS(GH_REPOS *arr, int primeiro, int fim,int id_que_estamos_a_procura)
{
    if (fim >= primeiro) {
        int mid = primeiro + (fim - primeiro) / 2;
 
        if (get_Owner_ID(arr[mid]) == id_que_estamos_a_procura)
            return id_que_estamos_a_procura;
 
        if (get_Owner_ID(arr[mid]) > id_que_estamos_a_procura)
            return binarySearch_REPOS(arr, primeiro, mid - 1, id_que_estamos_a_procura);
 
        return binarySearch_REPOS(arr, mid + 1, fim, id_que_estamos_a_procura);
    }
 
    return -1;
}





// Ordena um array de repos pelo seu owner_id
void quicksort_REPOS(GH_REPOS *array, int inicio, int fim)
{
    int i, j, pivo;
    GH_REPOS aux;
    i = inicio;
    j = fim-1;
    pivo = get_Owner_ID(array[(inicio + fim) / 2]);
    while(i <= j)
    {
        while(get_Owner_ID(array[i]) < pivo && i < fim)
        {
            i++;
        }
        while(get_Owner_ID(array[j]) > pivo && j > inicio)
        {
            j--;
        }
        if(i <= j)
        {
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    }
    if(j > inicio)
        quicksort_REPOS(array, inicio, j+1);
    if(i < fim)
        quicksort_REPOS(array, i, fim);
}


// Ordena um array de repos pelo seu id do repositório
void quicksort_R_ID(GH_REPOS *array, int inicio, int fim)
{
    int i, j, pivo;
    GH_REPOS aux;
    i = inicio;
    j = fim-1;
    pivo = get_ID_R(array[(inicio + fim) / 2]);
    while(i <= j)
    {
        while(get_ID_R(array[i]) < pivo && i < fim)
        {
            i++;
        }
        while(get_ID_R(array[j]) > pivo && j > inicio)
        {
            j--;
        }
        if(i <= j)
        {
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    }
    if(j > inicio)
        quicksort_R_ID(array, inicio, j+1);
    if(i < fim)
        quicksort_R_ID(array, i, fim);
}



// Procura binária de um id do repositório com return da descrição
char * binarySearch_R_DESC(GH_REPOS *arr, int primeiro, int fim,int id_que_estamos_a_procura)
{
    if (fim >= primeiro) {
        int mid = primeiro + (fim - primeiro) / 2;
 
        if (atoi(arr[mid]->id) == id_que_estamos_a_procura)
            return arr[mid]->description;
 
        if (atoi(arr[mid]->id) > id_que_estamos_a_procura)
            return binarySearch_R_DESC(arr, primeiro, mid - 1, id_que_estamos_a_procura);
 
        return binarySearch_R_DESC(arr, mid + 1, fim, id_que_estamos_a_procura);
    }
 return "NADA";
}