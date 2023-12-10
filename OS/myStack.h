#pragma once
#include"status.h"
#include<iostream>


typedef struct myStack {
	ElemType *base;
	ElemType *top;
	int stackSize;
}SqStack;

//初始化栈
Status InitStack(SqStack &S) {
	S.base = new ElemType[MAXSIZE];
	if (S.base == nullptr) {
		exit(MyOVERFLOW);
	}
	S.top = S.base;
	S.stackSize = MAXSIZE;
	return OK;
}


//入栈
Status Stack_Push(SqStack &S, ElemType e) {
	if (S.top - S.base == S.stackSize) {
		return ERROR;
	}

	*S.top = e;
	S.top++;
	return OK;
}
//出栈
Status Stack_Pop(SqStack &S, ElemType &e) {

	if (S.top == S.base) {
		return ERROR;
	}
	S.top--;
	e = *S.top;
	return OK;
}
//获取栈顶元素
ElemType Stack_GetTop(SqStack &S) {
	if (S.top == S.base) {
		return ERROR;
	}
	return *(S.top - 1);
}
//销毁栈
Status DestroyStack(SqStack &S) {
	if (S.base != S.top) {
		return ERROR;
	}
	delete[] S.base;
	S.base = NULL;
	S.top = NULL;
	S.stackSize = 0;
	return OK;
}
//判断栈是否为空
bool Stack_empty(SqStack &S) {
	if (S.base == S.top) {
		return true;
	}else {
		return false;
	}
}