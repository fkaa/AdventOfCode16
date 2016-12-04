#include <stdio.h>
#include <stdbool.h>

bool valid(int occurrences[26], char *ptr) {
    int prev = 0;

    for (int i = 0; i < 5; ++i) {
        char m = *ptr++;
        prev |= (1 << (m - 'a'));

        for (int j = 0; j < 26; ++j) {
            if (occurrences[j] > occurrences[m - 'a'] && !(prev & (1 << j))) {
                return false;
            }
        }
    }

    return true;
}

int main(int argc, char *argv[argc + 1]) {
    char line[256];
    int sum = 0;

    while (fgets(line, sizeof(line), stdin)) {
        int occurrences[26] = {0};
        int sector = 0;

        char *p = line;
        char c;

        while ((c = *p++)) {
            if (c == '-')
                continue;

            if (c > '9') {
                occurrences[c - 'a']++;
            } else {
                sector +=    (c - '0') * 100;
                sector += (*p++ - '0') * 10;
                sector += (*p++ - '0');

                (void)p++;

                if (valid(occurrences, p))
                    sum += sector;

                break;
            }
        }
    }

    printf("%d\n", sum);

    return 0;
}

