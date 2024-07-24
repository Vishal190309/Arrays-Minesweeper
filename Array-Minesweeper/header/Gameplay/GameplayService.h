#pragma once
namespace Gameplay {
	class GameplayController;
	enum class GameResult;
	class GameplayService {
	private:
		GameplayController* gameplay_controller;
	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();
		int getMinesCount();
		void startGame();
		void endGame(GameResult result);
		float getRemainingTime();
	};
}