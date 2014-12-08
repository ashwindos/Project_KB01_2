#include "Logger.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>

Logger::Logger(void)
{
}


Logger::~Logger(void)
{
}

void Logger::Log(std::string _text)
{
	std::ofstream outfile;
	outfile.open("log.txt", std::ios_base::app);
	// Write the time before each log
	std::time_t t = std::time(NULL);
    std::tm tm = *std::localtime(&t);
	outfile << '[' << std::put_time(&tm, "%c") << "] " << _text << std::endl;
}

void Logger::Log(int _text)
{
	std::ofstream outfile;
	outfile.open("log.txt", std::ios_base::app);
	// Write the time before each log
	std::time_t t = std::time(NULL);
    std::tm tm = *std::localtime(&t);
	outfile << '[' << std::put_time(&tm, "%c") << "] " << _text << std::endl;
}

void Logger::Log(float _text)
{
	std::ofstream outfile;
	outfile.open("log.txt", std::ios_base::app);
	// Write the time before each log
	std::time_t t = std::time(NULL);
    std::tm tm = *std::localtime(&t);
	outfile << '[' << std::put_time(&tm, "%c") << "] " << _text << std::endl;
}