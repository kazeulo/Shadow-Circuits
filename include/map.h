#ifndef MAP_H
#define MAP_H

#define WIDTH 10
#define HEIGHT 8

#define EMPTY ' '
#define WALL '#'
#define PLAYER '@'
#define SENSOR 'S'
#define CORE 'C'
#define LIGHT '*'

extern char map[HEIGHT][WIDTH + 1];

#endif