#pragma once
namespace Gameplay {
	class GameplayController;
	class GameplayService {
	private:
		GameplayController* gameplayController;
	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();

		void startGame();
	};
}