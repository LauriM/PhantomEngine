#pragma once

#define HANDLE_MESSAGE(p_msg)\
	String output;\
	std::stringstream __stringStream__; \
	__stringStream__ << p_msg; \
	output = __stringStream__.str();

// current logging commands
#define LOG_INFO(p_msg) do { if(phantom::g_logger != NULL) { HANDLE_MESSAGE(p_msg); phantom::g_logger->info(output); } } while (false)
#define LOG_WARNING(p_msg) do { if(phantom::g_logger != NULL) { HANDLE_MESSAGE(p_msg); phantom::g_logger->warning(output); } } while (false)
#define LOG_ERROR(p_msg) do { if(phantom::g_logger != NULL) { HANDLE_MESSAGE(p_msg); phantom::g_logger->error(output); } } while (false)

// TODO: hide log messages in release builds

namespace phantom {

	class Logger {
	public:
		virtual void error(const String &msg) = 0;
		virtual void warning(const String &msg) = 0;
		virtual void info(const String &msg) = 0;
	};

	extern Logger *g_logger;

}
