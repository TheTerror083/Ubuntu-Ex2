#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[]) 
{	
	for(int i=3; i>-1; i--)
	{	
		pid_t currPid = fork();
		if(currPid > 0)
		{
			printf("%d", i);
			waitpid(currPid, NULL, 0);
			exit(1);
		}
	}
	return argc;
}
