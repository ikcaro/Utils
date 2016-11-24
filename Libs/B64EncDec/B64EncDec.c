#include "B64EncDec.h"

int calcSize64(int s)
{
    int bi = s * 8;
    int mo = bi % 6;
    
    return (bi / 6) + ((mo > 0)? (mo % 3) + 1: 0);
}

int addPad64(char *c, int i, int s)
{
    int j;
    
    for (j = (3 - (s % 3)); (j > 0) && (j < 3); j--)
        c[i - j] = '=';
    c[i] = 0;
}

int findChar64(char c)
{
    int i;
    
    for (i = 0; i <= TBASE; i++)
        if (c == base_64[i])
            return i;
    return 0;
}

char *encodeB64(const unsigned char *m, int s)
{
    int j = 0;
    int i = 0;
    int t = 0;
    char *c = NULL;
    
    c = calloc(calcSize64(s) + 1, sizeof(char));
    if (!c)
        return c;
    
    while (j < s) {
        t  = (m[j++] << 0x10);
        t += (j < s)? (m[j++] << 0x08): 0;
        t += (j < s)? (m[j++] << 0x00): 0;
        
        c[i++] = base_64[(t >> 0x12) & 0x3F];
        c[i++] = base_64[(t >> 0x0C) & 0x3F];
        c[i++] = base_64[(t >> 0x06) & 0x3F];
        c[i++] = base_64[(t >> 0x00) & 0x3F];
    }
    
    addPad64(c, i, s);
    return c;
}

char *decodeB64(const unsigned char *m)
{
    int j = 0;
    int i = 0;
    int t = 0;
    int s = strlen(m);
    unsigned char *c = NULL;
    
    c = calloc(s + 1, sizeof(char));
    if (!c)
        return c;
    
    while (j < s) {
        t  = findChar64(m[j++]) << 0x12;
        t += findChar64(m[j++]) << 0x0C;
        t += findChar64(m[j++]) << 0x06;
        t += findChar64(m[j++]) << 0x00;
        
        c[i++] = (t >> 0x10);
        c[i++] = (t >> 0x08);
        c[i++] = (t >> 0x00);
    }
    
    return c;
}
