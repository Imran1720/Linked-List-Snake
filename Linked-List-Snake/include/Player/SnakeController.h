#pragma once

namespace Player
{
	class SnakeController
	{
	private:
		void destroy();

	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();
	};
}