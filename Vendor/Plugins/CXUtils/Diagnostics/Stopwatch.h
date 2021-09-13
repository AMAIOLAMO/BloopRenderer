#pragma once

#include <chrono>

namespace CXUtils
{
	/// <summary>
	///		A class that is used as a elapsed time checker
	/// </summary>
	class Stopwatch
	{
	private:
		std::chrono::steady_clock::time_point _start;

	public:
		void Start();

		std::chrono::duration<double> Stop();
	};
}


