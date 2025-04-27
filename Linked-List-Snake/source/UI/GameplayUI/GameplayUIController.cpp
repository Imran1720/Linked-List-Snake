#pragma once
#include "../../include/UI/GameplayUI/GameplayUIController.h"
#include "../../include/Global/ServiceLocator.h"

using namespace Global;


namespace UI
{
	namespace GameplayUI
	{
		
		GameplayUIController::GameplayUIController()
		{
			createTexts();

		}

		GameplayUIController::~GameplayUIController()
		{
			destroy();
		}

		void GameplayUIController::destroy()
		{
			delete(level_number_text);
			delete(score_text);
		}

		void GameplayUIController::initialize()
		{
			initializeTexts();
		}

		void GameplayUIController::update()
		{
			updateLevelNumberText();
			updateScoreText();
			updateTimeComplexityText();
			updateOperationText();
		}

		void GameplayUIController::render()
		{
			level_number_text->render();
			score_text->render();
			time_complexity_text->render();
			operation_text->render();
		}

		void GameplayUIController::show()
		{
			level_number_text->show();
			score_text ->show();
			time_complexity_text ->show();
			operation_text->show();
		}

		void GameplayUIController::createTexts()
		{
			level_number_text = new TextView();
			score_text = new TextView();
			time_complexity_text = new TextView();
			operation_text = new TextView();
		}

		void GameplayUIController::initializeTexts()
		{
			initializeLevelNumberText();
			initializeScoreText();
			initializeTimeComplexityText();
			initializeOperationText();

		}

		void GameplayUIController::initializeLevelNumberText()
		{
			level_number_text->initialize("LEVEL : 1", Vector2f(level_number_text_x_position, text_y_position), 
				FontType::DS_DIGIB,
				font_size, text_color);
		}

		void GameplayUIController::initializeScoreText()
		{
			score_text->initialize("SCORE : 0", Vector2f(score_text_x_position, text_y_position),
				FontType::DS_DIGIB, font_size, text_color);
		}

		void GameplayUIController::initializeTimeComplexityText()
		{

			time_complexity_text->initialize("TIME COMPLEXITY : O(n)", Vector2f(operations_text_x_position, time_complexity_text_y_position),
				FontType::DS_DIGIB, operation_font_size, text_color);
		
		}

		void GameplayUIController::initializeOperationText()
		{
			
			operation_text->initialize("LAST OPERATION : INSERT AT HEAD", Vector2f(operations_text_x_position, operations_text_y_position),
				FontType::DS_DIGIB, operation_font_size, text_color);
		}

		void GameplayUIController::updateLevelNumberText()
		{
			int level_number = ServiceLocator::getInstance()->getLevelService()->getLevelNumber();

			sf::String level_number_value = std::to_string(1 + (level_number));
			level_number_text->setText("LEVEL : " + level_number_value);

			level_number_text->update();
		}

		void GameplayUIController::updateScoreText()
		{
			int score_number = ServiceLocator::getInstance()->getPlayerService()->getPlayerScore();

			sf::String level_score_value = std::to_string(score_number);
			score_text->setText("SCORE : "+level_score_value);

			score_text->update();
		}

		void GameplayUIController::updateTimeComplexityText()
		{
			TimeComplexity time_complexity = ServiceLocator::getInstance()->getPlayerService()->getTimeComplexity();
			String time_complexity_value;

			switch (time_complexity)
			{
			case TimeComplexity::NONE:
				time_complexity_value = "";
				break;
			case TimeComplexity::ONE:
				time_complexity_value = "O(1)";
				break;
			case TimeComplexity::N:
				time_complexity_value = "O(N)";
				break;
			default:
				break;
			}

			time_complexity_text->setText("TIME COMPLEXITY : " + time_complexity_value);

			time_complexity_text->update();
		}

		void GameplayUIController::updateOperationText()
		{
			LinkedListOperations operation = ServiceLocator::getInstance()->getPlayerService()->getLastOperation();
			String operation_value;
			switch (operation)
			{
			case LinkedListOperations::NONE:
				operation_value = "";
				break;
			case LinkedListOperations::INSERT_AT_HEAD:
				operation_value = "INSERT_AT_HEAD";
				break;
			case LinkedListOperations::INSERT_AT_TAIL:
				operation_value = "INSERT_AT_TAIL";
				break;
			case LinkedListOperations::INSERT_AT_MID:
				operation_value = "INSERT_AT_MID";
				break;
			case LinkedListOperations::REMOVE_AT_HEAD:
				operation_value = "REMOVE_AT_HEAD";
				break;
			case LinkedListOperations::REMOVE_AT_TAIL:
				operation_value = "REMOVE_AT_TAIL";
				break;
			case LinkedListOperations::REMOVE_AT_MID:
				operation_value = "REMOVE_AT_MID";
				break;
			case LinkedListOperations::DELETE_HALF_LIST:
				operation_value = "DELETE_HALF_LIST";
				break;
			case LinkedListOperations::REVERSE_LIST:
				operation_value = "REVERSE_LIST";
				break;
			}

			operation_text->setText("TIME COMPLEXITY : " + operation_value);

			operation_text->update();
		}
		
	}
}