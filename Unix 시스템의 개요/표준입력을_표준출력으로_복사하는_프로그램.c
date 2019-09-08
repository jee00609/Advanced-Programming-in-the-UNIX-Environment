#include "apeu.h>
#define BUFFSIZE 4096

int main(void){
	//표준 입력을 표준 출력으로 복사하는 프로그램
	int n;
	char buf(BUFFSIZE);
	
	while((n=read(STDN_FILENO,buf,BUFFSIZE))> 0){
		if(write(STDOUT_FILENO,buf,n) != n){
			err_sys("write error");
		}
		
		if(n<0){
			err_sys("read error");
		}
	}


	exit(0);
}
