# 数据结构——c/c++

## 简述

该项目主要是实现“数据结构”（c/c++版）课程当中的数据结构和算法。

数据结构包括线性表、树、图等，算法包括表达式求值、KMP等。

编译测试使用win下的Makefile，确保环境变量PATH中包含有g++



## 组织

+ 目录结构

  DataStru  
  
  │  log.cpp：日志调试工具   
  
  │  main.cpp：执行入口函数  
  
  │  main.h：声明全局环境，包括全局引入库、全局宏参数、声明通用接口（例如：输出日志）  
  
  │  Makefile：编译配置脚本  
  
  │  
  
  ├─algorithmr：相关算法的整合头文件及各个独立实现  
  
  │  
  
  ├─linear：顺序表和链表的头文件及相关实现  
  
  │  
  
  └─stack：栈的头文件及相关实现   
  
  ​	



+ 接口耦合



## 使用

+ 说明：

  测试编译的gcc和std为

  `gcc version 8.1.0 (x86_64-posix-seh-rev0, Built by MinGW-W64 project)`

  `std=c++17`

+ 支持的命令及使用：

```sh
# 编译得到可执行文件
make

# 删除编译过程中的中间文件，即.o文件
make clean

# 删除中间文件及可执行文件
make clear
```





