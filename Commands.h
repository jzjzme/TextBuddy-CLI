#include "TextBuddy.h"

enum Commands{
	ADD = 1,
	DELETE = 2,
	CLEAR = 3,
	DISPLAY = 4,
	SEARCH = 5,
	SORT = 6,
	EXIT = 7

	static const string MESSAGE_WELCOME = "Welcome to TextBuddy 2!";
	static const string MESSAGE_ERROR = "There has been an error: ";

	static const int EXPECTED_ARG_NUMBER = 2;
	static const int POSITION_FILENAME = 1;
	static const int MIN_STR_LEN = 4;
	static const string TXT_EXTENSION = ".txt";

	static const string USER_COMMAND_ADD = "add";
	static const string USER_COMMAND_DELETE = "delete";
	static const string USER_COMMAND_CLEAR = "clear";
	static const string USER_COMMAND_DISPLAY = "display";
	static const string USER_COMMAND_SEARCH = "search";
	static const string USER_COMMAND_SORT = "sort";
	static const string USER_COMMAND_EXIT = "exit";

	bool isFileSpecified(int n);
	string getFileName();
	bool isLegit(string filename);

	string prompt(string msg);
	string promptMultipleWords(string msg);
	void printMessage(string msg);
	void printErrorMessage(string msg);

	string confirmFile(int i, char* argv[]);

	map<string, Commands> setupMap();

	bool isInString(string string, string substring);