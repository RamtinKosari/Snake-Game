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
            generateBlocks(BLOCK_TYPE_WALL);
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
                    foodCount++;
                }
                break;
            }
            //-- Set Wall Block Properties
            case BLOCK_TYPE_WALL: {
                //-- Reset Walls to Air Blocks
                for (int i = 0; i < board.height; i++) {
                    for (int j = 0; j < board.width; j++) {
                        if (blocks[i][j].type == BLOCK_TYPE_WALL) {
                            blocks[i][j].setType(BLOCK_TYPE_AIR);
                        }
                    }
                }
                //-- Obtain a Random Number from Hardware
                std::random_device rd;
                //-- Seed the Generator
                std::mt19937 gen(rd());
                //-- Define Distribution for X and Y
                std::uniform_int_distribution<> dis_x(1 + RK_GAME_SNAKE_CNF_WALL_PADDING, board.height - 2 - RK_GAME_SNAKE_CNF_WALL_PADDING);
                std::uniform_int_distribution<> dis_y(1 + RK_GAME_SNAKE_CNF_WALL_PADDING, board.width - 2 - RK_GAME_SNAKE_CNF_WALL_PADDING);
                //-- Define Distribution for Direction (0 for horizontal, 1 for vertical)
                std::uniform_int_distribution<> dis_dir(0, 1);
                //-- Generate Walls According to Amount Limit
                while (wallCount < RK_GAME_SNAKE_CNF_WALLS_AMOUNT) {
                    //-- Define X and Y
                    int x, y, dir;
                    //-- Define Valid Position
                    bool validPosition = true;
                    //-- Generate Random Starting Position and Ensure It's Free
                    do {
                        //-- Generate Random X and Y
                        x = dis_x(gen);
                        y = dis_y(gen);
                        // - Randomly Choose Direction (0 = Horizontal, 1 = Vertical)
                        dir = dis_dir(gen);
                        //-- Reset Valid Position
                        validPosition = true;
                        //-- Check if the Selected Position and the Entire wall in that Direction is Free
                        for (int i = -RK_GAME_SNAKE_CNF_WALL_PADDING; i < RK_GAME_SNAKE_CNF_WALL_LENGTH + RK_GAME_SNAKE_CNF_WALL_PADDING; i++) {
                            //-- Handle Direction
                            if (dir == 0) {
                                //-- Horizontal Wall
                                if (y + i < 1 || y + i >= board.width - 1 || blocks[x][y + i].type != BLOCK_TYPE_AIR) {
                                    validPosition = false;
                                    break;
                                }
                            } else {
                                //-- Vertical Wall
                                if (x + i < 1 || x + i >= board.height - 1 || blocks[x + i][y].type != BLOCK_TYPE_AIR) {
                                    validPosition = false;
                                    break;
                                }
                            }
                        }
                    } while (!validPosition);
                    //-- Place the wall
                    for (int i = 0; i < RK_GAME_SNAKE_CNF_WALL_LENGTH; i++) {
                        //-- Handle Direction
                        if (dir == 0) {
                            //-- Horizontal Wall
                            blocks[x][y + i].setType(BLOCK_TYPE_WALL);
                        } else {
                            //-- Vertical Wall
                            blocks[x + i][y].setType(BLOCK_TYPE_WALL);
                        }
                    }
                    //-- Increment Wall Counter
                    wallCount++;
                }
                break;
            }
            //-- Set Poison Block Properties
            case BLOCK_TYPE_POISON: {
                //-- Resize Poisons - Rows
                poisons.resize(board.height);
                //-- Resize Poisons - Columns
                for (int i = 0; i < board.height; i++) {
                    poisons[i].resize(board.width);
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
                //-- Generate Poisons According to Amount Limit
                while (poisonCount < RK_GAME_SNAKE_CNF_POISON_AMOUNT) {
                    //-- Generate Random Position and Ensure to Not Overlap and Not on Border
                    do {
                        //-- Generate Random X
                        x = dis_x(gen);
                        //-- Generate Random Y
                        y = dis_y(gen);
                    } while (
                        blocks[x][y].type != BLOCK_TYPE_AIR
                    ); //-- Ensure the Position is Free
                    //-- Add Poison
                    poisons[x][y] = Block(x, y);
                    //-- Set Poison Block Type
                    poisons[x][y].setType(BLOCK_TYPE_POISON);
                    //-- Set Block Type to Poison
                    blocks[x][y].setType(BLOCK_TYPE_POISON);
                    //-- Increase Counter
                    poisonCount++;
                }
                break;
            }
            //-- Set Speed Up Block Properties
            case BLOCK_TYPE_SPEED_UP: {
                //-- Resize Speed Ups - Rows
                speed_ups.resize(board.height);
                //-- Resize Speed Ups - Columns
                for (int i = 0; i < board.height; i++) {
                    speed_ups[i].resize(board.width);
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
                //-- Generate Speed Ups According to Amount Limit
                while (speedUpCount < RK_GAME_SNAKE_CNF_SPEED_UP_AMOUNT) {
                    //-- Generate Random Position and Ensure to Not Overlap and Not on Border
                    do {
                        //-- Generate Random X
                        x = dis_x(gen);
                        //-- Generate Random Y
                        y = dis_y(gen);
                    } while (
                        blocks[x][y].type != BLOCK_TYPE_AIR
                    ); //-- Ensure the Position is Free
                    //-- Add Speed Up
                    speed_ups[x][y] = Block(x, y);
                    //-- Set Speed Up Block Type
                    speed_ups[x][y].setType(BLOCK_TYPE_SPEED_UP);
                    //-- Set Block Type to Speed Up
                    blocks[x][y].setType(BLOCK_TYPE_SPEED_UP);
                    //-- Increase Counter
                    speedUpCount++;
                }
                break;
            }
            //-- Set Slow Down Block Properties
            case BLOCK_TYPE_SLOW_DOWN: {
                //-- Resize Slow Down - Rows
                slow_downs.resize(board.height);
                //-- Resize Slow Down - Columns
                for (int i = 0; i < board.height; i++) {
                    slow_downs[i].resize(board.width);
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
                //-- Generate Slow Down According to Amount Limit
                while (slowDownCount < RK_GAME_SNAKE_CNF_SLOW_DOWN_AMOUNT) {
                    //-- Generate Random Position and Ensure to Not Overlap and Not on Border
                    do {
                        //-- Generate Random X
                        x = dis_x(gen);
                        //-- Generate Random Y
                        y = dis_y(gen);
                    } while (
                        blocks[x][y].type != BLOCK_TYPE_AIR
                    ); //-- Ensure the Position is Free
                    //-- Add Slow Down
                    slow_downs[x][y] = Block(x, y);
                    //-- Set Slow Down Block Type
                    slow_downs[x][y].setType(BLOCK_TYPE_SLOW_DOWN);
                    //-- Set Block Type to Slow Down
                    blocks[x][y].setType(BLOCK_TYPE_SLOW_DOWN);
                    //-- Increase Counter
                    slowDownCount++;
                }
                break;
            }
            //-- Set Portal Block Properties
            case BLOCK_TYPE_PORTAL: {
                //-- Resize Portal - Rows
                portals.resize(board.height);
                //-- Resize Portal - Columns
                for (int i = 0; i < board.height; i++) {
                    portals[i].resize(board.width);
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
                //-- Generate Portals According to Amount Limit
                while (portalCount < RK_GAME_SNAKE_CNF_PORTAL_AMOUNT) {
                    //-- Generate Random Position and Ensure to Not Overlap and Not on Border
                    do {
                        //-- Generate Random X
                        x = dis_x(gen);
                        //-- Generate Random Y
                        y = dis_y(gen);
                    } while (
                        blocks[x][y].type != BLOCK_TYPE_AIR
                    ); //-- Ensure the Position is Free
                    //-- Add Portal
                    portals[x][y] = Block(x, y);
                    //-- Set Portal Block Type
                    portals[x][y].setType(BLOCK_TYPE_PORTAL);
                    //-- Set Block Type to Portal
                    blocks[x][y].setType(BLOCK_TYPE_PORTAL);
                    //-- Increase Counter
                    portalCount++;
                }
                break;
            }
            //-- Set Shield Block Properties
            case BLOCK_TYPE_SHIELD: {
                //-- Resize Shield - Rows
                shields.resize(board.height);
                //-- Resize Shield - Columns
                for (int i = 0; i < board.height; i++) {
                    shields[i].resize(board.width);
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
                //-- Generate Shields According to Amount Limit
                while (shieldCount < RK_GAME_SNAKE_CNF_SHIELD_AMOUNT) {
                    //-- Generate Random Position and Ensure to Not Overlap and Not on Border
                    do {
                        //-- Generate Random X
                        x = dis_x(gen);
                        //-- Generate Random Y
                        y = dis_y(gen);
                    } while (
                        blocks[x][y].type != BLOCK_TYPE_AIR
                    ); //-- Ensure the Position is Free
                    //-- Add Shield
                    shields[x][y] = Block(x, y);
                    //-- Set Shield Type
                    shields[x][y].setType(BLOCK_TYPE_SHIELD);
                    //-- Set Block Type to Shield
                    blocks[x][y].setType(BLOCK_TYPE_SHIELD);
                    //-- Increase Counter
                    shieldCount++;
                }
                break;
            }
            //-- Set Coin Block Properties
            case BLOCK_TYPE_COIN: {
                //-- Resize Coins - Rows
                coins.resize(board.height);
                //-- Resize Coins - Columns
                for (int i = 0; i < board.height; i++) {
                    coins[i].resize(board.width);
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
                //-- Generate Coins According to Amount Limit
                while (coinCount < RK_GAME_SNAKE_CNF_COIN_AMOUNT) {
                    //-- Generate Random Position and Ensure to Not Overlap and Not on Border
                    do {
                        //-- Generate Random X
                        x = dis_x(gen);
                        //-- Generate Random Y
                        y = dis_y(gen);
                    } while (
                        blocks[x][y].type != BLOCK_TYPE_AIR
                    ); //-- Ensure the Position is Free
                    //-- Add Coin
                    coins[x][y] = Block(x, y);
                    //-- Set Coin Type
                    coins[x][y].setType(BLOCK_TYPE_COIN);
                    //-- Set Block Type to Coin
                    blocks[x][y].setType(BLOCK_TYPE_COIN);
                    //-- Increase Counter
                    coinCount++;
                }
                break;
            }
            default:
                break;
        }
    }
# endif // RK_GAMES_SNAKE