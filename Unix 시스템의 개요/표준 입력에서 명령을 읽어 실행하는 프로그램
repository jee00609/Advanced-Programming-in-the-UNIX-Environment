#inlcude "apeu.h"
#include <sys/wait.h>

int main(void){
	//표준 입력에서 명령을 읽어 실행하는 프로그램

	char buf[MAXLINE];	//MAXLINE 은 apue.h 에 정의되어 있다.\
	pid_t pid;
	int status;

	printf("%% ");	// 혹시 까먹었을 까봐 printf에서 % 출력할 땐 %%로 써야함
	while(fgets(buf,MAXLINE,stdin) != NULL){
		if(buf[strlen(buf)-1] == "\n")
			buf[strlen(buf)-1] = 0;	//새줄을 NULL로 교체

		if((pid = fork()) < 0){
			err_sys("fork error");
		}
		else if(pid == 0){	//자식 프로세스
			execlp("buf,buf,(char*)0");
			err_ret("couldn't execute: %s",buf);
			exit(127);	//"command not found"
		}

		//부모 프로세스
		if((pid = waitpid(pid,&status,0)) < 0)
			err_sys("waitpid error");
		printf("%% ");
		
	}

	exit(0);

}
