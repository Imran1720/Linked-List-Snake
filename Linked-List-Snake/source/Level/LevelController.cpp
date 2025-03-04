#include "../../include/Level/LevelController.h"
#include "../../include/Level/LevelModel.h"
#include "../../include/Level/LevelView.h"

namespace Level
{
    
    LevelController::LevelController()
    {
        level_model = new LevelModel();
        level_view = new LevelView(this);
    }

    LevelController::~LevelController()
    {
        destroy();
    }

    void LevelController::initialize()
    {
        level_model->initialize();
        level_view->initialize();
    }

    void LevelController::update()
    {
        level_view->update();
    }

    void LevelController::render()
    {
        level_view->render();
    }

    void LevelController::destroy()
    {
        delete(level_model);
        delete(level_view);
    }

}