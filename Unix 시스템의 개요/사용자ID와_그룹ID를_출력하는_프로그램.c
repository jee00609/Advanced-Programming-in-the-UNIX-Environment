#include "apeu.h"
#include <dirent.h>

int main(void){
	//사용자 ID와 그룹 ID를 출력하는 프로그램

	printf("uid = %d, gid = %d\n",getuid(),getgid());
	exit(0);

}
