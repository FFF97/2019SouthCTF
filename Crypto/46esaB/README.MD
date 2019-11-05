# 豆破苍穹外传之涅天帝崛起【六】

```
==wVwc3XZBTdflzb091NoV2XmxWYntXMhRmYiJDMlBDOiZWOwQDZhBjMhJ2MmZjY0EWZ1MDZw0nf
```

能看出是一段倒的base64，base64解出来还是一段倒着的flag（再加上一点点废话）

## WriteUp

能看出是一段倒的base64，base64解出来还是一段倒着的flag（再加上一点点废话）

脚本写一下就搞定了

##  Script 

```python
import base64
base=''
s='==wVwc3XZBTdflzb091NoV2XmxWYntXMhRmYiJDMlBDOiZWOwQDZhBjMhJ2MmZjY0EWZ1MDZw0nf'
lenth=len(s)
for i in range(lenth):
	base+=s[-1]
	s=s[:-1]
galf=base64.b64decode(base)
galf=str(galf)[2:-1]
print(galf)

lenth=len(galf)
flag=''
for i in range(lenth):
	flag+=galf[-1]
	galf=galf[:-1]
	print(flag)
```

