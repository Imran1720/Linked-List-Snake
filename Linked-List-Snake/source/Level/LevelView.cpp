#include "../../include/Level/LevelView.h"
#include "../../include/Level/LevelController.h"

#include "../../include/Global/Config.h"
#include "../../include/Global/ServiceLocator.h"

using namespace Global;


namespace Level
{
    
    LevelView::LevelView(LevelController* controller)
    {
        level_controller = controller;
        createViews();
    }

    LevelView::~LevelView()
    {
    }

    void LevelView::initialize()
    {
        initializeBackground();
        calculateGridExtents();
        initializeBorder();
    }

    void LevelView::update()
    {
    }

    void LevelView::render()
    {
    }

    float LevelView::getGridWidth()
    {
        return grid_width;
    }

    float LevelView::getGridHeight()
    {
        return grid_height;
    }

    void LevelView::calculateGridExtents()
    {
        RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

        grid_width = game_window->getSize().x - 2 * border_offset_left;
        grid_height = game_window->getSize().y - 2 * border_offset_top;
    }

    void LevelView::initializeBackground()
    {
        RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

        Vector2f background_size = Vector2f(game_window->getSize().x, game_window->getSize().y);

        background_rectangle->initialize(background_size, Vector2f(0, 0), 0, background_color);
        background_rectangle->show();
    }

    void LevelView::initializeBorder()
    {

        border_rectangle->initialize(Vector2f(grid_width,grid_height),Vector2f(0,0),border_thickness,Color::Transparent,border_color);
        border_rectangle->show();
    }

    void LevelView::createViews()
    {
        background_rectangle = new RectangleShapeView();
        border_rectangle = new RectangleShapeView();
    }

    void LevelView::destroy()
    {
        delete(level_controller);
    }


}
