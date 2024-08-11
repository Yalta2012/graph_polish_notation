#include <math.h>
#include <stdio.h>

int main() {
    double a[] = {1, 2, 3.4, NAN, INFINITY, 4.123};
    for (int i = 0; i < 6; i++) {
        printf("%lf ", a[i]);
    }
    return 0;
}