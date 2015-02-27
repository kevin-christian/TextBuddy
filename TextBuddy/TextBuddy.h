#ifndef TEXTBUDDY_H
#define TEXTBUDDY_H
#include <vector>
#include <string>

class TextBuddy
{
private:
	std::vector<std::string> TextVector;
	std::string fileName;
public:
	void showWelcomeMessage();
	void addText(std::string text);
	void displayText();
	void deleteText(int textNumber);
	void clearText();
	void processCommand(std::string command);
	void finalizeText();
	void sortText();
	std::vector<std::string> searchText(std::string word);
	void displaySearch(std::vector<std::string> searchVector);
	TextBuddy(std::string argv);
	std::vector<std::string> getTextVector();
};

#endif