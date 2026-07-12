*This project has been created as part of the 42 curriculum by esttina.*

# So Long

## Description
So_long is a 2D game project where the goal is to collect all the collectibles on a map and reach the exit by choosing the shortest possible route. The game is built using the school's graphical library, MinilibX. It focuses on window management, event handling, and texture manipulation. 

![So Long Gameplay](https://github.com/user-attachments/assets/99c02589-5ade-4771-bfd2-7465a3e69cbc)

## Key Features
* **Dynamic Rendering:** Built using the MiniLibx graphical library for window and image management.
* **Map Validation:** Includes comprehensive checks for rectangular shape, wall enclosure, and valid path accessibility using a flood-fill algorithm.
* **Event Handling:** Supports keyboard inputs (W, A, S, D) and window events (ESC to quit, close button) for a smooth user experience.

## Project Structure

## Instructions

### Installation
Clone the repository:
```bash
git clone <repository.url>
```
Compile the project:
```bash
make
```
Run the game:
Provide a valid .ber map as an argument:
```bash
./so_long maps/valid.ber
```

### Technical Choices
* Map Parsing: The program reads the .ber file and validates it against the 5 allowed characters (0,1,C,E,P);
* Path Finding: A flood-fill algorithm is implemented to ensure the player can reach all the collectibles and the exit before the game starts.
* Memory management: The project utilizes standard library functions (malloc, free) with strict attention to avoiding memory leaks, verified via Valgrind.


### Execution
Run the game by providing a map file with the .ber extension:
```bash
./so_long maps/valid.ber
```

### Project Structure

```text
so_long/
├── Makefile            # Compilation rules (all, clean, fclean, re)
├── README.md           # Project documentation
├── include/            # Header files
│   └── so_long.h       # Main header with structs and prototypes
├── src/                # Game logic and source code
│   ├── hooks.c         # Key hooks and window closing logic
│   ├── images.c        # Texture loading and MLX image handling
│   ├── main.c          # Main loop and initialization
│   ├── parse_map.c     # Map reading and parsing
│   ├── path_checker.c  # Flood-fill algorithm for map validation
│   ├── render.c        # Drawing the map and sprites to the screen
│   └── validate_map.c  # Checking walls, shapes, and elements
├── textures/           # Game assets (XPM images)
│   ├── collectible.xpm
│   ├── exit.xpm
│   ├── floor.xpm
│   ├── player.xpm
│   └── wall.xpm
├── maps/               # Valid and invalid test maps
│   ├── valid.ber
│   ├── bad_elements.ber
│   ├── bad_shape.ber
│   ├── bad_walls.ber
│   └── ... (other test maps)
├── libft/              # Custom C utility library
│   ├── Makefile
│   ├── libft.h
│   └── *.c             # str_len, get_next_line, split, etc.
├── mlx_linux/          # MiniLibX library (Linux)
└── mlx_mac/            # MiniLibX library (macOS)
```

### Resources
#### Documentation & Graphics
* https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
* https://medium.com/@ahmadbilla07/understanding-mlx-init-in-minilibx-beginner-friendly-7272b7ac9181
* https://medium.com/@jalal92/understanding-the-minilibx-a-practical-dive-into-x-window-programming-api-in-c-cb8a6f72bec3

#### Algorithms & Debugging
* https://www.youtube.com/watch?v=VuiXOc81UDM
* For memory leak testing, I used Valgrind:
```bash
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/valid.ber
```






