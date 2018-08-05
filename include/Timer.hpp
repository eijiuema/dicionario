#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <map>

class Timer
{
private:
	typedef std::chrono::high_resolution_clock clock;
	static std::map<std::string, clock::time_point> timers;
	static clock clk;

public:
	using ns = std::chrono::nanoseconds;
	using us = std::chrono::microseconds;
	using ms = std::chrono::milliseconds;
	using s = std::chrono::seconds;

	static void start(const std::string &id) noexcept;
	template<class T> T static elapsed(const std::string &id) noexcept
	{
		return std::chrono::duration_cast<T>(clk.now() - timers[id]);
	}
};

#endif
