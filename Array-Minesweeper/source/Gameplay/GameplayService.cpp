#include "../../header/Gameplay/GameplayService.h"
#include "../../header/Gameplay/GameplayController.h"

namespace Gameplay {
	GameplayService::GameplayService()
	{
		gameplayController = new GameplayController();
	}
	GameplayService::~GameplayService()
	{
		delete(gameplayController);
	}
	void GameplayService::initialize()
	{
		gameplayController->initialize();
	}
	void GameplayService::update()
	{
		gameplayController->update();
	}
	void GameplayService::render()
	{
		gameplayController->render();
	}
	void GameplayService::startGame()
	{
		gameplayController->reset();
	}
}