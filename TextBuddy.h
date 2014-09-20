#include <stdio.h>
#include <tchar.h>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

class TextBuddy{

protected:
	vector<string> lines;
	string fileName;

private:
	vector<string> lines;

public:
	Data();
	Data(string fileTitle);
	~Data(void);

	void readFile();
	void saveFile();

	string getFileName();
	string get(int lineNum);
	int getSize();
	vector<string> getAll();

	void add(string line);
	void del(unsigned int lineNum);
	void clear();
	void display();
	SearchResult search(string toFind);
	void sort();

	SearchResult();
	~SearchResult();
	void add(string line);
	void display();
	vector<string> getAll();

	
};


