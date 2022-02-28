#pragma once

typedef struct repos1 *GH_REPOS1;

int get_sizeR();

GH_REPOS1 separate_r1 (char *linha);

int wikivalid (char *type);

int uservalid_r (GH_REPOS1 user);