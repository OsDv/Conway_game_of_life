# Game of Life

This project is an implementation of Conway's Game of Life, a cellular automaton simulation. The program uses OpenGL for rendering and GLFW for window management, providing a visually interactive experience.

## Features

- **Random Grid Generation**: Generate random initial states for the grid.
- **Next Generation Calculation**: Simulate the evolution of the grid based on Conway's rules.
- **Optimized Rendering**: Efficient rendering of the grid using OpenGL.
- **Camera Controls**: Navigate the simulation using keyboard inputs.
- **Zoom Functionality**: Adjust the zoom level for better visualization.

## Requirements

To build and run this project, you need the following:

- **C Compiler**: GCC or any compatible compiler.
- **CMake**: Version 3.31 or higher.
- **Dependencies**:
  - GLFW (Static library `glfw.a` included for windows in the `externals` folder)
  - OpenGL
  - GLAD (Included in the `externals` folder)

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/game_of_life.git
   cd game_of_life
   ```

2. Build the project using CMake:
   ```bash
   cmake -S . -B build
   cmake --build build
   ```

3. Run the executable:
   ```bash
   ./build/gameOfLife.exe
   ```

## Controls

- **Keyboard**:
  - `W`/`S`: Move up/down.
  - `A`/`D`: Move left/right.
  - `UP`/`DOWN`: Increase/decrease grid update speed.
- **Mouse Scroll**: Zoom in/out.

## File Structure

- `game_of_life.c`: Main source code for the simulation.
- `externals/`: Contains external dependencies like `glfw.a` and `glad.c`.
- `CMakeLists.txt`: Build configuration file.
- `README.md`: Project documentation.

## Acknowledgments

- **GLFW**: For window management and OpenGL context creation.
- **GLAD**: For OpenGL function loading.
- **Conway's Game of Life**: Inspiration for the simulation.

---

Feel free to contribute to this project by submitting issues or pull requests!
