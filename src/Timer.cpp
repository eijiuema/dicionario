#include "Timer.hpp"

Timer::Timer() noexcept
{
	start = Timer::clk.now();
}
