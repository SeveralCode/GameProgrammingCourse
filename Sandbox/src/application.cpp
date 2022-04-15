#include "application.h"
#include <iostream>

Application::~Application()
{
	delete mWindow;
}

void Application::createWindow(const float windowWidth, const float windowHeight, const char* title)
{
	mWindow = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), title);
	if (!mWindow)
	{
		std::cerr << "Application window initialization failed!\n";
		return;
	}
}

bool Application::isRunning()const { return mWindow->isOpen();}

unsigned Application::getFrameRate()const { return 1 / elapsedTime; }

void Application::setMaxFPS(const unsigned limit)
{
	maxFPS = limit;
}
void Application::enableFPSLimit() { fpsLimitEnabled = true; }
void Application::disableFPSLimit() { fpsLimitEnabled = false; }

void Application::enableFixedUpdate() { fixedUpdateEnabled = true; }
void Application::disableFixedUpdate() { fixedUpdateEnabled = false; }
void Application::setMillisecondsForFixedUpdate(const float milliseconds) { msForFixedUpdate = milliseconds; }

void Application::setBackgroundColor(const sf::Color color) { backgroundColor = color; }
void Application::setBackgroundColor(const float red, const float green, const float blue, const float alpha) { backgroundColor = sf::Color(red, green, blue, alpha); }

void Application::run()
{
	lastTime = tm.getCurrentTime();
	while (mWindow->isOpen())
	{
		updateGameTime();
		std::cout << "FPS: " << getFrameRate() << std::endl;
		processWindowEvents();
		processInput();
		if (fixedUpdateEnabled)
		{
			while (lag < msForFixedUpdate)
			{
				fixedUpdate();
				lag -= msForFixedUpdate;
			}
		}
		update();
		draw();
		if (fpsLimitEnabled)
		{
			sf::sleep(sf::seconds((1.0f / maxFPS)));
		}
	}
}

void Application::updateGameTime()
{
	currentTime = tm.getCurrentTime();
	elapsedTime = TimeManager::calculateElapsedTime(currentTime.asSeconds(), lastTime.asSeconds());
	lag += elapsedTime;
	lastTime = currentTime;
}

void Application::processWindowEvents()
{
	sf::Event evt{};
	while (mWindow->pollEvent(evt))
	{
		if (evt.type == sf::Event::EventType::Closed)
		{
			mWindow->close();
		}
	}
}

void Application::fixedUpdate()
{
}

void Application::processInput(){}

void Application::update()
{
	// TODO: update game componentes
}

void Application::draw()
{
	mWindow->clear(backgroundColor);

	mWindow->display();
}