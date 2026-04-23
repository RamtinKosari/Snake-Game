# ifndef RK_GAMES_SNAKE
    # include "Game.hpp"
    /**
     * @brief Construct a New rkgames::snake::Game::Game Object
     * 
     */
    rkgames::snake::Game::Game() {
        //-- Initialize Board
        board = Board(
            RK_GAME_SNAKE_CNF_BOARD_HEIGHT,
            RK_GAME_SNAKE_CNF_BOARD_WIDTH,
            RK_GAME_SNAKE_CNF_BOARD_COLOR
        );
        //-- Set Game Tips
        game_tips = {
            "Use Arrow Keys to Move",
            "Press 'Q' or 'Esc' to Quit"
        };
        //-- Set Score
        score = 0;
        //-- Clear Terminal
        clearTerminal();
        //-- Generate Board
        generate();
        //-- Display Game
        display();
    }
    /**
     * @brief Construct a New rkgames::snake::Game::Game Object
     * @param w Width of the Board
     * @param h Height of the Board
     */
    rkgames::snake::Game::Game(
        int &   w,
        int &   h
    ) {
        //-- Check if Width and Height are Valid
        if (w < 4) {
            clearTerminal();
            logger(LABEL, FAILURE "Width Must be Greater than 4");
            exit(0);
        }
        if (h < 4) {
            clearTerminal();
            logger(LABEL, FAILURE "Height Must be Greater than 4");
            exit(0);
        }
        //-- Initialize Board
        board = Board(
            h,
            w,
            RK_GAME_SNAKE_CNF_BOARD_COLOR
        );
        //-- Set Game Tips
        game_tips = {
            "Use Arrow Keys to Move",
            "Press 'Q' or 'Esc' to Quit"
        };
        //-- Set Score
        score = 0;
        //-- Clear Terminal
        clearTerminal();
        //-- Generate Board
        generate();
        //-- Display Game
        display();
    }
    /**
     * @brief Destroy the rkgames::snake::Game::Game Object
     */
    rkgames::snake::Game::~Game() {}
    /**
     * @brief Clear Terminal
     */
    void rkgames::snake::Game::clearTerminal() {
        std::cout << "\033[2J\033[1;1H";
    }
    /**
     * @brief Generate Board
     */
    void rkgames::snake::Game::generate() {
        //-- Resize Blocks - Rows
        blocks.resize(board.height);
        //-- Resize Blocks - Columns
        for (int i = 0; i < board.height; i++) {
            blocks[i].resize(board.width);
        }
        //-- Generate Board
        for (int i = 0; i < board.height; i++) {
            for (int j = 0; j < board.width; j++) {
                //-- Add Block
                blocks[i][j] = Block(
                    i,
                    j
                );
                //-- Set Block Type According to Position
                if (i == 0 || i == board.height - 1 || j == 0 || j == board.width - 1) {
                    blocks[i][j].setType(BLOCK_TYPE_BORDER);
                } else {
                    blocks[i][j].setType(BLOCK_TYPE_AIR);
                }
            }
        }
        //-- Generate Foods
        generateBlocks(BLOCK_TYPE_FOOD);
        //-- Generate Walls
        if (RK_GAME_SNAKE_CNF_ENABLE_WALL) {
            generateBlocks(BLOCK_TYPE_FOOD);
        }
        //-- Generate Poison
        if (RK_GAME_SNAKE_CNF_ENABLE_POISON) {
            generateBlocks(BLOCK_TYPE_POISON);
        }
        //-- Generate Speed Up
        if (RK_GAME_SNAKE_CNF_ENABLE_SPEED_UP) {
            generateBlocks(BLOCK_TYPE_SPEED_UP);
        }
        //-- Generate Speed Down
        if (RK_GAME_SNAKE_CNF_ENABLE_SLOW_DOWN) {
            generateBlocks(BLOCK_TYPE_SLOW_DOWN);
        }
        //-- Generate Portal
        if (RK_GAME_SNAKE_CNF_ENABLE_PORTAL) {
            generateBlocks(BLOCK_TYPE_PORTAL);
        }
        //-- Generate Shield
        if (RK_GAME_SNAKE_CNF_ENABLE_SHIELD) {
            generateBlocks(BLOCK_TYPE_SHIELD);
        }
        //-- Generate Coin
        if (RK_GAME_SNAKE_CNF_ENABLE_COIN) {
            generateBlocks(BLOCK_TYPE_COIN);
        }
    }
    /**
     * @brief Display Game
     */
    void rkgames::snake::Game::display() {
        //-- Disable Cursor Blinking
        // std::cout << "\033[?25l";
        //-- Move Cursor to the Top-Left Corner of the Terminal According to Board Height and Clear Lines
        // for (int i = 0; i < board.height + 1; i++) {
        //     // std::cout << "\033[A\033[2K";
        // }
        std::cout << "\033[" << (board.height+1) << "A"; // Move cursor up all at once
        //-- Determine Middle Row Range Start Position
        int middleStart = board.height / 2 - game_info.size() / 2;
        //-- Determine Middle Row Range End Position
        int middleEnd = middleStart + game_info.size();
        //-- Display Board
        for (int i = 0; i < board.height; i++) {
            for (int j = 0; j < board.width; j++) {
                std::cout << blocks[i][j].visual;
            }
            //-- Print Game Info Only for the Middle Rows
            if (i >= middleStart && i < middleEnd) {
                //-- Find the Corresponding Index
                int infoIndex = i - middleStart;
                //-- Append Game Info at the End of the Row According to Sign
                if (game_info[infoIndex].find("Walls Info") != std::string::npos) {
                    std::cout << "   " << CYAN << game_info[infoIndex] << RESET;
                    //-- Set Last Info Color
                    lastInfoColor = CYAN;
                } else if (game_info[infoIndex].find("Game Info") != std::string::npos) {
                    std::cout << "   " << ASTRAL << game_info[infoIndex];
                    //-- Set Last Info Color
                    lastInfoColor = ASTRAL;
                } else if (game_info[infoIndex].find("Food Info") != std::string::npos) {
                    std::cout << "   " << LIGHT_BLUE << game_info[infoIndex];
                    //-- Set Last Info Color
                    lastInfoColor = LIGHT_BLUE;
                } else if (game_info[infoIndex].find("Tips") != std::string::npos) {
                    std::cout << "   " << ORANGE << game_info[infoIndex];
                    //-- Set Last Info Color
                    lastInfoColor = ORANGE;
                } else if (game_info[infoIndex].find("Game Over") != std::string::npos) {
                    std::cout << "   " << RED << game_info[infoIndex];
                    //-- Set Last Info Color
                    lastInfoColor = RED;
                } else if (game_info[infoIndex].find("    ") != std::string::npos) {
                    std::cout << "";
                } else {
                    std::cout << "   " << lastInfoColor << "-" << RESET << game_info[infoIndex];
                }
            }
            std::cout << std::endl;
        }
    }
    /**
     * @brief Generate Blocks
     */
    void rkgames::snake::Game::generateBlocks(
        BLOCK_TYPES type
    ) {
        //-- Set Block Properties According to Type
        switch (type) {
            //-- Set Food Block Properties
            case BLOCK_TYPE_FOOD: {
                //-- Resize Foods - Rows
                foods.resize(board.height);
                //-- Resize Foods - Columns
                for (int i = 0; i < board.height; i++) {
                    foods[i].resize(board.width);
                }
                //-- Obtain a Random Number from Hardware
                std::random_device rd;
                //-- Seed the Generator
                std::mt19937 gen(rd());
                //-- Define Distribution for X
                std::uniform_int_distribution<> dis_x(1, board.height - 2);
                //-- Define Distribution for Y
                std::uniform_int_distribution<> dis_y(1, board.width - 2);
                //-- Define X and Y
                int x = 0, y = 0;
                //-- Generate Foods According to Amount Limit
                while (foodCount < RK_GAME_SNAKE_CNF_FOOD_AMOUNT) {
                    //-- Generate Random Position and Ensure to Not Overlap and Not on Border
                    do {
                        //-- Generate Random X
                        x = dis_x(gen);
                        //-- Generate Random Y
                        y = dis_y(gen);
                    } while (
                        blocks[x][y].type != BLOCK_TYPE_AIR
                    ); //-- Ensure the Position is Free
                    //-- Add Food
                    foods[x][y] = Block(x, y);
                    //-- Set Food Block Type
                    foods[x][y].setType(BLOCK_TYPE_FOOD);
                    //-- Set Block Type to Food
                    blocks[x][y].setType(BLOCK_TYPE_FOOD);
                    //-- Increase Counter
                    foodCount += 1;
                }
                break;
            }
            //-- Set Wall Block Properties
            case BLOCK_TYPE_WALL: {
                break;
            }
            //-- Set Poison Block Properties
            case BLOCK_TYPE_POISON: {
                break;
            }
            //-- Set Speed Up Block Properties
            case BLOCK_TYPE_SPEED_UP: {
                break;
            }
            //-- Set Slow Down Block Properties
            case BLOCK_TYPE_SLOW_DOWN: {
                break;
            }
            //-- Set Portal Block Properties
            case BLOCK_TYPE_PORTAL: {
                break;
            }
            //-- Set Shield Block Properties
            case BLOCK_TYPE_SHIELD: {
                break;
            }
            //-- Set Coin Block Properties
            case BLOCK_TYPE_COIN: {
                break;
            }
            default:
                break;
        }
    }
# endif // RK_GAMES_SNAKE