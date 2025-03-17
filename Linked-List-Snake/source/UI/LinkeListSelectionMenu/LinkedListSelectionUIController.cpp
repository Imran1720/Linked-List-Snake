#include "../../include/UI/LinkeListSelectionMenu/LinkedListSelectionUIController.h"
#include "../../include/Main/GameService.h"
#include "../../include/Global/Config.h"
#include "../../include/Global/ServiceLocator.h"
#include "SFML/Graphics.hpp"
namespace UI
{
	namespace LinkeListSelection
	{
		using namespace Main;
		using namespace Global;
		using namespace sf;

		LinkedListSelectionUIController::LinkedListSelectionUIController()
		{
			createImage();
			createButtons();
		}

		LinkedListSelectionUIController::~LinkedListSelectionUIController()
		{
			destroy();
		}

		void LinkedListSelectionUIController::initialize()
		{
			initializeBackgroundImage();
			initializeButtons();
			registerButtonCallback();
		}

		void LinkedListSelectionUIController::update()
		{
			background_image->update();
			updateButtons();
		}

		void LinkedListSelectionUIController::render()
		{
			if (GameService::getGameState() == GameState::LINKED_LIST_SELECTION)
			{
				background_image->render();
				renderButtons();
			}
		}

		void LinkedListSelectionUIController::show()
		{
			background_image->show();
			single_linked_list_button->show();
			double_linked_list_button->show();
			menu_button->show();
		}

		void LinkedListSelectionUIController::createImage()
		{
			background_image = new ImageView();
		}

		void LinkedListSelectionUIController::createButtons()
		{
			single_linked_list_button = new ButtonView();
			double_linked_list_button = new ButtonView();
			menu_button = new ButtonView();
		}

		void LinkedListSelectionUIController::initializeBackgroundImage()
		{
			RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			background_image->initialize(Config::background_texture_path,game_window->getSize().x,game_window->getSize().y,
				Vector2f(0,0));

			background_image->setImageAlpha(background_alpha);
		}

		void LinkedListSelectionUIController::initializeButtons()
		{
			single_linked_list_button->initialize("SINGLE_LINKED_LIST_BUTTON",
				Config::single_linked_list_button_texture_path,
				button_width, button_height,
				Vector2f(0, single_linked_list_button_y_position));

			double_linked_list_button->initialize("DOUBLE_LINKED_LIST_BUTTON",
				Config::double_linked_list_button_texture_path,
				button_width, button_height,
				Vector2f(0, double_linked_list_button_y_position));

			menu_button->initialize("MENU_BUTTON",
				Config::menu_button_texture_path,
				button_width, button_height,
				Vector2f(0, menu_button_y_position));

			single_linked_list_button->setCentreAlinged();
			double_linked_list_button->setCentreAlinged();
			menu_button->setCentreAlinged();

		}


		void LinkedListSelectionUIController::updateButtons()
		{
			single_linked_list_button->update();
			double_linked_list_button->update();
			menu_button->update();
		}

		void LinkedListSelectionUIController::renderButtons()
		{
				single_linked_list_button->render();
				double_linked_list_button->render();
				menu_button->render();
		}

		void LinkedListSelectionUIController::registerButtonCallback()
		{
			single_linked_list_button->registerCallbackFuntion(std::bind(&LinkedListSelectionUIController::singleLinkedListCallback, this));
			double_linked_list_button->registerCallbackFuntion(std::bind(&LinkedListSelectionUIController::doubkeLinkedListCallback, this));
			menu_button->registerCallbackFuntion(std::bind(&LinkedListSelectionUIController::menuCallback, this));
		}

		void LinkedListSelectionUIController::singleLinkedListCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			ServiceLocator::getInstance()->getLevelService()->createLevel(LinkedListType::SINGLE_LINKED_LIST);
			GameService::setGameState(GameState::GAMEPLAY);
		}

		void LinkedListSelectionUIController::doubkeLinkedListCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			ServiceLocator::getInstance()->getLevelService()->createLevel(LinkedListType::DOUBLE_LINKED_LIST);
			GameService::setGameState(GameState::GAMEPLAY);
		}

		void LinkedListSelectionUIController::menuCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::MAIN_MENU);
		}

		void LinkedListSelectionUIController::destroy()
		{
			delete background_image;
			delete single_linked_list_button;
			delete double_linked_list_button;
			delete menu_button;
		}

	

	}
}