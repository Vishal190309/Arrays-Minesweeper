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
            CellController(sf::Vector2i);
            ~CellController();

            void initialize(float cell_width, float cell_height);
            void update();
            void render();

            void openCell();

            void flagCell();

            CellState getCellState();
            CellValue getCellValue();
            sf::Vector2i getCellPosition();
            void reset();
        };
    }
}