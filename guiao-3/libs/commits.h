#include "../libs/auxiliar.h"

typedef struct commit *GH_COMMIT;

typedef struct colab *COLAB;

typedef struct datevalid *DATEV;

DATEV sep_datevalid(char *linha);

GH_COMMIT separate_c (char *linha);

int compareDatas (DATEV dfixa, DATEV dfile);

int get_Author_ID (GH_COMMIT commit);

int get_Committer_ID (GH_COMMIT commit);

char * get_Commit_at(GH_COMMIT commit);

int get_Rep_ID(GH_COMMIT commit);

ARRDUP colabor();

ARRDUP readCommits(DATEV datainput);
