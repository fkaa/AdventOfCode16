#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int freq[8][26] = {{0}};
    int *cur = freq;

    char c;
    while ((c = getchar()) != EOF) {
        printf("%c\n", c);
        if (c != '\n') {
            cur[c - 'a']++;
            cur += 26;
        } else {
            cur = freq;
        }
    }

    for (int i = 0; i < 8; ++i) {
        int max = -1;
        int idx = -1;
        for (int j = 0; j < 26; ++j) {
            int f = freq[i][j];
            if (f > max) {
                idx = j;
                max = f;
            }
        }
        putchar('a' + idx);
    }

    putchar('\n');s

    return 0;
}
