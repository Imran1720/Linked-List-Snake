#pragma once
#include "Graphics/GraphicService.h"
#include "Event/EventService.h"
#include "UI/UIService.h"
#include "Sound/SoundService.h"
#include "Time/TimeService.h"
#include "Level/LevelService.h"
#include "Player/PlayerService.h"

using namespace Graphics;
using namespace UI;
using namespace Level;
using namespace Event;
using namespace Sound;
using namespace Time;
using namespace Player;


namespace Global
{
    class ServiceLocator
    {
    private:
        EventService* event_service;
        GraphicService* graphic_service;
        SoundService* sound_service;
        UIService* ui_service;
        TimeService* time_service;
        LevelService* level_service;
        PlayerService* player_service;

        ServiceLocator();
        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        EventService* getEventService();
        GraphicService* getGraphicService();
        SoundService* getSoundService();
        UIService* getUIService();
        TimeService* getTimeService();
        LevelService* getLevelService();
        PlayerService* getPlayerService();
        void deleteServiceLocator();
    };
}