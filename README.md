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
  - GLFW (Static library `glfw.a` included in the `externals` folder)
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
- **Mouse Scroll**: Zoom in/out.

## File Structure

- `game_of_life.c`: Main source code for the simulation.
- `externals/`: Contains external dependencies like `glfw.a` and `glad.c`.
- `CMakeLists.txt`: Build configuration file.
- `README.md`: Project documentation.

## License

This project is licensed under the MIT License. See the full license below:

```
MIT License

Copyright (c) 2025 Oussama Belguesmia

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## Acknowledgments

- **GLFW**: For window management and OpenGL context creation.
- **GLAD**: For OpenGL function loading.
- **Conway's Game of Life**: Inspiration for the simulation.

---

Feel free to contribute to this project by submitting issues or pull requests!