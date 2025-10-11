# ifndef SGCOOP_CONFIGS
    /**
     * @file Configs.hpp
     * @author Arash Rahmani (github.com/arashrahmani)
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief Snake Game Implementation in C++ Using Object-Oriented Programming Configurations
     * @date 2024-09-19
     */
    # define SGCOOP_CONFIGS
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
    class Color {
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
            Color() {
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
            Color(int r, int g, int b) {
                red = r;
                green = g;
                blue = b;
            }
    };
    /**
     * @brief Define Whitespace
     * @note Use Odd Number of Spaces for Character to be Centered
     */
    # define WHITE_SPACE "  "
    // ፨ ⁜ ⁖ ⁕ ⁘ ⁙ ⁚ ⁛ ⁜ ⁝ ⁞ ⁐  ⃟   ⃝   ⃞   ⃠ ⊞⊡⊠⊕⊗⊘⋰⋱⋮ ⌾ ⌺ ⎔ ⎕ ╋ █ ░▒▓▩▣◈◌◎●◆◔ ◴ ☕ ☢ ☣☠⛃⛁⛂⛀✧✚ ⥀⥁⸎🌀 ҉ ◌◯☯⚝⚛ 



    //--------------------------//
    //--| Game Configuration |--//
    //--------------------------//
    /**
     * @brief Game Timer (Seconds)
     */
    # define GAME_TIME 1200
    /**
     * @brief Scores Per 10 Second
     */
    # define SCORES_PER_SECOND 15



    //---------------------------//
    //--| Color Configuration |--//
    //---------------------------//
    /**
     * @def INFO
     * @brief Information Message
     * @details This Macro Defines Information Message Log Label for Algorithms Class
     */
    # define INFO "\033[38;2;0;170;170m[INFO]\033[0m "
    /**
     * @def CYAN
     * @brief Cyan Label Message
     * @details This Macro Defines Cyan Message Log Label for Algorithms Class
     */
    # define CYAN "\033[38;2;0;255;255m"
    /**
     * @def LIGHT_BLUE
     * @brief Light Blue Label Message
     * @details This Macro Defines Light Blur Message Log Label for Algorithms Class
     */
    # define LIGHT_BLUE "\033[38;2;183;199;212m"
    /**
     * @def Astral
     * @brief Astal Label Message
     * @details This Macro Defines Astral Message Log Label for Algorithms Class
     */
    # define ASTRAL "\033[38;2;160;142;171m"
    /**
     * @def ORANGE
     * @brief Orange Label Message
     * @details This Macro Defines Orange Message Log Label for Algorithms Class
     */
    # define ORANGE "\033[38;2;255;165;0m"
    /**
     * @def RED
     * @brief Red Label Message
     * @details This Macro Defines Red Message Log Label for Algorithms Class
     */
    # define RED "\033[38;2;255;0;0m"
    /**
     * @def RESET
     * @brief Reset Label Message
     * @details This Macro Resets Log Message Format
     */
    # define RESET "\033[0m "

    /**
     * @brief Game Delay (Milliseconds)
     * @note Default Value is 16ms for ~60FPS
     */
    # define GAME_DELAY 16

    //---------------------------//
    //--| Board Configuration |--//
    //---------------------------//
    /**
     * @brief Board Width
     * @note Default Value is 64 Blocks
     */
    # define BOARD_WIDTH 38
    /**
     * @brief Board Height
     * @note Default Value is 52 Blocks
     */
    # define BOARD_HEIGHT 37
    /**
     * @brief Board Background Color (RGB)
     */
    # define BOARD_COLOR Color(0, 7, 15)
    /**
     * @brief Board Character
     */
    # define BOARD_CHARACTER WHITE_SPACE



    //----------------------------//
    //--| Border Configuration |--//
    //----------------------------//
    /**
     * @brief Border Color (RGB)
     */
    # define BORDER_COLOR Color(0, 20, 40)
    /**
     * @brief Border Character
     */
    # define BORDER_CHARACTER WHITE_SPACE



    //--------------------------//
    //--| Food Configuration |--//
    //--------------------------//
    /**
     * @brief Food Color (RGB)
     */
    # define FOOD_COLOR Color(0, 200, 100)
    /**
     * @brief Food Character
     */
    # define FOOD_CHARACTER "◎ " //◆ ☉ ◎ ● ■ ▲ ⬤ ❖ 🌀 ■
    /**
     * @brief Amount of Food Generated for each Time
     */
    # define FOOD_AMOUNT 3



    //--------------------------//
    //--| Wall Configuration |--//
    //--------------------------//
    /**
     * @brief Generate Walls
     */
    # define GENERATE_WALLS true
    /**
     * @brief Wall Color (RGB)
     */
    # define WALL_COLOR Color(0, 40, 80)
    /**
     * @brief Wall Character
     */
    # define WALL_CHARACTER "  "
    /**
     * @brief Wall Amounts
     */
    # define WALL_AMOUNT 4
    /**
     * @brief Wall Length
     */
    # define WALL_LENGTH 6
    /**
     * @brief Wall Padding
     */
    # define WALL_PADDING 5
    /**
     * @brief Generate Walls During Game
     * @note if Enabled, Walls will be Generated During Game each GENERATE_WALLS_EACH Seconds
     */
    # define GENERATE_WALLS_DURING_GAME true
    /**
     * @brief Generate Walls Each Seconds
     * @note if GENERATE_WALLS_DURING_GAME is Enabled, This Value will be Used for Generating Walls
     * @note Default Value is 10 Seconds
     */
    # define GENERATE_WALLS_EACH 10
    /**
     * @brief Generate Walls Near Radius
     * @note if GENERATE_WALLS_DURING_GAME is Enabled, This Value will be Used for Generating Walls Near Snake
     * @note Default Value is 5 Blocks
     * @note -1 for Disabling
     * @warning Do Not Set This Value to 0, Because Snake Will be Surrounded by Walls and Game Will be Over
     */
    # define GENERATE_WALLS_NEAR_RADIUS -1



    //----------------------------//
    //--| Poison Configuration |--//
    //----------------------------//
    /**
     * @brief Generate Poisons
     */
    # define GENERATE_POISONS true
    /**
     * @brief Poison Color (RGB)
     */
    # define POISON_COLOR Color(255, 120, 0)
    /**
     * @brief Poison Character
     */
    # define POISON_CHARACTER "☠ "
    /**
     * @brief Poison Amounts
     */
    # define POISON_AMOUNT 3
    /**
     * @brief Generate Poisons During Game
     * @note if Enabled, Poisons will be Generated During Game each GENERATE_POISONS_EACH Seconds
     */
    # define GENERATE_POISONS_DURING_GAME true
    /**
     * @brief Generate Poisons Each Seconds
     * @note if GENERATE_POISONS_DURING_GAME is Enabled, This Value will be Used for Generating Poisons
     * @note Default Value is 10 Seconds
     */
    # define GENERATE_POISONS_EACH 25













    //------------------------------//
    //--| Speed Up Configuration |--//
    //------------------------------//
    /**
     * @brief Generate Speed Ups
     */
    # define GENERATE_SPEED_UPS false
    /**
     * @brief Speed Up Color (RGB)
     */
    # define SPEED_UP_COLOR Color(255, 255, 0)
    /**
     * @brief Speed Up Character
     */
    # define SPEED_UP_CHARACTER "⊕ "
    /**
     * @brief Speed Up Amounts
     */
    # define SPEED_UP_AMOUNT 1





    /**
     * @brief Generate Slow Downs
     */
    # define GENERATE_SLOW_DOWNS false
    /**
     * @brief Generate Portals
     */
    # define GENERATE_PORTALS false
    /**
     * @brief Generate Reverses
     */
    # define GENERATE_REVERSES false
    /**
     * @brief Generate Shields
     */
    # define GENERATE_SHIELDS false
    /**
     * @brief Generate Coins
     */
    # define GENERATE_COINS false
    /**
     * @brief Generate Treasures
     */
    # define GENERATE_TREASURES false

    

    

    /**
     * @brief Snake Color (RGB)
     */
    # define SNAKE_COLOR Color(0, 255, 0)
    /**
     * @brief Snake Character
     */
    # define SNAKE_CHARACTER "■ "
    /**
     * @brief Speed Up Color (RGB)
     */
    # define SPEED_UP_COLOR Color(255, 255, 0)
    /**
     * @brief Slow Down Color (RGB)
     */
    # define SLOW_DOWN_COLOR Color(255, 0, 255)
    /**
     * @brief Portal Color (RGB)
     */
    # define PORTAL_COLOR Color(0, 255, 255)
    /**
     * @brief Reverse Color (RGB)
     */
    # define REVERSE_COLOR Color(255, 255, 255)
    /**
     * @brief Shield Color (RGB)
     */
    # define SHIELD_COLOR Color(255, 255, 255)
    /**
     * @brief Coin Color (RGB)
     */
    # define COIN_COLOR Color(255, 255, 255)
    /**
     * @brief Treasure Color (RGB)
     */
    # define TREASURE_COLOR Color(255, 255, 255)



    /**
     * @brief Enable Debug Mode
     * @details Debug Mode is Used for Debugging Purposes and Prints
     * @note Debug Mode Show Prints and More Info Logs
     */
    # define ENABLE_DEBUG true
# endif // SGCOOP_CONFIGS