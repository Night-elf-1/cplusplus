// globals.h
#ifndef GLOBALS_H
#define GLOBALS_H

// 这个头文件用于声明全局变量和函数。

// 声明全局变量
extern int sharedVar;               // 这里必须加上extern

// 声明全局函数
void modifySharedVar(int value);

#endif // GLOBALS_H