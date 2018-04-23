//fork and execl code to overcome problem of getting stuck in child process by using wait()
#include <unistd.h>
#include <stdio.h>
#include "sys/types.h"
#include <sys/wait.h>
int main(){

pid_t pid;
int ping_fork;
//create a menu
printf("Please choose one of the following commands:\n1. ls\n2. pwd\n3 Ping www.apple.com\n4 Ping www.coventry.ac.uk and www.sunderland.ac.uk\n");
int option;
//get the user input
scanf("%d",&option);
    int status = 0;
    int i;
    pid= fork() ;

	if (pid == 0) {
		//To show the seperation of parent and child
		sleep(5);
		//use switch case to act on the user input
		switch (option){
			case 1:
				printf("I am the child my PID is %d.\n",getpid());
				execl ("/bin/ls",".",(char*) NULL);
				break;
			case 2:
				printf("I am the child my PID is %d.\n",getpid());
				execl ("/bin/pwd",".",(char*) NULL);
				break;
			case 3:
				printf("I am the child my PID is %d.\n",getpid());
				execl ("/bin/ping", "ping", "-c 4","www.apple.com", (char*) NULL);
				break;
			case 4:
				if (pid == 0){
					printf("I am the child my PID is %d.\n",getpid());
					//execl ("/bin/ping", "ping", "-c 4", "www.sunderland.ac.uk", (char*) NULL);
				}else {
					ping_fork = fork();
					if (ping_fork == 0){
						wait(&status);
						printf("I am the child my PID is %d.\n",getpid());
						//execl("/bin/ping", "ping","-c 4", "www.coventry.ac.uk", (char*) NULL);
					}else {
						printf ( " I am the parent my PID is %d, myPPID is %d, \n and my child's PID is %d\n ",getpid(),getppid(),pid);
					}
				}
				break;
			default:
				printf("Invalid Selection");
				break;
        	}
	}
	if(pid!=0) {
                printf ( " I am the parent my PID is %d, myPPID is %d, \n and my child's PID is %d\n ",getpid(),getppid(),pid);
        }
return 0;
}

