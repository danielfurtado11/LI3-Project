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


struct arrayUser {
    GH_USER *array;
    int max;
    int size;
};


int get_Size_U(INFO_USER users){
    int size = users->size;
    return size;
}

GH_USER * get_Array_U(INFO_USER users){
    GH_USER *arr = users->array;
    return arr;
}



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


// Função do Login
char * get_Login(GH_USER user){
    char *login = strdup (user->login);
    return login;
}

INFO_USER initUser(){
    INFO_USER users = malloc (sizeof(struct arrayUser));
    users->array = malloc(500 * sizeof(GH_USER));
    users->max = 500;
    users->size = 0;
    return users;
}


void insertUser (INFO_USER user, GH_USER new){

    if (user->max == user->size) {
        user->max += user->max; 
        user->array = (GH_USER *)realloc(user->array, user->max * sizeof(GH_USER));
        }
    int N = user->size++;
    user->array[N] = new; 
}




INFO_USER data_User(){

    FILE *f  = fopen("../guiao-2/entrada/users.csv", "r+");
    if (!f){printf("ERRO\n"); return 0;}

    char buffer[700000], *buffer2;
    INFO_USER utilizador = initUser();

    fgets(buffer, 700000, f);
    while(fgets(buffer, 700000, f)) // Saca a linha
    {
        buffer2 = buffer;  // Colocar buffer2 a apontar para o buffer

        GH_USER new = malloc(sizeof(GH_USER));
        new = separate(buffer2);
        insertUser(utilizador, new);
    }

return utilizador;
}



// Função que procura pelo o id - procura binária
int binarySearch_U(GH_USER *arr, int primeiro, int fim,int id_que_estamos_a_procura)
{
    if (fim >= primeiro) {
        int mid = primeiro + (fim - primeiro) / 2;
 
        if (get_ID(arr[mid]) == id_que_estamos_a_procura)
            return id_que_estamos_a_procura;
 
        if (get_ID(arr[mid]) > id_que_estamos_a_procura)
            return binarySearch_U(arr, primeiro, mid - 1, id_que_estamos_a_procura);
 
        return binarySearch_U(arr, mid + 1, fim, id_que_estamos_a_procura);
    }
 
    return -1;
}



// Função que procura pelo o id e retorna o login
char * binarySearch_U_Login(GH_USER *arr, int primeiro, int fim,int id_que_estamos_a_procura)
{
    if (fim >= primeiro) {
        int mid = primeiro + (fim - primeiro) / 2;
 
        if (get_ID(arr[mid]) == id_que_estamos_a_procura)
            return get_Login(arr[mid]);
 
        if (get_ID(arr[mid]) > id_que_estamos_a_procura)
            return binarySearch_U_Login(arr, primeiro, mid - 1, id_que_estamos_a_procura);
 
        return binarySearch_U_Login(arr, mid + 1, fim, id_que_estamos_a_procura);
    }
 
    return "NADA";
}



// Ordena um array de users pelo seu id
void quicksortUSER(GH_USER *array, int inicio, int fim)
{
	int i, j, pivo;
    GH_USER aux;
	i = inicio;
	j = fim-1;
	pivo = get_ID(array[(inicio + fim) / 2]);
	while(i <= j)
	{
		while(get_ID(array[i]) < pivo && i < fim)
		{
			i++;
		}
		while(get_ID(array[j]) > pivo && j > inicio)
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
		quicksortUSER(array, inicio, j+1);
	if(i < fim)
		quicksortUSER(array, i, fim);
}