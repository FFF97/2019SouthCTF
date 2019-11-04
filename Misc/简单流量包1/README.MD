题目就给了个流量包，然后提示一下新生使用wireshark这个软件去分析

流量包丢wireshark里，看到一堆TCP包，追踪TCP流，一开始找到两个页面

> `<input style="width:300px;" type="text" name="address1" value="where is flag?" />`
>
> `<input style="width:300px;" type="text" name="address1" value="can you find me?" />`

然后。。。

就是。。。

一个。。。

师傅给的，假flag

`flag{This_is_wrong_flag}`

555太难过了，不应该是**This is a wrong flag**才对吗



*真flag在下面啦，中间有一堆坏包，大概870的位置，拉过去，然后追踪TCP流，接着就很简单了*
