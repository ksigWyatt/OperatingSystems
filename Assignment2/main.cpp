/*
 * last 4 digits: 3040
 * assignment# 2
 * course id: 80604
 * 
 */

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


int calculateFibonacci(int value) {
    // init of result to 1
    result = 1;
    int a = 0, c, i;
    
    if( value == 0){
        return 0;
    } 
    
    // this might be wrong / not accurate to use because this returns the sum of
    // the series. Not the series itself. Might want to use an array or something.
    for (i = 2; i <= value; i++) {
     
        c = a + result;
        a = result;
        result = c;
    }
   return result; 
}


int main(int argc, char** argv) {
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
                 result = calculateFibonacci(value);

                 // Alert the waiting processes that we are done
                 printf("The first %d numbers in Fibonacci are: %d\n", value, result);          
                 
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
        
//        // Waiting for the child to finish
//        wait(&status);
//        
//        //Exit status holds the the least significant 8 bits of the status argument 
//        result = WEXITSTATUS(status);
        
    }
    // If the fork failed handle the exception - end the program with code 1
    else {
        printf("Fork Failed!\n");
        return 1;
    }
    return 0;
}