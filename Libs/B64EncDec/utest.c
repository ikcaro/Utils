#include "B64EncDec.h"

int main()
{
    char  str[] = "this is a normal string to code/decode";
    char *ostr1 = NULL;
    char *ostr2 = NULL;
    
    ostr1 = encodeB64(str, strlen(str));
    printf("[%s] => [%s]\n", str, ostr1);
    
    ostr2 = decodeB64(ostr1);
    printf("[%s] => [%s]\n", ostr1, ostr2);
    
    free(ostr1);
    free(ostr2);
    
    return 0;
}

