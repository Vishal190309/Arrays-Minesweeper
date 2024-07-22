#pragma once


namespace Gameplay
{
    namespace Board
    {
        class BoardController;
        class BoardService
        {
        private:
            BoardController* board_controller;

            void destroy();

        public:
            BoardService();
            ~BoardService();
            void initialize();
            void update();
            void render();

            void resetBoard();
        };
    }
}