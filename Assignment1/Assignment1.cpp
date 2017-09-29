#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

int result = 0;
int value = 0;

int main(int argc, char *argv[]) {
	// char *name = argv;
	
   	cout << "Enter a number between 1 and 5: " << endl;
   	cin >> value;
   
   	if ((value < 1) && (value > 5)) {
   		cout << "That number is not between 1 and 5." << endl;
		   
		double modulo = value % 1;
		if (modulo != 0) {
			cout << "The number you entered is not an integer. Please enter again" << endl;
			cin >> value;
		}	
   }
}
