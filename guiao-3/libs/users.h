typedef struct user *GH_USER;

typedef struct arrayType *ARR_TYPE;

GH_USER separate (char *linha);

int get_ID(GH_USER user);

char * get_Type(GH_USER user);

ARR_TYPE sum_Type();

int get_Bot(ARR_TYPE user);

int get_User(ARR_TYPE user);

int get_Org(ARR_TYPE user);
