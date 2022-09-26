#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	FILE *fp = NULL;
	char buff[255];
	int rc = fork();
	if(rc < 0){
		fprintf(stderr,"fork.failed\n");
		exit(1);
	}else if(rc==0){
		fp = fopen("5-2-in.txt", "r");
		fgets(buff, 255, (FILE*)fp);
   		printf("CHILD: %s\n", buff );
   		fclose(fp);
   		fp = fopen("5-2-out.txt", "a+");
   		fprintf(fp, "子进程写回\n");
   		fclose(fp);
	}
	else{
		fp = fopen("5-2-in.txt", "r");
		fgets(buff, 255, (FILE*)fp);
   		printf("PARENT: %s\n", buff );
   		fclose(fp);
		fp = fopen("5-2-out.txt", "a+");
   		fprintf(fp, "父进程写回\n");
   		fclose(fp);
	}
	return 0;	
}
