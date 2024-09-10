# 2048 Game Implementation

This is a C++ implementation of the popular 2048 game. The goal of the game is to slide numbered tiles on a grid to combine them into a tile with the number 2048.

## Features

- **Random Tile Generation**: The game places a `2` or `4` in a random empty cell of a 4x4 grid after each move.
- **Basic Movement Logic**: Tiles can be shifted up, and merging logic will combine adjacent tiles of the same value.
- **Win Condition**: Reach the 2048 tile to win the game.
- **Lose Condition**: The game ends when there are no valid moves left.

## How It Works

- The game starts with a 4x4 grid where two random tiles (either `2` or `4`) are placed.
- The player can move the tiles using four possible directions (up, down, left, right). After each move, a new tile (either `2` or `4`) is placed in a random empty cell.
- If two tiles of the same value collide when the grid is shifted, they will merge into one tile whose value is the sum of the two tiles.
- The game continues until the player achieves a tile with the value `2048`, or no more moves are possible.

## Getting Started

### Prerequisites

- C++ Compiler (e.g., GCC or Clang)
- Basic knowledge of C++ and object-oriented programming

### Running the Game

1. Clone the repository or download the source code.

```bash
git clone <repository-url>
