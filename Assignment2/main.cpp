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
int resultArray[5]; // Might need to make result an array? or another Data Type
int value = 0;


// Use pointer for array instead?
int calculateFibonacci(int value) {
    // init
    int t1 = 0, t2 = 1, nextTerm = 0;
    
    if(value == 0){
        return 0;
    } 
    
    // Increment through and print n terms of fibonacci sequence
    for (int i = 1; i <= value; ++i)
    {
        // Prints the first two terms as 1.
        if(i == 1)
        {
            cout << t1;
            continue;
        }
        if(i == 2)
        {
            cout << " " << t2 << " ";
            continue;
        }
        resultArray[i + 1] = t1 + t2;
        t1 = t2;
        t2 = resultArray[i + 1];
        
    }
   return resultArray[]; 
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
                 resultArray[] = calculateFibonacci(value);

                 // Alert the waiting processes that we are done
                 printf("The first %d numbers in Fibonacci are: ", value); 
                 
                 //Print the numbers in order as an array
                 for (int i = 0; i < value; i++) {
                     printf("%d, ", resultArray[i]);
                 }
                 
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
        wait(&status);
//        
//        //Exit status holds the the least significant 8 bits of the status argument 
        resultArray[] = WEXITSTATUS(status);
        
    }
    // If the fork failed handle the exception - end the program with code 1
    else {
        printf("Fork Failed!\n");
        return 1;
    }
    return 0;
}