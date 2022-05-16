#include "application.h"
#include "component.h"
#include "drawable.h"
#include <iostream>
#include <SFML/Graphics.hpp>

#include <Components/renderer2D.h>

#include "Classes/area2d.h"
#include "Classes/character.h"
#include "Components/movement_component.h"

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
	for (auto item : allEntities)
	{
		if (item->is_active && item->tick_enabled()) item->on_fixed_update(elapsedTime);
	}
}

void Application::initialize()
{
	auto background = new gfl::Sprite();
	background->renderer->set_texture_source("res/textures/background.png", true, true);
	background->rect_transform->set_scale(1920, 1080);
	allEntities.push_back(background);

	/*const auto player = new Sprite();
	player->renderer->set_texture_source("res/textures/player.png", true, false);
	player->rect_transform->set_scale(64, 64);
	player->rect_transform->set_position(960 - 32, 540 - 32);
	player->add_component(new Controller());
	player->add_component(new MovementComponent());
	allEntities.push_back(player);*/

	const auto player = new gfl::Character();
	player->renderer->set_texture_source("res/textures/player.png", true, false);
	player->rect_transform->set_scale(64, 64);
	player->rect_transform->set_position(960 - 32, 540 - 32);
	allEntities.push_back(player);
}

void Application::processInput()
{
		/*for each (auto actor in allEntities)
		{
			auto controllers = actor->get_components<Controller>();

			if (controllers.size() == 0) continue;

			for each (auto controller in controllers)
			{
				sf::Keyboard::Key key1;
				sf::Keyboard::Key key2;

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					key1 = sf::Keyboard::Up;
				}
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					key1 = sf::Keyboard::Down;
				}
				else
				{
					key1 = sf::Keyboard::Unknown;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					key2 = sf::Keyboard::Left;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					key2 = sf::Keyboard::Left;
				}
				else
				{
					key2 = sf::Keyboard::Unknown;
				}

				sf::Keyboard::Key inputs[] = { key1, key2 };
				controller->on_input(inputs);

			}
		}*/
}

void Application::update()
{
	for (GameObject* item : allEntities)
	{
		if (item->is_active && item->tick_enabled()) item->on_update(elapsedTime);
	}
}

void Application::draw()
{
	mWindow->clear(backgroundColor);
	
	for each (auto item in allEntities)
	{
		const auto renders = item->get_components<RectTransform>();

		for each(auto rend in renders)
		{
			mWindow->draw(*rend->get_transform());
		}
	}

	mWindow->display();
}