#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "../libs/query.h"
#include "../libs/struct_q.h"



int main(int argc, char **argv){
  if(argc == 2){
  char * file = argv[1];
  char text[100];
  sprintf(text, "../guiao-2/entrada/%s", file); 
  FILE *f = fopen(text, "r+");
  if (!f) {printf("Não existe ficheiro.\n"); return -1;}
  
  char buffer[80];
  int i = 1;
  char *buffer2 = buffer;
  
  while (fgets(buffer2, 40, f)) {
  
    switch (buffer[0])
    {
    case '1':
      query1(i);
      break;
    
    case '2':
      query2(i);
      break;

    case '3':
      query3(i);
      break;
    
    case '4':
      query4(i);
      break;

    case '5':
    {
      int size = get_Size_5();
      QUERY_5 q5 = malloc (size);
      q5 = get_q5(buffer2);
      int n = get_N(q5);
      char * date1 =  get_D1(q5);
      char * date2 = get_D2(q5);

      query5(i,n,date1,date2);
    break;
    }

    case '6':
    {
      int size = get_Size_6();
      QUERY_6 q6 = malloc (size);
      q6 = get_q6(buffer2);
      int n = get_N6(q6);
      char * lang = get_Lang(q6);
      query6(i,n,lang);
    break;
    }

    case '7':
    {
      QUERY_7 q7 = malloc(get_Size_7());
      q7 = get_q7(buffer2);
      char * date = get_D7(q7);
      query7(i,date);
    }

    default:
      break;
    }
  
    i++;
  }



return 0;
  }
}



