/*
 * Logger.cpp
 *
 *  Created on: Feb 17, 2014
 *      Author: Vince
 */
using namespace std;

#include "Logger.h"
#include <stdarg.h>
#include <string>

Logger::Logger(Level minLoggerLevel, string loggerName) {
	m_loggerLevel = minLoggerLevel;
	m_loggerName = loggerName;
}

void Logger::Log(Level level, string logMessageFormat, ...) {
	//	Filter log messages
	//	The lower the log level the more severe
	if (level > m_loggerLevel) {
		return;
	}
	string levelStr = "";
	switch (level) {
	case ALL:
		levelStr = "ALL";
		break;
	case FATAL:
		levelStr = "FATAL";
		break;
	case WARN:
		levelStr = "WARNING";
		break;
	case INFO:
		levelStr = "INFO";
		break;
	case DEBUG:
		levelStr = "DEBUG";
		break;
	case FINE:
		levelStr = "FINE";
		break;
	default:
		levelStr = "undef";
	}
	//	Print the logger ID and the level
	printf("[%s] [%7s] ", m_loggerName.c_str(), levelStr.c_str());
	va_list args;
	va_start(args, logMessageFormat);
	vprintf(logMessageFormat.c_str(), args);
	va_end(args);
	std::printf("\n");
}

void Logger::All(string logMessageFormat, ...) {
	va_list args;
	va_start(args, logMessageFormat);
	Log(ALL, logMessageFormat, args);
	va_end(args);
}
void Logger::Fatal(string logMessageFormat, ...) {
	va_list args;
	va_start(args, logMessageFormat);
	Log(FATAL, logMessageFormat, args);
	va_end(args);
}
void Logger::Warn(string logMessageFormat, ...) {
	va_list args;
	va_start(args, logMessageFormat);
	Log(WARN, logMessageFormat, args);
	va_end(args);
}
void Logger::Info(string logMessageFormat, ...) {
	va_list args;
	va_start(args, logMessageFormat);
	Log(INFO, logMessageFormat, args);
	va_end(args);
}
void Logger::Debug(string logMessageFormat, ...) {
	va_list args;
	va_start(args, logMessageFormat);
	Log(DEBUG, logMessageFormat, args);
	va_end(args);
}
void Logger::Fine(string logMessageFormat, ...) {
	va_list args;
	va_start(args, logMessageFormat);
	Log(FINE, logMessageFormat, args);
	va_end(args);
}
