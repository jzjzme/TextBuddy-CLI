
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void printErrorMsg(string msg){
	vector<string> data;
	cout << "Error: " << msg << endl;
}

bool checkFile(int n){
	if (n < 2){
		return false;
	}
	return true;
}
string getFile(){
	string s;
	cout << "file:";
	cin >> s;
	return s;
}

vector<string> readFile(string file){
	fstream myfile;
	vector<string> data;
	string line;
	myfile.open(file, ios::in || ios::out);
	while (getline(myfile, line)){
		data.push_back(line);
	}
	myfile.close();
	return data;
}

void printIntro(string file){
	cout << "Welcome to TextBuddy. " << file << " is ready for use\n";
}

string requestCommand(){
	string cmd;
	cout << "command: ";
	cin >> cmd;
	return cmd;
}

vector<string> add(vector<string> &data, string file){
	string line;
	getline(cin, line);
	cout << "Added to " << file << ": " << line << endl;
	data.push_back(line.substr(1, string::npos));
	return data;
}

vector<string> del(vector<string> &data, string file){
	unsigned int linenum;
	std::cin >> linenum;
	if (linenum <= data.size() && linenum > 0){
		cout << "Removed from " << file << ": " << data[linenum - 1] << endl;
		data.erase(data.begin() + linenum - 1);
	}

	return data;
}

vector<string> clear(vector<string> &data, string file){
	data.clear();
	cout << "All content deleted from " << file << endl;
	return data;
}

void print_data(vector<string> &data){
	for (unsigned int i = 0; i < data.size(); i++){
		cout << i + 1 << ". " << data[i] << endl;
	}
}

void display(vector<string> data, string file){
	if (data.empty()){
		printErrorMsg(file + " is empty");
	}
	else{
		print_data(data);
	}
}

vector<string> commandInput(string cmd, vector<string> &data, string file){
	if (cmd == "add"){
		data = add(data, file);
	}
	else if (cmd == "delete"){
		data = del(data, file);
	}
	else if (cmd == "clear"){
		data = clear(data, file);
	}
	else if (cmd == "display"){
		display(data, file);
	}
	else if (cmd == "exit"){
		NULL;
	}
	else{
		string burnline;
		getline(cin,burnline);
		printErrorMsg("Command not recognised");
	}
	return data;
}

void saveData(vector<string> &data, string file){
	fstream myfile;
	myfile.open(file, std::ios::trunc | std::ios::out);
	for (unsigned int i = 0; i < data.size(); i++){
		myfile << data[i] << std::endl;
	}
	myfile.close();
}

void loop(vector<string> &data, string file){
	string cmd = "";
	while(cmd != "exit"){
		cmd = requestCommand();
		data = commandInput(cmd, data, file);
		saveData(data, file);
	}
}

int main(int argc, char* argv[])
{
	string file;
	vector<string> data;
	
	file = argv[1];

	data = readFile(file);

	printIntro(file);
	loop(data, file);
	return 1;
}