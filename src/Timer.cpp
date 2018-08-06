#include "Timer.hpp"

std::map<std::string, Timer::clock::time_point> Timer::timers;

void Timer::start(const std::string &id) noexcept
{
	timers[id] = clk.now();
}
