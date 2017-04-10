/* @file CommandPlus.h
Header File for CommandPlus */


#ifndef COMMANDS_
#define COMMANDS_
#include<string>
using namespace std;

class CommandPlus
{
private:
	char _command;
	string _deletedLine;
	int _deletedPosition;
	int _deletedLineNum;

public:
	CommandPlus(char);
	CommandPlus(char , string);
	CommandPlus(char, string, int);
	//CommandPlus();
	char returnCommand();
	string returnDeletedLine();
	int returnDeletedPosition();
	
};
//#include"CommandPlus.inl"

#endif