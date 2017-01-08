#include "../header/Logger.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Logger logObj;

	logObj.log(0, "log test info", __LINE__);
	logObj.log(1, "log test error", __LINE__);
	logObj.log(2, "log test debug", __LINE__);
	logObj.log(3, "log test warning", __LINE__);
	logObj.log(4, "log test default case in switch");

	//logObj.printAll();	

	logObj.printByType(0);

	logObj.writeFile("hohohaha.log");
	// Logger::printFile("hohohaha.log");

	logObj.stopLogger();
	
	system("pause");
	return 0;
}
