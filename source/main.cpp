#include "../header/Logger.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	Logger logObj;

	logObj.log(3, "Logger object created.", __LINE__);

	cout << "Enter the word for other player to guess" << endl;
	logObj.log(0, "Program prompts player to enter word for other player to guess", __LINE__);

	string word;
	do {
		getline(cin, word);

		if (word == "")
			logObj.log(1, "Player did not enter anything", __LINE__);

	} while (word.empty() || all_of(word.begin(), word.end(), isspace));

	logObj.log(0, "Player entered the word", __LINE__);

	string copy = word;

	string Underscore;

	for (int i = 0; i != word.length(); i++) {

		if (word.at(i) == ' ') {
			Underscore += " ";
		}
		else {
			Underscore += "_";
		}
	}

	for (int i = 0; i != 50; ++i) {
		cout << endl;
	}

	string guess;
	int wrong = 0;

	logObj.log(2, "Before entering the game while loop", __LINE__);

	while (1) {
		if (wrong == 6) {
			cout << "You Lose! The word was: " << word << endl;
			logObj.log(3, "Player has lost the game!", __LINE__);
			break;
		}

		cout << Underscore << endl;
		cout << "There are " << word.length() << " letters with spaces" << endl;
		logObj.log(0, "Remind the user on how many more letters with spaces", __LINE__);

		cout << "You have " << 6 - wrong << " more tries left" << endl;
		logObj.log(0, "Remind the user on the number of tries left", __LINE__);

		if (Underscore == word) {
			cout << "You win!" << endl;
			logObj.log(3, "Player has won the game. Game will now quit.", __LINE__);
			break;
		}

		cout << "Guess a letter or a word" << endl;
		logObj.log(0, "Prompts for input of letter or word from player", __LINE__);
		getline(cin, guess);

		if (guess.length() > 1) {
			if (guess == word) {
				cout << "That's right, you win!" << endl;
				logObj.log(3, "Player has won the game. Game will now quit.", __LINE__);
				break;
			}
			else {
				cout << "wrong word " << endl;
				logObj.log(0, "Player has guessed wrongly.", __LINE__);
				wrong++;
			}
		}
		else if (copy.find(guess) != -1) {
			while (copy.find(guess) != -1) {
				Underscore.replace(copy.find(guess), 1, guess);
				copy.replace(copy.find(guess), 1, "_");
			}
		}
		else {
			cout << "That's wrong" << endl;
			logObj.log(0, "Player has guessed wrongly.", __LINE__);
			wrong++;
		}

		cout << endl;
	}

	logObj.log(2, "Exited from the game while loop", __LINE__);
	logObj.printByType(0);
	// logObj.printAll();
	logObj.showNumOfLogs();
	logObj.writeFile("game.log");
	// logObj.printFile("game.log");
	logObj.stopLogger();

	return 0;
}

/*
Logger logObj;

logObj.log(0, "log test info", __LINE__);
logObj.log(1, "log test error", __LINE__);
logObj.log(2, "log test debug", __LINE__);
logObj.log(3, "log test warning", __LINE__);
logObj.log(4, "log test default case in switch");

//logObj.printAll();

logObj.printByType(0);
logObj.printByType(3);

logObj.writeFile("hohohaha.log");
// Logger::printFile("hohohaha.log");

logObj.stopLogger();

system("pause");
return 0;
*/
