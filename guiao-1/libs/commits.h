#pragma once

typedef struct commit *GH_COMMIT;

int get_sizeC();

GH_COMMIT separate_c (char *linha);

void show_commit(FILE *stream, GH_COMMIT k);

int uservalid_c (GH_COMMIT user);