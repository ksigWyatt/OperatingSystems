#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int result = 0;
int value = 0;

int calculateFactorial(int value) {
    
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
    
    // Create a child process
    pid_t pid = fork();
    
    // Inside the child
    if (pid == 0) {
        
        printf("Child pid is % d\n" ,getpid());
        
        cout << "Enter an integer" << endl;
        cin >> value;
       
        if ((value > 1) || (value < 5)) {
            // Store result of 
            result = calculateFactorial(value);
            
            // getting 1280 for the factorial?
            exit(result);
        }
    } 
    // inside the parent
    else if (pid > 0){
        printf("My id is % d\n\n", getpid());
        
        // returns the PID of the child that was operating before the process ended
        wait(&result);
        
        printf("Factorial of %d = %d\n", value, result);
        
    }
    else {
        printf("Fork Failed!\n");
        return 1;
    }
    return 0;
}