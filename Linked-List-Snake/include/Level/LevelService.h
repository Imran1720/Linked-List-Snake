#pragma once
#include "Level/LevelConfig.h"

namespace Level
{
	class LevelController;
	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelNumber current_level;

		void destroy();
	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		void createLevelController();
		//void createLevel(LevelNumber level_to_load);
		void createLevel(LinkedListType list_type);

		void spawnPlayer(LinkedListType list_type);

		float getCellWidth();
		float getCellHeight();

		void spawnFood();
		void spawnLevelElements(LevelNumber level_to_load);

		int getLevelNumber();
		void setLevel(LevelNumber level_to_load);
	};
}