#define __USE_XOPEN 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include<ctype.h>
#include "../libs/usersg1.h"

struct user1 { 
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

struct date {
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
};


GH_USER1 separate1 (char *string) {
    GH_USER1 user = malloc(sizeof(struct user1));
    char *linha = strdup(string);
    user->id = strdup(strsep(&linha, ";"));
    user->login = strdup(strsep(&linha, ";"));
    user->type = strdup(strsep(&linha, ";"));
    user->created_at = strdup(strsep(&linha, ";"));
    user->followers = strdup(strsep(&linha, ";"));
    user->followers_list = strdup(strsep(&linha, ";"));
    user->following = strdup(strsep(&linha, ";"));
    user->following_list = strdup(strsep(&linha, ";"));
    user->public_gists = strdup(strsep(&linha, ";"));
    user->public_repos = strdup(strsep(&linha, "\n"));    
    return user;
}


//funcao do tamanho da struct
int get_sizeU (){
    int c = sizeof(struct user1);
    return c;
}


// Função que testa se é Utilizador, Organization, Bot
int typevalid (char *type) {
    if (!strcmp (type, "Bot") || !strcmp (type, "User") || !strcmp (type, "Organization")) return 0;
    else return 1;    
}


// Função que testa se é uma string (para o login)
int stringvalid (char *string){
    int x = strcmp("",string);
    if (x  == 0) return 1;
    else return 0;    
}



// Função verificia se é um número válido maior que 0
int numvalid (char *num) {
    
    for (int i = 0; num[i]!= '\0'; i++)
        if (isdigit(num[i]) == 0)
              return 1;
              
    return 0;
}


// Função que verifica se a lista está corretamente estruturada
int correctlist (char *list){
    // Serve para remover os casos em que a lista está incorreta ex.: [1242, 14314,
    char *sep = strdup(list);
    char *first = &sep[0];
    char *last  = &sep[strlen(sep)-1];
    if ((*first == '[') && (*last == ']')) return 0;
    else return 1;
}


// Função verifica se os elementos da lista são válidos
int elemvalid (char *list){
    // [12323, 2A3432, 24323]
    int c = 0;
    int l = 0;
    int i = 0;
    char *sep, *pedaco;
    sep = strdup(list);
    if (strcmp("[]",sep) == 0) return 0;
    l = correctlist(sep);
    if (l != 0) return 1;
    sep[strlen(sep)-1] = '\0';
    while((pedaco = strsep(&sep,",")) != NULL){
        pedaco = pedaco+1;
        int x = numvalid(pedaco);
        c = c+x;
        i++;
  }
    if(c == 0) return i;
    else return -1;
}


//Função que verifica se o nº de followers é correto
int listvalid (char *number, char *list) {
    int i = elemvalid(list);
    int n = atoi(number);
    if (i == n) return 0;
    else return 1;
}


// Verifica a estrutura da data
int structdate(char *string){
    char *date= strdup(string);
    int len = strlen(date);
    if (len != 19) return 1;
    char *t1 = &date[4]; // posição onde se econtra o '-' da data;
    char *t2 = &date[7]; // posição onde se econtra o '-' da data;
    char *p1 = &date[13]; // posição onde se econtra o ':' da data;
    char *p2 = &date[16]; // posição onde se econtra o ':' da data;

    if ((*t1 == '-') && (*t2 == '-')  && (*p1 == ':') && (*p2 == ':')) return 0;
    else return 1;
}


// Coloca a data na struct
S_DATE sep_date(char *string) {

    S_DATE date = malloc(sizeof(struct date));
    date->year = atoi(strdup(strsep(&string, "-")));
    date->month = atoi(strdup(strsep(&string, "-")));
    date->day = atoi(strdup(strsep(&string, " ")));
    date->hour = atoi(strdup(strsep(&string, ":"))); 
    date->min = atoi(strdup(strsep(&string, ":")));
    date->sec = atoi(strdup(strsep(&string, "\0")));
    
  return date;
}

// Primeira data limite
S_DATE fstdate(){
    S_DATE new = malloc(sizeof(struct date));
    new->year = 2005;
    new->month = 04;
    new->day = 07;
    new->hour = 00;
    new->min = 00;
    new->sec = 00;

    return new;
}

// Data atual
S_DATE actdate(){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  S_DATE act = malloc(sizeof(struct date));
  act->year = tm.tm_year + 1900;
  act->month = tm.tm_mon + 1;
  act->day = tm.tm_mday;
  act->hour = tm.tm_hour;
  act->min = tm.tm_min;
  act->sec = tm.tm_sec;
  return act;
}


// Compara datas
int datevalid(char *linha){
    int i = structdate(linha);
    if (i == 1) return 1;
    char *s = strdup(linha);
    S_DATE new = sep_date(s);
    S_DATE fst = fstdate();
    S_DATE act = actdate();


    if (new->year > act->year || new->year<fst->year) return 1;
    if ((new->month > act->month && new->year == act->year) || (new->month < fst->month && new->year == fst->year)) return 1;
    return 0;
}


void print_line(FILE *stream, char *s){
    fprintf(stream, "%s", s);
}


int uservalid (GH_USER1 user){
    int x = 0;

    x = numvalid(user->id) + numvalid(user->public_gists) + numvalid(user->public_repos) + typevalid(user->type) + stringvalid(user->login)+ numvalid (user->followers) + listvalid (user->followers, user->followers_list) + datevalid(user->created_at)+ numvalid(user->following);
    return x;
}




 