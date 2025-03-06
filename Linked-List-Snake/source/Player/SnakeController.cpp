#include "../../include/Player/SnakeController.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Event/EventService.h"

#include <iostream>
using namespace std;


using namespace Global;
using namespace Event;

namespace Player
{
	SnakeController::SnakeController()
	{
		single_linked_list = nullptr;
		current_direction = default_direction;
		createLinkedList();
	}

	SnakeController::~SnakeController()
	{
		destroy();
	}

	void SnakeController::initialize()
	{
		float width = ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		float height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		single_linked_list->initialize(width,height,default_position,default_direction);
	}

	void SnakeController::update()
	{
		if (current_snake_state == SnakeState::ALIVE)
		{
			processSnakeBehaviour();
		}
		else
		{
			handleRestart();
		}
	}

	void SnakeController::render()
	{
		single_linked_list->render();
	}

	void SnakeController::reset()
	{
	}

	void SnakeController::respawnSnake()
	{
	}

	void SnakeController::spawnSnake()
	{
		for (int i = 0; i < initial_snake_length; i++)
		{
			single_linked_list->insertNodeAtTail();
		}
	}

	void SnakeController::setSnakeState(SnakeState state)
	{
		current_snake_state = state;
	}

	SnakeState SnakeController::getSnakeState()
	{
		return current_snake_state;
	}

	void SnakeController::delayUpdate()
	{
		elapsed_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (elapsed_duration >= movement_frame_duration)
		{
			elapsed_duration = 0.f;
			updateSnakeDirection();
			//processSnakeCollision();
			moveSnake();
		}
	}

	
	void SnakeController::processSnakeBehaviour()
	{
		processPlayerInput();
		delayUpdate();

	}

	void SnakeController::processPlayerInput()
	{
		EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedUpArrowKey() && current_direction!=Direction::DOWN)
		{
			current_direction = Direction::UP;
		}
		else if (event_service->pressedDownArrowKey() && current_direction != Direction::UP)
		{
			current_direction = Direction::DOWN;

		}
		else if (event_service->pressedLeftArrowKey() && current_direction != Direction::RIGHT)
		{
			current_direction = Direction::LEFT;

		}
		else if (event_service->pressedRightArrowKey() && current_direction != Direction::LEFT)
		{
			current_direction = Direction::RIGHT;

		}

	}

	void SnakeController::updateSnakeDirection()
	{
		single_linked_list->updateNodeDirection(current_direction);
	}

	void SnakeController::moveSnake()
	{
		single_linked_list->updateNodePosition();
	}

	void SnakeController::processSnakeCollision()
	{
	}

	void SnakeController::handleRestart()
	{
	}

	void SnakeController::createLinkedList()
	{
		single_linked_list = new SingleLinkedList();
	}

	void SnakeController::destroy()
	{
		delete(single_linked_list);
	}

}