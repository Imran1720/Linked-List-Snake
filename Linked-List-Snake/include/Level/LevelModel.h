#pragma once
#include <vector>
#include "Level/LevelData.h"
#include "Element/ElementData.h"

using namespace std;

namespace Level
{

	class LevelModel
	{
	private:

		//level data
		vector<LevelData> level_configurations;
		vector<ElementData> level_1_element_list;
		vector<ElementData> level_2_element_list;
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