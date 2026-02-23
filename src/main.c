#include <stdio.h>
#include "../include/game.h"
#include "../include/map.h"
#include <conio.h> // Windows only

int main() {
    initGame();

    printf("\n================================\n");
    printf("     Welcome to ShadowGrid!     \n");
    printf("================================\n\n");
    printf("Use W/A/S/D keys to move your robot (@).\n");
    printf("Reach the core (C) without being detected by sensors (S).\n");
    printf("Press any key to start...\n");
    getch(); // Wait for first keypress

    while (1) {
        drawMap();

        char input = getch();
        movePlayer(input);

        // Check win condition
        if (player.x == coreX && player.y == coreY) {
            drawMap();
            printf("Congratulations! You reached the core! You win!\n");
            break;
        }

        // Check detection
        if (isDetected()) {
            drawMap();
            printf("Detected by a sensor! Game over.\n");
            break;
        }
    }
    return 0;
}