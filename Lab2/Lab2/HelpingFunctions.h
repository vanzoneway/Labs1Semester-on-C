#include <stdio.h>
#define Ox 30
#define Oy 6
#include <math.h>


int main() {
    char graph[Oy * 2][Ox * 2];
    for (int y = 0; y < Oy * 2; y++) {
        for (int x = 0; x < Ox * 2; x++) {
            graph[y][x] = '.';
            graph[Oy][x] = '-';
        }
        graph[y][Ox] = '|';


    }
    for (int x = 0; x < Ox; x++) {
        double y = sqrt(25 - pow(x, x));
        graph[(int)round(y) + Oy][x + Ox] = '*';
    }
    for (int y = 0; y < Oy * 2; y++) {
        for (int x = 0; x < Ox * 2; x++) {
            printf("%c ", graph[y][x]);
        }
        printf("\n");
    }

}
