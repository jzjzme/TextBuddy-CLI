
#includes "TextBuddy.h"
#includes "Commands.h"
using namespeace std;

TextBuddy::Data(){
}

TextBuddy::Data(sstring fileTitle){
	fileName = fileTitle;
	readFile();
}

TextBuddy::~Data(void){
}

void TextBuddy::readFile(){
	string line;
	sfstream file;
	file.open(fileName.c_str(), ios_base::in);
	while (getline(file, line)){
		lines.push_back(line);
	}
	file.close();
}

void TextBuddy::saveFile(){
	fstream file;
	file.open(fileName.c_str(), ios_base::in | ios_base::out | ios_base::trunc);
	for (unsigned int i = 0; i < lines.size(); i++){
		file << lines[i] << endl;
	}
	file.close();
}

string TextBuddy::getFileName(){
	return fileName;
}

string TextBuddy::get(int lineNum){
	return lines[lineNum - 1];
}

int TextBuddy::getSize(){
	return lines.size();
}

vector<string> TextBuddy::getAll(){
	return lines;
}

void TextBuddy::add(string line){
	lines.push_back(line);
	printMessage("Added to " + fileName + ": " + line);
}

void TextBuddy::del(unsigned int lineNum){
	if (lineNum > lines.size() || lineNum <= 0){
		printErrorMessage("Invalid input");
	}
	else{
		printMessage("Removed from " + fileName + ": " + lines[lineNum - 1]);
		lines.erase(lines.begin() + lineNum - 1);
	}
}

void TextBuddy::clear(){
	printMessage("All content deleted from " + fileName);
	lines.clear();
}

void TextBuddy::display(){
	for (unsigned int i = 0; i < lines.size(); i++){
		cout << i + 1 << ". " << lines[i] << sendl;
	}
}

SearchResult TextBuddy::search(string toFind){
	SearchResult searchResults;
	for (unsigned int i = 0; i < lines.size(); i++){
		if (isInString(lines[i], toFind)){
			stringstream line;
			line << i + 1 << ". " << lines[i];
			searchResults.add(line.str());
		}
	}
	printMessage("Search results: ");
	searchResults.display();
	return searchResults;
}

void TextBuddy::sort(){
	sort(lines.begin(), lines.end());
	printMessage(fileName + " has been sorted.");
}

TextBuddy::SearchResult()
{
}


TextBuddy::~SearchResult(){
}

void TextBuddy::add(std::string line){
	lines.push_back(line);
}

void TextBuddy::display(){
	for (unsigned int i = 0; i < lines.size(); i++){
		printMessage(lines[i]);
	}
}

vector<string> TextBuddy::getAll(){
	return lines;
}

void engageUser(Data &textFile);
void executeUserCommand(Commands command, Data &textFile);

int main(int argc, char* argv[]){
	string fileName = confirmFile(argc, argv);
	printMessage(MESSAGE_WELCOME);
	Data textFile(fileName);
	engageUser(textFile);
	return 0;
}

void engageUser(Data &textFile){
	map<string, Commands> commandMap = setupMap();
	string command = "";
	while (command != USER_COMMAND_EXIT){
		command = prompt("command");
		executeUserCommand(commandMap[command], textFile);
	}
}

void executeUserCommand(Commands command, Data &textFile){
	string line;
	unsigned int lineNum;
	switch (command){
	case ADD:
		cin.ignore();
		getline(cin, line);
		textFile.add(line);
		break;

	case DELETE:
		cin >> lineNum;
		textFile.del(lineNum);
		break;

	case CLEAR:
		textFile.clear();
		break;

	case DISPLAY:
		textFile.display();
		break;

	case SEARCH:
		cin.ignore();
		getline(cin, line);
		textFile.search(line);
		break;

	case SORT:
		textFile.sort();
		break;

	case EXIT:
		NULL; // no need to take action
		break;

	default:
		getline(cin, line); // clears the extra line leftover from the wrong command
		printErrorMessage("Command not recognised");
	}
	textFile.saveFile();
}