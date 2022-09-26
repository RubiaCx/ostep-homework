#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int x = 100;
	printf("\n");
	int rc = fork();
	if(rc < 0){
		fprintf(stderr,"fork.failed\n");
		exit(1);
	}else if(rc==0){
		x = 200;
		printf("CHILD(pid:%d) x=%d\n",(int)getpid(),x);
	}
	else{
		x = 300;
		printf("PARENT(pid:%d) x=%d\n",(int)getpid(),x);
	}
	return 0;
}


