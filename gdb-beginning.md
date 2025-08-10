## gdb

gdb是一个伟大的调试器, 全称GNU symbolic debugger, 使用它我们可以读取二进制可执行文件的汇编代码, 监测程序运行的故障…………

闲话少说, 我们学习一下如何初步的使用, 以完成最后的 bomb lab

## 常用命令

csapp书上介绍了一些知识, 我们先参考这个  
- q -> quit 退出
- b 函数名 -> breakpoint 在函数入口打断点
- b * 地址 -> 在指令地址处打断点
- d 编号 -> delete 删除一个断点, 断点生成是会返回编号的
- d ->删除全部断点
- r -> run 开始运行
- c -> continue 继续执行到下一个断点
- ni -> nexti 相当于'逐过程'
- si -> stepi 相当于'单步调试' 这两个可以在后面接数字,表示做几次
- finish -> 跳出正在执行的函数,告诉你返回值和PC目前在的地址
- info r 所有寄存器
- info f 看栈帧 栈里面存放的所有东西,%rbp 返回地址 局部变量 栈顶地址

## print 命令

print \$rax 查看寄存器  
/x 参数 十六进制  
/t 参数 二进制  
print ($rax + 8) 输出内容加上8  
print *( int\* ) (\$rsp) 输出该地址的int数据  

## 查看字符数组/字符串
x -> examine 查看内存  
/s：以字符串格式显示  
$rsi：以寄存器 rsi 的值作为首地址  
故 `x/s $rsi` 会打印一个字符串

## gdbinit
在当前目录新建 .gdbinit 文件
往这个文件里写入这样的指令:
```txt
layout asm
layout regs
```
可以让gdb在启动时不需要再输入这些繁琐的东西  
linux系统使用`echo 'set auto-load safe-path /' >  ~/.config/gdb/gdbinit`加载这个配置在用户目录

## 命令行参数自动读入

有些程序读取命令行参数, 我们可以先把参数放在一个文本文件里面, 然后使用:
```
set args args.txt
```