#include "time_manager.h"

TimeManager::TimeManager(){}

TimeManager::~TimeManager(){}

sf::Time TimeManager::getCurrentTime()const
{
	return clock.getElapsedTime();
}

float TimeManager::calculateElapsedTime(const float currentTime, const float lastTime)
{
	return currentTime - lastTime;
}
