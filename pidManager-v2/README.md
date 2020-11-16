# pidManager-threads


#instructions

Problems
Modify hw1: using thread to create subprocesses do requesting and releasing pid numbers

Language
•	whichever preferred

Requirements
•	pid range: 300-5000
•	thread number: 20
•	wait for a random period of time after pid creation
•	release pid after waiting
•	proper output

#functions
int requestpid();  //get real pid number
int allocatepid();  //assign pseudo-pid
int allocate_map();  //find valid location
void releasepid(int index);  
void *threadfunc(void *arg);  //use thread to create subprocesses
