#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

int result = 0;
int value = 0;

int calculateFactorial(int num) {
    
    while(num > 0) {
        result = num + num - 1;
        num--;
    }
    if (num <= 0) {
        result = 1;
    }
    return result; 
}

int main(int argc, char** argv) {
    
    // Create a child process
    int child_id = fork();
    
    // Inside the parent
    if (child_id == 0) {
        
        //printf("Child of % s is % d\n", name, getpid());
        //wait(1);
        printf("Factorial of %d = %d\n", value, result);
    } 
    // inside the child
    else {
        //printf("My id is % d\n", getpid());
        
        cout << "Enter an integer" << endl;
        cin >> value;
        
        if ((value > 1) || (value < 5)) {
            result = calculateFactorial(value);
        }
    }

    return 0;
}


