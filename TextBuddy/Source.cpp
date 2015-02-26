#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void addText(string text, vector<string>& TextVector, string argv)
{
	TextVector.push_back(text);
	cout << "added to " << argv<<": '"<<text<<" '"<<endl;
}

void displayText(vector<string>& TextVector, string argv)
{
	if(!TextVector.empty()){
		vector<string>::iterator iter;
		int textNumber=1;
		for(iter=TextVector.begin(); iter!=TextVector.end(); ++iter){
		cout << textNumber << "." << *iter << endl;
		++textNumber;
		}
	}
	else{
		cout << argv << " is empty" << endl;
	}
}

void deleteText(vector<string>& TextVector, int textNumber, string argv)
{
	vector<string>::iterator iter;
	iter = TextVector.begin();
	textNumber = textNumber-1;
	while(textNumber>0){
		++iter;
		--textNumber;
	}
	if(iter >= TextVector.end()){
		cout<<"The text to be deleted does not exist"<<endl; 
	}
	else{
		cout<<"deleted from "<<argv<<": '"<<*iter<<" '"<<endl;
		TextVector.erase(iter);
	}
}

void clearText(vector<string>& TextVector, string argv)
{
	while(!TextVector.empty()) {
		TextVector.pop_back();
	}
	cout<<"all content deleted from "<< argv <<endl ;
}

void processCommand(vector<string>& TextVector, string argv, string command)
{
	string text;
	int textNumber;
	while(command != "exit")  {
		if(command == "add") {
			getline(cin, text);
			addText(text, TextVector, argv);
		}
		else if(command == "display") {
			displayText(TextVector, argv);	
		}
		else if(command == "delete"){
			cin>>textNumber;
			deleteText(TextVector, textNumber, argv);
		}
		else if(command == "clear"){
			clearText(TextVector, argv);
		}
		else{
			cout<<"invalid command"<<endl;
		}
		cout<<"command: ";
		cin >> command;
	}
}

//finalizeText function saves the final list of text 
//into the command line parameter, in this case 'mytextfile.txt'   
//after the user enter the command 'exit' 
void finalizeText(vector<string>& TextVector, string argv)
{
	ofstream finalTextFile(argv);
	vector<string>::iterator iter;
	int textNumber = 1;
	if(!TextVector.empty()){
		for(iter=TextVector.begin(); iter!=TextVector.end(); ++iter){
			finalTextFile<<textNumber<<"."<<*iter<<endl;
			++textNumber;
		}
	}
	finalTextFile.close();
}

int main(int argc, char * argv[]) {
	string command;
	vector<string> TextVector;
	cout << "Welcome to Textbuddy. " << argv[1] << " is ready for use" << endl;
	cout << "command: ";
	cin >> command;
	processCommand(TextVector, argv[1], command);
	finalizeText(TextVector, argv[1]);
	return 0;
}