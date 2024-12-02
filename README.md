# Chess Using SFML ♟️🖥️

A **2-player chess game** built using **C++** and the **Simple and Fast Multimedia Library (SFML)**! 🎮 This game combines Object-Oriented Programming (OOP) principles with a smooth **GUI** for an immersive chess experience. Play the classic game of chess with a dynamic interface and mouse-based piece movement! 🏰♟️

## Features 🌟

- **Interactive Chessboard** 🏁: A fully functional chessboard with a smooth, clickable interface for easy piece movement.
- **Two-player Mode** 👥: Play against a friend locally with no AI needed.
- **SFML Integration** 🔧: Custom GUI and user interaction powered by SFML (Dynamic Linked Library).
- **Object-Oriented Design** 🏗️: Code structure based on OOP principles for easy modification and extension.
- **Mouse-based Movement** 🖱️: Move pieces directly with the mouse for a modern touch on the classic game.

## Tools & Technologies 🛠️

- **C++** 💻: The main programming language used for game logic and backend development.
- **SFML** 🎨: A dynamic multimedia library (DLL) used for GUI and game visuals. **Note:** SFML is not included by default in C++ libraries; you'll need to import the files.
- **Visual Studio** 🧑‍💻: IDE used for developing and compiling the game.
  
## Prerequisites ⚙️

- **SFML Library** 📚: You must import the SFML DLL files into your project for the game to run.
- **Increased Stack Size** ⛔: Set your reserve stack size to **larger than 32,580** to avoid memory-related issues.

## How to Run the Chess Game 🚀

Follow these simple steps to set up and run the game on your system.

### 1. Clone the Repository

Clone the repository to your local machine:

```bash
git clone https://github.com/yourusername/chess-using-sfml.git
cd chess-using-sfml
```

### 2. Install SFML
Before compiling, you'll need to install SFML and link it with your project:

Download SFML from the official website.
Extract the downloaded files and place them in your project directory or system path.

### 3. Compile the Game in Visual Studio
Note: Make sure to link the SFML DLLs in Visual Studio by including them in the project settings.

Run the following script to compile and run the game:
```bash
#!/bin/bash

# Step 1: Set up SFML environment (ensure SFML is linked to your project)
echo "Setting up SFML library..."
# (Ensure SFML is installed and linked in Visual Studio)

# Step 2: Build the project in Visual Studio (You can also build manually via IDE)
echo "Building Chess Game..."
# Use Visual Studio build commands or IDE to compile the game

# Step 3: Run the game after build completes
echo "Run the Chess Game in Visual Studio!"
```
Alternatively, you can manually build and run the project from Visual Studio by linking the SFML libraries in the project settings.

### 4. Run the Game
You can run the game from Visual Studio by pressing Build and Run button

### 5. Enjoy the Game 🎉
Now you can enjoy a friendly game of chess! ♟️ Play against your friend by clicking and dragging the pieces to make your moves. 🏆

### Troubleshooting 🛠️
- SFML Library Not Found ⚠️: If you encounter issues with the SFML library not being found, double-check that the SFML DLLs are correctly linked in your project settings and placed in the executable's directory.
- Stack Size Error ⚠️: If you see a "stack overflow" error, increase the reserve stack size in your project settings (Visual Studio: Project > Properties > Linker > System > Stack Reserve Size).

For more detailed instructions on setting up SFML in Visual Studio, refer to the SFML Setup Guide. ✨
