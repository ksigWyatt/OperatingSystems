#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

int result = 0;
int value = 0;

int calculateFactorial(int num) {
    
    result = 1;
    return result; 
}

int main(int argc, char** argv) {
    
    // Create a child process
    int child_id = fork();
    
    // Inside the child
    if (child_id == 0) {
        //printf("Child of % s is % d\n", name, getpid());
        result = calculateFactorial(value);
       return 0;
    } 
    // inside the parent
    else {
        printf("Factorial of %d = %d\n", value, result);
        //printf("My id is % d\n", getpid());
        return 0;
    }
    
    
    return 0;
}


