/*
 * Logger.h
 * Logs messages to the console.
 *
 *  Created on: Feb 14, 2014
 *      Author: Vince
 */
#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>

enum Level { 
	ALL = 0,
	FATAL = 100,
	WARN = 200,
	INFO = 300,
	DEBUG = 400,
	FINE = 500,
	SILENT = 900
};

class Logger {
	Level m_loggerLevel;
	std::string m_loggerName;
	
public:
	/**
	 * Creates a Logger with the specified minimum Logger Level and logger name.
	 * The minimum Logger Level specifies the minimum required Logger Level for a message to be printed.
	 */
	Logger(Level minLoggerLevel, std::string loggerName);
	/**
	 * Logs a message, formatted by the optional arguments, at the specified Logger Level.
	 */
	void Log(Level level, std::string logMessageFormat, ...);
	
	void All(std::string logMessageFormat, ...);
	void Fatal(std::string logMessageFormat, ...);
	void Warn(std::string logMessageFormat, ...);
	void Info(std::string logMessageFormat, ...);
	void Debug(std::string logMessageFormat, ...);
	void Fine(std::string logMessageFormat, ...);
};
#endif /* LOGGER_H_ */
