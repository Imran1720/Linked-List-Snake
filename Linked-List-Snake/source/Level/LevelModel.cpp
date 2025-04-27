#include "../../include/Level/LevelModel.h"

namespace Level
{
   
    LevelModel::LevelModel()
    {
    }

    LevelModel::~LevelModel()
    {
    }

    void LevelModel::initialize(int width,int height)
    {
        cell_width = width / number_of_columns;
        cell_height = height / number_of_rows;
    }

    void LevelModel::update()
    {
    }

    void LevelModel::render()
    {
    }

    float LevelModel::getCellWidth()
    {
        return cell_width;
    }

    float LevelModel::getCellHeight()
    {
        return cell_height;
    }

    void LevelModel::destroy()
    {

    }
}