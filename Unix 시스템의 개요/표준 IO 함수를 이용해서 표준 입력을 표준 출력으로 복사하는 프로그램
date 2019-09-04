#include "apeu.h"

int main(void){
	//표준 I/O 함수를 이용해서 표준 입력을 표준 출력으로 복사하는 프로그램
	int c;
	while((c = getc(stdin)) != EOF)
		if(putc(c,stdout) == EOF)
			err_sys("output error");

	if(ferror(stdin))
		err_sys("input error");

	exit(0);
}
