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


    void LevelService::createLevel(LevelNumber level_to_load)
    {
        current_level = level_to_load;
        spawnPlayer();
    }

    void LevelService::spawnPlayer()
    {
        ServiceLocator::getInstance()->getPlayerService()->spawnPlayer();
    }

    float LevelService::getCellWidth()
    {
        return level_controller->getCellWidth();
    }

    float LevelService::getCellHeight()
    {
        return level_controller->getCellHeight();
    }

    void LevelService::destroy()
    {
        delete(level_controller);
    }
}