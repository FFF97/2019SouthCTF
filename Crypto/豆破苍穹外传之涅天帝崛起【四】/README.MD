# 豆破苍穹外传之涅天帝崛起【四】

```
学过贝斯决第三卷，涅普觉得已经天下无敌。
遂再次挑衅豆弟，扬言三天之内鲨了豆弟，并且把他骨灰都扬了。
豆弟闻言大怒，带着物管气势汹汹的打向厦门软件职业技术学院的丐帮，要讨个说法。
顿时间，厦门软件职业技术学院风云齐聚，学院上空乌云密布，两方人马凌空而立，剑拔弩张，只差一点火星引爆。
面对着怒气冲天的豆弟，涅普脸上掀起一抹玩味的笑容，还不等豆弟行动，大喝一声，起阵二十二周天贝斯大阵瞬间成型，刹那间，封锁住了方圆百里的空间。
豆弟心中咯噔一声，怒气全消，眼中浮现出一丝惊惧之色。
二十二周天贝斯大阵，以往只听老师说过，是传说中失传已久的阵法，玄级封锁类阵法，大阵成型时，一只苍蝇都飞不出。
豆弟转念一想师尊的教诲，随后皱起眉头，他只依稀记得老师说过，破解之法，需贯通阵中二十二处漏洞，才可一股作气破解阵法。
只是，这漏洞藏在哪里了呢。

YmFzZX==
IGp1ZV==
IDQ6IF==
dGlhbv==
IHhpbm==
ZyBqaW==
YW4sam==
dW4gev==
aSB5aX==
IHppIF==
cWlhbm==
ZyBide==
IHhpO2==
IGRpIE==
c2hpIF==
a3VuLP==
IGp1bm==
emkged==
aSBob2==
dSBkZV==
IHphaS==
IHd1Lh==
```

## WriteUp

考点是base64隐写，脚本也是网上找的。。。

##  Script 

```python
# encoding: utf-8
def get_base64_diff_value(s1, s2):
    base64chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/'
    res = 0
    for i in xrange(len(s1)):
        if s1[i] != s2[i]:
            return abs(base64chars.index(s1[i]) - base64chars.index(s2[i]))
    return res


def solve_stego():
    with open('贝斯决第四卷.txt', 'rb') as f:
        file_lines = f.readlines()
    bin_str = ''
    for line in file_lines:
        steg_line = line.replace('\n', '')
        norm_line = line.replace('\n', '').decode('base64').encode('base64').replace('\n', '')
        diff = get_base64_diff_value(steg_line, norm_line)
        print (steg_line, norm_line, diff, bin_str)
        pads_num = steg_line.count('=')
        if diff:
            bin_str += bin(diff)[2:].zfill(pads_num * 2)
        else:
            bin_str += '0' * pads_num * 2
    res_str = ''
    for i in xrange(0, len(bin_str), 8):
        res_str += chr(int(bin_str[i:i + 8], 2))
    print (res_str)


solve_stego()
```

