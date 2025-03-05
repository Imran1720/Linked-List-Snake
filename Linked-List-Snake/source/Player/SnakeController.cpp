#include "../../include/Player/SnakeController.h"

namespace Player
{
	SnakeController::SnakeController()
	{
	}

	SnakeController::~SnakeController()
	{
		destroy();
	}

	void SnakeController::initialize()
	{
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
	}

	void SnakeController::spawnSnake()
	{
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

	void SnakeController::destroy()
	{
	}

}