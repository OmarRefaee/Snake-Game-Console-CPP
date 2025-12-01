#include <iostream>
#include <vector>
using namespace std;

// ----------------------------
// SHARED DATA
// ----------------------------
struct Position {
    int x, y;
};

vector<Position> snake;
Position food;
int score;
int dirX, dirY;
const int WIDTH = 20;
const int HEIGHT = 15;

// ----------------------------
// 1) TAREK – Input + Movement
// ----------------------------
void handleInput() {
    // TODO: read input W/A/S/D and update dirX, dirY
}

void moveSnake() {
    // TODO: move head + move body + handle growth
}

// ----------------------------
// 2) ABDO ELSAYED – Food System
// ----------------------------
void spawnFood() {
    // TODO: randomly place food not inside snake
}

bool eatenFood() {
    // TODO: return true if snake head touches food
    return false;
}

// ----------------------------
// 3) OMAR – Game Manager
// ----------------------------
bool isDead() {
    // TODO: return true if snake hits wall or itself
    return false;
}

void draw() {
    // TODO: print map, snake, food, score
}

void resetGame() {
    // TODO: reset snake, direction, score, spawn food
}

int main() {
    cout << "Hello Test" << endl;
    // TODO: initialize game
    // TODO: loop: handleInput → moveSnake → eatenFood → isDead → draw
    return 0;
}
