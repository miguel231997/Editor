


#include"editor.h"

XiEditor::XiEditor(string fileName)
{
	ifstream inFile;
	
	

	inFile.open(fileName);

	if (!inFile)
	{
		cout << "File does not exist!!!";
		return;
	}

	int i = 0;
	int numLines = 0;
	//Counts the number of lines in the file

	string garbage;
	while (!inFile.eof())
	{
		getline(inFile,garbage);
		numLines++;
	}
	_size = numLines*2;

	//Clearing eof flag and returning to the start of the file
	inFile.clear();
	inFile.seekg(0, ios::beg);


	//Sets size of array to double the number of lines in the file
	_lines = new string[_size];


	//Fills array with file contents
	while (!inFile.eof())
	{
		getline(inFile, _lines[i]);
		if (_lines[i] == "")
			_lines[i] += ' ';
		i++;
	}
	

	//Initiliazes line number and position
	
	_maxLines = numLines;
	_curLine =0;
	_curPosition=0;
	_previousPosition = 0;
	
	
}      


void XiEditor::printLines()
{
	//Using size for now NEEDS TO BE CHANGED
	for (int i = 0; i < _size; i++)
	{
		//If at line, shows the star
		
			
		if (i == _curLine)
		{
				cout <<"*"<< _lines[i] << endl;

			for (int j = 0; j < _curPosition; j++) {
				cout << " ";
			}
				cout << " ^" << endl;
			
		}

		else
		{
				cout << _lines[i] << endl;
		}
			
			}
}

void XiEditor::removeLine()
{
	int i = _curLine;
	CommandPlus dCommand('d', _lines[_curLine], _curLine);
    
	//Deletes line and moves every up
	_lines[i].erase(_lines[i].begin(), _lines[i].end());

	for (i ; i < _maxLines; i++)
	{
		_lines[i] = _lines[i+ 1];
	}
	_maxLines--;


	//Prepares for the undo function
	undoStack.push(dCommand);



 } 

void XiEditor::removeChar()
{
	string deletedChar (1,_lines[_curLine][_curPosition]);
	CommandPlus XCommand('x', deletedChar, _curPosition);
	if (_curPosition >= 0)
		undoStack.push(XCommand);
		_lines[_curLine].erase(_curPosition, 1);
}


void XiEditor::moveLeft()
{
		_curPosition--;
		_previousPosition = _curPosition;
}
void XiEditor::moveRight()
{
		_curPosition++;
		_previousPosition = _curPosition;
}
void XiEditor::moveUp()
{
		_curLine--;
}

void XiEditor::moveDown()
{
		_curLine++;
}


void XiEditor::fixText()
{
	int lineLength = _lines[_curLine].length() - 1;
	//If it overflows to the left
	if (_curPosition < 0)
	{
		_curPosition = 0;
	}

	
	//If it overflows to the right
	else if (_curPosition > lineLength)
	{
		
		_curPosition = _lines[_curLine].length()-1;
	}

	if (_curLine<0)
	{ 
		_curLine = 0;
	}
	else if (_curLine >= _maxLines)
	{
		_curLine = _maxLines;
	}
	 
}

void XiEditor::undo()
{
	if (!undoStack.isEmpty())
	{
		CommandPlus previousCommand = undoStack.peek();
		undoStack.pop();
		string deletedString = previousCommand.returnDeletedLine();
		switch (previousCommand.returnCommand())
		{
		case 'j':
			moveUp();
			_curPosition = _previousPosition;
			break;
		case'k':
			moveDown();
			_curPosition = _previousPosition;
			break;
		case 'h':
			moveRight();
			break;
		case 'l':
			moveLeft();
			break;
		case 'x':
			_lines[_curLine].insert(previousCommand.returnDeletedPosition(), deletedString);
			break;
		case 'd':
			
			_maxLines++;
			int i = _maxLines;
			for (i; i>= _curLine; i--)
			{
				_lines[i+1] = _lines[i];
			}
			
			_lines[_curLine] = deletedString;
			break;
		}
	}
	else
		cout<<"Undo Stack is empty!" << endl;
}


void XiEditor::addToUndo(char toAdd) {

	CommandPlus CommandToUndo(toAdd);
	undoStack.push(CommandToUndo);


}
