#pragma once
#include <SFML/Graphics.hpp>
#include "Player/Direction.h"
#include "LinkedList/SingleLinkedList.h"

using namespace LinkedList;
using namespace sf;

namespace Player
{
	enum class SnakeState
	{
		ALIVE,
		DEAD
	};

	

	class SnakeController
	{
	private:

		const Vector2i default_position = Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;
		Direction current_direction;

		const int initial_snake_length = 10;
		SnakeState current_snake_state;

		SingleLinkedList* single_linked_list;

		void processSnakeBehaviour();
		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void handleRestart();

		void createLinkedList();
		void destroy();

	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();

		void reset();
		void respawnSnake();
		void spawnSnake();

		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();

	};
}