#pragma once

typedef struct user *GH_USER;



GH_USER separate1 (char *linha);

int get_sizeU();

int typevalid (char *type);

int stringvalid (char *string);

char * verifica( char *rep);

int comp (int x);

int numvalid (char *num);

int correctlist (char *list);

int elemvalid (char *list);

int listvalid (char *number, char *list);

int structdate(char *string);

int numdate(char *string);

int datevalid(char *date);

void show_user(FILE *stream, GH_USER k);

int uservalid (GH_USER user);