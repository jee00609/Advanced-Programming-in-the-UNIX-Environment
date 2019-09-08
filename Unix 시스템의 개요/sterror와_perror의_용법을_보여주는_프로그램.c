#include "apue.h"
#include <errno.h>

int main(int argc, char *argv[]){
	//sterror와 perror의 용법을 보여주는 프로그램

	fprintf(stderr,"EACCES: %s\n",strerror(EACCES));
	errno = ENOENT;
	perror(argv[1]);
	exit(0);

}

/*
#include <string.h>  // C++ 에서는 <cstring>
char* strerror(int errnum);

오류 메세지 문자열을 가리키는 포인터를 얻어온다.
errnum 의 값을 통해 발생하였던 오류에 알맞은 오류 메세지를 가리키는 포인터를 리턴한다. 
이 때 리턴되는 포인터는 문자열 리터럴을 가리키고 있기 때문에 그 내용이 바뀔 수 없다.
참고로 strerror 에 의해 출력되는 오류 메세지는 현재 사용중인 컴파일러나 플랫폼에 따라 다를 수 있다.

errnum ==> 오류 번호
return값 ==> 오류 번호에 해당하는 오류 문자열을 가리키는 포인터

출처: https://modoocode.com/105
*/

/*
stdin == 기본 입력장치(키보드) ==> 입력
stdout == 기본 출력장치(모니터) ==> 출력
stderr == 기본 출력장치(모니터) ==> 에러
stdprn == 프린터 ==> 프린터
stdaux == 통신포트 ==>AUX

fprintf(stderr,"ERROR TEST!"); 로 stderr 출력

TIP) fprintf 는 파일에 작성하는 함수가 아닌 스트림에 출력하는 함수

출처: https://bit.ly/2k0w8HM
*/
