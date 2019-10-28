#include <stdio.h>
char buf[0x100];
int main()
{
	setbuf(stdin, 0);
	setbuf(stdout, 0);
	printf("%p\n",buf);
	printf("shellcode:");
	read(0,buf,0x100);
	int (*ret)() = (int(*)())buf;
	ret();
	return ;
}
