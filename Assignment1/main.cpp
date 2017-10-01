#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

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
    
    // Inside the child
    if (child_id == 0) {
        
        //printf("Child of % s is % d\n", name, getpid());
        
        cout << "Enter an integer" << endl;
        cin >> value;
       
        if ((value > 1) || (value < 5)) {
            // Store result of 
            result = calculateFactorial(value);
            cout << result << " is the result of the factorial. " << endl;
        }
    } 
    // inside the parent
    else {
        //printf("My id is % d\n", getpid());
        
        printf("Factorial of %d = %d\n", value, result);
        
        // Testing a theory
        // that didn't work either - `a` must be of type something I declare
        // int a = wait(&value);
    }
    return 0;
}


