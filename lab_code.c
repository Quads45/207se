//fork and execl code to overcome problem of getting stuck in child process by using wait()
#include <unistd.h>
#include <stdio.h>
#include "sys/types.h"
#include <sys/wait.h>
int main(){
        
pid_t pid;
//create a menu
printf("Please choose one of the following commands:\n1. ls\n2. \n3. who\n");
int option;
scanf("%d",&option);
    int status = 0;
    int i;
    pid= fork() ;
        if(pid!=0) {
                wait(&status);
                printf ( " I am the parent my PID is %d, myPPID is %d, \n ",getpid(),getppid());
        }
	else {
		switch (option){
			case 1:
				execl ("/bin/ls",".",(char*)0);
				break;
			case 2:
				execl ("/bin/sh","sh","/home/tree.sh",(char*) NULL);
				break;
			case 3:
				execl ("/bin/who",".",(char*) NULL);
				break;
			default:
				printf("Invalid Selection");
				break;
        	}
	}
return 0;
}
