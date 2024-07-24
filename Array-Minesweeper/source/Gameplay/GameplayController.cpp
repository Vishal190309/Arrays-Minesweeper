#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"
#include "../../header/Gameplay/Board/BoardController.h"

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
		if (isTimeOver())
		endGame(GameResult::LOST);

	}

	bool GameplayController::isTimeOver() { return (remaining_time <= 1); }

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

	void GameplayController::beginGameOverTimer() 
	{ 
		remaining_time = game_over_time; 
	}
	void GameplayController::reset()
	{
		game_result = GameResult::NONE;
		remaining_time = max_duration;
		Global::ServiceLocator::getInstance()->getBoardService()->resetBoard();
	}

	void GameplayController::endGame(GameResult result)
	{
		// The switch statement handles the different possible outcomes of the game.
		switch (result)
		{
			// In case the game is won, the gameWon() method is called.
		case GameResult::WON:
			gameWon();
			break;
			// In case the game is lost, the gameLost() method is called.
		case GameResult::LOST:
			gameLost();
			break;
			// The default case is not used here as all possible game outcomes should be WON or LOST.
		default:
			// No action is needed for default case.
			break;
		}
	}

	void GameplayController::gameWon()
	{
		game_result = GameResult::WON;
		beginGameOverTimer();
		Global::ServiceLocator::getInstance()->getBoardService()->flagAllMines();
		Global::ServiceLocator::getInstance()->getBoardService()->setBoardState(Board::BoardState::COMPLETED);
		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::GAME_WON);
	}

	void GameplayController::gameLost()
	{
		if (game_result == GameResult::NONE)
		{
			game_result = GameResult::LOST;
			beginGameOverTimer();
			Global::ServiceLocator::getInstance()->getBoardService()->showBoard();
			Global::ServiceLocator::getInstance()->getBoardService()->setBoardState(Board::BoardState::COMPLETED);
		}
		else
		{
			showCredits();
		}

	}

	void GameplayController::showCredits() { Main::GameService::setGameState(Main::GameState::CREDITS); }

}