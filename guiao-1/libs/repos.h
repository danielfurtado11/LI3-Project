#pragma once

typedef struct repos *GH_REPOS;

int get_sizeR();

GH_REPOS separate_r (char *linha);

int wikivalid (char *type);

int uservalid_r (GH_REPOS user);

void show_user_r(FILE *stream, GH_REPOS k);