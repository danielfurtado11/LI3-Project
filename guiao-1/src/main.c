#define __USE_XOPEN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../libs/users.h"
#include "../libs/commits.h"
#include "../libs/repos.h"

int main_user() {

    FILE *f  = fopen("entrada/users1.csv", "r");  // Abrir o ficheiro em modo leitur
    FILE *fp = fopen ("saida/users-ok.csv", "w+");
    if (!f){
     printf("Ficheiro Inválido\n"); // Indica caso o ficheiro não exista
     return 1; // Se o ficheiro nao existir e f ficar NULL, retorna 1
    }

    char buffer[700000], *buffer2;  // Buffer usado para guardar uma linha e buffer2 usado como auxiliar
    int maximo = 100; // Array de utilizadores, que é aconselhavel ser dinâmico
    int i = 0; 
    GH_USER *array = malloc (maximo * get_sizeU());

    
    while(fgets(buffer, 700000, f)) // Enquanto ler uma linha continua o ciclo
    {
        buffer2 = buffer;  // Colocar buffer2 a apontar para o buffer
        array[i] = malloc(get_sizeU()); // Alocar espaço no array para o user
        array[i++] = separate(buffer2); // Construir o user

        if (i == maximo){
            maximo += maximo * 0.4;
            array =(GH_USER *)realloc(array,maximo * get_sizeU());
        }
    
    
    
    }
    


    fprintf(fp, "id;login;type;created_at;followers;follower_list;following;following_list;public_gists;public_repos\n");
    for (int j = 0 ; j<i ; j++){
        if (uservalid(array[j]) == 0)
            show_user(fp, array[j]);
    }   
    
    fclose(fp);
    fclose(f);
    return 0;

}







int main_commit() {

    FILE *f  = fopen("entrada/commits.csv", "r");  // Abrir o ficheiro em modo leitur
    FILE *fp = fopen ("saida/commits-ok.csv", "w+");
    if (!f){
     printf("Ficheiro Inválido\n"); // Indica caso o ficheiro não exista
     return 1; // Se o ficheiro nao existir e f ficar NULL, retorna 1
    }
    char buffer[700000], *buffer2;  // Buffer usado para guardar uma linha e buffer2 usado como auxiliar
    int maximo = 100; // Array de utilizadores, que é aconselhavel ser dinâmico
    int i = 0; 
    GH_COMMIT *array = malloc (maximo * get_sizeC());


    while(fgets(buffer, 700000, f)) // Enquanto ler uma linha continua o ciclo
    {
        buffer2 = buffer;  // Colocar buffer2 a apontar para o buffer
        array[i] = malloc(get_sizeC()); // Alocar espaço no array para o user
        array[i++] = separate_c(buffer2); // Construir o user
    
        if (i == maximo){
            maximo += maximo * 0.4;
            array =(GH_COMMIT *)realloc(array,maximo * get_sizeC());
        }
    
    
    
    }
    fprintf(fp, "repo_id;author_id;committer_id;commit_at;message\n");
    for (int j = 0 ; j<i ; j++){
        if (uservalid_c(array[j]) == 0)
            show_commit(fp, array[j]);
    }




   
    fclose(fp);

    fclose(f);
    return 0;

}


int main_repos() {

    FILE *f  = fopen("entrada/repos.csv", "r");  // Abrir o ficheiro em modo leitur
    FILE *fp = fopen ("saida/repos-ok.csv", "w+");
    if (!f){
     printf("Ficheiro Inválido\n"); // Indica caso o ficheiro não exista
     return 1; // Se o ficheiro nao existir e f ficar NULL, retorna 1
    }
    char buffer[700000], *buffer2;  // Buffer usado para guardar uma linha e buffer2 usado como auxiliar
    int maximo = 100; // Array de utilizadores, que é aconselhavel ser dinâmico
    int i = 0; 
    GH_REPOS *array = malloc (maximo * get_sizeR());


    while(fgets(buffer, 700000, f)) // Enquanto ler uma linha continua o ciclo
    {
        buffer2 = buffer;  // Colocar buffer2 a apontar para o buffer
        array[i] = malloc(get_sizeR()); // Alocar espaço no array para o user
        array[i++] = separate_r(buffer2); // Construir o user
    
        if (i == maximo){
            maximo += maximo * 0.4;
            array =(GH_REPOS *)realloc(array,maximo * get_sizeR());
        }
    
    

    }
    fprintf(fp, "id;owner_id;full_name;license;has_wiki;description;language;default_branch;created_at;updated_at;forks_count;open_issues;stargazers_count;size\n");
    for (int j = 0 ; j<i ; j++){
        if (uservalid_r(array[j]) == 0)
            show_user_r(fp, array[j]);
    }   
    
    fclose(fp);
    fclose(f);
    return 0;

}

int main(int argc, char **argv){

  if (strcmp(argv[1],"exercicio-1") == 0 && argc == 2){
    main_user();
    main_repos();
    main_commit();
  }
}