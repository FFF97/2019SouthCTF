# 豆破苍穹外传之涅天帝崛起【五】

```
再次输给涅普的豆弟心有不甘，于之后便费劲心思修炼。 后被摩斯斗皇收为弟子，传下一本摩斯功，豆弟苦思冥想了三天也没看明白。

..-./.-../.-/--./  --/---/-....-/.../.----/-....-/--./-----/-./--./
```

## WriteUp

很明显是摩斯电码，但是好像很多人找了好几个解密网站都没有直接解出来

给个网站：https://www.ctftools.com/down/

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

