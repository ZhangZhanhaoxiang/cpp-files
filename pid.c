#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;

	printf("Before fork ...\n");


	switch (pid = fork()) {


		case -1:
			printf("fork call fail\n");
			fflush(stdout);
			exit(1);


		case 0:
			printf("I am child.\n");
			printf("The pid of child is: %d\n", getpid());
			printf("The pid of child's parent is: %d\n", getppid());
			printf("Child exiting...\n");

			exit(0);


		default:
			printf("I am father.\n");
			printf("The pid of parent is: %d\n", getpid());
			printf("The pid of parent's child is: %d\n", pid);
	}

	printf("After fork, program exiting...\n");

	exit(0);
}
