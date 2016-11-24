#ifndef __B64EncDec__
#define __B64EncDec__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TBASE	64
static char base_64[TBASE] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int   calcSize64(int s);
int   addPad64(char *c, int i, int s);
int   findChar64(char c);
char *encodeB64(const unsigned char *m, int s);
char *decodeB64(const unsigned char *m);

#endif
