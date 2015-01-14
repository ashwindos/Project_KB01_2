#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <Windows.h>

class Logger
{
public:
	Logger(void);
	~Logger(void);

	/// Appends a string to log.txt, includes the time of the log.
	void Log(std::string);
	
	/// Appends an int to log.txt, includes the time of the log.
	void Log(int);
	
	/// Appends a float to log.txt, includes the time of the log.
	void Log(float);

	/// Appends a char to log.txt, includes the time of the log.
	void Log(char);
};

#endif