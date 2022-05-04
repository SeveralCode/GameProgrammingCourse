#include "application.h"
#include "game_object.h"

int main()
{

    Application* app = new Application();
    app->createWindow(1920, 1080, "My Awesome Game");
    app->setMaxFPS(60);
    app->enableFPSLimit();
    app->disableFixedUpdate();
    app->run();

    return 0;
}