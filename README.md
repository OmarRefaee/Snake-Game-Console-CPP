# 🐍 Snake Game - C++ Console Application

## Short Description

A classic **Snake Game** implemented as a simple, fast, and efficient console application using **C++**. The project is built around an **Object-Oriented Programming (OOP)** architecture for clear separation of logic, game state, and input handling.

### 🖼️ Preview

**[Insert Screenshot or Animated GIF of the game running here]**

---

## 🚀 Getting Started

### Prerequisites

-   **Operating System:** Windows **only**. (The project relies on OS-specific console functions from `<conio.h>` and `<Windows.h>`).
-   **Compiler:** A C++ compiler (e.g., g++ via MinGW or MSVC) capable of compiling C++11 or later.

### Setup

1.  Clone this repository:
    ```bash
    git clone [https://github.com/OmarRefaee/Snake-Game-Console-CPP](https://github.com/OmarRefaee/Snake-Game-Console-CPP)
    ```
2.  Navigate to the project directory.
3.  Compile the source code using your preferred compiler:
    ```bash
    g++ SnakeGame.cpp -o SnakeGame.exe
    ```
4.  Run the executable from your console:
    ```bash
    .\SnakeGame.exe
    ```

---

## ✨ Core Features

-   **Responsive Input:** Uses unbuffered input (`_kbhit()`) for immediate snake control without waiting for the Enter key.
-   **Dynamic Growth:** Snake grows by one segment upon consuming food, handled efficiently by skipping the tail removal.
-   **Collision Detection:** Checks for instant game over conditions (hitting the wall or self-collision).
-   **Game Management:** Tracks current score and persists the high score across game resets.
-   **Console Display:** Utilizes console cursor positioning for fast, flicker-free rendering of the map and game elements.

---

## 🧱 Architecture (OOP Design)

The project separates responsibilities into three primary classes, promoting clean code and maintainability (Separation of Concerns).

### 1. 🐍 `Snake` (Input + Movement)

Handles all aspects of the player character.

-   `handleInput()`: Captures player keystrokes (W/A/S/D) and updates the snake's direction.
-   `moveSnake(bool isGrow)`: Updates the head position, shifts the body segments, and manages growth if `isGrow` is true.

### 2. 🍎 `Board` (Food System)

Manages the game environment elements, primarily the food.

-   `spawnFood()`: Generates new food coordinates, ensuring they do not overlap with the snake's body.
-   `eatenFood()`: Checks if the snake's head position matches any food item position.

### 3. 🎮 `Game` (Game Manager)

Controls the overall state, loop, and display.

-   `isDead()`: Checks for game over conditions (wall collision or self-collision).
-   `draw()`: Renders the entire game state (map, snake, food, score) to the console.
-   `resetGame()`: Restores all objects (`Snake`, `Board`, `Game`) to their initial state for a new round.

## 🔄 Game Loop Execution

The core game logic runs continuously, processing state updates in the following critical order:

$$\text{handleInput()} \rightarrow \mathbf{\text{eatenFood()}} \rightarrow \mathbf{\text{moveSnake()}} \rightarrow \text{isDead()} \rightarrow \text{draw()}$$

---

## 🕹️ Controls

|  Key  | Action                              |
| :---: | :---------------------------------- |
| **W** | Move Up                             |
| **S** | Move Down                           |
| **A** | Move Left                           |
| **D** | Move Right                          |
| **X** | Trigger Game Reset (Manual Restart) |

---

## 🤝 Contribution

This project was developed by the following contributors:

-   **AHMED:** Input + Movement (`Snake` Class)
-   **ABDO ELSAYED:** Food System (`Board` Class)
-   **OMAR:** Game Manager (`Game` Class)

---

## 📄 License

This project is licensed under the **MIT License** - see the [LICENSE.md](LICENSE.md) file for details.
