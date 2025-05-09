#include "../../include/Level/LevelService.h"
#include "../../include/Level/LevelController.h"
#include "../../include/Global/ServiceLocator.h"

using namespace Global;

namespace Level
{
    

    LevelService::LevelService()
    {
        level_controller = nullptr;
        createLevelController();
    }

    LevelService::~LevelService()
    {
        destroy();
    }

    void LevelService::initialize()
    {
        level_controller->initialize();
    }

    void LevelService::update()
    {
        level_controller->update();
    }

    void LevelService::render()
    {
        level_controller->render();
    }

    void LevelService::createLevelController()
    {
        level_controller = new LevelController();

    }

    void LevelService::createLevel(LinkedListType list_type)
    {
        spawnLevelElements(current_level);
        spawnPlayer(list_type);
        spawnFood();
    }


 /*   void LevelService::createLevel(LevelNumber level_to_load)
    {
        current_level = level_to_load;
        spawnLevelElements(level_to_load);
        spawnPlayer();
        spawnFood();
    }*/

    void LevelService::spawnPlayer(LinkedListType list_type)
    {
        ServiceLocator::getInstance()->getPlayerService()->spawnPlayer(list_type);
    }

    float LevelService::getCellWidth()
    {
        return level_controller->getCellWidth();
    }

    float LevelService::getCellHeight()
    {
        return level_controller->getCellHeight();
    }

    void LevelService::spawnFood()
    {
        ServiceLocator::getInstance()->getFoodService()->startFoodSpawning();
    }

    void LevelService::spawnLevelElements(LevelNumber level_to_load)
    {
        float cell_width = level_controller->getCellWidth();
        float cell_height = level_controller->getCellHeight();

        vector<ElementData> element_data_list = level_controller->getElementDataList(static_cast<int>(level_to_load));

        ServiceLocator::getInstance()->getElementService()->spawnElement(element_data_list,cell_width,cell_height);
    }

    int LevelService::getLevelNumber()
    {
        int number = static_cast<int>(current_level);
        return number;
    }

    void LevelService::setLevel(LevelNumber level_to_load)
    {
        current_level = level_to_load;
    }

    void LevelService::destroy()
    {
        delete(level_controller);
    }
}