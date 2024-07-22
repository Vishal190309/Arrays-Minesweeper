#pragma once
#include <sfml/Graphics.hpp>

namespace Gameplay
{
    namespace Cell
    {
        enum class CellState;
        enum class CellValue;
        class CellView;
        class CellModel;


        class CellController
        {
        private:
            class CellView* cell_view;
            class CellModel* cell_model;
           
            void destroy();

        public:
            CellController();
            ~CellController();

            void initialize();
            void update();
            void render();

            CellState getCellState();
            CellValue getCellValue();
            sf::Vector2i getCellPosition();
            void reset();
        };
    }
}