#include "Stopwatch.h"

using namespace std::chrono;

void CXUtils::Stopwatch::Start()
{
	_start = std::chrono::high_resolution_clock::now();
}

std::chrono::duration<double> CXUtils::Stopwatch::Stop()
{
	return std::chrono::high_resolution_clock::now() - _start;
}
