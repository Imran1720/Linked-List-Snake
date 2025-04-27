#include "../../include/Element/ElementService.h"

namespace Element
{
	void ElementService::destroy()
	{
	}
	ElementService::ElementService() = default;
	ElementService::~ElementService() = default;
	
	void ElementService::initialize()
	{
	}
	void ElementService::update()
	{
		for (int i = 0; i < obstale_list.size(); i++)
		{
			obstale_list[i]->update();
		}
	}
	void ElementService::render()
	{
		for (int i = 0; i < obstale_list.size(); i++)
		{
			obstale_list[i]->render();
		}
	}
	void ElementService::spawnObstacle(Vector2i position, float width, float height)
	{
		Obstacle* obstacle = new Obstacle();
		obstacle->initialize(position, width, height);
		obstale_list.push_back(obstacle);
	}
	const void ElementService::spawnElement(vector<ElementData>& element_data_list, float width, float height)
	{
		for (int i = 0; i < element_data_list.size(); i++)
		{
			switch (element_data_list[i].element_type)
			{
			case ElementType::OBSTACLE:
				spawnObstacle(element_data_list[i].grid_position,width,height);
				break;
			}
		}
	}
}