#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Gameplay {
	GameplayController::GameplayController()
	{
	}
	GameplayController::~GameplayController()
	{
	}
	void GameplayController::initialize()
	{
	}
	void GameplayController::update()
	{
	}
	void GameplayController::render()
	{
	}
	void GameplayController::reset()
	{
		Global::ServiceLocator::getInstance()->getBoardService()->resetBoard();
	}
}