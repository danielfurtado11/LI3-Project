typedef struct user *GH_USER;

typedef struct arrayUser *INFO_USER;

int get_Size_U(INFO_USER users);

GH_USER * get_Array_U(INFO_USER users);


int get_ID(GH_USER user);

char * get_Type(GH_USER user);

char * get_Login(GH_USER user);

GH_USER separate (char *linha);

void insertUser (INFO_USER user_arr, GH_USER user);

INFO_USER initUser();

INFO_USER data_User();

void quicksortUSER(GH_USER *array, int inicio, int fim);

int binarySearch_U(GH_USER *arr, int primeiro, int fim, int id_que_estamos_a_procura);

char * binarySearch_U_Login(GH_USER *arr, int primeiro, int fim,int id_que_estamos_a_procura);