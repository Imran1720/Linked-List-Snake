#pragma once
#include "UI/Interface/IUIController.h"
#include "UI/UIElement/ButtonView.h"
#include "UI/UIElement/ImageView.h"


namespace UI
{
	using namespace Interface;
	using namespace UIElement;

	namespace LinkeListSelection
	{
		class LinkedListSelectionUIController : public IUIController
		{
		private:
		private:
			//button
			const float button_width = 400.f;
			const float button_height = 140.f;

			//positions
			const float single_linked_list_button_y_position = 500.f;
			const float double_linked_list_button_y_position = 700.f;
			const float menu_button_y_position = 900.f;

			//alpha
			const float background_alpha = 85.f;

			//Button and background
			ImageView* background_image;

			ButtonView* single_linked_list_button;
			ButtonView* double_linked_list_button;
			ButtonView* menu_button;

			void createImage();
			void createButtons();
			void initializeBackgroundImage();
			void initializeButtons();

			void updateButtons();
			void renderButtons();

			void registerButtonCallback();
			void singleLinkedListCallback();
			void doubkeLinkedListCallback();
			void menuCallback();
			void destroy();
		public:

			LinkedListSelectionUIController();
			~LinkedListSelectionUIController();

		public:
			// Inherited via IUIController
			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}