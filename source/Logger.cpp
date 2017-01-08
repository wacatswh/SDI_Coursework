#include "../header/Logger.h"
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
#include <sstream>

using namespace std;

Logger::Logger()
{
	numOfLog = numOfInfoLog = numOfErrorLog = numOfDebugLog = 0;
	start = std::chrono::system_clock::now();
}

Logger::~Logger()
{
	
}

void Logger::showNumOfLogs()
{
	cout << "Total logs: " << numOfLog << endl;
}

void Logger::printAll()
{
	list.linkedListType<string>::print();
}

void Logger::printByType(const int i)
{
	switch (i)
	{
	case 0:
		list.unorderedLinkedList::printLogType("INFO");
		break;

	case 1:
		list.unorderedLinkedList::printLogType("ERROR");
		break;

	case 2:
		list.unorderedLinkedList::printLogType("DEBUG");
		break;

	case 3:
		list.unorderedLinkedList::printLogType("WARNING");
		break;

	default:
		Logger::log(3, "Wrong parameter! Send valid logLevel 0 - 3 as parameter.");
		break;
	}
}

void Logger::log(const int logLevel, const string logMessage, const int lineNumber)
{
	string temp, tempLineNumber;
	tempLineNumber = to_string(lineNumber);

	switch (logLevel)
	{
	// logLevel == 0 is info 
	case 0:
		temp = "Line " + tempLineNumber + ": " + "[INFO] " + logMessage;
		list.unorderedLinkedList<string>::insertLast(temp);
		numOfLog++;
		break;

	// logLevel == 1 is error
	case 1:
		temp = "Line " + tempLineNumber + ": " + "[ERROR] " + logMessage;
		list.unorderedLinkedList<string>::insertLast(temp);
		numOfLog++;
		break;

	// logLevel == 2 is debug
	case 2:
		temp = "Line " + tempLineNumber + ": " + "[DEBUG] " + logMessage;
		list.unorderedLinkedList<string>::insertLast(temp);
		numOfLog++;
		break;

	// logLevel == 3 is warning
	case 3:
		temp = "Line " + tempLineNumber + ": " + "[WARNING] " + logMessage;
		list.unorderedLinkedList<string>::insertLast(temp);
		numOfLog++;
		break;

	default:
		Logger::log(3, "Wrong parameter! Send valid logLevel 0 - 3 as first parameter.");
		break;
	}
}

void Logger::writeFile(const string outputFileName)
{
	list.unorderedLinkedList::writeFile(outputFileName);

	end = std::chrono::system_clock::now();

	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	ofstream outFile;
	outFile.open(outputFileName, ios::app);

	outFile << "Total logs: " << numOfLog << "\n";

	#pragma warning(disable : 4996)
	outFile << "Finished at " << std::ctime(&end_time) << "\n";

	outFile.close();
}

void Logger::printFile(const string inputFileName)
{
	string s;
	ifstream inFile;

	inFile.open(inputFileName);

	if (!inFile)
	{
		cerr << "Unable to open file!" << endl;
		return;
	}

	while (getline(inFile, s, '\n'))
	{
		cout << s << endl;
	}

	inFile.close();
}

void Logger::stopLogger()
{
	end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	showNumOfLogs();

	#pragma warning(disable : 4996)
	cout << "Finished at " << std::ctime(&end_time)
		<< "Elapsed time: " << elapsed_seconds.count() << "s\n";

	Logger::~Logger();
}