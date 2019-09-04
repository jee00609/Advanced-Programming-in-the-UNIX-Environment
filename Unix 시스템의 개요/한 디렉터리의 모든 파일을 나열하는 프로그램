#include "apeu.h"
#include <dirent.h>

int main(int argc , char *argv[]){
	//한 디렉터리의 모든 파일을 나열하는 프로그램

	DIR *dp;
	Struct dirent *dirp;

	if(argc !=2)
		err_quit("usuage: ls directory_name");

	if((dp = opendir(argv[1])) == NULL)		//opendir() 함수는 매개변수 dirname에 해당하는 디렉토리 스트림을 열고,
		err_sys("can't open %s", argv[1]);	//그 디렉토리 스트림에 대한 포인터를 반환

	while((dirp = readdir(dp)) != NULL)	//readdir() 함수는 파일 서술자 fd에 의해 지목된 디렉토리에서
		printf("%s\n",dirp->d_name);	//dirp에 의해 포인트된 메모리 지역에 있는 dirent 구조체를 읽어, DIR*에 저장한다.
						//count 인자는 메모리 공간의 크기이지만, 무시 가능하다.


	closedir(dp);	//return : 성공시 0, 실패시 -1
	exit(0);

}

///////////////////////////////////////////

/*

apeu란 Advanced Programming in the Unix Environment 의 약자

dirent 구조체는 다음과 같이 선언된다.
 struct dirent
{
    long d_ino;                                /* 아이노드 */
    off_t d_off;                                 /* dirent 의 offset */
    unsigned short d_reclen;            /* d_name 의 길이 */
    char d_name [NAME_MAX+1];   /* 파일 이름(없다면 NULL로 종료) */
}

dirent 구조체는 파일, 또는 디렉토리가 가지고 있는 정보 구조체이다.

d_ino :: 는 파일이 가지고 있는 자신만의 번호 inode를 가리키는 숫자이다.
d_off  :: 는 디렉토리의 시작에서 dirent까지의 거리를 말한다.
d_reclen :: 파일 혹은 디렉토리의 이름의 길이이다. (NULL을 포함하지 않는다.)
d_name :: 파일 혹은 디렉토리의 이름이다. (NULL이라면 파일 없음을 의미)

return :: 성공 : 1, 실패 : -1.

출처: https://sosal.kr/114 [so_sal]
*/
