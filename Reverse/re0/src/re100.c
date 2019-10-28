#include <stdio.h>
char flag[]="********************************";
int main()
{
    for(int i=0;i<32;i++)
    {
        flag[i]+=i;
        if(flag[i]>='0'&&flag[i]<='9')
        {
            flag[i]=flag[i]-'0';
        }
        else if(flag[i]>='a'&&flag[i]<='z')
        {
            flag[i]-='0';
        }
        else if(flag[i]>='A'&&flag[i]<='Z')
        {
            flag[i]-='0';
        }

        printf("%02d",flag[i]);
        if((i+1)%4==0) puts("");
        else printf(",");
    }

    return 0;
}
