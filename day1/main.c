#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

const char N = 0;
const char E = 1;
const char S = 2;
const char W = 3;

int main(int argc, char *argv[argc + 1]) {
    char current_dir = N;

    char *input = malloc(MAX_INPUT_SIZE);
    fgets(input, MAX_INPUT_SIZE, stdin);

    int x = 0, y = 0;

    char *ptr = strtok(input, ", ");
    while (ptr) {
        char dir = *ptr++;
        int amt = atoi(ptr);

        if (dir == 'L') {
            if (current_dir - 1 < N)
                current_dir = W;
            else
                current_dir--;
        } else if (dir == 'R') {
            if (current_dir + 1 > W)
                current_dir = N;
            else
                current_dir++;
        }

        switch (current_dir) {
            case N:
                y += amt;
                break;
            case E:
                x += amt;
                break;
            case S:
                y -= amt;
                break;
            case W:
                x -= amt;
                break;
            default:
                break;
        }

        ptr = strtok(NULL, ", ");
    }

    printf("%d\n", abs(x) + abs(y));

    return 0;
}
