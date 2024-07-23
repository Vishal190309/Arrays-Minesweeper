#include "../../header/UI/Gameplay/GaameplayUIController.h"
#include "../../header/Global/ServiceLocator.h"
#include <iostream>
#include <sstream>
#include<string>
#include <iomanip> 

namespace UI {
    namespace Gameplay {
        using namespace UI::UIElement;
        GameplayUIController::GameplayUIController()
        {
            createTexts();
        }

        GameplayUIController::~GameplayUIController()
        {
        }

        void GameplayUIController::createTexts()
        {
            time_text = new TextView();
        }

        void GameplayUIController::initialize()
        {
            initializeTexts();
        }

        void GameplayUIController::initializeTexts()
        {
            initializeTimeText();
        }

        void GameplayUIController::initializeTimeText()
        {
            time_text->initialize("000", sf::Vector2f(time_text_left_offset, time_text_top_offset), FontType::ROBOTO, font_size, text_color);
        }

        void GameplayUIController::update()
        {
            updateTimeText();
        }

        void GameplayUIController::render()
        {
            time_text->render();
        }

        void GameplayUIController::updateTimeText()
        {
            int remaining_time = Global::ServiceLocator::getInstance()->getGameplayService()->getRemainingTime();

            std::stringstream stream;
            stream << std::setw(3) << std::setfill('0') << remaining_time;
            std::string string_remaining_time = stream.str();

            time_text->setText(string_remaining_time);
            time_text->update();
        }

        void GameplayUIController::show()
        {
            time_text->show();
        }
    }
}