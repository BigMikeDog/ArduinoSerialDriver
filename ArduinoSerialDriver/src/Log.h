#pragma once

#include "spdlog/spdlog.h"

namespace ASD {

	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }

	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};
}

//Logging Macros
#define ASD_TRACE(...)    ::ASD::Log::GetLogger()->trace(__VA_ARGS__)
#define ASD_INFO(...)     ::ASD::Log::GetLogger()->info(__VA_ARGS__)
#define ASD_WARN(...)     ::ASD::Log::GetLogger()->warn(__VA_ARGS__)
#define ASD_ERROR(...)    ::ASD::Log::GetLogger()->error(__VA_ARGS__)
#define ASD_FATAL(...)    ::ASD::Log::GetLogger()->fatal(__VA_ARGS__)

