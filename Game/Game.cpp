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
        // generate();
        // //-- Display Game
        // display();
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
            w,
            h,
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
        // //-- Generate Board
        // generate();
        // //-- Display Game
        // display();

    }
    /**
     * @brief Destroy the rkgames::snake::Game::Game Object
     * 
     */
    rkgames::snake::Game::~Game() {}
    /**
     * @brief Clear Terminal
     */
    void rkgames::snake::Game::clearTerminal() {
        std::cout << "\033[2J\033[1;1H";
    }

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
# endif // RK_GAMES_SNAKE