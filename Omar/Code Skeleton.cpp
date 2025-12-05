#include <iostream>
#include <vector>
#include <thread> // For std::this_thread::sleep_for
#include <chrono> // For std::chrono::seconds, milliseconds, etc.
using namespace std;

// ----------------------------
// SHARED DATA
// ----------------------------
struct Position {
    int x, y;
};

const int WIDTH = 50;
const int HEIGHT = 15;

// OOP Classes

// AHMED - Input + Movement
class Snake {
private:
    vector<Position> snake;
    int dirX, dirY;

public:
    Position head;
    vector<Position> body;
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
    vector<Position> food1;
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
    int score = 0;

public:
    // ----------------------------
    // 3) OMAR – Game Manager
    // ----------------------------
    bool isDead(Position tester, vector<Position> testerBody) {
        // TODO: return true if snake hits wall or itself
        if (tester.x == 0 || tester.y == 0 || tester.x == WIDTH-1 || tester.y == HEIGHT-1)
        {
            cout << "GAME OVER" << endl;
            return true;
        }
        else
        {
            for (int i = 0; i < testerBody.size(); i++)
            {
                if (tester.x == testerBody[i].x && tester.y == testerBody[i].y)
                {
                    cout << "GAME OVER" << endl;
                    return true;
                }
            }
        }
        return false;
    }

    void draw(Position tester, vector<Position> testerBody, vector<Position> testerFood) {
        // TODO: print map, snake, food, score
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                
                if (j == 0)
                    cout << "*";
                else if (j == WIDTH - 1)
                    cout << "*";
                else if (i == 0 || i == HEIGHT - 1)
                    cout << "*";
                else if (tester.x == j && tester.y == i)
                    cout << "O";
                else {
                    bool tf = true;
                    for (int k = 0; k < testerBody.size(); k++)
                    {
                        if (testerBody[k].x == j && testerBody[k].y == i)
                        {
                            cout << "-";
                            tf = false;
                        }
                    }
                    for (int l = 0; l < testerFood.size(); l++)
                    {
                        if (testerFood[l].x == j && testerFood[l].y == i)
                        {
                            cout << "@";
                            tf = false;
                        }
                    }
                    if (tf)
                        cout << " ";
                }
                
            }
            cout << endl;
        }
        cout << "SCORE: " <<  score << endl;
    }

    void resetGame(Game game1, Snake snake1) {
        // TODO: reset snake, direction, score, spawn food
        Snake snake2;
        snake1 = snake2;
        
        Game game2;
        game1 = game2;
    }
};

int main() {
    cout << "SNAKE GAME" << endl;
    // TODO: initialize game
    // TODO: loop: handleInput → moveSnake → eatenFood → isDead → draw
    Game game1;
    Snake snake1;
    Board board1;

    while (true)
    {
        std::cout << "\033[2J\033[1;1H";
        snake1.handleInput();
        snake1.moveSnake();
        game1.isDead(snake1.head, snake1.body);
        game1.draw(snake1.head, snake1.body, board1.food1);
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    Position tester;
    tester.x = 5;
    tester.y = 10;

    vector<Position> testerBody;
    testerBody.push_back({ 5, 10 });
    testerBody.push_back({ 3, 10 });
    testerBody.push_back({ 2, 10 });

    vector<Position> testerFood;
    testerFood.push_back({10, 10});

    Game game;
    game.draw(tester, testerBody, testerFood);
    game.isDead(tester, testerBody);
    return 0;
}