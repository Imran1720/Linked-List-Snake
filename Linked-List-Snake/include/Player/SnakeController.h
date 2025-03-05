#pragma once

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

		const int initial_snake_length = 10;
		SnakeState current_snake_state;

		void processSnakeBehaviour();
		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void handleRestart();

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