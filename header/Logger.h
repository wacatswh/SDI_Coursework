#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
#include "unorderedLinkedList.h"

using namespace std;

class Logger {
	public:
		Logger();
		~Logger();
		void showNumOfLogs();
		void stopLogger();
		void printAll();
		void printByType(const int i);
		void log(const int logLevel, const string logMessage, const int lineNumber = 0);
		void writeFile(const string outputFileName);
		static void printFile(const string inputFileName);
	private:
		int numOfLog, numOfInfoLog, numOfErrorLog, numOfDebugLog;
		unorderedLinkedList<string> list;
		std::chrono::time_point<std::chrono::system_clock> start, end;
};

#endif /* LOGGER_H_ */
