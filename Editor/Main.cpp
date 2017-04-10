
#include"editor.h"
#include"CommandPlus.cpp"



// this program doesn't do much yet
void main(int argc, char * argv[]) {

	string garbage;
	XiEditor editor(argv[1]);
	string userInput;
	//User input for userInput



	while (userInput != "0")
	{
		system("cls");
		editor.printLines();
		cout << setw(45) << setfill(' ') << "J (down)" << endl
			<< setw(44) << setfill(' ') << "K (up) " << endl
			<< setw(46) << setfill(' ') << "L (right)" << endl
			<< setw(45) << setfill(' ') << "H (left)" << endl
			<< setw(60) << setfill(' ') << "X to delete a character" << endl
			<< setw(64) << setfill(' ') << "dd (twice) to delete a line" << endl
			<< setw(47) << setfill(' ') << "0 To quit " << endl << endl;
		
		

		userInput = _getch();
		
		if (userInput == "j") {

			editor.moveDown();
			editor.addToUndo('j');
		}
		else if (userInput == "k") {
			editor.moveUp();
			editor.addToUndo('k');
		}
		else if (userInput == "l") {
			editor.moveRight();
			editor.addToUndo('l');
		}
		else if (userInput == "h") {
			editor.moveLeft();
			editor.addToUndo('h');
		}
		else if (userInput == "u")
			editor.undo();
		else if (userInput == "x")
		{
			editor.removeChar();
		}
		else if (userInput == "0")
			return;
		else if (userInput == "d" )
		{
			system("cls");
			editor.printLines();
			cout << " Type in another 'd' to delete a line, or any other character to go back to the menu: " << endl << endl;
			string secondUserInput;
			secondUserInput = _getch();
			if (secondUserInput == "d")
			{
				editor.removeLine();
				
			}
		}
		else
		{
			cout << "ERROR - CHECK YOUR INPUT! " << endl << endl;
		}
		editor.fixText();
	}
	
	
}