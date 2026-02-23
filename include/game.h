#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

typedef struct {
    int x, y;
} Player;

typedef struct {
    int x, y;
} Sensor;

extern Player player;
extern Sensor sensors[];
extern int sensorCount;

extern int coreX;
extern int coreY;

// Add this declaration
bool isReachable();

void initGame();
void drawMap();
bool isDetected();
void movePlayer(char input);

#endif