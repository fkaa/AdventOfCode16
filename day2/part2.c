#include <stdlib.h>
#include <stdio.h>

const char LUT[13][4] = {
                                       { 3,  1,  1,  1  },
                    { 6,  2,  3,  2 }, { 7,  2,  4,  1  }, { 8,  3,  4,  4 },
    { 5, 5, 6, 5 }, { 10, 5,  7,  2 }, { 11, 6,  8,  3  }, { 12, 7,  9,  4 }, { 9, 8, 9, 9 },
                    { 10, 10, 11, 6 }, { 13, 10, 12, 7  }, { 12, 11, 12, 8 },
                                       { 13, 13, 13, 11 }
};

int main(int argc, char *argv[argc + 1]) {
    int code = 5;
    char c;

    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            code = LUT[code - 1][(char)((c * c) >> 10) & 3];
        } else {
            putchar('0' + (code > 9 ? (code + 7) : code));
        }
    }

    putchar('\n');

    return 0;
}

