#pragma once
#include <vector>
#include "../../include/Element/Obstacle.h";
#include "../../include/Element/ElementData.h";

using namespace std;

namespace Element
{
	class ElementService
	{
	private:
		vector<Obstacle*> obstale_list;

		void destroy();

	public :
		ElementService();
		~ElementService();

		void initialize();
		void update();
		void render();

		void spawnObstacle(Vector2i position, float width, float heoght);

		const void spawnElement(vector <ElementData>& element_data_list, float width, float heoght);
	};
}