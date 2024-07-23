#pragma once

namespace Gameplay {
	class GameplayController {
	private:
		const float max_duration = 300.f;
		float remaining_time;
	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		void updateRemainingTime();

		float getRemainingTime();

		void reset();
	};
	
}