#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>



/*  Remoção de commits que refiram utilizadores (committer_id, author_id)
inexistentes */
void remoçãocommits(){

FILE *fp = fopen(, "w+");


/*
* INICIALIZAR AS CENAS
*/

    INFO_USER users = data_User;
    int sizeU = get_Size_U(users);
    GH_USER *arrU = get_Array_U(users);

    INFO_COMMIT commits = data_Commit();
    int sizeC = get_Size_C (commits);
    GH_COMMIT *arrC = get_Array_C(commits);
/* 
* CRIEI UM OUTRO COMMIT PARA SER MAIS RAPIDO
*/

    INFO_COMMIT commits2 = data_Commit();
    int sizeC2 = get_Size_C (commits2);
    GH_COMMIT *arrC2 = get_Array_C(commits2);

/*
* ORDENAR POR COMMITER E AUTHOR
*/
    quicksort_COMMITERID(arrC,0,sizeC);
    quicksort_AUTHORID(arrC2,0,sizeC2);

/*
* Começar o for
*/ 


    for(int contador = 0; contador < sizeU; contador++){
        long r = binarySearch(arrC,get_COMMITERID[contador],0,sizeC-1);
        long r2 = binarySearch(arrC2,get_authorID[contador],0,sizeC2-1);
        if (r == -1 || r2 == -1){

        }
    }
}





void commit() {

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