#pragma once
#include <vector>
#include "Level/LevelData.h"
#include "Element/ElementData.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
using namespace Element;

namespace Level
{

	class LevelModel
	{
	private:

		//level data
		vector<LevelData> level_configurations;
		vector<ElementData> level_1_element_list = {};
		vector<ElementData> level_2_element_list =
		{
			//top left
			ElementData(ElementType::OBSTACLE,Vector2i(1,1)),
			ElementData(ElementType::OBSTACLE,Vector2i(2,1)),
			ElementData(ElementType::OBSTACLE,Vector2i(3,1)),
			ElementData(ElementType::OBSTACLE,Vector2i(4,1)),
			ElementData(ElementType::OBSTACLE,Vector2i(1,2)),
			ElementData(ElementType::OBSTACLE,Vector2i(1,3)),
			ElementData(ElementType::OBSTACLE,Vector2i(1,4)),

			////top right
			ElementData(ElementType::OBSTACLE,Vector2i(1,49)),
			ElementData(ElementType::OBSTACLE,Vector2i(1,48)),
			ElementData(ElementType::OBSTACLE,Vector2i(1,47)),
			ElementData(ElementType::OBSTACLE,Vector2i(1,46)),
			ElementData(ElementType::OBSTACLE,Vector2i(2,49)),
			ElementData(ElementType::OBSTACLE,Vector2i(3,49)),
			ElementData(ElementType::OBSTACLE,Vector2i(4,49)),


			//middle top
			ElementData(ElementType::OBSTACLE,Vector2i(12,25)),
			ElementData(ElementType::OBSTACLE,Vector2i(12,24)),
			ElementData(ElementType::OBSTACLE,Vector2i(12,23)),
			ElementData(ElementType::OBSTACLE,Vector2i(12,22)),
			ElementData(ElementType::OBSTACLE,Vector2i(12,21)),
			ElementData(ElementType::OBSTACLE,Vector2i(12,20)),
			ElementData(ElementType::OBSTACLE,Vector2i(12,26)),
			ElementData(ElementType::OBSTACLE,Vector2i(12,27)),
			ElementData(ElementType::OBSTACLE,Vector2i(12,28)),
			ElementData(ElementType::OBSTACLE,Vector2i(12,29)),
			ElementData(ElementType::OBSTACLE,Vector2i(12,30)),

			////middle bottom
			ElementData(ElementType::OBSTACLE,Vector2i(16,25)),
			ElementData(ElementType::OBSTACLE,Vector2i(16,24)),
			ElementData(ElementType::OBSTACLE,Vector2i(16,23)),
			ElementData(ElementType::OBSTACLE,Vector2i(16,22)),
			ElementData(ElementType::OBSTACLE,Vector2i(16,21)),
			ElementData(ElementType::OBSTACLE,Vector2i(16,20)),
			ElementData(ElementType::OBSTACLE,Vector2i(16,26)),
			ElementData(ElementType::OBSTACLE,Vector2i(16,27)),
			ElementData(ElementType::OBSTACLE,Vector2i(16,28)),
			ElementData(ElementType::OBSTACLE,Vector2i(16,29)),
			ElementData(ElementType::OBSTACLE,Vector2i(16,30)),


			//bottom left
			ElementData(ElementType::OBSTACLE,Vector2i(26,1)),
			ElementData(ElementType::OBSTACLE,Vector2i(25,1)),
			ElementData(ElementType::OBSTACLE,Vector2i(24,1)),
			ElementData(ElementType::OBSTACLE,Vector2i(23,1)),
			ElementData(ElementType::OBSTACLE,Vector2i(26,2)),
			ElementData(ElementType::OBSTACLE,Vector2i(26,3)),
			ElementData(ElementType::OBSTACLE,Vector2i(26,4)),

			////bottom right
			ElementData(ElementType::OBSTACLE,Vector2i(26,49)),
			ElementData(ElementType::OBSTACLE,Vector2i(26,48)),
			ElementData(ElementType::OBSTACLE,Vector2i(26,47)),
			ElementData(ElementType::OBSTACLE,Vector2i(26,46)),
			ElementData(ElementType::OBSTACLE,Vector2i(25,49)),
			ElementData(ElementType::OBSTACLE,Vector2i(24,49)),
			ElementData(ElementType::OBSTACLE,Vector2i(23,49)),

		};
		//vector<LevelData> level_configurations;


		//cell data
		float cell_width;
		float cell_height;

		void initializeLevelData();
		void destroy();
	public:

		static const int number_of_rows = 28;
		static const int number_of_columns = 51;

		LevelModel();
		~LevelModel();

		void initialize(int width,int height);
		void update();
		void render();

		float getCellWidth();
		float getCellHeight();
		const vector<ElementData>& getElementDataList(int level_to_load);
	};
}