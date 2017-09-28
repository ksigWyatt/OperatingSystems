#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

// init of Global vars
int result = 0;
int value = 0;


int main(int argc, char *argv[]) {
	// char *name = argv;
	double number_entered;
   
   	cout << "Enter a number between 1 and 5: " << endl;
   	cin >> number_entered;
   
   	if ((number_entered < 1) && (number_entered > 5)) {
   		cout << "That number is not between 1 and 5." << endl;	
   }
}
