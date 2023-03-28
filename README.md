# TicTacToe

Classic Tic-Tac-Toe Game

---

## Building

Visual Studio 2022 is recommended. The application should work on all Operating Systems, but it has only been tested on Windows.

### Requirements

-   [premake5](https://premake.github.io/)
-   [SDL2](https://www.libsdl.org/)
-   [Visual Studio 2022](https://visualstudio.microsoft.com/) or higher

### Steps

1. Clone the repository using `git clone https://github.com/DevTotoro/TicTacToe`.
2. Create a `.bat` file in the now cloned repository and enter the following:

```
CALL path\to\premake5.exe\premake5.exe vs2022
PAUSE
```

3. Save the file and run it.
4. A `.sln` file should have been created in the directory.
5. Open the solution with Visual Studio and build the project.
6. The files generated can be found in the `./build/bin/` folder.
7. Copy the `SDL2.dll` file located in `location/of/SDL2/lib/x86` to the same folder as the `.exe`.

If you make any changes to the project you can regenerate the project files by re-running the `.bat` file.
