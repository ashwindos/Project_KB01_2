#include <string>

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
};