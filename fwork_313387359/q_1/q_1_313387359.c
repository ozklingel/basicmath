
#define _BSD_SOURCE
#include <stdio.h>
#include <stdlib.h>

char globBuf[65536];            /* 1. heap */
int primes[] = { 2, 3, 5, 7 };  /* 2. stack*/

static int
square(int x)                   /* 3. text*/
{
    int result;                 /* 4. stack */

    result = x * x;
    return result;              /* 5. .The value of result is then copied into the adress of the call of squer functionin docalc.
}

static void
doCalc(int val)                 /* 6. text */
{
    printf("The square of %d is %d\n", val, square(val));

    if (val < 1000) {
        int t;                  /* 7. stack */

        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}

int
main(int argc, char* argv[])    /* text*/
{
    static int key = 9973;      /* stack */
    static char mbuf[10240000]; /* heap*/
    char* p;                    /* stack */


    doCalc(key);

    exit(EXIT_SUCCESS);
}

