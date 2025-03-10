#pragma once
#include "../../include/Food/FoodItem.h"
#include <random>

using namespace std;

namespace Food
{
	class FoodService
	{
		private:
			FoodItem* current_food_item;
			float cell_width;
			float cell_height;
			
			default_random_engine random_engine;
			random_device new_random_device;

			FoodItem* createFoodItem(Vector2i position, FoodType type);
			Vector2i getRandomPosition();
			FoodType getRandomFoodType();
			void spawnFood();
			void destroyFood();
			void reset();

		public:
			FoodService();
			~FoodService();

			void initialize();
			void update();
			void render();

			void startFoodSpawning();
			bool isValidPosition(Vector2i random_position);


	};
}