#include "../../../header/Gameplay/Board/BoardController.h"
#include "../../../header/Gameplay/Board/BoardView.h"
#include "../../../header/UI/UIElement/ButtonView.h"
#include "../../../header/Global/ServiceLocator.h"
#include "../../../header/Gameplay/Cell/CellModel.h"
#include <array>

namespace Gameplay
{
	namespace Board
	{
		using namespace Cell;

		BoardController::BoardController()
		{
			board_view = new BoardView(this);
			createBoard();
		}

		BoardController::~BoardController()
		{
			destroy();
		}

		void BoardController::createBoard()
		{
			for (int i = 0; i < number_of_colums; i++)
			{
				for (int j = 0; j < number_of_colums; j++)
				{
					board[i][j] = new CellController(sf::Vector2i(i,j));
				}
			}
			
		}

		void BoardController::initializeCells()
		{
			float cell_width = board_view->getCellWidth();
			float cell_height = board_view->getCellHeight();

			for (int i = 0; i < number_of_colums; i++)
			{
				for (int j = 0; j < number_of_colums; j++)
				{
					board[i][j]->initialize(cell_width, cell_height);
				}
			}
		}

		int BoardController::getMinesCount()
		{
			return mines_count - flagged_cells;
		}

		void BoardController::initialize()
		{
			board_view->initialize();
			initializeCells();
		}

		void BoardController::update()
		{
			board_view->update();
			for (int i = 0; i < number_of_colums; i++)
			{
				for (int j = 0; j < number_of_colums; j++)
				{
					board[i][j]->update();
				}
			}
		}

		void BoardController::render()
		{
			board_view->render();
			for (int i = 0; i < number_of_colums; i++)
			{
				for (int j = 0; j < number_of_colums; j++)
				{
					board[i][j]->render();
				}
			}
		}

		void BoardController::openCell(sf::Vector2i cell_position)
		{
			if (board[cell_position.x][cell_position.y]->canOpenCell())
			{
				board[cell_position.x][cell_position.y]->openCell();
			}
		}

		void BoardController::flagCell(sf::Vector2i cell_position)
		{
			switch (board[cell_position.x][cell_position.y]->getCellState())
			{
			case::Gameplay::Cell::CellState::FLAGGED:
				Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::FLAG);
				flagged_cells--; //Used to update Gameplay UI
				break;
			case::Gameplay::Cell::CellState::HIDDEN:
				Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::FLAG);
				flagged_cells++; //Used to update Gameplay UI
				break;
			}

			board[cell_position.x][cell_position.y]->flagCell();
		}

		void BoardController::processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type)
		{
			switch (button_type)
			{
			case UI::UIElement::ButtonType::LEFT_MOUSE_BUTTON:
				openCell(cell_controller->getCellPosition());
				break;
			case UI::UIElement::ButtonType::RIGHT_MOUSE_BUTTON:
				flagCell(cell_controller->getCellPosition());
				break;
			}
		}

		

		void BoardController::reset()
		{
			flagged_cells = 0;
			resetBoard();
		}

		void BoardController::resetBoard()
		{
			for (int row = 0; row < number_of_rows; ++row)
			{
				for (int col = 0; col < number_of_colums; ++col)
				{
					board[row][col]->reset();
				}
			}
		}

		void BoardController::deleteBoard()
		{
			for (int i = 0; i < number_of_colums; i++)
			{
				for (int j = 0; j < number_of_colums; j++)
				{
					delete(board[i][j]);
				}
			}
		}


		void BoardController::destroy()
		{
			deleteBoard();
			delete(board_view);
		}
	}
}
