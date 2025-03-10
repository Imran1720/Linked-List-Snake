#include "../../include/Food/FoodService.h"
#include "../../include/Global/ServiceLocator.h"
#include "SFML/Graphics.hpp"
using namespace Global;
using namespace sf;

namespace Food
{
	
	FoodService::FoodService()
	{
		current_food_item = nullptr;

	}
	FoodService::~FoodService()
	{
		destroyFood();
	}
	void FoodService::initialize()
	{
	}
	void FoodService::update()
	{
		if (current_food_item)
		{
			current_food_item->update();

		}
	}
	void FoodService::render()
	{
		if (current_food_item)
		{
		current_food_item->render();
		}
	}

	void FoodService::startFoodSpawning()
	{
		cell_width = ServiceLocator::getInstance()->getLevelService()->getCellWidth() ;
		cell_height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		spawnFood();
	}

	FoodItem* FoodService::createFoodItem(Vector2i position, FoodType type)
	{
		FoodItem* food_item = new FoodItem();
		food_item->initialize(position, cell_width, cell_height, type);

		return food_item;
	}

	void FoodService::spawnFood()
	{
		current_food_item = createFoodItem(Vector2i(14,13),FoodType::APPLE);

	}

	void FoodService::destroyFood()
	{
		if (current_food_item)
		{
		delete(current_food_item);
		}
	}
	void FoodService::reset()
	{
	}
}