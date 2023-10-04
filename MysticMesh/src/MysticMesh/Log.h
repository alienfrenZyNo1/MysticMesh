#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace MysticMesh {
	class MYSTICMESH_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger;  }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define MM_CORE_TRACE(...)    ::MysticMesh::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MM_CORE_INFO(...)     ::MysticMesh::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MM_CORE_WARN(...)     ::MysticMesh::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MM_CORE_ERROR(...)    ::MysticMesh::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MM_CORE_FATAL(...)    ::MysticMesh::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define MM_TRACE(...)         ::MysticMesh::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MM_INFO(...)          ::MysticMesh::Log::GetClientLogger()->info(__VA_ARGS__)
#define MM_WARN(...)          ::MysticMesh::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MM_ERROR(...)         ::MysticMesh::Log::GetClientLogger()->error(__VA_ARGS__)
#define MM_FATAL(...)         ::MysticMesh::Log::GetClientLogger()->fatal(__VA_ARGS__)

