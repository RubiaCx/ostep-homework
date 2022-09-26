#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	char buff[255];
	FILE *fp = NULL;
	FILE *fi = NULL;
	fp = fopen("5-2-out-2.txt", "w");
	fi = fopen("5-2-in.txt", "r");
	int rc = fork();
	if(rc < 0){
		fprintf(stderr,"fork.failed\n");
		exit(1);
	}else if(rc==0){
		fgets(buff, 255, (FILE*)fi);
   		printf("CHILD: %s\n", buff );
   		fclose(fi);
   		fprintf(fp, "子进程写回\n");
   		fclose(fp);
	}
	else{
		fgets(buff, 255, (FILE*)fi);
   		printf("PARENT: %s\n", buff );
   		fclose(fi);
   		fprintf(fp, "父进程写回\n");
   		fclose(fp);
	}
	return 0;	
}
