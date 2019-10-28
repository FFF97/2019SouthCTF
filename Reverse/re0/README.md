# Re:0
`Easy Reverse`

[re100](attachment/re100) \
[output.txt](src/output.txt) \
[re100.c](src/re100.c)

## WriteUp

这题其实相当于逆向的签到题，后来源码都给了，但是做题情况和我预料的差的有点远

[源码](src/re100.c) \
源码很容易就看懂，是对flag的每一个字符的ascii码先加上对应的下标i后，通过判断加上i后的flag[i] 是否在[a-z][A-Z][0-9]里，如果在，就减去数字0的ascii码

这里有两个坑(?)，一个是有的同学可能看漏了一个`flag[i]+=i;`然后解了半天都解不出
还有就是判断的`flag[i]`是加上i的，有点同学在写逆向脚本时漏了这一点导致flag有部分不对

 这里放出我的脚本
### Solver
 ```python
a = [4,1,22,7,8,58,9,62,64,59,60,33,33,30,17,24,19,38,35,22,40,39,26,40,27,32,93,28,31,36,30,50]
b = [4,0,20,4,4,53,3,55,56,50,50,22,21,17,3,9,3,21,17,3,20,18,4,17,3,7,67,1,3,7,0,19]
flag =""
for i in range(32):
	if(a[i]<65 and a[i]>57):
		flag += str(chr(b[i]))
	elif(a[i]>90 and a[i]<97):
		flag += str(chr(b[i]))
	else:
		flag += str(chr(b[i]+ord('0')))
print "flag{%s}"%flag

 ```



## flag

`flag{40D44537822FEA393EA3DB4A37C1370C}`
