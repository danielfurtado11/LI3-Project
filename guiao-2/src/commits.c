#define __USE_XOPEN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include "../libs/commits.h"

struct commit { 
    char *repo_id;
    char *author_id;
    char *committer_id;
    char *commit_at;
    char *message;
};


struct arrayCommit{
    GH_COMMIT *array;
    int max;
    int size;
};

int get_Size_C(INFO_COMMIT commits){
    int size = commits->size;
    return size;
}

GH_COMMIT * get_Array_C(INFO_COMMIT commits){
    GH_COMMIT *arr = commits->array;
    return arr;
}


// Funções sobre a struct dos Commits
GH_COMMIT separate_c (char *linha) {
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

INFO_COMMIT initCommit(){
    INFO_COMMIT commit = malloc (sizeof(struct arrayCommit));
    commit->array = malloc(500 * sizeof(GH_COMMIT));
    commit->max = 500;
    commit->size = 0;
    return commit;
}



void insertCommit (INFO_COMMIT user, GH_COMMIT new){

    if (user->max == user->size) {
        user->max += user->max; 
        user->array = (GH_COMMIT *)realloc(user->array, user->max * sizeof(GH_COMMIT));
        }
    int N = user->size++;
    user->array[N] = new; 
}




INFO_COMMIT data_Commit(){

    FILE *f  = fopen("../guiao-2/entrada/commits.csv", "r+");
    if (!f){printf("ERRO\n"); return 0;}

    char buffer[700000], *buffer2;
    INFO_COMMIT utilizador = initCommit();

    fgets(buffer, 700000, f);
    while(fgets(buffer, 700000, f)) // Saca a linha
    {
        buffer2 = buffer;  // Colocar buffer2 a apontar para o buffer

        GH_COMMIT new = malloc(sizeof(GH_COMMIT));
        new = separate_c(buffer2);
        insertCommit(utilizador, new);
    }

return utilizador;
}



// Procura binária pelo author_id 
long binarySearch(GH_COMMIT *arr, long x, int low, int high) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (get_Author_ID(arr[mid]) == x)
      return mid;

    if (get_Author_ID(arr[mid]) < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}



// Procura binária pelo commiter_id
int binarySearch_C_COMMITER(GH_COMMIT *arr, int primeiro, int fim,int id_que_estamos_a_procura)
{
    if (fim >= primeiro) {
        int mid = primeiro + (fim - primeiro) / 2;
 
        if (get_Committer_ID(arr[mid]) == id_que_estamos_a_procura)
            return id_que_estamos_a_procura;
 
        if (get_Committer_ID(arr[mid]) > id_que_estamos_a_procura)
            return binarySearch_C_COMMITER(arr, primeiro, mid - 1, id_que_estamos_a_procura);
 
        return binarySearch_C_COMMITER(arr, mid + 1, fim, id_que_estamos_a_procura);
    }
 
    return -1;
}




// Ordena um array de commiters pelo seu author_id
void quicksort_AUTHORID(GH_COMMIT *array, int inicio, int fim)
{
	int i, j, pivo;
    GH_COMMIT aux;
	i = inicio;
	j = fim-1;
	pivo = get_Author_ID(array[(inicio + fim) / 2]);
	while(i <= j)
	{
		while(get_Author_ID(array[i]) < pivo && i < fim)
		{
			i++;
		}
		while(get_Author_ID(array[j]) > pivo && j > inicio)
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
		quicksort_AUTHORID(array, inicio, j+1);
	if(i < fim)
		quicksort_AUTHORID(array, i, fim);
}





// Ordena um array de commiters pelo seu committer_id
void quicksort_COMMITERID(GH_COMMIT *array, int inicio, int fim)
{
	int i, j, pivo;
    GH_COMMIT aux;
	i = inicio;
	j = fim-1;
	pivo = get_Committer_ID(array[(inicio + fim) / 2]);
	while(i <= j)
	{
		while(get_Committer_ID(array[i]) < pivo && i < fim)
		{
			i++;
		}
		while(get_Committer_ID(array[j]) > pivo && j > inicio)
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
		quicksort_COMMITERID(array, inicio, j+1);
	if(i < fim)
		quicksort_COMMITERID(array, i, fim);
}