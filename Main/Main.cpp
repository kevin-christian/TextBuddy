#include <iostream>
#include <string>
#include "TextBuddy.h"

int main(int argc, char * argv[]) {
	TextBuddy textBuddy(argv[1]);
	std::string command;
	textBuddy.showWelcomeMessage();
	std::cin >> command;
	textBuddy.processCommand(command);
	textBuddy.finalizeText();
	return 0;
}