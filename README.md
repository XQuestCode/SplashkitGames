## Splashkit Games

This repository contains games developed using the Splashkit library. Each game is stored in a dedicated subfolder, following the specified folder structure.

### Folder Structure

The repository follows the following folder structure:

```
root/
├── game1/
│   ├── src/
│   │   ├── game1.cpp
│   │   └── ...
│   ├── images/
│   │   ├── template.gif
│   │   └── ...
│   ├── readme.md
│   └── index.json
├── game2/
│   ├── src/
│   │   ├── game2.cpp
│   │   └── ...
│   ├── images/
│   │   ├── template.gif
│   │   └── ...
│   ├── readme.md
│   └── index.json
└── ...
```

Each game subfolder (`game1`, `game2`, etc.) contains the following:

- `src/`: This directory holds the game source files (e.g., `game1.cpp`, `game2.cpp`, etc.).
- `images/`: This directory contains any images or other assets used by the game, such as `template.gif`.
- `readme.md`: A Markdown file that provides information about the game, including a description, instructions, and any other relevant details.
- `index.json`: A JSON file that contains metadata about the game, as described below.

### `index.json` Format

The `index.json` file in each game subfolder follows this structure:

```json
{
    "name": "Angry Birds",
    "description": "A simple game of Angry Birds",
    "image": "template.gif",
    "language": "cpp",
    "command": "clang++ *.cpp -l SplashKit -o game && ./game"
}
```

The fields in the `index.json` file are:

- `name`: The name of the game.
- `description`: A brief description of the game.
- `image`: The filename of an image that represents the game (e.g., `template.gif`).
- `language`: The programming language used to develop the game (e.g., `cpp`).
- `command`: The command to build and run the game.

### Running the Games

To run a game, navigate to the game's subfolder and execute the command specified in the `index.json` file. For example, to run the "Angry Birds" game, you would execute the following command in the terminal:

```
clang++ *.cpp -l SplashKit -o game && ./game
```

This will compile the game source files and run the executable.