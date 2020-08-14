#include "Debug/Log.h"

int main()
{
	ASD::Log::Init();
	ASD_WARN("Initialized Log!");
	ASD_INFO("This is some info.");

	return 0;
}