# Snake 
## Overview
This Snake game is a classic arcade game implemented in C using the SDL library. The player controls a snake, guiding it to eat food while avoiding collisions with the game area boundaries and itself. Each time the snake eats food, it grows in length. The game continues until the snake collides with the boundary or itself.

## Screenshot
![Snake Game Screenshot](https://github.com/harrydobbs/snake_c/blob/main/images/screenshot.png)

## Features
- Smooth snake movement.
- Random food generation.
- Adjustable game speed.

## Requirements
- SDL2 library
- C compiler (e.g., GCC)
- Make 

## Installation and Running
1. **Clone the Repository**
   ```
   git clone [URL to your repository]
   cd [repository name]
   ```

2. **Build the Game**
   ```
   make all
   ```
   This command will compile the source files and link them with the SDL2 library.

3. **Run the Game**
   ```
   ./build/snake_game
   ```

## Controls
- **Arrow Keys**: Use the arrow keys to change the direction of the snake (Up, Down, Left, Right).

## Configuration
The game can be customized by modifying the `parameters.h` file which includes settings such as screen width, screen height, and snake speed.


## License
This project is licensed under the unlicense.

