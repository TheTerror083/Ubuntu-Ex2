#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int s101,s102,s103; //parent is 100
	s101 = fork();
 			
	if(s101 == 0)
	{
		s102 = fork();
		waitpid(s102, NULL, 0);
		if(s102==0){
			printf("102 id is: %d \n",getpid());
		}
		else{
			printf("101 id is: %d \n",getpid());
		}
		exit(1);
	}

	if(s101 > 0){
		waitpid(s101, NULL, 0);
		s103 = fork();
		if(s103==0){
			printf("103 id is: %d \n",getpid());
			exit(1);
		}
	}
	waitpid(s103, NULL, 0);
	printf("100 id is: %d \n",getpid());
	return argc;
}
