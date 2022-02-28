#define __USE_XOPEN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include "../libs/auxiliar.h"


/* Remove todas as ocorrencias */
int remove_occurences(int x, int *arr, int size){
    int i = 0, j;
    int total_elements = size;
    while (i < total_elements){
        if (arr[i] == x){
            for (j = i; j < (total_elements - 1) ;j++)
                arr[j] = arr[j+1];
             total_elements--; 
        }
        else
           i++; 
    }
    return total_elements;
}

/* Elemento do array mais frequente */
int mostFrequent(int *arr, int n) 
{ 


    int max_count = 1, res = arr[0], curr_count = 1; 
    for (int i = 1; i < n; i++) { 
        if (arr[i] == arr[i - 1]) 
            curr_count++; 
        else { 
            if (curr_count > max_count) { 
                max_count = curr_count; 
                res = arr[i - 1]; 
            } 
            curr_count = 1; 
        } 
    } 
  
    if (curr_count > max_count) 
    { 
        max_count = curr_count; 
        res = arr[n - 1]; 
    } 
  
    return res; 
}




/* Remove todos os duplicados de um array */
int remove_duplicate(int *arr, int n)
{

  if (n == 0 || n == 1)
    return n;

  int temp[n];

  int j = 0;
  int i;
  for (i = 0; i < n - 1; i++)
    if (arr[i] != arr[i + 1])
      temp[j++] = arr[i];
  temp[j++] = arr[n - 1];

  for (i = 0; i < j; i++)
    arr[i] = temp[i];

  return j;
}



/* Remove o último elemento da string p.e. '\n' */
char * remove_last (char *lang){
    int x = strlen(lang);
    lang[x-1] = '\0';
    return lang;
}




/* Verifica se uma data está entre 2 datas */
int dateq5 (char *data1, char *data2, char *atual){

    struct tm fst = {0};
    struct tm lst = {0};
    struct tm act   = {0};

    strptime(data1, "%Y-%m-%d", &fst);
    time_t fsttime = mktime(&fst);

    strptime(data2, "%Y-%m-%d", &lst);
    time_t lsttime = mktime(&lst);

    strptime(atual, "%Y-%m-%d", &act);
    time_t acttime = mktime(&act);

    int diff1 = difftime (lsttime, fsttime);
    int diff2 = difftime (acttime, fsttime);

    if ((diff1 >= diff2) && (diff2 > 0)) return 1;
    else return -1;
}




/* Verifica se a data está antes ou depois de uma determinada data */
int dateq7 (char *data, char *atual){

    struct tm def = {0};
    struct tm act   = {0};

    strptime(data, "%Y-%m-%d", &def);
    time_t deftime= mktime(&def);

    strptime(atual, "%Y-%m-%d", &act);
    time_t acttime= mktime(&act);

    int diff = difftime (deftime, acttime);

    if (diff > 0) return 1;
    else return -1;
}






/* Ordena o array por ordem crescente */
void quicksort(int *array, int inicio, int fim)
{
    int i, j, pivo, aux;
    i = inicio;
    j = fim-1;
    pivo = array[(inicio + fim) / 2];
    while(i <= j)
    {
        while(array[i] < pivo && i < fim)
        {
            i++;
        }
        while(array[j] > pivo && j > inicio)
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
        quicksort(array, inicio, j+1);
    if(i < fim)
        quicksort(array, i, fim);
}