#include <stdio.h>
#include <stdlib.h>
#include "../include/game.h"
#include "../include/map.h"

Player player;
Sensor sensors[2];
int sensorCount = 2;

int coreX, coreY;

void initGame() {
    int sIndex = 0;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (map[y][x] == PLAYER) {
                player.x = x;
                player.y = y;
            } else if (map[y][x] == SENSOR) {
                sensors[sIndex].x = x;
                sensors[sIndex].y = y;
                sIndex++;
            } else if (map[y][x] == CORE) {
                coreX = x;
                coreY = y;
            }
        }
    }
}

void drawMap() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    for (int y = 0; y < HEIGHT; y++) {
        printf("%s\n", map[y]);
    }
}

bool isDetected() {
    for (int i = 0; i < sensorCount; i++) {
        int sx = sensors[i].x;
        int sy = sensors[i].y;

        // Vertical up
        for (int y = sy - 1; y >= 0; y--) {
            if (map[y][sx] == WALL) break;
            if (y == player.y && sx == player.x) return true;
        }
        // Vertical down
        for (int y = sy + 1; y < HEIGHT; y++) {
            if (map[y][sx] == WALL) break;
            if (y == player.y && sx == player.x) return true;
        }
        // Horizontal left
        for (int x = sx - 1; x >= 0; x--) {
            if (map[sy][x] == WALL) break;
            if (sy == player.y && x == player.x) return true;
        }
        // Horizontal right
        for (int x = sx + 1; x < WIDTH; x++) {
            if (map[sy][x] == WALL) break;
            if (sy == player.y && x == player.x) return true;
        }
    }
    return false;
}

void movePlayer(char input) {
    int newX = player.x;
    int newY = player.y;

    if (input == 'w') newY--;
    else if (input == 's') newY++;
    else if (input == 'a') newX--;
    else if (input == 'd') newX++;

    if (map[newY][newX] != WALL) {
        map[player.y][player.x] = EMPTY;
        player.x = newX;
        player.y = newY;
        map[player.y][player.x] = PLAYER;
    }
}