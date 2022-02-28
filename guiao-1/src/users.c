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


GH_USER separate1 (char *linha) {
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




//funcao do tamanho da struct
int get_sizeU (){
    int c = sizeof(struct user);
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


// Função que verifica se o último parâmetro é um número
char * verifica( char *rep){
    char *c = strdup(rep);
    int a = strlen(c);
    if (strchr(c, '\n') != NULL){
    c[a-2] = '\0';
    }
    return c;
}



//Função que calcula o comprimento de um número
int comp (int x) {
  if (x == 0) return 1;
  int i = 0;
   while (x > 0) {
      x = x/10;
      i++;
}
   return i;
}




// Função verificia se é um número válido maior que 0
int numvalid (char *num) { 
    int length = strlen(num); 
    int val = atoi(num);
    int len = comp(val);
    if (len == 0) return 1;
    int mod = (length % len);
    int div = (length / len);
    if ((val == 0) && (*num != '0')) return 1;
    if ((val >= 0) && (mod == 0) &&(div == 1)) return 0;
    else return 1;
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
  }
    if(c == 0) return 0;
    else return 1;
}


//Função que verifica se o nº de followers é correto
int listvalid (char *number, char *list) {
    if (elemvalid (list) > 0) return 1;
    char *found;
    int i = 0;
    int c = 1;
    int num = atoi(number);
    c = strcmp (list, "[]");
    while((found = strsep(&list,",")) != NULL )
        i++;
    if (c == 0) i = 0;
    if ((i == num) && (num >= 0)) return 0;
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

// Verifica os números da data
int numdate(char *string){
    int ano, mes, dia, hora, min, seg;
    ano = mes = dia = hora = min = seg = 100;
    char *date = strdup(string);
    char *p = &date[18];
    int v = numvalid(p);
    if (v != 0) return 1;
    int k = structdate(date);
    if (k != 0) return 1;
    sscanf(date, "%d-%d-%d %d:%d:%d", &ano, &mes, &dia, &hora, &min, &seg);
    if ((ano == 100) || (mes == 100) || (dia == 100) || (hora == 100) || (min == 100) || (seg == 100)) return 1;
    else return 0;
}



// Função que testa se a data é válida
int datevalid(char *date){
    int k = numdate(date);
    if (k != 0) return 1;

    char *fstdate = "2005-04-07 00:00:00";
  
    struct tm fst = {0};
    struct tm t = {0};
    time_t currdate;
    time (&currdate);
  
    strptime(date, "%Y-%m-%d %H:%M:%S", &t);
    time_t stringt = mktime(&t);
  
    strptime(fstdate, "%Y-%m-%d %H:%M:%S", &fst);
    time_t fsttime = mktime(&fst);
  
    int diff1 = difftime (currdate,stringt);
    int diff2 = difftime (stringt, fsttime);

    if ((diff1 > 0) && (diff2 > 0)) return 0;
    else return 1;
}


void show_user(FILE *stream, GH_USER k){
    fprintf(stream, "%d;%s;%s;%s;%d;%s;%d,%s;%d;%d\n", atoi(k->id), k->login, k->type, k->created_at, atoi(k->followers), k->followers_list, atoi(k->following), k->following_list, atoi(k->public_gists), atoi(k->public_repos));
}

int uservalid (GH_USER user){
    int x = 0;

    x = numvalid(user->id) + numvalid(user->public_gists) + numvalid( verifica (user->public_repos)) + typevalid(user->type) + stringvalid(user->login) + numvalid (user->followers) + listvalid (user->followers, user->followers_list) + datevalid(user->created_at) + numvalid(user->following);
    return x;
}




 