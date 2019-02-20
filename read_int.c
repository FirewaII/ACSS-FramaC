#include <stdio.h>
#include "read_int.h"

int read_int(void) {
    static int count = 1;
    int result, c;
    printf("Entrez un entier (num %d) : ", count);
    while (!scanf("%d", &result)) {
        while ((c = getchar()) != '\n' && c != EOF); /* flush stdin */
        printf("Syntaxe invalide, recommencez (num %d) : ", count);
    }
    count++;
    return result;
}
