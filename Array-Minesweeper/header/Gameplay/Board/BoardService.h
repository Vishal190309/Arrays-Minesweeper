#pragma once

namespace UI {
    namespace UIElement {
        enum class ButtonType;
    }
}

namespace Gameplay
{
    namespace Cell {
        class CellController;
    }
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
            void processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type);
            int getMinesCount();
            void resetBoard();
        };
    }
}