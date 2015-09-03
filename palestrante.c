#include "palestrante.h"
#include "mystring.h"

palestrante *cria_palestrante (char *nome, int matricula){
    char        *n;
    palestrante   *p;

    p = malloc (sizeof(palestrante));

    if (!p)
        return NULL;

    n = newString( strlen(nome) );

    strcpy (nome, n);

    p->nome = n;
    p->matricula = matricula;

    return p;
}

void *remove_palestrante (palestrante *p){
    delString(p->nome);
    free(p);
}
