#include "World.h"

World::World()
{
    m_running = true;
}

World::~World()
{

}

void World::init()
{
    m_presenter.init();
}

void World::run()
{
    m_presenter.draw();
    m_inputManager.handleInput();
}

void World::destroy()
{
    SDL_DestroyWindow(m_presenter.m_mainWindow);
    SDL_DestroyRenderer(m_presenter.m_mainRenderer);

    m_inputManager.m_keyboardState = NULL;
}

bool World::isRunning()
{
    return m_running;
}
