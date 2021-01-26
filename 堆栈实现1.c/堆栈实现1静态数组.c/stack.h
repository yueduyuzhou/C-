#pragma once

#define STACK_TYPE int    //宏定义

void push(STACK_TYPE value);    //压入堆栈

void pop();    //弹出栈顶

STACK_TYPE top();    //返回栈顶

int is_empty();    //检测堆栈是否为空

int is_full();    //检测堆栈是否已满


