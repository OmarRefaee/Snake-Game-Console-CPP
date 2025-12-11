#include <iostream>
#include <vector>
#include <thread> // For std::this_thread::sleep_for
#include <chrono> // For std::chrono::seconds, milliseconds, etc.
#include <conio.h>
#include <string>
#include <Windows.h>
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
    enum  enDirection { W = 1, S = 2, D = 3, A = 4, X = 5 };
public:
    Position head = { WIDTH / 2, HEIGHT / 2 };
    vector<Position> body;
    enDirection Dir;
    bool isReset = false;
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
            case 'X':
                isReset = true;
                break;
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

    void moveSnake(bool isGrow) {
        Position oldHead = head;
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

        // moving body
        body.insert(body.begin(), oldHead);

        if (!isGrow)
        {
            body.pop_back();
        }
    }
};

class Board {
private:
    Position food;

public:
    vector<Position> food1;
    vector<Position> growbodyy;
    void spawnFood(vector<Position> body) {


        bool valid = false;

        while (!valid)
        {

            srand(time(NULL));
            food.x = rand() % (WIDTH - 2) + 1;
            food.y = rand() % (HEIGHT - 2) + 1;
            valid = true;
            for (int i = 0; i < body.size(); i++) {
                if (food.x == body[i].x && food.y == body[i].y)
                    valid = false;
            }
        }
        food1.push_back(food);

    }


    bool eatenFood(Position head) {


        for (int i = 0; i < food1.size(); i++) {
            if (head.x == food.x && head.y == food.y)
            {

                growbodyy.push_back(food);

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
    int highScore = 0;
    // ----------------------------
    // 3) OMAR – Game Manager
    // ----------------------------
    bool isDead(Position tester, vector<Position> testerBody) {
        // TODO: return true if snake hits wall or itself
        if (tester.x == 0 || tester.y == 0 || tester.x == WIDTH - 1 || tester.y == HEIGHT - 1)
        {
            cout << "GAME OVER!" << endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
            system("cls");
            return true;
        }
        else
        {
            for (int i = 0; i < testerBody.size(); i++)
            {
                if (tester.x == testerBody[i].x && tester.y == testerBody[i].y)
                {
                    cout << "GAME OVER!" << endl;
                    this_thread::sleep_for(chrono::milliseconds(1000));
                    system("cls");
                    return true;
                }
            }
        }
        return false;
    }

    void ShowConsoleCursor(bool showFlag)
    {
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

        CONSOLE_CURSOR_INFO     cursorInfo;

        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = showFlag; // set the cursor visibility
        SetConsoleCursorInfo(out, &cursorInfo);
    }

    void draw(Position tester, vector<Position> testerBody, vector<Position> testerFood) {
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD Position = { 0, 0 };
        SetConsoleCursorPosition(hOut, Position); // Move cursor to top-left
        ShowConsoleCursor(false);

        // TODO: print map, snake, food, score
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < WIDTH; j++)
            {
                if (j == 0)
                    cout << u8"\u2588";
                else if (j == WIDTH - 1)
                    cout << u8"\u2588";
                else if (i == 0 || i == HEIGHT - 1)
                    cout << u8"\u2588";
                else if (tester.x == j && tester.y == i)
                    cout << "O";
                else {
                    bool tf = true;
                    for (int k = 0; k < testerBody.size(); k++)
                    {
                        if (testerBody[k].x == j && testerBody[k].y == i)
                        {
                            cout << "o";
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
        cout << "HIGH SCORE: " << highScore << endl;

    }

    void resetGame(Game& game1, Snake& snake1, Board& board1) {
        // TODO: reset snake, direction, score, spawn food
        snake1.isReset = false;
        snake1.head = { WIDTH / 2 , HEIGHT / 2 };
        snake1.body = {};
        snake1.Dir = {};

        game1.score = 0;

        board1.food1 = {};
        board1.spawnFood(snake1.body);

        cout << "Game Reseted!" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
        system("cls");
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

    SetConsoleOutputCP(CP_UTF8);

    bool isGrow = false;
    while (true)
    {
        snake1.handleInput();
        if (snake1.isReset == true)
        {
            game1.highScore = game1.score;
            game1.resetGame(game1, snake1, board1);
        }
        if (board1.eatenFood(snake1.head))
        {
            isGrow = true;
            board1.spawnFood(snake1.body);
            game1.score++;
        }
        snake1.moveSnake(isGrow);
        isGrow = false;
        if (game1.isDead(snake1.head, snake1.body))
        {
            if (game1.score > game1.highScore)
                game1.highScore = game1.score;
            game1.resetGame(game1, snake1, board1);
        }
        game1.draw(snake1.head, snake1.body, board1.food1);
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    return 0;
}