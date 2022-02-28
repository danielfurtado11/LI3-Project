typedef struct repos *GH_REPOS;

typedef struct arrayRepos *INFO_REPOS;

int get_Size_R(INFO_REPOS repos);

GH_REPOS * get_Array_R(INFO_REPOS repos);

GH_REPOS separate_r (char *linha);

char * get_language(GH_REPOS repos);

int get_ID_R (GH_REPOS repos);

int get_Owner_ID (GH_REPOS repos);

char * get_Description (GH_REPOS repos);

void insertRepos (INFO_REPOS user, GH_REPOS new);

INFO_REPOS initRepos();

INFO_REPOS data_Repos();

void quicksort_REPOS(GH_REPOS *array, int inicio, int fim);

void quicksort_R_ID(GH_REPOS *array, int inicio, int fim);

int binarySearch_REPOS(GH_REPOS *arr, int primeiro, int fim,int id_que_estamos_a_procura);

char * binarySearch_R_DESC(GH_REPOS *arr, int primeiro, int fim,int id_que_estamos_a_procura);