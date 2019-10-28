# 豆破苍穹(一)
```
《2019-10-11 14:34:51 豆圣成弟》
据那场双弟之战已过了许久，自豆弟突破那境界后便毫无音讯，但成弟之后的瞬间留下的神秘压缩包却无人可破，而如今你却受到神秘声音的指引知道了密码与时间戳相关，故事就此展开……
```
[flag.zip](attachment/flag.zip)
## WriteUp

由于压缩包密码和时间戳相关，而题目又有一个精确的时间，那么很容易联想到密码就是这时间转时间戳
```python
import time
dt = "2019-10-11 14:34:51"
timeArray = time.strptime(dt, "%Y-%m-%d %H:%M:%S")
timestamp = time.mktime(timeArray)

print "%d"%timestamp
#1570775691
```
然后成功解开压缩包获得flag

## flag

`flag{d9832a587d8a4de1e69c94e1d907d421}`
