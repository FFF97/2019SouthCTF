#include <stdio.h>
void eval()
{
	system("/bin/sh");
}
int main()
{
	setbuf(stdin, 0);
	setbuf(stdout, 0);
	char buf[0x20];
	puts("no pwn no life!");
	printf("input:");
	read(0,buf,0x100);
	return ;
	
}
