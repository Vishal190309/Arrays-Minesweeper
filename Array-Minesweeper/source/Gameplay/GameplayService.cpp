#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Gameplay {
	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
	}
	GameplayService::~GameplayService()
	{
		delete(gameplay_controller);
	}
	void GameplayService::initialize()
	{
		gameplay_controller->initialize();
	}
	void GameplayService::update()
	{
		gameplay_controller->update();
	}
	void GameplayService::render()
	{
		gameplay_controller->render();
	}
	int GameplayService::getMinesCount()
	{
		return Global::ServiceLocator::getInstance()->getBoardService()->getMinesCount();
	}
	void GameplayService::startGame()
	{
		gameplay_controller->reset();
	}

	float GameplayService::getRemainingTime()
	{
		return gameplay_controller->getRemainingTime();
	}
}