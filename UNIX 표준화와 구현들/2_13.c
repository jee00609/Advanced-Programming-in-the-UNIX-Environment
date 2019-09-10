#include "apue.h"
#include <errno.h>
#include <limits.h>

static void pr_sysconf(char *,int);
static void pr_pathconf(char *,char *,int);

int main(int argc, char *argv[]){
	//가능한 모든 sysconf,pathconf 한계 값들을 출력하는 프로그램	

	if(argc != 2)
		err_quit("usuage: a.out <dirname>");

#ifdef ARG_MAX
	printf("ARG_MAX defined to be %d\n",ARG_MAX+0);
#else
	printf("no symbol for ARG_MAX\n");
	
#endif
#ifdef _SC_ARG_MAX
	pr_sysconf("ARG_MAX=",_SC_ARG_MAX);
#else
	printf("no symbol for _SC_ARG_MAX\n");

#endif

/*...sysconf의 나머지 기호들도 비슷한 방식으로 처리한다.*/

#ifdef _PC_MAX_CANON
	printf("MAX_CANON defined to be %d\n",_PC_MAX_CANON+0);
#else
	printf("no symbol for _PC_MAX_CANON\n");

#endif

/*...나머지 pathconf 기호들에 대해서도 비슷한 코드가 반복된다...*/
	exit(0);

}

static void pr_sysconf(char *mesg,int name){
	long val;
	
	fputs(mesg,stdout);
	errno = 0;

	if((val = sysconf(name)) < 0){
		if(errno != 0){
			if(errno == EINVAL)
				fputs("(not supported\n)",stdout);
			else 
				err_sys("sysconf error");
		}
		else {
			fputs("(no limit)\n",stdout);
		}			
	}
	else{
		printf(" %ld\n",val);
	}
}

static void pr_pathconf(char *mesg,char *path,int name){
	long val;
	
	fputs(mesg,stdout);
	errno = 0;

	if((val = pathconf(path,name)) < 0){
		if(errno != 0){
			if(errno == EINVAL)
				fputs("(not supported)\n",stdout);
			else
				err_sys("pathconf error,path = %s",path);
		}
		else{
			fputs("(not limit)\n",stdout);
		}
	}
	else{
		printf(" %ld\n",val);
	}
}

