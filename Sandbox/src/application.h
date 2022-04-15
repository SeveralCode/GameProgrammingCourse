#ifndef APPLICATION_H
#define APPLICATION_H

#include "time_manager.h"
#include <SFML/Graphics.hpp>

class Application
{
public:
	Application() : mWindow(nullptr), 
		maxFPS(0), 
		fpsLimitEnabled(false),
		backgroundColor(sf::Color::Black) {}
	~Application();
	
	/// <summary>
	/// Creates application window
	/// </summary>
	/// <param name="windowWidth">the window width</param>
	/// <param name="windowHeight">the window height</param>
	/// <param name="windowTitle">window main title</param>
	void createWindow(float windowWidth, float windowHeight, const char* windowTitle);

	/// <summary>
	/// Get TRUE if the application should kill itself.
	/// </summary>
	/// <returns> TRUE or FALSE</returns>
	bool isRunning()const;

	/// <summary>
	/// Executes application lifecycle.
	/// </summary>
	void run();

	/// <summary>
	/// Calculate the total frames in one seconds by elapsed time
	/// </summary>
	/// <returns>total frames</returns>
	unsigned getFrameRate()const;

	/// <summary>
	/// limit frame per seconds to a constant value (e.g. 60)
	/// </summary>
	/// <param name="limit"></param>
	void setMaxFPS(unsigned limit);

	/// <summary>
	/// Enabled the FPS limit
	/// </summary>
	void enableFPSLimit();

	/// <summary>
	/// Disable the FPS limit (enable infinite frames per second)
	/// </summary>
	void disableFPSLimit();

	/// <summary>
	/// Enable fixed update
	/// </summary>
	void enableFixedUpdate();

	/// <summary>
	/// Disable fixed update
	/// </summary>
	void disableFixedUpdate();

	/// <summary>
	/// Set the number of milliseconds for fixed update
	/// </summary>
	/// <param name="milliseconds">fixed update frequency - i.e. 0.016</param>
	void setMillisecondsForFixedUpdate(float milliseconds);

	void setBackgroundColor(sf::Color color);
	void setBackgroundColor(float red, float green, float blue, float alpha);

private:
	void processInput();
	void draw();
	void processWindowEvents();
	void fixedUpdate();
	void update();
	void updateGameTime();

private:
	sf::RenderWindow* mWindow;
	TimeManager tm;
	sf::Time lastTime, currentTime;
	float elapsedTime;
	float lag;
	unsigned maxFPS;
	bool fpsLimitEnabled;
	bool fixedUpdateEnabled;
	float msForFixedUpdate;
	sf::Color backgroundColor;

};

#endif