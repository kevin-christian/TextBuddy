#ifndef TEXTBUDDY_H
#define TEXTBUDDY_H
#include <vector>
#include <string>

class TextBuddy
{
private:
	std::vector<std::string> TextVector;
public:
	void showWelcomeMessage(std::string argv);
	void addText(std::string text,  std::string argv);
	void displayText(std::string argv);
	void deleteText(int textNumber, std::string argv);
	void clearText(std::string argv);
	void processCommand(std::string argv, std::string command);
	void finalizeText(std::string argv);

};

#endif