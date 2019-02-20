// TODO : mettre les bonnes annotations...

/*@
    requires x >= 0;
    requires y >= 1;
    // q est le quotient de x par y <=>
    //      1) q * y <= x
    //      2) x - q * y < y        (x - q *y) est le reste
    ensures \result * y <= x;
    ensures x - \result * y < y;
    assigns \nothing;
  @*/
int quotient(int x,int y) {
    int q = 0;
    int r = x;
  
    /*@
        loop invariant q >= 0;
        loop invariant r >= 0;
        loop invariant q * y + r == \at(x, Pre);
        loop assigns q, r;
        loop variant r;
    */
    while (r >= y) {
        q++;
        r -= y;
    }
    return q;
}

#include "read_int.h"
#include "write_int.h"

#include <limits.h>

int main(void) {
    int x = read_int(), y = read_int(), q;

    if (x == INT_MIN) x = INT_MAX;
    if (y == INT_MIN) y = INT_MAX;
    if (x < 0) x = -x;
    if (y < 0) y = -y;

    q = quotient(x, y);

    write_int("quotient : ", q);

    return 0;
}
