#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include <SFML/System.hpp>

struct TimeManager
{
public:
	TimeManager();
	virtual ~TimeManager();

	sf::Time getCurrentTime()const;

	static float calculateElapsedTime(float currentTime, float lastTime);

private:
	sf::Clock clock;
};

#endif