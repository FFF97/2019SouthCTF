# 豆破苍穹外传之涅天帝崛起【三】

```python
涅普获得《贝斯决第二卷》后，修炼一日千里，这天，学院安排他出门试炼，行至水泮，只见水中突有水龙跃起，口吐人言道：“雷普，你当真逃得出魂天帝的手心？”，涅普闻言大惊，后背已然湿了大片，四处观望，并无魂族之人，当下便定下心来，刚想好生盘问水龙，再定睛一看，水龙早已不翼而飞，只剩一本《贝斯决第三卷》静静的浮在空中。
涅普取过《贝斯决第三卷》，揭开来，发现这下大部分都看得懂了，只是有一些紧要之处的章法被墨汁涂改，无法窥得其中真意。

# /usr/bin/python

base64_table = ['=', '0', '9', 'A', '■', 'e', '/', 'g', 'B', 'Z', 'a', '1', 'b', '3', 'f', '+', '4', '2', '8', 'Q', 'l',
          'm', '5', 'C', 'Y', '6', '7', 'c', 'N', 'h', 'i', 'O', 'd', '■', 'E', 'k', 'M', 'F', 'G', 'H', 'I', 'n',
          'o', 'J', 't', 'u', 'U', 'V', 'q', 'r', '■', 'v', 'p', 'w', 'x', 'y', 'z', 'K', 'L', 'R', 'j', 's', 'P',
          'S', 'T', ][::-1]

def encode_b64(s):
l = len(s)
i = 0
result = ''
while i < l:
  s1 = s[i]
  b1 = bin(ord(s1))[2:]
  cb1 = b1.rjust(8, '0')
  i += 1
  if i >= l:
      cb2 = '00000000'
  else:
      s2 = s[i]
      b2 = bin(ord(s2))[2:]
      cb2 = b2.rjust(8, '0')
  i += 1
  if i >= l:
      cb3 = '00000000'
  else:
      s3 = s[i]
      b3 = bin(ord(s3))[2:]
      cb3 = b3.rjust(8, '0')
  cb = cb1 + cb2 + cb3
  rb1 = cb[:6]
  rb2 = cb[6:12]
  rb3 = cb[12:18]
  rb4 = cb[18:]
  ri1 = int(rb1, 2)
  ri2 = int(rb2, 2)
  ri3 = int(rb3, 2)
  ri4 = int(rb4, 2)
  if i - 1 >= l and ri3 == 0:
      ri3 = -1
  if i >= l and ri4 == 0:
      ri4 = -1
  result += base64_table[ri1] + base64_table[ri2] + base64_table[ri3] + base64_table[ri4]
  i += 1
return result

print encode_b64(flag)
# output: H7+OHZ■bGLc3nac3■aRDk7RfGo■bEJAiInvcDq==
```



## WriteUp

base64码表替换，就给脚本了，懒狗真的懒得写解说了

##  Script 

```python
# /usr/bin/python
import base64

base64_table = ['=', '0', '9', 'A', 'W', 'e', '/', 'g', 'B', 'Z', 'a', '1', 'b', '3', 'f', '+', '4', '2', '8', 'Q', 'l',
                'm', '5', 'C', 'Y', '6', '7', 'c', 'N', 'h', 'i', 'O', 'd', 'D', 'E', 'k', 'M', 'F', 'G', 'H', 'I', 'n',
                'o', 'J', 't', 'u', 'U', 'V', 'q', 'r', 'X', 'v', 'p', 'w', 'x', 'y', 'z', 'K', 'L', 'R', 'j', 's', 'P',
                'S', 'T', ][::-1]


old_base64_table = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
                 'T',
                 'U', 'V', 'W', 'X', 'Y', 'Z',
                 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                 'u',
                 'v', 'w', 'x', 'y', 'z',
                 '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                 '+', '/', '=', ]

for i in 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/':
    s='H7+OHZ'+i+'bGLc3nac3'+i+'aRDk7RfGo'+i+'bEJAiInvcDq=='
    res = ""
    for n in s:
        res += old_base64_table[base64_table.index(n)]
    print(i,end='***')
    print(base64.b64decode(res))

print("******************************************")

for i in 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/':
    s='H7+OHZ'+'Q'+'bGLc3nac3'+i+'aRDk7RfGo'+i+'bEJAiInvcDq=='
    res = ""
    for n in s:
        res += old_base64_table[base64_table.index(n)]
    print(i,end='***')
    print(base64.b64decode(res))

print("******************************************")

for i in 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/':
    s='H7+OHZ'+'Q'+'bGLc3nac3'+'n'+'aRDk7RfGo'+i+'bEJAiInvcDq=='
    res = ""
    for n in s:
        res += old_base64_table[base64_table.index(n)]
    print(i,end='***')
    print(base64.b64decode(res))

print("******************************************")

for i in 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/':
    s='H7+OHZ'+'Q'+'bGLc3nac3'+'n'+'aRDk7RfGo'+'R'+'bEJAiInvcDq=='
    res = ""
    for n in s:
        res += old_base64_table[base64_table.index(n)]
    print(i,end='***')
    print(base64.b64decode(res))
```

##  Flag
