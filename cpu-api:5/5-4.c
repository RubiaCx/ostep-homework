#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char *argv[],char *env[])
{
	int x=0;
	int rc = fork();
	if(rc < 0)
	{
		fprintf(stderr,"fork.failed\n");
		exit(1);
	}else if(rc==0)
	{
		printf("CHILD(pid:%d)\n",(int)getpid());
		execl("/bin/ls","ls","-l","/etc",(char *)0);  
		execle("/bin/ls","ls","-l","/etc",(char *)0,env); 
		execlp("/bin/ls","ls","-l","/etc",(char *)0);  
		char *argv[] = {"ls","-l","/etc",(char *)0};
        execv("/bin/ls",argv); 
        execvp("/bin/ls",argv);  
	}
	else{
		printf("PARENT(pid:%d)\n",(int)getpid());
		execl("/bin/ls","ls","-l","/etc",(char *)0);  
		execle("/bin/ls","ls","-l","/etc",(char *)0,env); 
		execlp("/bin/ls","ls","-l","/etc",(char *)0);  
		char *argv[] = {"ls","-l","/etc",(char *)0};
        execv("/bin/ls",argv); 
        execvp("/bin/ls",argv); 
    }
	return 0;
}
