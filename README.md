# 🕹️ So Long  

**So Long** is a 2D game built using **MLX42**, where the player navigates a map, collects items, and reaches the exit while avoiding enemies.  

## 📜 Features  
✅ Player movement (WASD or arrow keys)  
✅ Collectible items  
✅ Enemy movement (all enemies move in the same initial direction)  
✅ Exit unlocks after collecting all items  
✅ Simple rendering using MLX42  

## 📁 Files  

- `so_long.c` – Initializes the game and handles the main loop  
- `ft_parse.c` – Parses and validates the map  
- `move_player.c` – Handles player inputs 
- `draw_map.c` – Displays the game elements  

## 🕹️ Controls  

| Key  | Action |
|------|--------|
| W / ↑ | Move Up |
| A / ← | Move Left |
| S / ↓ | Move Down |
| D / → | Move Right |
| ESC  | Quit Game |

## 🏆 Goal  

1️⃣ Collect all items 🏆  
2️⃣ Reach the exit 🚪  
3️⃣ Avoid enemies! ☠️  

## ⚠️ Notes  

- The map must be **rectangular**, surrounded by walls, and contain at least **one player, one exit, and one collectible**.  
- The game follows **Norminette** coding standards.  

## 🚀 Run the Game  

You can use the **run_game.sh** script to compile and launch the game.  

```bash
chmod +x run_game.sh
./so_long maps/bonus/map.ber
