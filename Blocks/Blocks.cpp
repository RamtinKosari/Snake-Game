# ifndef RK_GAMES_SNAKE_BLOCKS
    # include "Blocks.hpp"
    /**
     * @brief Set Type of the Block
     * @param t 
     */
    void rkgames::snake::Block::setType(BLOCK_TYPES t) {
        //-- Set Type
        type = t;
        //-- Set Block Properties According to Type
        switch (type) {
            //-- Set Air Block Properties
            case BLOCK_TYPE_AIR: {
                //-- Set Color
                color = RK_GAME_SNAKE_CNF_BOARD_COLOR;
                //-- Set Character
                character = RK_GAME_SNAKE_CNF_BOARD_CHARACTER;
                //-- Set Visual Representation
                setVisual();
                break;
            }
            //-- Set Border Block Properties
            case BLOCK_TYPE_BORDER: {
                //-- Set Color
                color = RK_GAME_SNAKE_CNF_BORDER_COLOR;
                //-- Set Character
                character = RK_GAME_SNAKE_CNF_BORDER_CHARACTER;
                //-- Set Visual Representation
                setVisual();
                break;
            }
            //-- Set Food Block Properties
            case BLOCK_TYPE_FOOD: {
                //-- Set Color
                color = RK_GAME_SNAKE_CNF_FOOD_COLOR;
                //-- Set Character
                character = RK_GAME_SNAKE_CNF_FOOD_CHARACTER;
                //-- Set Visual Representation
                setVisual(false);
                break;
            }
            //-- Set Wall Block Properties
            case BLOCK_TYPE_WALL: {
                //-- Set Color
                color = RK_GAME_SNAKE_CNF_WALL_COLOR;
                //-- Set Character
                character = RK_GAME_SNAKE_CNF_WALL_CHARACTER;
                //-- Set Visual Representation
                setVisual();
                break;
            }
            //-- Set Poison Block Properties
            case BLOCK_TYPE_POISON: {
                //-- Set Color
                color = RK_GAME_SNAKE_CNF_POISON_COLOR;
                //-- Set Character
                character = RK_GAME_SNAKE_CNF_POISON_CHARACTER;
                //-- Set Visual Representation
                setVisual(false);
                break;
            }
            //-- Set Speed Up Block Properties
            case BLOCK_TYPE_SPEED_UP: {
                //-- Set Color
                color = RK_GAME_SNAKE_CNF_SPEED_UP_COLOR;
                //-- Set Character
                character = RK_GAME_SNAKE_CNF_SPEED_UP_CHARACTER;
                //-- Set Visual Representation
                setVisual(false);
                break;
            }
            //-- Set Slow Down Block Properties
            case BLOCK_TYPE_SLOW_DOWN: {
                //-- Set Color
                color = RK_GAME_SNAKE_CNF_SPEED_UP_COLOR;
                //-- Set Character
                character = RK_GAME_SNAKE_CNF_SPEED_UP_CHARACTER;
                //-- Set Visual Representation
                setVisual(false);
                break;
            }
            //-- Set Portal Block Properties
            case BLOCK_TYPE_PORTAL: {
                //-- Set Color
                color = RK_GAME_SNAKE_CNF_PORTAL_COLOR;
                //-- Set Character
                character = RK_GAME_SNAKE_CNF_PORTAL_CHARACTER;
                //-- Set Visual Representation
                setVisual(false);
                break;
            }
            //-- Set Shield Block Properties
            case BLOCK_TYPE_SHIELD: {
                //-- Set Color
                color = RK_GAME_SNAKE_CNF_SHIELD_COLOR;
                //-- Set Character
                character = RK_GAME_SNAKE_CNF_SHIELD_CHARACTER;
                //-- Set Visual Representation
                setVisual(false);
                break;
            }
            //-- Set Coin Block Properties
            case BLOCK_TYPE_COIN: {
                //-- Set Color
                color = RK_GAME_SNAKE_CNF_COIN_COLOR;
                //-- Set Character
                character = RK_GAME_SNAKE_CNF_COIN_CHARACTER;
                //-- Set Visual Representation
                setVisual(false);
                break;
            }
            default:
                break;
        }
    }
    /**
     * @brief Set Visual Representation of the Block
     * @param background 
     */
    void rkgames::snake::Block::setVisual(bool background) {
        //-- Set Visual Representation According to Background
        if (background) {
            visual = "\033[48;2;" + std::to_string(color.red) + ";" + std::to_string(color.green) + ";" + std::to_string(color.blue) + "m" + character + "\033[0m";
        } else {
            visual = "\033[48;2;" + std::to_string(RK_GAME_SNAKE_CNF_BOARD_COLOR.red) + ";" + std::to_string(RK_GAME_SNAKE_CNF_BOARD_COLOR.green) + ";" + std::to_string(RK_GAME_SNAKE_CNF_BOARD_COLOR.blue) + "m";
            visual += "\033[38;2;" + std::to_string(color.red) + ";" + std::to_string(color.green) + ";" + std::to_string(color.blue) + "m" + character + "\033[0m";
        }
    }
# endif // RK_GAMES_SNAKE_BLOCKS