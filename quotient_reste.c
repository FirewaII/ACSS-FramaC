// TODO : mettre les bonnes annotations...

/*@
    requires x >= 0;
    requires y >= 1;
    requires \valid(q) && \valid(r); // q et r != NULL
    requires \separated(q, r);
    ensures x == *q * y + *r;
    ensures 0 <= *r < y;
    assigns *q, *r;
  @*/
void quotient(int x,int y, int *q, int *r) {
    *q = 0;
    *r = x;
  
    /*@
        loop invariant *q >= 0;
        loop invariant *r >= 0;
        loop invariant *q * y + *r == \at(x, Pre);
        loop assigns *q, *r;
        loop variant *r;
    */
    while (*r >= y) {
        (*q)++;
        *r -= y;
    }
}

#include "read_int.h"
#include "write_int.h"

#include <limits.h>

int main(void) {
    int x = read_int(), y = read_int();

    int quo, res;

    if (x == INT_MIN) x = INT_MAX;
    if (y == INT_MIN) y = INT_MAX;
    if (x < 0) x = -x;
    if (y < 0) y = -y;

    quotient(x, y, &quo, &res);

    write_int("quotient : ", quo);
    write_int("reste : ", res);

    return 0;
}
