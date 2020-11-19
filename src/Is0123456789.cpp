#include <iostream>
#include <sstream>
#include <thread>

#define MAX_CHECK_VALUE INT64_MAX

#define SLOW 0
#define MEDIUM 1
#define FAST 2
#define SUPA_FAST 3
#define LIGHTNING 4
#define SPEED_MODE SLOW // Change this to SLOW, MEDIUM, FAST, SUPA_FAST, or LIGHTNING if you want to 

bool works(uint64_t num)
{
	std::string str;
	{
		std::stringstream ss;
		ss << num;
		str = ss.str();
	}

	uint8_t values[10] = {};

	for (char c : str)
		values[c - '0']++;

	bool works = true;
	for (size_t i = 0; i < 10; i++)
		if (values[i] != values[(i + 1) % 10])
			works = false;
	return works;
}

uint64_t powi(uint64_t num, uint64_t exp)
{
	uint64_t val = 1;
	for (uint64_t i = 0; i < exp; i++)
		val *= num;
	return val;
}

int main()
{
	std::stringstream msgs;

	uint64_t numPows = 0;
	uint64_t pow = 0;
	while (pow < MAX_CHECK_VALUE)
	{
		pow = powi(2, ++numPows);

		std::cout << msgs.str();
		std::cout << "/* * * * * */\nChecking " << pow << "...\n/* * * * * */\n";
		msgs << pow << ' ' << (works(pow) ? "Does" : "Doesn't") << " Work!\n";
		std::cout << pow << ' ' << (works(pow) ? "Does" : "Doesn't") << " Work!\n";
		
		using namespace std::chrono_literals;
#if SPEED_MODE == SLOW
		std::this_thread::sleep_for(1s);
#elif SPEED_MODE == MEDIUM
		std::this_thread::sleep_for(500ms);
#elif SPEED_MODE == FAST
		std::this_thread::sleep_for(250ms);
#elif SPEED_MODE == SUPA_FAST
		std::this_thread::sleep_for(100ms);
#elif SPEED_MODE == LIGHTNING
#else
#error Invalid Speed Mode!
#endif
		system("cls");
	}
	std::cout << msgs.str();

	std::cin.get();
}