#pragma once
#include <sfml/Graphics.hpp>
#include "../../header/Gameplay/Cell/CellController.h"
#include<random>

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
        enum class BoardState
        {
            FIRST_CELL,       // The state when the player opens first cell.
            PLAYING,          // The game is in progress.
            COMPLETED,    // The game is over.
        };

        class BoardView;

        class BoardController
        {
        public:
            static const int number_of_rows = 9;
            static const int number_of_colums = 9;
            static const int mines_count = 8;

            BoardController();
            ~BoardController();

            void initialize();
            void update();
            void render();
            void showBoard();
            void processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type);
           
            void reset();
            int getMinesCount();
            BoardState getBoardState();
            void setBoardState(BoardState state);
            void resetBoard();

        private:
            BoardView* board_view;
            Cell::CellController* board[number_of_rows][number_of_colums];
            int flagged_cells = 0;
            BoardState board_state;

            // To generate random values.
            std::default_random_engine random_engine;

            // To give random seed to generator.
            std::random_device random_device;

            void createBoard();
            void initializeCells();
            int countMinesAround(sf::Vector2i cell_position);
            bool isValidCellPosition(sf::Vector2i cell_position);
            void openCell(sf::Vector2i cell_position);
            void populateBoard(sf::Vector2i cell_position);
            void populateMines(sf::Vector2i cell_position);
            void populateCells();
           
            void openAllCells();
            void flagCell(sf::Vector2i cell_position);
            void processCellValue(sf::Vector2i cell_position);
            void processMineCell(sf::Vector2i cell_position);
            void processEmptyCell(sf::Vector2i cell_position);
            void openEmptyCells(sf::Vector2i cell_position);
            void destroy();
            void deleteBoard();
        };
    }
}