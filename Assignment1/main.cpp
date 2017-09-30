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
    
    if (child_id == 0) {

       printf("Child of _ is % d\n", getpid());
       return 0;

    } 
    else if(child_id > 0){
        
	result = calculateFactorial(value);
    }
    cout << "the result is: " << result << endl;
    return 0;
}


