#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "../../include/Level/LevelConfig.h"

using namespace Level;
using namespace sf;
using namespace std;
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
		void spawnPlayer(LinkedListType list_type);
		vector<Vector2i> getSnakePositionList();
		int getPlayerScore();

		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();

	};
}