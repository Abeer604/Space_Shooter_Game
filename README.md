# Space Invaders — Console Window Game

A Space Invaders-style shooter game built in C++ for Windows, rendered directly onto a console window using the Win32 GDI API.

---

## Files

| File | Description |
|------|-------------|
| `game.cpp` | Main game logic including the game loop, ship movement, alien movement, bullet mechanics, collision detection, scoring, and save/load functionality. |
| `GUILib.h` | A custom graphics library that wraps Win32 GDI calls to draw lines, rectangles, ellipses, and text directly on the console window. |

---

## How to Run

1. Open the project in a Windows C++ compiler/IDE (e.g. Visual Studio).
2. Compile `game.cpp` (which includes `GUILib.h`).
3. Run the executable. A console window will open and the game will render inside it.

> **Note:** This project targets **Windows only** and will not compile on Linux or macOS.

---

## Controls

| Key | Action |
|-----|--------|
| `← → ↑ ↓` Arrow Keys | Move ship |
| `Space` | Shoot bullet |
| `Escape` | Pause / Unpause |

---

## Gameplay

- A **5×10 grid of aliens** moves across and down the screen.
- Move your ship and shoot bullets to destroy all **50 aliens** before they reach you.
- If the aliens advance past your ship, you **lose a life** and your score drops by **20 points**.
- Each alien destroyed earns **10 points**.
- You start with **3 lives**. The game ends when all lives are lost or all aliens are destroyed.

---

## Save System

The game automatically saves its full state to `data.txt` on every frame — including ship position, alien positions, score, and remaining lives. On the next launch, you will be prompted to either **load** the saved game or **start a new game**.

---

## Project Structure

```
|____game.cpp       # Game logic and entry point
|____GUILib.h       # Custom Win32 GDI drawing library
|____data.txt       # Auto-generated save file (created at runtime)
```
