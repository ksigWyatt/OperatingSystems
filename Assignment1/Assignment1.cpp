#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <string.h>
#include <unistd.h>

using namespace std;

int result = 0;


int main(int argc, char *argv[]) {
	// char *name = argv;
	int value = 0;
	
   	cout << "Enter a number between 1 and 5: " << endl;
   	getline(cin, value);
   	
   
   	if ((value < 1) && (value > 5)) {
   		cout << "That number is not between 1 and 5." << endl;
		   
		   
		if (cin.fail()) {
			cout << "The number you entered is not a integer" << endl;
		}
	}
	return 0;
}
