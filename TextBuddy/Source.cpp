/** This is used to execute the commands given by the user on the command line
interface.
* It is assumed that there is no existing file and a new file is executed each time.
* The file is also saved after each user operation. The command format is given by
* the example interaction below:
Welcome to TextBuddy. mytextfile.txt is ready to use.
command: add Little Brown Fox
added to mytextfile.txt " Little Brown Fox "
command: add jumped over the lazy dog
added to mytextfile.txt " jumped over the lazy dog "
command: add jumped over the rainbow
added to mytextfile.txt " jumped over the rainbow "
command: display
1. Little Brown Fox
2. jumped over the lazy dog
3. jumped over the rainbow
command: delete 2
deleted from mytextfile.txt " jumped over the lazy dog "
command: display
1. Little Brown Fox
2. jumped over the rainbow
command: add then it runs away
1. Little Brown Fox
2. jumped over the rainbow
3. then it runs away
command: clear
all content deleted from mytextfile.txt
command: display
mytextfile.txt is empty
command: exit
* @author Kevin Christian
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "TextBuddy.h"

using namespace std;

void TextBuddy::addText(string text)
{
	TextVector.push_back(text);
	cout << "added to " << fileName<<": '"<<text<<" '"<<endl;
}

void TextBuddy::displayText()
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
		cout << fileName << " is empty" << endl;
	}
}

void TextBuddy::deleteText(int textNumber)
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
		cout<<"deleted from "<<fileName<<": '"<<*iter<<" '"<<endl;
		TextVector.erase(iter);
	}
}

void TextBuddy::clearText()
{
	while(!TextVector.empty()) {
		TextVector.pop_back();
	}
	cout<<"all content deleted from "<< fileName <<endl ;
}

/*void TextBuddy::sortText()
{
	if(!TextVector.empty()) {
		sort(TextVector.begin(), TextVector.end(), [](string a, string b) -> bool {
			for(int i=0; i != a.size() && i != b.size() ; ++i){ 
				if(tolower(a[i]) < tolower(b[i])){
					return true;
				}
				else if(tolower(a[i]) == tolower(b[i])){
					continue;
				}
				else{
					return false;
				}
			}
			return true;
		});
	}
	displayText();
}*/

vector<string> TextBuddy::searchText(string word)
{
	vector<string> searchVector;
	for(int textNumber=0; textNumber != TextVector.size(); ++textNumber){
		unsigned int checkWord = 0;
		checkWord = TextVector[textNumber].find(word);
		if(checkWord != string::npos){
			searchVector.push_back(TextVector[textNumber]);
		}
	}
	return searchVector;
}

void TextBuddy::displaySearch(vector<string> searchVector)
{
	if(!searchVector.empty()){
		vector<string>::iterator iter;
		int textNumber=1;
		for(iter=searchVector.begin(); iter!=searchVector.end(); ++iter){
		cout << textNumber << "." << *iter << endl;
		++textNumber;
		}
	}
	else{
		cout <<"not found" << endl;
	}
}

void TextBuddy::processCommand(string command)
{
	string text;
	int textNumber;
	while(command != "exit") {
		if(command == "add") {
			getline(cin, text);
			addText(text);
		}
		else if(command == "display") {
			displayText();	
		}
		else if(command == "delete"){
			cin>>textNumber;
			deleteText(textNumber);
		}
		else if(command == "clear"){
			clearText();
		}
		/*else if(command == "sort"){
			sortText();
		}*/
		else if(command == "search"){
			string word;
			cin>>word;
			displaySearch(searchText(word));
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
void TextBuddy::finalizeText()
{
	ofstream finalTextFile;
	vector<string>::iterator iter;
	int textNumber = 1;
	if(!TextVector.empty()){
		for(iter=TextVector.begin(); iter!=TextVector.end(); ++iter){
			finalTextFile << textNumber<<"."<<*iter<<endl;
			++textNumber;
		}
	}
	finalTextFile.close();
}
void TextBuddy::showWelcomeMessage()
{
	cout << "Welcome to Textbuddy. " << fileName << " is ready for use" << endl;
	cout << "command: ";
}

TextBuddy::TextBuddy(string argv)
{
	fileName = argv;
}

std::vector<std::string> TextBuddy::getTextVector()
{
	return TextVector;
}
