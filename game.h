#ifndef GAME_H
#define GAME_H

#include <windows.h>

#define MAX_X 50
#define MAX_Y 25
#define INITIAL_DELAY 100
#define MAX_UNRIPE_PUMPKINS 90
#define MAX_RIPE_PUMPKINS 5

enum direction { LEFT, RIGHT, UP, DOWN };

typedef struct tail_t {
    int x;
    int y;
} tail_t;

typedef struct drone_t {
    int x;
    int y;
    tail_t *tail;
    size_t tsize;
    int level;
    int color;
    enum direction dir;
} drone_t;

typedef struct pumpkin_t {
    int x;
    int y;
    int ripe;
} pumpkin_t;

void startGame();
drone_t initDrone(int x, int y, size_t tsize, int color, enum direction dir);
void generateUnripePumpkins(pumpkin_t unripePumpkins[]);
void printDrones(drone_t drones[], int droneCount, pumpkin_t ripePumpkins[], pumpkin_t unripePumpkins[], int paused, char field[MAX_X][MAX_Y]);
drone_t moveDrone(drone_t drone);
int isValidDirection(enum direction currentDirection, enum direction newDirection);
enum direction handleKey(char key, enum direction currentDirection, int* paused);
enum direction handleKey2(char key, enum direction currentDirection, int* paused);
int getDelay(int level);
int isCellFree(int x, int y, drone_t drones[], int droneCount, pumpkin_t unripePumpkins[]);
enum direction findRipePumpkin(drone_t drone, drone_t drones[], int droneCount, pumpkin_t ripePumpkins[], pumpkin_t unripePumpkins[], int droneId);
void startMenu(int* color1, int* color2, int* mode, int* autoMode, int* droneCount);
int checkCollision(drone_t drones[], int droneCount, pumpkin_t unripePumpkins[]);

#endif
