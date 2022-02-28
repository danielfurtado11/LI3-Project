#define __USE_XOPEN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include "../libs/auxiliar.h"


struct arrdup {
    int *arr;
    int size;
};


/* Remove todos os duplicados de um array */
ARRDUP remove_duplicate1(int *arr, int n)
{

    ARRDUP new = malloc (sizeof(struct arrdup));
    new->size = 0;
    int maximo = 300;
    new->arr = malloc(sizeof(int) * maximo);

  int j = 0;
  int i;
  for (i = 0; i < n - 1; i++)
    if (arr[i] != arr[i + 1]){
        if(new->size == maximo){
            maximo += 0.5 * maximo;
            new->arr = (int *) realloc(new->arr, maximo * sizeof(int));
        }
        new->arr[new->size++] = arr[i];
    }
  new->arr[j++] = arr[n - 1];


  return new;
}


int * get_ARR_DUP (ARRDUP dup){
    int * new = dup->arr;
    return new;
}

int get_SIZE_ARR (ARRDUP dup){
    int size = dup->size;
    return size;
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

// Procura binária 
long binarySearch(int *arr, int x, int low, int high) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] == x)
      return mid;

    if (arr[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}