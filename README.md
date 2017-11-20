# Operating Systems - COP 4610

This repo is a workspace for all homework assignments that were worked on in my senior Operating Systems class. The class emphasised C/C++ languages as well as the Java Runnable Interface in order to take advantage of the system calls & threads on various systems. 

## Topics 
- Threading
- Process Communication
- Multi Processing
- Deadlocks
- Synchronization of Processes

### Compilers
- Cygwin GCC / C++ Compiler
- Javac & JVM

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

### Assignment 2 - Oct 12, 2017                                                                        
_Requirements - not required to submit code_ 
- Write a C/C++ program using the fork() system call that generates the Fibonacci sequence in the child process. 
- The number of the sequence will be provided in the command line. _For example, if 5 is provided, the first five numbers in the Fibonacci sequence will be output by the child process._  
- Because the parent and child processes have their own copies of the data it will be necessary for the child to output the sequence.
- Have the parent invoke the wait() call to wait for the child process to complete before exiting the program. 
- Perform necessary error checking to ensure that a non-negative number is passed on the command line.

### Assignment 3 - November 7, 2017
_Requirements_
- Develop a Java monitor, called Garden. Three threads work in the garden and their names are Jordan, Charles, and Tracy.
- Your Garden class must be based on Lock and Condition.
- Their coordination must work as described: 
    - Jordan digs 10 holes.
    - Charles plants something in these 10 holes.
    - Tracy fills these ten holes after being planted.
    - Jordan will wait if there are five unfilled holes.
    - Charles will wait if all holes are with plants.
    - Tracy will wait if all holes are either empty or already filled.
    - It takes Jordan less than 100 milliseconds to dig a hole.
    - It takes Charles less than 500 milliseconds to plant something in a hole.
    - It takes Tracy less than 500 milliseconds to fill a hole.
- Use conditions and locks to solve the problems. Do not use Java's synchronized, wait, and notify commands.
