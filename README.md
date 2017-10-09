# Operating Systems - COP 4610

This repo is a workspace for all homework assignments that were worked on in my senior Operating Systems class. The class emphasised C/C++ languages in order to take advantage of the system calls on various systems. 

## Topics 
- Threading
- Process Communication
- Multi Processing

### Compiler
Cygwin GCC / C++ Compiler

## Assignments

### Assignment 1 - Oct 3, 2017                                                                                    
_Requirements_
- Initialize two global integer variables called "result" and "value ". Assign both variables the value zero. 
- Read a number from the command line and store it in the global variable “value”
- The program should only accept numbers between 1 and 5.
- The final calculated answer MUST be assigned to the global variable "result".
- The result MUST be printed by the parent process. 
- Have the parent invoke the wait() system call to wait for the child to calculate the factorial and return the answer to the parent process. 
- Include proper error checking. 
- Include comments in your program.
- You MUST print the output INSIDE the parent process.

### Assignment 2 - Oct 10, 2017                                                                        
_Requirements_
- Write a C/C++ program using the fork() system call that generates the Fibonacci sequence in the child process. 
- The number of the sequence will be provided in the command line. _For example, if 5 is provided, the first five numbers in the Fibonacci sequence will be output by the child process._  
- Because the parent and child processes have their own copies of the data it will be necessary for the child to output the sequence.
- Have the parent invoke the wait() call to wait for the child process to complete before exiting the program. 
- Perform necessary error checking to ensure that a non-negative number is passed on the command line.