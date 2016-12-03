#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[argc + 1]) {

    int triangles = 0;
    int a, b, c;
    while (scanf(" %d %d %d\n", &a, &b, &c) > 0) {
        if (a + b > c && b + c > a && c + a > b)
            triangles++;
    }

    printf("%d\n", triangles);

    return 0;
}

