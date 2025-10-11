# ifndef SGCOOP_BLOCKS
    /**
     * @file Blocks.hpp
     * @author Arash Rahmani (github.com/arashrahmani)
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief Snake Game Implementation in C++ Using Object-Oriented Programming - Blocks Header File
     * @date 2024-09-19
     */
    # define SGCOOP_BLOCKS
    //-- Check if Library is being Compiled by RKACPB
    # ifdef RKACPB
        //-- Check if Configs File is Configured
        # ifndef HAS_RKACPB_MODULE_CONFIGS
            # error "Configs File is Required for SGCOOP Blocks Module"
        # endif // HAS_RKACPB_CONFIGS
    # endif // RKACPB
    //-- Include Configuration File
    # ifndef SGCOOP_CONFIGS
        # include "Configs.hpp"
    # endif // SGCOOP_CONFIGS
    /**
     * @brief Define Blocks Type
     * 
     */
    enum BLOCK_TYPES {
        BLOCK_TYPE_AIR,
        BLOCK_TYPE_BORDER,
        BLOCK_TYPE_FOOD,
        BLOCK_TYPE_BARRIER,
        BLOCK_TYPE_WALL,
        BLOCK_TYPE_SPEED_UP,
        BLOCK_TYPE_SLOW_DOWN,
        BLOCK_TYPE_PORTAL,
        BLOCK_TYPE_POISON,
        BLOCK_TYPE_REVERSE,
        BLOCK_TYPE_SHIELD,
        BLOCK_TYPE_COIN,
        BLOCK_TYPE_TREASURE
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
            Color color;
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
                character = BOARD_CHARACTER;
                type = BLOCK_TYPE_AIR;
                color = BOARD_COLOR;
            }
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
                Color c,
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
# endif // SGCOOP_BLOCKS