#include <limits.h>

/*@
    requires x >= 0;
    // TODO (2) : ajouter un "requires" pour avoir le "ensures" avec les RTE
    requires x <= INT_MAX / 2;
    ensures \result == 2 * x;
    // TODO (3) : ajouter le bon "assigns"
    assigns \nothing;
*/
int fois_2(int x) {
    int y = 0;
    /*@
        loop invariant x >= 0;
        loop invariant y >= 0;
        loop invariant y == 2 * (\at(x, Pre) - x);
        // TODO (3) : ajouter le bon "loop assigns"
        loop assigns x, y;
        // TODO (4) : ajouter un "loop variant"
        loop variant x;
    */
    while (x != 0) {
        y += 2;
        x--;
    }
    return y;
}

int c = 42;

#include "read_int.h"
#include "write_int.h"

int main(void) {
    int a_doubler = read_int();
    write_int("le nombre * 2 : ", fois_2(a_doubler));

    //@ assert c == 42;

    return 0;
}
