# ifndef SGCOOP_GAME
    /**
     * @file Game.hpp
     * @author Arash Rahmani (github.com/arashrahmani)
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief Snake Game Implementation in C++ Using Object-Oriented Programming - Game Header File
     * @date 2024-09-19
     */
    # define SGCOOP_GAME
    //-- Check if Library is being Compiled by RKACPB
    # ifdef RKACPB
        //-- Check if Configs File is Configured
        # ifndef HAS_RKACPB_MODULE_CONFIGS
            # error "Configs File is Required for SGCOOP Game Module"
        # endif // HAS_RKACPB_CONFIGS
        //-- Check if Snake File is Configured
        # ifndef HAS_RKACPB_MODULE_SNAKE
            # error "Snake File is Required for SGCOOP Game Module"
        # endif // HAS_RKACPB_SNAKE
        //-- Check if Blocks File is Configured
        # ifndef HAS_RKACPB_MODULE_BLOCKS
            # error "Blocks File is Required for SGCOOP Game Module"
        # endif // HAS_RKACPB_BLOCKS
    # endif // RKACPB
    //-- Include Configuration File
    # ifndef SGCOOP_CONFIGS
        # include "Configs.hpp"
    # endif // SGCOOP_CONFIGS
    //-- Include Snake File
    # ifndef SGCOOP_SNAKE
        # include "Snake.hpp"
    # endif // SGCOOP_SNAKE
    //-- Include Blocks File
    # ifndef SGCOOP_BLOCKS
        # include "Blocks.hpp"
    # endif // SGCOOP_BLOCKS
    /**
     * @brief Define Game Class
     * @class Game
     */
    class Game {
        public:
            /**
             * @brief Game Information
             */
            std::vector<std::string> game_info;
            /**
             * @brief Game Tips
             */
            std::vector<std::string> game_tips;
            /**
             * @brief Game Score
             */
            int score;
            /**
             * @brief Food Count
             */
            int foodCount;
            /**
             * @brief Wall Count
             */
            int wallCount;
            /**
             * @brief Poison Count
             */
            int poisonCount;
            /**
             * @brief Last Information Color
             */
            std::string lastInfoColor;
            /**
             * @brief Define Board Structure
             * @struct Board
             * @param height Height of the Board
             * @param width Width of the Board
             * @param color Color of the Board
             */
            struct Board {
                /**
                 * @brief Height of the Board
                 */
                int height;
                /**
                 * @brief Width of the Board
                 */
                int width;
                /**
                 * @brief Color of the Board
                 */
                Color color;
                /**
                 * @brief Construct a New Configurable Board Object
                 * @param h Height of the Board
                 * @param w Width of the Board
                 * @param c Color of the Board
                 */
                Board(
                    int h = 0,
                    int w = 0,
                    Color c = BOARD_COLOR
                ) {
                    /**
                     * @brief Height of the Board
                     */
                    height = h;
                    /**
                     * @brief Width of the Board
                     */
                    width = w;
                    /**
                     * @brief Color of the Board
                     */
                    color = c;
                }
            };
            /**
             * @brief Board Object
             */
            Board board;
            /**
             * @brief Snake Object
             */
            Snake snake;
            /**
             * @brief Blocks Object
             */
            std::vector<std::vector<Block>> blocks;
            /**
             * @brief Foods Object
             */
            std::vector<std::vector<Block>> foods;
            /**
             * @brief Poisons Object
             */
            std::vector<std::vector<Block>> poisons;
            /**
             * @brief Construct a New Game Object
             */
            Game();
            /**
             * @brief Generate Board
             */
            void generate();
            /**
             * @brief Display Game
             */
            void display();
            /**
             * @brief Clear Terminal
             */
            void clearTerminal();
            /**
             * @brief Generate Foods
             */
            void generateFoods();
            /**
             * @brief Generate Walls
             */
            void generateWalls();
            /**
             * @brief Generate Poissons
             */
            void generatePoisons();
            /**
             * @brief Update Game Board
             */
            void update();
    };
# endif // SGCOOP_GAME