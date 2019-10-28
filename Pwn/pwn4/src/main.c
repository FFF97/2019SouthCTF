#include<stdio.h>
#include<stdlib.h>
int key = 0;
int main()
{
	char buf[0x100];
	puts("hey#");
	scanf("%d",&key);
	if(key!=0x1919)
	{
		printf("114514\n");
	}
	else exit(1337);
	puts("Go?");
	read(0,buf,0x80);
	printf(buf);
	if(key==0x1919)
	{
		system("/bin/sh");
	}
	return ;
}
