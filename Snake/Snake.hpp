# ifndef SGCOOP_SNAKE
    /**
     * @file Snake.hpp
     * @author Arash Rahmani (github.com/arashrahmani)
     * @author Ramtin Kosari (ramtinkosari@gmail.com)
     * @brief Snake Game Implementation in C++ Using Object-Oriented Programming - Snake Header File
     * @date 2024-09-19
     */
    # define SGCOOP_SNAKE
    //-- Check if Library is being Compiled by RKACPB
    # ifdef RKACPB
        //-- Check if Configs File is Configured
        # ifndef HAS_RKACPB_MODULE_CONFIGS
            # error "Configs File is Required for SGCOOP Snake Module"
        # endif // HAS_RKACPB_CONFIGS
    # endif // RKACPB
    //-- Include Configuration File
    # ifndef SGCOOP_CONFIGS
        # include "Configs.hpp"
    # endif // SGCOOP_CONFIGS
    /**
     * @brief Define Snake Class
     * @class Snake
     */
    class Snake {
        private:
            /**
             * @brief Body of the Snake
             */
            // std::vector<SGPoint> body;
            /**
             * @brief Previous Positions of the Snake
             */
            // std::vector<SGPoint> previous_pos;
        public:
            /**
             * @brief Construct a New Snake Object
             */
            Snake() {}
            /**
             * @brief Construct a New Snake Object
             * @param center_y Center Y-Axis Coordinate
             * @param center_x Center X-Axis Coordinate
             */
            Snake(int center_y, int center_x);
    };
# endif // SGCOOP_SNAKE