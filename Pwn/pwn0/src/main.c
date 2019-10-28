#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main()
{
	setbuf(stdin,0);
	setbuf(stdout,0);
	char buf[0x70];
	while(1)
	{
		printf("$");
		read(0,buf,0x10);
		if(!strcmp(buf,"getshell\n")) break;
		memset(buf,0,0x20);	
	}
	system("/bin/sh");
	return 0;
}
