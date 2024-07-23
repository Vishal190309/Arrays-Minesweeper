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
		updateRemainingTime();
	}
	void GameplayController::render()
	{
	}

	void GameplayController::updateRemainingTime()
	{
		remaining_time -= Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	float GameplayController::getRemainingTime()
	{
		return remaining_time;
	}
	void GameplayController::reset()
	{
		remaining_time = max_duration;
		Global::ServiceLocator::getInstance()->getBoardService()->resetBoard();
	}
}