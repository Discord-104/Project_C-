# 🎮 Tetris Game Project

## 📝 Overview
This project implements a simplified version of the Tetris game. The main components include classes to manage blocks, colors, tetrominoes, the game board, and the game mechanics.

---

## 🧩 Classes Overview

### 🟥 **CBlock**
📦 Represents a single block on the Tetris grid.

#### ✨ Attributes:
- **`x`** (int): X coordinate of the block.
- **`y`** (int): Y coordinate of the block.
- **`color`** (CColor): Color of the block.

#### ⚙️ Methods:
- **Constructors**:
  - Default: Initializes `x`, `y` to `0` with a default color.
  - Overloaded: Allows specifying coordinates and color.
- **Getters**: `get_X()`, `get_Y()`, `get_Color()`.
- **Setters**: `set_X()`, `set_Y()`, `set_Color()`.
- **Operations**:
  - `add(CBlock p)`: Adds the coordinates of another block.
  - `sub(CBlock p)`: Subtracts the coordinates of another block.

---

### 🎨 **CColor**
🌈 Represents the RGB color of a block.

#### ✨ Attributes:
- **`r`, `g`, `b`** (int): Red, green, and blue color values.

#### ⚙️ Methods:
- **Constructors**:
  - Default: Initializes color to black (0, 0, 0).
  - Overloaded: Allows specifying RGB values.
- **Getters**: `get_Red()`, `get_Green()`, `get_Blue()`.
- **Setters**: `set_Red()`, `set_Green()`, `set_Blue()`.

---

### 🔄 **CTetromino**
📐 Represents a tetromino (a group of four connected blocks).

#### ✨ Attributes:
- **`tetromino`** (CBlock[MAX_EL_T]): Array of blocks that make up the tetromino.

#### ⚙️ Methods:
- **Constructors**:
  - Default: Initializes the blocks to default values.
  - Overloaded: Creates a tetromino based on a central block and shape.
- **Operations**:
  - `add(CBlock offset, int i)`: Moves block `i` by an offset.
  - `rotate()`: Rotates the tetromino.
  - `isInside(int maxX, int maxY)`: Checks if the tetromino is within the bounds.

---

### 🎮 **CTetris**
🕹️ Manages the game board and logic.

#### ✨ Attributes:
- **`matrix`**: Board that stores the colors of the blocks.
- **`tetromino`**: Active tetromino.
- **`lines`**, **`score`**, **`speed`**: Game status.

#### ⚙️ Methods:
- `movement(int key)`: Manages the movement of the tetromino.
- `CreateTetromino()`: Generates a new random tetromino.
- `isGameOver()`: Checks if the game is over.
- `shift(int row)`: Removes a completed row and shifts the rows above.

---

## 🚀 Compilation and Execution

1. Ensure all `.cpp` and `.h` files are in the same directory.  
2. Compile the project:  
   ```sh
   g++ -o Tetris CTetris.cpp CBlock.cpp CColor.cpp CTetromino.cpp main.cpp
   ```  
3. Run the program:  
   ```sh
   ./Tetris
   ```

---

## 🎮 Controls
- **⬅️ Left Arrow**: Move the tetromino left.  
- **➡️ Right Arrow**: Move the tetromino right.  
- **⬆️ Up Arrow**: Rotate the tetromino.  
- **⬇️ Down Arrow**: Increase the falling speed.

---

## 🌟 Features
- 🎲 Random generation of tetrominoes with different colors.  
- 🧱 Real-time detection of collisions and movements.  
- 🏆 Row elimination and scoring mechanics.  
- ⏩ Adjustable speed for increasing challenge.

---

## 🚧 Future Improvements
- 🔊 Addition of sound effects and background music.  
- 🖼️ Implementation of a graphical user interface (GUI).  
- 🆙 Levels with increasing difficulty.  
- 💾 Save and load game state.

---

## 👤 Author
📛 **[Guido Ramella]**  
📩 **[kujoj9129@gmail.com]**

---

## 📄 License  
This project is distributed under the **MIT License**.  


