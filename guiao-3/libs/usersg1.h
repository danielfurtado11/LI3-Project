#pragma once

typedef struct user1 *GH_USER1;

typedef struct date *S_DATE;


GH_USER1 separate1 (char *linha);

int get_sizeU();

int typevalid (char *type);

int stringvalid (char *string);

int numvalid (char *num);

int correctlist (char *list);

int elemvalid (char *list);

int listvalid (char *number, char *list);

int structdate(char *string);

int numdate(char *string);

int datevalid(char *date);

void print_line(FILE *stream, char *s);

int uservalid (GH_USER1 user);

S_DATE sep_date(char *string);

S_DATE fstdate();

S_DATE actdate();

int datevalid(char *linha);