# encoding: utf-8
from secret import flag, key


def encrypt(flag, key):
    r = ""
    for i in flag:
        r += chr((ord(i) + key) % 128)
    return r


print encrypt(flag, key).encode("base64")

# output:d31yeAxIQUZJSENDRHNEQUFHSUpCREp1c0F1SXVGdkdBR0J3Qw4=
