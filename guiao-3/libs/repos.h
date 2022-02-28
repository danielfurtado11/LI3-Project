typedef struct repos *GH_REPOS;

typedef struct reposall *REPOSALL;

GH_REPOS separate_r (char *linha);

int get_ID_R (GH_REPOS repos);

int get_Owner_ID (GH_REPOS repos);

char * get_Description (GH_REPOS repos);

REPOSALL allrepos();

int getsizeR(REPOSALL repos);
