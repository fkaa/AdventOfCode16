#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 1024
#define MAX_INSTRUCTION_SIZE 512

typedef struct Position {
    int x;
    int y;
} Position;

const Position deltas[4] = {
        {  0,  1 },
        {  1,  0 },
        {  0, -1 },
        { -1,  0 }
};

bool intersects(Position a1, Position a2, Position b1, Position b2, Position *out) {
    int a_minx = a1.x < a2.x ? a1.x : a2.x;
    int a_maxx = a1.x > a2.x ? a1.x : a2.x;
    int a_miny = a1.y < a2.y ? a1.y : a2.y;
    int a_maxy = a1.y > a2.y ? a1.y : a2.y;

    int b_minx = b1.x < b2.x ? b1.x : b2.x;
    int b_maxx = b1.x > b2.x ? b1.x : b2.x;
    int b_miny = b1.y < b2.y ? b1.y : b2.y;
    int b_maxy = b1.y > b2.y ? b1.y : b2.y;

    if (a_minx < b_maxx && a_maxx > b_minx && a_miny < b_maxy && a_maxy > b_miny) {
        *out = (Position) { a1.x, b1.y };
        return true;
    }

    return false;
}

int main(int argc, char *argv[argc + 1]) {
    char current_dir = 0;

    char *input = malloc(MAX_INPUT_SIZE);
    fgets(input, MAX_INPUT_SIZE, stdin);

    Position *positions = calloc(MAX_INSTRUCTION_SIZE, sizeof(*positions));
    Position pos = {0, 0};

    bool found = false;
    int count = 1;
    char *ptr = strtok(input, ", ");
    while (ptr) {
        char dir = ((*ptr++) & 0x3) - 1;
        int amt = atoi(ptr);

        current_dir = (current_dir + dir) & 3;
        pos.x += deltas[current_dir].x * amt;
        pos.y += deltas[current_dir].y * amt;

        if (!found) {
            Position prev = positions[count - 1];

            for (int i = 0; i < count - 1; ++i) {
                Position p1 = positions[i],
                         p2 = positions[i + 1];

                Position r = (Position) { p2.x - p1.x, p2.y - p1.y },
                         s = (Position) { pos.x - prev.x, pos.y - prev.y };

                if (!((r.x && s.x) || (r.y && s.y))) {
                    Position p;

                    if (intersects(p1, p2, prev, pos, &p)) {
                        found = true;
                        printf("%d\n", abs(p.x) + abs(p.y));
                    }
                }
            }
        }

        positions[count++] = pos;

        ptr = strtok(NULL, ", ");
    }

    printf("%d\n", abs(pos.x) + abs(pos.y));

    return 0;
}
