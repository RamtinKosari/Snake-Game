# ifndef RK_GAMES_SNAKE_BLOCKS
    /**
     * @file Blocks.hpp
     * @author Arash Rahmani (github.com/arashrahmani)
     * @author Ramtin Kosari (github.com/ramtinkosari)
     * @brief Snake Game Implementation in C++ Using Object-Oriented Programming - Game Block Header File
     * @def RK_GAMES_SNAKE_BLOCKS
     * @version 1.1
     * @date 2026-04-20
     */
    # define RK_GAMES_SNAKE_BLOCKS
    //-- Check if Library is being Compiled by RKACPB
    # ifdef RKACPB
        //-- Check if Configs File is Configured
        # ifndef HAS_RKACPB_MODULE_CONFIGS
            # error "Configs File is Required for RK_GAMES_SNAKE_BLOCKS Module"
        # endif // HAS_RKACPB_CONFIGS
        //-- Check if RKLogger File is Configured
        # ifndef HAS_RKACPB_MODULE_RKLOGGER
            # error "RKLogger File is Required for RK_GAMES_SNAKE_BLOCKS Module"
        # endif // HAS_RKACPB_MODULE_RKLOGGER
    # endif // RKACPB
    //-- Include Configuration File
    # ifndef SGCOOP_CONFIGS
        # include "Configs.hpp"
    # endif // SGCOOP_CONFIGS
    //-- Include RKLogger
    # ifndef RKLOGGER
        # include "RKLogger.hpp"
    # endif // RKLOGGER
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
             * @brief Define Blocks Type
             * 
             */
            enum BLOCK_TYPES {
                BLOCK_TYPE_AIR,
                BLOCK_TYPE_BORDER,
                BLOCK_TYPE_FOOD,
                BLOCK_TYPE_WALL,
                BLOCK_TYPE_POISON,
                BLOCK_TYPE_SPEED_UP,
                BLOCK_TYPE_SLOW_DOWN,
                BLOCK_TYPE_PORTAL,
                BLOCK_TYPE_SHIELD,
                BLOCK_TYPE_COIN
            };
            /**
             * @brief Define Blocks Class
             * @class Block
             */
            class Block {
                public:
                    /**
                     * @brief X-Axis Coordinate of the Block
                     */
                    int x;
                    /**
                     * @brief Y-Axis Coordinate of the Block
                     */
                    int y;
                    /**
                     * @brief Type of the Block
                     */
                    BLOCK_TYPES type;
                    /**
                     * @brief Color of the Block
                     */
                    RKColor color;
                    /**
                     * @brief Visual Representation of the Block
                     */
                    std::string visual;
                    /**
                     * @brief Character Representation of the Block
                     */
                    std::string character;
                    /**
                     * @brief Construct a New Block Object
                     */
                    Block() {
                        character = RK_GAME_SNAKE_CNF_BOARD_CHARACTER;
                        type = BLOCK_TYPE_AIR;
                        color = RK_GAME_SNAKE_CNF_BOARD_COLOR;
                    }
                    /**
                     * @brief Construct a new Block object
                     * @param _x 
                     * @param _y 
                     */
                    Block(int _x, int _y) {
                        x = _x;
                        y = _y;
                    }
                    /**
                     * @brief Construct a New Block Object
                     * @param t Type of the Block
                     * @param c Color of the Block
                     * @param v Visual Representation of the Block
                     * @param ch Character Representation of the Block
                     */
                    Block(
                        int _x,
                        int _y,
                        RKColor c,
                        BLOCK_TYPES t,
                        std::string v,
                        std::string ch
                    ) {
                        character = ch;
                        visual = v;
                        color = c;
                        type = t;
                        x = _x;
                        y = _y;
                    }
                    /**
                     * @brief Set Type of the Block
                     * @param t Type of the Block
                     */
                    void setType(BLOCK_TYPES t);
                    /**
                     * @brief Set Visual Representation of the Block
                     */
                    void setVisual(bool background = true);
            };
        }
    }
# endif // RK_GAMES_SNAKE_BLOCKS