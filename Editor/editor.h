#pragma once
#include<fstream>
#include<string>
#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<algorithm>
#include<conio.h>
#include"LinkedStack.h"
#include"CommandPlus.h"
//#include"CommandPlus.inl"
using namespace std;


class XiEditor{

public:
	void printLines();
	//Prints out all the 


	XiEditor(string);
	// Constructor reads in file, counts number of lines, creates an array and fills it with the contents of the file 
	//Parameters : name of a text file

	void addToUndo(char);

	void removeLine();
	//removes the line that is preceded with the star when pressing X

	void removeChar();
	//Deletes the char pointed to by the carret '^'


	void moveLeft();
	// Moves the '^' one unit to the left

	void moveRight();
	// Moves the '^' one unit to the right


	void moveUp();
	//Moves the '*' one unit up


	void moveDown();
	//Moves the '*' one unit down


	 void fixText();
	 //Fixes the inconsistencies with moving above the limited number of lines, above the max chars...

	 void undo();

private:

	int _curLine;
	//Number of the line

	int _curPosition;
	///Position in a certain line

	int _previousPosition;

	int _maxLines;
	// Number of lines in the actual file

	int _size;
	//Max size of the array of strings

	string * _lines;
	//Dynamic array that contains the contents of the text file

	LinkedStack<CommandPlus> undoStack;

};
