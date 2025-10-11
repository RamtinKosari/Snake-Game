# ifndef SGCOOP_GAME
    # include "Game.hpp"
    /**
     * @brief Construct a New Game Object
     */
    Game::Game() {
        //-- Initialize Board
        board = Board(
            BOARD_HEIGHT,
            BOARD_WIDTH,
            BOARD_COLOR
        );
        //-- Set Game Tips
        game_tips = {
            "Use Arrow Keys to Move",
            "Press 'Q' or 'Esc' to Quit",
            "each 10 Seconds Will Give You a 15 Score"
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
     * @brief Generate Board
     */
    void Game::generate() {
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
        generateFoods();
        //-- Generate Walls
        if (GENERATE_WALLS) {
            generateWalls();
        }
        //-- Generate Poisons
        if (GENERATE_POISONS) {
            generatePoisons();
        }
    }
    /**
     * @brief Display Game
     */
    void Game::display() {
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
        //-- Reset Food Count
        foodCount = 0;
        //-- Calculate Amount of Foods
        for (int i = 0; i < board.height; i++) {
            for (int j = 0; j < board.width; j++) {
                if (blocks[i][j].type == BLOCK_TYPE_FOOD) {
                    foodCount++;
                }
            }
        }
        //-- Reset Wall Count
        wallCount = 0;
        //-- Calculate Amount of Walls
        for (int i = 0; i < board.height; i++) {
            for (int j = 0; j < board.width; j++) {
                if (blocks[i][j].type == BLOCK_TYPE_WALL) {
                    wallCount++;
                }
            }
        }
        //-- Reset Poison Count
        poisonCount = 0;
        //-- Calculate Amount of Poisons
        for (int i = 0; i < board.height; i++) {
            for (int j = 0; j < board.width; j++) {
                if (blocks[i][j].type == BLOCK_TYPE_POISON) {
                    poisonCount++;
                }
            }
        }
    }
    /**
     * @brief Clear Terminal
     */
    void Game::clearTerminal() {
        std::cout << "\033[2J\033[1;1H";
    }
    /**
     * @brief Generate Foods
     */
    void Game::generateFoods() {
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
        //-- Define Food Counter
        int foodCount = 0;
        //-- Generate Foods According to Amount Limit
        while (foodCount < FOOD_AMOUNT) {
            //-- Define X and Y
            int x, y;
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
            //-- Increment Food Counter
            foodCount++;
        }
    }
    /**
     * @brief Generate Walls
     */
    void Game::generateWalls() {
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
        std::uniform_int_distribution<> dis_x(1 + WALL_PADDING, board.height - 2 - WALL_PADDING);
        std::uniform_int_distribution<> dis_y(1 + WALL_PADDING, board.width - 2 - WALL_PADDING);
        //-- Define Distribution for Direction (0 for horizontal, 1 for vertical)
        std::uniform_int_distribution<> dis_dir(0, 1);
        //-- Define Wall Counter
        int wallCount = 0;
        //-- Generate Walls According to Amount Limit
        while (wallCount < WALL_AMOUNT) {
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
                for (int i = -WALL_PADDING; i < WALL_LENGTH + WALL_PADDING; i++) {
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
            for (int i = 0; i < WALL_LENGTH; i++) {
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
    }
    /**
     * @brief Generate Poissons
     */
    void Game::generatePoisons() {
        //-- Reset Poisons to Air Blocks
        for (int i = 0; i < board.height; i++) {
            for (int j = 0; j < board.width; j++) {
                if (blocks[i][j].type == BLOCK_TYPE_POISON) {
                    blocks[i][j].setType(BLOCK_TYPE_AIR);
                }
            }
        }
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
        //-- Define Poison Counter
        int poisonCount = 0;
        //-- Generate Poisons According to Amount Limit
        while (poisonCount < POISON_AMOUNT) {
            //-- Define X and Y
            int x, y;
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
            //-- Increment Poison Counter
            poisonCount++;
        }
    }
    /**
     * @brief Update Game Board
     */
    void Game::update() {
        //-- Initialize Last Poison Generation Time Variables
        auto LAST_POISON_GENERATION = std::chrono::steady_clock::now();
        //-- Initialize Last Wall Generation Time Variables
        auto LAST_WALL_GENERATION = std::chrono::steady_clock::now();
        //-- Initialize Last FPS Print Generation Time Variables
        auto LAST_FPS_PRINT = std::chrono::steady_clock::now();
        //-- Initialize Start Time
        auto START_TIME = std::chrono::steady_clock::now();
        //-- Initialize Frame Counter
        int frameCount = 0;
        //-- Initialize Frames Per Second
        int manualFPS = 0;
        //-- Initialize Last FPS
        int lastFPS = 0;
        //-- Obtain Current Time
        auto now = std::chrono::steady_clock::now();
        //-- Calculate Elapsed Time Since Start of the Game
        auto elapsedGameTime = std::chrono::duration_cast<std::chrono::seconds>(
            now - START_TIME
        ).count();
        //-- Calculate Time Passed Since Last Wall Generation
        auto elapsedWallTime = std::chrono::duration_cast<std::chrono::seconds>(
            now - LAST_WALL_GENERATION
        ).count();
        //-- Calculate Time Passed Since Last FPS Print
        auto elapsedFpsTime = std::chrono::duration_cast<std::chrono::seconds>(
            now - LAST_FPS_PRINT
        ).count();
        //-- Calculate Time Passed Sinse Last Poison Generation
        auto elapsedPoisonTime = std::chrono::duration_cast<std::chrono::seconds>(
            now - LAST_POISON_GENERATION
        ).count();
        //-- Calculate Elapsed Time Hours
        int e_hours = elapsedGameTime / 3600;
        //-- Calculate Elapsed Time Minutes
        int e_minutes = (elapsedGameTime % 3600) / 60;
        //-- Calculate Elapsed Time Seconds
        int e_seconds = elapsedGameTime % 60;
        //-- Calculate Time Left Hours
        int hours = (GAME_TIME - elapsedGameTime) / 3600;
        //-- Calculate Time Left Minutes
        int minutes = ((GAME_TIME - elapsedGameTime) % 3600) / 60;
        //-- Calculate Time Left Seconds
        int seconds = (GAME_TIME - elapsedGameTime) % 60;
        //-- Game Loop
        while (true) {
            //-- Obtain Current Time
            now = std::chrono::steady_clock::now();
            //-- Calculate Elapsed Time Since Start of the Game
            elapsedGameTime = std::chrono::duration_cast<std::chrono::seconds>(
                now - START_TIME
            ).count();
            //-- Calculate Time Passed Since Last Wall Generation
            elapsedWallTime = std::chrono::duration_cast<std::chrono::seconds>(
                now - LAST_WALL_GENERATION
            ).count();
            //-- Calculate Time Passed Since Last FPS Print
            elapsedFpsTime = std::chrono::duration_cast<std::chrono::seconds>(
                now - LAST_FPS_PRINT
            ).count();
            //-- Calculate Time Passed Sinse Last Poison Generation
            elapsedPoisonTime = std::chrono::duration_cast<std::chrono::seconds>(
                now - LAST_POISON_GENERATION
            ).count();
            //-- Generate Walls During Game each GENERATE_WALLS_EACH Seconds
            if (GENERATE_WALLS_DURING_GAME && GENERATE_WALLS && elapsedWallTime >= GENERATE_WALLS_EACH) {
                //-- Generate Walls
                generateWalls();
                //-- Reset the Wall Generation Timer
                LAST_WALL_GENERATION = now;
            }
            //-- Generate Poisons During Game each GENERATE_POISONS_EACH Seconds
            if (GENERATE_POISONS_DURING_GAME && GENERATE_POISONS && elapsedPoisonTime >= GENERATE_POISONS_EACH) {
                //-- Generate Poisons
                generatePoisons();
                //-- Reset the Poison Generation Timer
                LAST_POISON_GENERATION = now;
            }
            //-- Print FPS Every Second
            if (elapsedFpsTime >= 1) {
                //-- Reset the FPS Print Timer
                LAST_FPS_PRINT = now;
                //-- Set Last FPS
                lastFPS = manualFPS;
                //-- Reset Manual FPS
                manualFPS = 0;
                //-- Add Score Every 10 Seconds
            }
            //-- Clear game_info
            game_info.clear();
            //-- Set Game Info : Game Info
            game_info.push_back("Game Info");
            //-- Calculate Elapsed Time Hours
            e_hours = elapsedGameTime / 3600;
            //-- Calculate Elapsed Time Minutes
            e_minutes = (elapsedGameTime % 3600) / 60;
            //-- Calculate Elapsed Time Seconds
            e_seconds = elapsedGameTime % 60;
            //-- Set Game Info : Ellapsed Time Since Start of the Game
            game_info.push_back("Elapsed Time : " + std::to_string(e_hours) + "h " + std::to_string(e_minutes) + "m " + std::to_string(e_seconds) + "s");
            //-- Calculate Time Left Hours
            hours = (GAME_TIME - elapsedGameTime) / 3600;
            //-- Calculate Time Left Minutes
            minutes = ((GAME_TIME - elapsedGameTime) % 3600) / 60;
            //-- Calculate Time Left Seconds
            seconds = (GAME_TIME - elapsedGameTime) % 60;
            //-- Set Game Info : Time Left
            game_info.push_back("Time Left : " + std::to_string(hours) + "h " + std::to_string(minutes) + "m " + std::to_string(seconds) + "s");
            //-- Set Game Info : Score
            game_info.push_back("Score : " + std::to_string(score));
            //-- Set Game Info : Coins
            game_info.push_back("Coins : 0");
            //-- Set Game Info : FPS
            game_info.push_back("FPS : " + std::to_string(lastFPS));
            //-- Set Game Info : White Space
            game_info.push_back("    ");
            //-- Set Game Info : Food Info
            game_info.push_back("Food Info");
            //-- Set Game Info : Food Amount
            game_info.push_back("Amount of Food : " + std::to_string(foodCount));
            //-- Set Game Info : Poisons Amount
            if (GENERATE_POISONS) {
                game_info.push_back("Amount of Poisons : " + std::to_string(poisonCount));
                //-- Set Game Info : Tile Until Next Poison Generation
                if (GENERATE_POISONS_DURING_GAME) {
                    game_info.push_back("Next Poisons : " + std::to_string(GENERATE_POISONS_EACH - elapsedPoisonTime) + "s");
                }
            }
            //-- Set Game Info : Walls Info
            if (GENERATE_WALLS) {
                //-- Print White Space
                game_info.push_back("    ");
                //-- Set Game Info : Walls Info
                game_info.push_back("Walls Info");
                //-- Set Game Info : Walls Amount
                game_info.push_back("Amount of Walls : " + std::to_string(WALL_AMOUNT));
                //-- Set Game Info : Tile Until Next Wall Generation
                if (GENERATE_WALLS_DURING_GAME) {
                    game_info.push_back("Next Walls : " + std::to_string(GENERATE_WALLS_EACH - elapsedWallTime) + "s");
                }
            }
            //-- Set Game Info : White Space
            game_info.push_back("    ");
            //-- Set Game Info : Tips
            game_info.push_back("Tips");
            //-- Show Game Tips
            for (int i = 0; i < game_tips.size(); i++) {
                game_info.push_back(game_tips[i]);
            }
            //-- Delay
            std::this_thread::sleep_for(std::chrono::milliseconds(GAME_DELAY));
            //-- Clear Terminal
            // clearTerminal();
            //-- Display Game
            display();
            //-- Increment Frame Count
            frameCount++;
            //-- Increment Manual FPS
            manualFPS++;
            //-- Reset Frame Counter every 10000 Frames
            if (frameCount == 10000) {
                frameCount = 0;
            }
            //-- Handle if Game Time is Over
            if (elapsedGameTime >= GAME_TIME) {
                //-- Set Game Info : White Space
                game_info.push_back("    ");
                //-- Set Game Info : Game Over
                game_info.push_back("Game Over");
                //-- Set Game Info : Time is Over
                game_info.push_back("Time is Over");
                //-- Clear Terminal
                // clearTerminal();
                //-- Display Game
                display();
                //-- Exit the Game
                exit(0);
            }
        }
    }
# endif // SGCOOP_GAME