#pragma once
#include "UI/UIElement/TextView.h"
#include "UI/Interface/IUIController.h"
#include <SFML/Graphics.hpp>

using namespace UI::UIElement;
using namespace UI::Interface;
using namespace sf;

namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController : public IUIController
		{
		private:
			TextView* score_text;
			TextView* level_number_text;
			TextView* time_complexity_text;
			TextView* operation_text;

			const float font_size = 60.f;
			const float operation_font_size = 30.f;

			const float operations_text_x_position = 1330.f;
			const float time_complexity_text_y_position = 45.f;
			const float operations_text_y_position = 10.f;

			const float text_y_position = 7.f;
			const float level_number_text_x_position = 65.f;
			const float score_text_x_position = 800.f;
			const Color text_color = Color::Black;

			void destroy();
		public:
			GameplayUIController();
			~GameplayUIController();

			// Inherited via IUIController
			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

			void createTexts();

			void initializeTexts();
			void initializeLevelNumberText();
			void initializeScoreText();
			void initializeTimeComplexityText();
			void initializeOperationText();

			void updateLevelNumberText();
			void updateScoreText();
			void updateTimeComplexityText();
			void updateOperationText();

		};
	}
}