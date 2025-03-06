#include "../../include/Player/SnakeController.h"
#include "../../include/Global/ServiceLocator.h"

#include <iostream>
using namespace std;


using namespace Global;

namespace Player
{
	SnakeController::SnakeController()
	{
		single_linked_list = nullptr;

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
		single_linked_list->createHeadNode();
	}

	void SnakeController::setSnakeState(SnakeState state)
	{
		current_snake_state = state;
	}

	SnakeState SnakeController::getSnakeState()
	{
		return current_snake_state;
	}

	void SnakeController::processSnakeBehaviour()
	{
		processPlayerInput();
		updateSnakeDirection();
		processSnakeCollision();
		moveSnake();

	}

	void SnakeController::processPlayerInput()
	{
	}

	void SnakeController::updateSnakeDirection()
	{
	}

	void SnakeController::moveSnake()
	{
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