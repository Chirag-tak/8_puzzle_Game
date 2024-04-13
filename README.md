# 8_puzzle_Game
# Sliding Puzzle Game
This project implements a simple command-line-based sliding puzzle game in C, where the player needs to arrange the numbers in ascending order by moving a blank space within a 3x3 grid.
## Table of Contents

- [Getting Started](#getting-started)
- [Game Rules](#game-rules)
- [Usage](#usage)
- [Dependencies](#dependencies)
- [Contributing](#contributing)
- [License](#license)

## Getting Started

To get started with the game, clone this repository to your local machine:

```bash
git clone https://github.com/your-username/sliding-puzzle.git
```

Compile the code using any C compiler:

```bash
gcc sliding_puzzle.c -o sliding_puzzle
```

Run the compiled executable:

```bash
./sliding_puzzle
```

## Game Rules

1. The game starts with a randomly generated initial configuration of the puzzle.
2. The player can move the blank space (represented as -1) to adjacent positions (up, down, left, or right) within the 3x3 grid.
3. The goal is to arrange the numbers 1 to 8 in ascending order from left to right, top to bottom, with the blank space in the bottom-right corner.

## Usage

1. Upon starting the game, you will see the initial puzzle configuration and a choice matrix indicating valid moves.
2. Enter the position number of the blank space you want to move next.
3. Continue making moves until you solve the puzzle.

## Dependencies

This program uses standard C libraries:

- stdio.h
- math.h
- stdlib.h
- time.h

## Contributing
Contributions to this project are welcome. If you have suggestions for improvements, open an issue or fork the repository and submit a pull request.

You can customize this README according to your project's specifics, such as adding more details about the implementation, additional features, or instructions for advanced usage.
