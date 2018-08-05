#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <map>

class Timer
{
private:
	typedef std::chrono::high_resolution_clock clock;
	static clock clk;
	clock::time_point start;

public:
	using ns = std::chrono::nanoseconds;
	using us = std::chrono::microseconds;
	using ms = std::chrono::milliseconds;
	using s = std::chrono::seconds;

	Timer() noexcept;
	template<class T> T elapsed() const noexcept
	{
		return std::chrono::duration_cast<T>(clk.now() - start);
	}
};

#endif
