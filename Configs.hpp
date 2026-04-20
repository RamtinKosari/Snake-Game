# ifndef RK_GAMES_SNAKE_CONFIGS
    /**
     * @file main.cpp
     * @author Arash Rahmani (github.com/arashrahmani)
     * @author Ramtin Kosari (github.com/ramtinkosari)
     * @brief Snake Game Implementation in C++ Using Object-Oriented Programming - Configurations Header File
     * @version 1.1
     * @date 2026-04-20
     */
    # define RK_GAMES_SNAKE_CONFIGS
    //-- Include IOStream Library
    # ifndef _GLIBCXX_IOSTREAM
        # include <iostream>
    # endif // _GLIBCXX_IOSTREAM
    //-- Include Vector Library
    # ifndef _GLIBCXX_VECTOR
        # include <vector>
    # endif // _GLIBCXX_VECTOR
    //-- Include String Library
    # ifndef _GLIBCXX_STRING
        # include <string>
    # endif // _GLIBCXX_STRING
    //-- Include Random Library
    # ifndef _GLIBCXX_RANDOM
        # include <random>
    # endif // _GLIBCXX_RANDOM
    //-- Include Chrono Library
    # ifndef _GLIBCXX_CHRONO
        # include <chrono>
    # endif // _GLIBCXX_CHRONO
    //-- Include Thread Library
    # ifndef _GLIBCXX_THREAD
        # include <thread>
    # endif // _GLIBCXX_THREAD
    /**
     * @brief Define Color Class
     * @class Color
     */
    class RKColor {
        public:
            /**
             * @brief Red Color
             */
            int red;
            /**
             * @brief Green Color
             */
            int green;
            /**
             * @brief Blue Color
             */
            int blue;
            /**
             * @brief Construct a New Color Object
             */
            RKColor() {
                red = 0;
                green = 0;
                blue = 0;
            }
            /**
             * @brief Construct a New Color Object
             * @param r Red Color
             * @param g Green Color
             * @param b Blue Color
             */
            RKColor(int r, int g, int b) {
                red = r;
                green = g;
                blue = b;
            }
    };
    //---------------------------//
    //--| Board Configuration |--//
    //---------------------------//
    /**
     * @def RK_GAME_SNAKE_CNF_WHITE_SPACE
     * @brief Define Whitespace
     * @note Use Odd Number of Spaces for Character to be Centered
     */
    # define RK_GAME_SNAKE_CNF_WHITE_SPACE "  "
    // ፨ ⁜ ⁖ ⁕ ⁘ ⁙ ⁚ ⁛ ⁜ ⁝ ⁞ ⁐  ⃟   ⃝   ⃞   ⃠ ⊞⊡⊠⊕⊗⊘⋰⋱⋮ ⌾ ⌺ ⎔ ⎕ ╋ █ ░▒▓▩▣◈◌◎●◆◔ ◴ ☕ ☢ ☣☠⛃⛁⛂⛀✧✚ ⥀⥁⸎🌀 ҉ ◌◯☯⚝⚛ 
    /**
     * @def RK_GAME_SNAKE_CNF_BOARD_WIDTH
     * @brief Board Width
     * @details Default Value is 38 Blocks
     */
    # define RK_GAME_SNAKE_CNF_BOARD_WIDTH 38
    /**
     * @def RK_GAME_SNAKE_CNF_BOARD_HEIGHT
     * @brief Board Height
     * @details Default Value is 37 Blocks
     */
    # define RK_GAME_SNAKE_CNF_BOARD_HEIGHT 37
    /**
     * @def RK_GAME_SNAKE_CNF_BOARD_COLOR
     * @brief Board Background Color (RGB)
     */
    # define RK_GAME_SNAKE_CNF_BOARD_COLOR RKColor(0, 7, 15)
    /**
     * @def RK_GAME_SNAKE_CNF_BOARD_CHARACTER
     * @brief Board Character
     */
    # define RK_GAME_SNAKE_CNF_BOARD_CHARACTER RK_GAME_SNAKE_CNF_WHITE_SPACE
# endif // RK_GAMES_SNAKE_CONFIGS