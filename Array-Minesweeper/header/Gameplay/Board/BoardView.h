#pragma once
#include "../../header/UI/UIElement/ImageView.h"

namespace Gameplay
{
    namespace Board
    {
        class BoardController;

        class BoardView
        {
        private:

            const float board_width = 866.f;
            const float board_height = 1080.f;

            const float background_alpha = 85.f;

            ImageView* board_image;
            ImageView* background_image;
            BoardController* board_controller;

            void initializeBackgroudImage();
            void initializeBoardImage();

        public:
            BoardView(BoardController* controller);
            ~BoardView();

            void initialize();
            void update();
            void render();
        };
    }
}