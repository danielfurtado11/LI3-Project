#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../libs/struct_q.h"

struct query5 {
    int x; 
    int n;
    char * date1;
    char * date2;
};

QUERY_5 get_q5 (char *linha) {
    QUERY_5 q5 = malloc(sizeof(struct query5));
    q5->x = atoi(strdup(strsep(&linha, " ")));
    q5->n = atoi(strdup(strsep(&linha, " ")));
    q5->date1 = strdup(strsep(&linha, " "));
    q5->date2 = strdup(strsep(&linha, "\n")); 
    return q5;
}

int get_Size_5(){
    int size = sizeof(struct query5);
    return size;
}

int get_N(QUERY_5 q5){
    int n = q5->n;
    return n;
}

char * get_D1(QUERY_5 q5){
    char * date = q5->date1;
    return date;
}

char * get_D2(QUERY_5 q5){
    char * date = q5->date2;
    return date;
}


struct query6 {
    int x; 
    int n;
    char * lang;
};


QUERY_6 get_q6 (char *linha) {
    QUERY_6 q6 = malloc(sizeof(struct query6));
    q6->x = atoi(strdup(strsep(&linha, " ")));
    q6->n = atoi(strdup(strsep(&linha, " "))); 
    q6->lang = strdup(strsep(&linha,"\n")); 
    return q6;
}


int get_Size_6(){
    int size = sizeof(struct query6);
    return size;
}

int get_N6(QUERY_6 q6){
    int n = q6->n;
    return n;
}

char * get_Lang(QUERY_6 q6){
    char * lang = q6->lang;
    return lang;
}



struct query7 {
    int x; 
    char * date;
};

QUERY_7 get_q7 (char *linha) {
    QUERY_7 q7 = malloc(sizeof(struct query7));
    q7->x = atoi(strdup(strsep(&linha, " ")));
    q7->date = strdup(strsep(&linha, "\n")); 
    return q7;
}

int get_Size_7(){
    int size = sizeof(struct query7);
    return size;
}

char * get_D7(QUERY_7 q7){
    char * date = q7->date;
    return date;
}