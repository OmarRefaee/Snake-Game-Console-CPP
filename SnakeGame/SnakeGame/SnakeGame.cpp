#include <iostream>
#include <vector>
#include <thread> // For std::this_thread::sleep_for
#include <chrono> // For std::chrono::seconds, milliseconds, etc.
#include <conio.h>
#include <string>
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
    enum  enDirection { W = 1, S = 2, D = 3, A = 4 };
public:
    Position head = { 5, 10 };
    vector<Position> body;
    enDirection Dir;
    // ----------------------------
    // 1) AHMED – Input + Movement
    // ----------------------------
    void handleInput() {
        if (_kbhit())
        {
            //Using toupper to Convert any Characters to Capital
            //Using _getch() 
            char  c = _getch();
            c = toupper(c);
            switch (c)
            {
            case 'W':
                Dir = enDirection::W;
                break;
            case 'S':
                Dir = enDirection::S;
                break;
            case 'A':
                Dir = enDirection::A;
                break;

            case 'D':
                Dir = enDirection::D;
                break;

            default:
                break;
            }
        }
    }

    void moveSnake() {
        switch (Dir)
        {
        case W:
            head.y--;
            break;
        case S:
            head.y++;
            break;
        case A:
            head.x--;
            break;
        case D:
            head.x++;
            break;
        }
    }
};

class Board {
private:
    Position food;

public:
    vector<Position> food1;

    void spawnFood(vector<Position> body) {


        bool valid = false;

        while (!valid) {
            food.x = rand() % (WIDTH - 2) + 1;
            food.y = rand() % (HEIGHT - 2) + 1;
            valid = true;
            for (int i = 0; i < body.size(); i++) {
                if (food.x == body[i].x && food.y == body[i].y)
                    valid = false;
                break;
            }
        }
        food1.push_back(food);
    }



    bool eatenFood(Position head) {


        for (int i = 0; i < food1.size(); i++) {
            if (head.x == food1[i].x && head.y == food1[i].y)
            {
                food1.erase(food1.begin() + i);
                return true;
            }
        }

        return false;
    }
};


// OMAR - Game Manager
class Game {
private:

public:
    int score = 0;
    // ----------------------------
    // 3) OMAR – Game Manager
    // ----------------------------
    bool isDead(Position tester, vector<Position> testerBody) {
        // TODO: return true if snake hits wall or itself
        if (tester.x == 0 || tester.y == 0 || tester.x == WIDTH - 1 || tester.y == HEIGHT - 1)
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
        cout << "SCORE: " << score << endl;
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

    board1.spawnFood(snake1.body);
    while (true)
    {
        //std::cout << "\033[2J\033[1;1H";
        system("cls");
        snake1.handleInput();
        snake1.moveSnake();
        if (board1.eatenFood(snake1.head))
        {
            board1.spawnFood(snake1.body);
            game1.score++;
        }
        if (game1.isDead(snake1.head, snake1.body))
        {
            break;
        }
        game1.draw(snake1.head, snake1.body, board1.food1);
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    return 0;
}