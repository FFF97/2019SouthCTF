#include <stdio.h>
#include <stdlib.h>
char sh[0x10] = "/bin/sh";
int main()
{
 	setbuf(stdin, 0);
	setbuf(stdout, 0);
	char buf[0x20];
	puts("# hack me #");
	system("date");
	printf("root@vm >");
	read(0,buf,0x100);
	return ;
}
