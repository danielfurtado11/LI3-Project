#pragma once

typedef struct commit1 *GH_COMMIT1;

int get_sizeC();

GH_COMMIT1 separate_c1 (char *linha);

int uservalid_c (GH_COMMIT1 user);