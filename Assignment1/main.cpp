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
    // n * n-1
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
    
    // Create a child process
    //char process = argv[0];
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
            exit(0);
        }
    } 
    // inside the parent
    else if (pid > 0){
        printf("My id is % d\n\n", getpid());
        
        // waiting for the child to finish
        wait(&status);
        
        printf("Factorial of %d = %d\n", value, result);
        
    }
    else {
        printf("Fork Failed!\n");
        return 1;
    }
    return 0;
}