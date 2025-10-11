# ifndef SGCOOP_BLOCKS
    # include "Blocks.hpp"
    void Block::setType(BLOCK_TYPES t) {
        //-- Set Type
        type = t;
        //-- Set Block Properties According to Type
        switch (type) {
            //-- Set Air Block Properties
            case BLOCK_TYPE_AIR: {
                //-- Set Color
                color = BOARD_COLOR;
                //-- Set Character
                character = BOARD_CHARACTER;
                //-- Set Visual Representation
                setVisual();
                break;
            }
            //-- Set Border Block Properties
            case BLOCK_TYPE_BORDER: {
                //-- Set Color
                color = BORDER_COLOR;
                //-- Set Character
                character = BORDER_CHARACTER;
                //-- Set Visual Representation
                setVisual();
                break;
            }
            //-- Set Food Block Properties
            case BLOCK_TYPE_FOOD: {
                //-- Set Color
                color = FOOD_COLOR;
                //-- Set Character
                character = FOOD_CHARACTER;
                //-- Set Visual Representation
                setVisual(false);
                break;
            }
            //-- Set Wall Block Properties
            case BLOCK_TYPE_WALL: {
                //-- Set Color
                color = WALL_COLOR;
                //-- Set Character
                character = WALL_CHARACTER;
                //-- Set Visual Representation
                setVisual();
                break;
            }
            //-- Set Poison Block Properties
            case BLOCK_TYPE_POISON: {
                //-- Set Color
                color = POISON_COLOR;
                //-- Set Character
                character = POISON_CHARACTER;
                //-- Set Visual Representation
                setVisual(false);
                break;
            }
            //-- Set Speed Up Block Properties
            case BLOCK_TYPE_SPEED_UP: {
                //-- Set Color
                color = SPEED_UP_COLOR;
                //-- Set Character
                character = SPEED_UP_CHARACTER;
                //-- Set Visual Representation
                setVisual(false);
                break;
            }
            default:
                break;
        }
    }
    void Block::setVisual(bool background) {
        //-- Set Visual Representation According to Background
        if (background) {
            visual = "\033[48;2;" + std::to_string(color.red) + ";" + std::to_string(color.green) + ";" + std::to_string(color.blue) + "m" + character + "\033[0m";
        } else {
            visual = "\033[38;2;" + std::to_string(color.red) + ";" + std::to_string(color.green) + ";" + std::to_string(color.blue) + "m" + character + "\033[0m";
        }
    }
# endif // SGCOOP_BLOCKS