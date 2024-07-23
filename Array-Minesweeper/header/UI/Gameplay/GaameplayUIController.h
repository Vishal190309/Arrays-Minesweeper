#pragma once
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/TextView.h"
#include <SFML/Graphics/Color.hpp>
namespace UI {
	namespace Gameplay {
		class GameplayUIController : public Interface::IUIController {

		private:
			const int font_size = 110;
			const sf::Color text_color = sf::Color::Red;

			const float time_text_top_offset = 65.f;
			const float time_text_left_offset = 1090.f;

			UIElement::TextView* time_text;

			void createTexts();
			void initializeTexts();
			void initializeTimeText();
		public:
			GameplayUIController();
			~GameplayUIController();

			void initialize() override;
			void update() override;
			void render() override;

			void updateTimeText();

			void show();
		};
	}
}