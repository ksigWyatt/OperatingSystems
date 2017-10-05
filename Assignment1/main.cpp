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
    
    // reset the value to 1 if the user enters a number <= 0
    if (value <= 0) {
        result = 1;
    }
    
    for(int i = 1; i <= value; ++i) {
        result *= i;
    }    
    
    return result; 
}

int main(int argc, char* argv[]) {
    int status;
    
    // Ask for input
    cout << "Enter an integer between 1 and 5: " << endl;
    cin >> value;
   
    // Create a child process
    pid_t pid = fork();
    
    // Inside the child
    if (pid == 0) {
            
        //Check that the value is of the correct number
        if (value >= 1) {
            if (value <= 5) {
                 // Store result of 
                 result = calculateFactorial(value);

                 // Alert the waiting processes that we are done
                 exit(result); 
            }
            // > 1 && > 5
            else {
                printf("the number you entered was not an integer between 1 and 5." );
                return 1;
            }
        }
        // < 1
        else {
            printf("the number you entered was not an integer between 1 and 5." );
            return 1;
        }
    } 
    // Inside the parent
    else if (pid > 0){
        
        // Waiting for the child to finish
        wait(&status);
        
        // List that did not work - But might be correct after some factoring
        result = WEXITSTATUS(status);
       
        // if something happened notify the user
        if (result == 0) {
            printf("\nAn error occurred. Please try again");
        }
        else if (value > 5) {
            printf("\nAn error occurred. Please try again");
        }
        else {
            // Output as specified by the assignment
            printf("Factorial of %d = %d\n", value, result);
        }   
    }
    // If the fork failed handle the exception - end the program with code 1
    else {
        printf("Fork Failed!\n");
        return 1;
    }
    return 0;
}