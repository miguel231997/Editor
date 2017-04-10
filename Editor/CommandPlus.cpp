/** @file CommandPlus.inl
Implementation File for CommandPlus */


#include"CommandPlus.h"

CommandPlus::CommandPlus(char commandToSave): _command(commandToSave), _deletedLine(""){}

CommandPlus::CommandPlus(char commandToSave, string deletedLineToSave): _command(commandToSave),_deletedLine(deletedLineToSave){}


CommandPlus::CommandPlus(char commandToSave, string deletedLineToSave, int pos)
{
	_command = commandToSave;
	_deletedLine = deletedLineToSave;
	_deletedPosition = pos;

}


char CommandPlus::returnCommand()
{
	return _command;
}

string CommandPlus::returnDeletedLine()
{
	return _deletedLine;
}

int CommandPlus::returnDeletedPosition()
{
	return _deletedPosition;

}

