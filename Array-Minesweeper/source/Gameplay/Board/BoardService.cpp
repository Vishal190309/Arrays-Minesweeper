#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/UI/UIElement/ButtonView.h"
namespace Gameplay
{
	namespace Board
	{
		
		BoardService::BoardService()
		{
			board_controller = nullptr;
		}

		BoardService::~BoardService()
		{
			destroy();
		}

		void BoardService::initialize()
		{
			board_controller = new BoardController();
			board_controller->initialize();
		}

		void BoardService::update()
		{
			board_controller->update();
		}

		void BoardService::render()
		{
			board_controller->render();
		}

		BoardState BoardService::getBoardState()
		{
			return board_controller->getBoardState();
		}

		void BoardService::setBoardState(BoardState board_state)
		{
			board_controller->setBoardState(board_state);
		}

		void BoardService::showBoard()
		{
			board_controller->showBoard();
		}

		void BoardService::processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type)
		{
			board_controller->processCellInput(cell_controller, button_type);
		}

		int BoardService::getMinesCount()
		{
			return board_controller->getMinesCount();
		}

		void BoardService::resetBoard()
		{
			board_controller->reset();
		}

		void BoardService::destroy()
		{
			delete(board_controller);
		}
	}
}