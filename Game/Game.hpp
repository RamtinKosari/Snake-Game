# ifndef RK_GAMES_SNAKE
    /**
     * @file Game.hpp
     * @author Arash Rahmani (github.com/arashrahmani)
     * @author Ramtin Kosari (github.com/ramtinkosari)
     * @brief Snake Game Implementation in C++ Using Object-Oriented Programming - Game Header File
     * @version 1.1
     * @date 2026-04-20
     */
    # define RK_GAMES_SNAKE
    //-- Check if Library is being Compiled by RKACPB
    # ifdef RKACPB
        //-- Check if Configs File is Configured
        # ifndef HAS_RKACPB_MODULE_CONFIGS
            # error "Configs File is Required for RK_GAMES_SNAKE Module"
        # endif // HAS_RKACPB_CONFIGS
        //-- Check if RKLogger File is Configured
        # ifndef HAS_RKACPB_MODULE_RKLOGGER
            # error "RKLogger File is Required for RK_GAMES_SNAKE Module"
        # endif // HAS_RKACPB_MODULE_RKLOGGER
        //-- Check if Blocks File is Configured
        # ifndef HAS_RKACPB_MODULE_BLOCKS
            # error "Blocks File is Required for RK_GAMES_SNAKE Module"
        # endif // HAS_RKACPB_MODULE_BLOCKS
    # endif // RKACPB
    //-- Include Configuration File
    # ifndef RK_GAMES_SNAKE_CONFIGS
        # include "Configs.hpp"
    # endif // RK_GAMES_SNAKE_CONFIGS
    //-- Include RKLogger
    # ifndef RKLOGGER
        # include "RKLogger.hpp"
    # endif // RKLOGGER
    //-- Include Blocks
    # ifndef RK_GAMES_SNAKE_BLOCKS
        # include "Blocks.hpp"
    # endif // RK_GAMES_SNAKE_BLOCKS
    /**
     * @namespace rkgames
     * @brief rkgames namespace
     */
    namespace rkgames {
        /**
         * @namespace snake
         * @brief snake namespace
         */
        namespace snake {
            /**
             * @class Game
             * @brief Snake Game Class
             */
            class Game {
                public:
                    //--------------------//
                    //-- | Attributes | --//
                    //--------------------//
                    /**
                     * @brief Blocks Object
                     */
                    std::vector<std::vector<Block>> blocks, foods, poisons, speed_ups, slow_downs, portals, shields, coins;
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
                    long long int score;
                    /**
                     * @brief Block Counters
                     */
                    int foodCount = 0, wallCount = 0, poisonCount = 0, speedUpCount = 0, slowDownCount = 0, portalCount = 0, shieldCount = 0, coinCount = 0;
                    /**
                     * @brief Last Information Color
                     */
                    std::string lastInfoColor;
                    //--------------------//
                    //-- | Structures | --//
                    //--------------------//
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
                        RKColor color;
                        /**
                         * @brief Construct a New Configurable Board Object
                         * @param h Height of the Board
                         * @param w Width of the Board
                         * @param c Color of the Board
                         */
                        Board(
                            int h = 0,
                            int w = 0,
                            RKColor c = RK_GAME_SNAKE_CNF_BOARD_COLOR
                        ) {
                            height = h;
                            width = w;
                            color = c;
                        }
                    };
                    /**
                     * @brief Board Object
                     */
                    Board board;
                    //-----------------//
                    //-- | Methods | --//
                    //-----------------//
                    /**
                     * @brief Construct a New Game Object
                     */
                    Game();
                    /**
                     * @brief Construct a New Game Object with Specific Width and Height
                     * @param w Width of the Board
                     * @param h Height of the Board
                     */
                    Game(
                        int &   w,
                        int &   h
                    );
                    /**
                     * @brief Destroy the Game Object
                     */
                    ~Game();
                    /**
                     * @brief Generate Board
                     */
                    void generate();
                    /**
                     * @brief Generate Blocks
                     * @param t Block Type
                     */
                    void generateBlocks(
                        BLOCK_TYPES t
                    );
                    /**
                     * @brief Display Game
                     */
                    void display();
                    /**
                     * @brief Clear Terminal
                     */
                    void clearTerminal();
            };
        }
    }
# endif // RK_GAMES_SNAKE