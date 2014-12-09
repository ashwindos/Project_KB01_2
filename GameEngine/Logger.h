#ifndef __LOGGER_H_
#define __LOGGER_H_
#include <string>

class Logger
{
public:
	Logger(void);
	~Logger(void);

	/// Appends a string to log.txt, includes the time of the log.
	void Log(std::string);
	/// Appends a string to log.txt, includes the time of the log.
	
	/// Appends an int to log.txt, includes the time of the log.
	void Log(int);
	
	/// Appends a float to log.txt, includes the time of the log.
	void Log(float);
};
#endif