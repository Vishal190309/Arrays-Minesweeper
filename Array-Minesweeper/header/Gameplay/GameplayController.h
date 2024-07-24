#pragma once

namespace Gameplay {

	enum class GameResult
	{
		NONE,
		WON,
		LOST
	};

	class GameplayController {
	private:
		const float max_duration = 300.f;
		const float game_over_time = 11.f;
		float remaining_time;
		GameResult game_result;

		void gameWon();
		void gameLost();
		void showCredits();
	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		bool isTimeOver();
		void render();

		void updateRemainingTime();

		float getRemainingTime();

		void beginGameOverTimer();

		void reset();
		void endGame(GameResult result);
		
	};
	
}