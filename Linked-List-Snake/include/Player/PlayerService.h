#pragma once

namespace Player
{
	class SnakeController;
	class PlayerService
	{
	private:
		SnakeController* snake_controller;

		void destroy();

	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

		void createController();
		void spawnPlayer();

	};
}