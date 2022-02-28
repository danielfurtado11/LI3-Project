#define __USE_XOPEN
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../libs/usersg1.h"
#include "../libs/commitsg1.h"
#include "../libs/reposg1.h"

int main_user() {

    FILE *f  = fopen("entrada/users-g3.csv", "r");  // Abrir o ficheiro em modo leitur
    FILE *fp = fopen ("saida/users-ok.csv", "w+");
    if (!f){
     printf("Ficheiro Inválido\n"); // Indica caso o ficheiro não exista
     return 1; // Se o ficheiro nao existir e f ficar NULL, retorna 1
    }

    fprintf(fp, "id;login;type;created_at;followers;follower_list;following;following_list;public_gists;public_repos\n");

    char buffer[700000], *buffer2;  // Buffer usado para guardar uma linha e buffer2 usado como auxiliar
    int i = 0;

    fgets(buffer, 70000, f);// eliminar a primeira linha
    
    while(fgets(buffer, 700000, f)) // Enquanto ler uma linha continua o ciclo
    {
        buffer2 = buffer;  // Colocar buffer2 a apontar para o buffer
        GH_USER1 new = malloc(get_sizeU());
        new = separate1(buffer2);
        i = uservalid(new);
        if (i == 0) print_line(fp, buffer2);
    }
    
    fclose(fp);
    fclose(f);
    return 0;

}









int main_commit() {

    FILE *f  = fopen("entrada/commits-g3.csv", "r");  // Abrir o ficheiro em modo leitura
    FILE *fp = fopen ("saida/commits-ok.csv", "w+");
    if (!f){
     printf("Ficheiro Inválido\n"); // Indica caso o ficheiro não exista
     return 1; // Se o ficheiro nao existir e f ficar NULL, retorna 1
    }
    char buffer[700000], *buffer2;  // Buffer usado para guardar uma linha e buffer2 usado como auxiliar
    int i = 0;

    fgets(buffer, 70000, f);// eliminar a primeira linha
    fprintf(fp, "repo_id;author_id;committer_id;commit_at;message\n");


    while(fgets(buffer, 700000, f)) // Enquanto ler uma linha continua o ciclo
    {
        buffer2 = buffer;  // Colocar buffer2 a apontar para o buffer
        GH_COMMIT1 new = separate_c1(buffer2);
        i = uservalid_c(new);
        if(i == 0) print_line(fp, buffer2);    
    }
   
    fclose(fp);
    fclose(f);
    return 0;

}


int main_repos() {

    FILE *f  = fopen("entrada/repos-g3.csv", "r");  // Abrir o ficheiro em modo leitur
    FILE *fp = fopen ("saida/repos-ok.csv", "w+");
    if (!f){
     printf("Ficheiro Inválido\n"); // Indica caso o ficheiro não exista
     return 1; // Se o ficheiro nao existir e f ficar NULL, retorna 1
    }
    char buffer[700000], *buffer2;  // Buffer usado para guardar uma linha e buffer2 usado como auxiliar
    int i = 0; 


    fprintf(fp, "id;owner_id;full_name;license;has_wiki;description;language;default_branch;created_at;updated_at;forks_count;open_issues;stargazers_count;size\n");

    while(fgets(buffer, 700000, f)) // Enquanto ler uma linha continua o ciclo
    {
        buffer2 = buffer;  // Colocar buffer2 a apontar para o buffer
        GH_REPOS1 new = separate_r1(buffer2);
        i = uservalid_r(new);
        if (i == 0) print_line(fp, buffer2);
    }
    
    fclose(fp);
    fclose(f);
    return 0;

}


int maing1(){
    printf("A Filtrar Ficheiros...\n");

    main_user();
    main_repos();
    main_commit();

    printf("Ficheiros filtrados com sucesso.\n\n");
    return 0;
  
}