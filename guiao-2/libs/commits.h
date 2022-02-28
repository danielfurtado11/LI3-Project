

typedef struct commit *GH_COMMIT;

typedef struct arrayCommit *INFO_COMMIT;

int get_Size_C(INFO_COMMIT commits);

GH_COMMIT * get_Array_C(INFO_COMMIT commits);

GH_COMMIT separate_c (char *linha);

int get_Author_ID (GH_COMMIT commit);

int get_Committer_ID (GH_COMMIT commit);

char * get_Commit_at(GH_COMMIT commit);

int get_Rep_ID(GH_COMMIT commit);

void insertCommit (INFO_COMMIT user, GH_COMMIT new);

INFO_COMMIT initCommit();

INFO_COMMIT data_Commit();

void quicksort_AUTHORID(GH_COMMIT *array, int inicio, int fim);

void quicksort_COMMITERID(GH_COMMIT *array, int inicio, int fim);

int binarySearch_C_COMMITER(GH_COMMIT *arr, int primeiro, int fim,int id_que_estamos_a_procura);

long binarySearch(GH_COMMIT *arr, long x, int low, int high);