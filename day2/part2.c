#include <stdlib.h>
#include <stdio.h>

const int LUT[15][4] = {
        { 4, 1, 2, 1 }, { 5, 1, 3, 2 }, { 6, 2, 3, 3 },
        { 7, 4, 5, 1 }, { 8, 4, 6, 2 }, { 9, 5, 6, 3 },
        { 7, 7, 8, 4 }, { 8, 7, 9, 5 }, { 9, 8, 9, 6 }
};

int main(int argc, char *argv[argc + 1]) {
    int code = 5;
    char c;

    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            code = LUT[code - 1][(char)((c * c) >> 10) & 3];
        } else {
            putchar('0' + code);
        }
    }

    putchar('\n');

    return 0;
}

