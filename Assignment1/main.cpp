#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

// init of Global vars
int result = 0;
int value = 0;

int calculateFactorial(int value) {
    // init of result to 1
    result = 1;
    for(int i = 1; i <= value; ++i) {
        result *= i;
    }
    if (value <= 0) {
        result = 1;
    }
    
    printf("the factorial of %d is %d\n", value, result);
    return result; 
}

int main(int argc, char* argv[]) {
    
    int status = 0;
    
    // Ask for input
    cout << "Enter an integer" << endl;
    cin >> value;
    
    // Create a child process
    pid_t pid = fork();
    
    // Inside the child
    if (pid == 0) {
            
        if ((value > 1) || (value < 5)) {
            // Store result of 
            result = calculateFactorial(value);
            
            // Alert the waiting processes that we are done
            exit(result);
        }
    } 
    // Inside the parent
    else if (pid > 0){
        
        // Waiting for the child to finish
        wait(&result);
        wait(&value);
        // Fixing the result value - the value is multiplied by 255
        result = result / 255;
        
        // Output as specified by the assignment
        printf("Factorial of %d = %d\n", value, result);
        
    }
    // If the fork failed handle the exception - end the program with code 1
    else {
        printf("Fork Failed!\n");
        return 1;
    }
    return 0;
}