#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	cout << "Checking for output..." << endl;
	cout << "Press ESC to quit" << endl;
	
	string last, current;
	string line;
	
	string check;
	
	if (argc > 1) check = argv[1];
	else check = "accepted";
	
	last = "";
	current = "";
	
	ifstream file;
	
	file.open("output.txt");
	if (file.is_open())
	{
		while (file.good())
		{
			getline (file,line);
			last += "\r\n" + line ;
		}	
		file.close();
	}
	
	while (GetAsyncKeyState(VK_ESCAPE) == 0) {
		Sleep(2000);
		
		current = "";
		file.open("output.txt");		
		if (file.is_open())
		{
			while (file.good())
			{
				getline (file,line);
				current += "\r\n" + line;
			}	
			file.close();
		}
		if (current.substr(last.length()).rfind(argv[1]) != string::npos) {
			PlaySound(TEXT("ding.wav"), NULL, SND_FILENAME);						
		}
		cout << current.substr(last.length());
		last = current;			
	}
		
	return 0;
}