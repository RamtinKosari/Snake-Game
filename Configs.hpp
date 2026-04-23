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
    ///////////////////////////////
    //---------------------------//
    //--| Board Configuration |--//
    //---------------------------//
    ///////////////////////////////
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
    ////////////////////////////////
    //----------------------------//
    //--| Border Configuration |--//
    //----------------------------//
    ////////////////////////////////
    /**
     * @def RK_GAME_SNAKE_CNF_BORDER_COLOR
     * @brief Border Color (RGB)
     */
    # define RK_GAME_SNAKE_CNF_BORDER_COLOR RKColor(0, 20, 40)
    /**
     * @def RK_GAME_SNAKE_CNF_BORDER_CHARACTER
     * @brief Border Character
     */
    # define RK_GAME_SNAKE_CNF_BORDER_CHARACTER RK_GAME_SNAKE_CNF_WHITE_SPACE
    //////////////////////////////
    //--------------------------//
    //--| Food Configuration |--//
    //--------------------------//
    //////////////////////////////
    /**
     * @def RK_GAME_SNAKE_CNF_FOOD_COLOR
     * @brief Food Color (RGB)
     */
    # define RK_GAME_SNAKE_CNF_FOOD_COLOR RKColor(0, 200, 100)
    /**
     * @def RK_GAME_SNAKE_CNF_FOOD_CHARACTER
     * @brief Food Character
     */
    # define RK_GAME_SNAKE_CNF_FOOD_CHARACTER "◎ "
    /**
     * @def RK_GAME_SNAKE_CNF_FOOD_AMOUNT
     * @brief Default Food Amount to be Generated
     */
    # define RK_GAME_SNAKE_CNF_FOOD_AMOUNT 3
    //◆ ☉ ◎ ● ■ ▲ ⬤ ❖ 🌀 ■
    //////////////////////////////
    //--------------------------//
    //--| Wall Configuration |--//
    //--------------------------//
    //////////////////////////////
    /**
     * @def RK_GAME_SNAKE_CNF_ENABLE_WALL
     * @brief Enable Wall Generation
     */
    # define RK_GAME_SNAKE_CNF_ENABLE_WALL false
    /**
     * @def RK_GAME_SNAKE_CNF_WALL_COLOR
     * @brief Wall Color (RGB)
     */
    # define RK_GAME_SNAKE_CNF_WALL_COLOR RKColor(0, 40, 80)
    /**
     * @def RK_GAME_SNAKE_CNF_WALL_CHARACTER
     * @brief Wall Character
     */
    # define RK_GAME_SNAKE_CNF_WALL_CHARACTER RK_GAME_SNAKE_CNF_WHITE_SPACE
    /**
     * @def RK_GAME_SNAKE_CNF_WALLS_AMOUNT
     * @brief Default WALLS Amount to be Generated
     */
    # define RK_GAME_SNAKE_CNF_WALLS_AMOUNT 3
    ////////////////////////////////
    //----------------------------//
    //--| Poison Configuration |--//
    //----------------------------//
    ////////////////////////////////
    /**
     * @def RK_GAME_SNAKE_CNF_ENABLE_POISON
     * @brief Enable Poison Generation
     */
    # define RK_GAME_SNAKE_CNF_ENABLE_POISON false
    /**
     * @brief Poison Color (RGB)
     */
    # define RK_GAME_SNAKE_CNF_POISON_COLOR RKColor(255, 120, 0)
    /**
     * @def RK_GAME_SNAKE_CNF_POISON_CHARACTER
     * @brief Poison Character
     */
    # define RK_GAME_SNAKE_CNF_POISON_CHARACTER "☠ "
    /**
     * @def RK_GAME_SNAKE_CNF_POISON_AMOUNT
     * @brief Default Poison Amount to be Generated
     */
    # define RK_GAME_SNAKE_CNF_POISON_AMOUNT 3
    //////////////////////////////////
    //------------------------------//
    //--| Speed Up Configuration |--//
    //------------------------------//
    //////////////////////////////////
    /**
     * @def RK_GAME_SNAKE_CNF_ENABLE_SPEED_UP
     * @brief Enable Speed Up Generation
     */
    # define RK_GAME_SNAKE_CNF_ENABLE_SPEED_UP false
    /**
     * @def RK_GAME_SNAKE_CNF_SPEED_UP_COLOR
     * @brief Speed Up Color (RGB)
     */
    # define RK_GAME_SNAKE_CNF_SPEED_UP_COLOR RKColor(255, 255, 0)
    /**
     * @def RK_GAME_SNAKE_CNF_SPEED_UP_CHARACTER
     * @brief Speed Up Character
     */
    # define RK_GAME_SNAKE_CNF_SPEED_UP_CHARACTER "⊕ "
    /**
     * @def RK_GAME_SNAKE_CNF_SPEED_UP_AMOUNT
     * @brief Default Speed Up Amount to be Generated
     */
    # define RK_GAME_SNAKE_CNF_SPEED_UP_AMOUNT 3
    ///////////////////////////////////
    //-------------------------------//
    //--| Slow Down Configuration |--//
    //-------------------------------//
    ///////////////////////////////////
    /**
     * @def RK_GAME_SNAKE_CNF_ENABLE_SPEED_DOWN
     * @brief Enable Speed Down Generation
     */
    # define RK_GAME_SNAKE_CNF_ENABLE_SLOW_DOWN false
    /**
     * @def RK_GAME_SNAKE_CNF_SLOW_DOWN_COLOR
     * @brief Slow Down Color (RGB)
     */
    # define RK_GAME_SNAKE_CNF_SLOW_DOWN_COLOR RKColor(255, 255, 0)
    /**
     * @def RK_GAME_SNAKE_CNF_SLOW_DOWN_CHARACTER
     * @brief Slow Down Character
     */
    # define RK_GAME_SNAKE_CNF_SLOW_DOWN_CHARACTER "⊕ "
    /**
     * @def RK_GAME_SNAKE_CNF_SPEED_DOWN_AMOUNT
     * @brief Default Speed Down Amount to be Generated
     */
    # define RK_GAME_SNAKE_CNF_SPEED_DOWN_AMOUNT 3
    ////////////////////////////////
    //----------------------------//
    //--| Portal Configuration |--//
    //----------------------------//
    ////////////////////////////////
    /**
     * @def RK_GAME_SNAKE_CNF_ENABLE_PORTAL
     * @brief Enable Portal Generation
     */
    # define RK_GAME_SNAKE_CNF_ENABLE_PORTAL false
    /**
     * @def RK_GAME_SNAKE_CNF_PORTAL_COLOR
     * @brief Portal Color (RGB)
     */
    # define RK_GAME_SNAKE_CNF_PORTAL_COLOR RKColor(255, 255, 0)
    /**
     * @def RK_GAME_SNAKE_CNF_PORTAL_CHARACTER
     * @brief Portal Character
     */
    # define RK_GAME_SNAKE_CNF_PORTAL_CHARACTER "⊕ "
    /**
     * @def RK_GAME_SNAKE_CNF_PORTAL_AMOUNT
     * @brief Default Portals Amount to be Generated
     */
    # define RK_GAME_SNAKE_CNF_PORTAL_AMOUNT 3
    ////////////////////////////////
    //----------------------------//
    //--| Shield Configuration |--//
    //----------------------------//
    ////////////////////////////////
    /**
     * @def RK_GAME_SNAKE_CNF_ENABLE_SHIELD
     * @brief Enable Shield Generation
     */
    # define RK_GAME_SNAKE_CNF_ENABLE_SHIELD false
    /**
     * @def RK_GAME_SNAKE_CNF_SHIELD_COLOR
     * @brief Shield Color (RGB)
     */
    # define RK_GAME_SNAKE_CNF_SHIELD_COLOR RKColor(255, 255, 0)
    /**
     * @def RK_GAME_SNAKE_CNF_SHIELD_CHARACTER
     * @brief Shield Character
     */
    # define RK_GAME_SNAKE_CNF_SHIELD_CHARACTER "⊕ "
    /**
     * @def RK_GAME_SNAKE_CNF_SHIELD_AMOUNT
     * @brief Default Shields Amount to be Generated
     */
    # define RK_GAME_SNAKE_CNF_SHIELD_AMOUNT 3
    //////////////////////////////
    //--------------------------//
    //--| Coin Configuration |--//
    //--------------------------//
    //////////////////////////////
    /**
     * @def RK_GAME_SNAKE_CNF_ENABLE_COIN
     * @brief Enable Coin Generation
     */
    # define RK_GAME_SNAKE_CNF_ENABLE_COIN false
    /**
     * @def RK_GAME_SNAKE_CNF_COIN_COLOR
     * @brief Coin Color (RGB)
     */
    # define RK_GAME_SNAKE_CNF_COIN_COLOR RKColor(255, 255, 0)
    /**
     * @def RK_GAME_SNAKE_CNF_COIN_CHARACTER
     * @brief Coin Character
     */
    # define RK_GAME_SNAKE_CNF_COIN_CHARACTER "⊕ "
    /**
     * @def RK_GAME_SNAKE_CNF_COIN_AMOUNT
     * @brief Default Coin Amount to be Generated
     */
    # define RK_GAME_SNAKE_CNF_COIN_AMOUNT 3
# endif // RK_GAMES_SNAKE_CONFIGS