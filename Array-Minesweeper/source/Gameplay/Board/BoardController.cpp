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

		BoardController::BoardController() : random_engine(random_device())
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

		BoardState BoardController::getBoardState()
		{
			return board_state;
		}

		void BoardController::setBoardState(BoardState state)
		{
			board_state = state;
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
				if (board_state == BoardState::FIRST_CELL)
				{
					populateBoard(cell_position);
					board_state = BoardState::PLAYING;
				}
				board[cell_position.x][cell_position.y]->openCell();
			}
		}
		void BoardController::populateBoard(sf::Vector2i cell_position)
		{
			populateMines(cell_position);
			populateCells(); 
		}

		void BoardController::populateMines(sf::Vector2i cell_position)
		{
			// Co-ordinate distribution i.e. selecting random position for mines.
			std::uniform_int_distribution<int> x_distribution(0, number_of_colums - 1); //Subtracted -1 because index in an array ranges from 0 to size-1
			std::uniform_int_distribution<int> y_distribution(0, number_of_rows - 1);

			// Generate mines.
			for (int a = 0; a < mines_count; a++)
			{
				int i = static_cast<int>(x_distribution(random_engine));
				int j = static_cast<int>(y_distribution(random_engine));

				if (board[i][j]->getCellValue() == CellValue::MINE || (cell_position.x == i && cell_position.y == j)) a--; //a-- runs a loop 1 extra time
				else board[i][j]->setCellValue(CellValue::MINE);


			}
		}

		void BoardController::populateCells()
		{
			for (int a = 0; a < number_of_rows; a++)
			{
				for (int b = 0; b < number_of_colums; b++)
				{
					if (board[a][b]->getCellValue() != CellValue::MINE)
					{
						CellValue value = static_cast<CellValue>(countMinesAround(sf::Vector2i(a, b)));
						board[a][b]->setCellValue(value);
					}
				}
			}
		}

		int BoardController::countMinesAround(sf::Vector2i cell_position)
		{
			int mines_around = 0;

			for (int a = -1; a < 2; a++)
			{
				for (int b = -1; b < 2; b++)
				{
					//If its the current cell, or cell position is not valid, then the loop will skip once
					if ((a == 0 && b == 0) || !isValidCellPosition(sf::Vector2i(cell_position.x + a, cell_position.y + b))) continue;

					if (board[a + cell_position.x][b + cell_position.y]->getCellValue() == CellValue::MINE) mines_around++;
				}
			}

			return mines_around;
		}

		bool BoardController::isValidCellPosition(sf::Vector2i cell_position)
		{
			// if position is withing the bounds of the array, then position is valid
			return (cell_position.x >= 0 && cell_position.y >= 0 && cell_position.x < number_of_colums && cell_position.y < number_of_rows);
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
