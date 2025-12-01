#include <iostream>
#include <vector>
using namespace std;

// ----------------------------
// SHARED DATA
// ----------------------------
struct Position {
    int x, y;
};

const int WIDTH = 20;
const int HEIGHT = 15;

// OOP Classes

// AHMED - Input + Movement
class Snake {
private:
    vector<Position> snake;
    int dirX, dirY;

public:
    // ----------------------------
    // 1) AHMED – Input + Movement
    // ----------------------------
    void handleInput() {
        // TODO: read input W/A/S/D and update dirX, dirY
    }

    void moveSnake() {
        // TODO: move head + move body + handle growth
    }
};

// ABDO - Food System
class Board {
private:
    Position food;

public:
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
};

// OMAR - Game Manager
class Game {
private:
    int score;

public:
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
};

int main() {
    cout << "Hello Test" << endl;
    // TODO: initialize game
    // TODO: loop: handleInput → moveSnake → eatenFood → isDead → draw
    return 0;
}