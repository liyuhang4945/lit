#pragma once
#include "status.h"
#include <iostream>
//typedef int ElemType; //
typedef struct SqList {
	ElemType *data; // 基地址
	int length;
} SqList;

// 顺序表初始化
Status InitList(SqList &L) {
	L.data = new ElemType[MAXSIZE];
	// 分配数组空间
	if (!L.data) {
		exit(MyOVERFLOW);
	}
	L.length = 0;
	return OK;
}

Status SqList_push_back(SqList &L, ElemType e) {
	if (L.data == NULL) {
		return ERROR;
	}
	if (L.length >= MAXSIZE) {
		return ERROR;
	}
	L.data[L.length] = e;
	L.length++;
	return OK;
}
Status GetElem(SqList L, int i, ElemType &e) { // 取值
	if (i < 1 || i > L.length) {
		return ERROR;
	}
	e = L.data[i - 1];
	return OK;
}

int LocateElem(const SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) {
			return i + 1;
		}
	}
	return 0; // 查找失败
}
// 线性表的插入
Status ListInsert(SqList &L, int i, ElemType e) {
	if ((i < 1) || (i > L.length + 1)) { // 非法的i值
		return ERROR;
	}
	if (L.length == MAXSIZE) { // 存储空间已满
		return ERROR;
	}
	for (int j = L.length - 1; j >= i - 1; j--) { // 元素后移
		L.data[j + 1] = L.data[j];
	}
	L.data[i - 1] = e;
	L.length++;
	return OK;
}

// 线性表删除
Status ListDelete(SqList &L, int i) {
	if (i < 1 || i > L.length) {
		return ERROR;
	}
	for (int j = i; j <= L.length - 1; j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return OK;
}
void TraverseSqList(const SqList &L) {
	for (int i = 0; i < L.length; i++) {
		std::cout << " " << L.data[i] << std::endl;
	}
}

Status ClearSqList(SqList &L) {
	L.length = 0;
	return OK;
}
Status  DeStroySqList(SqList &L) {
	L.length = 0;
	delete[] L.data;
	return OK;
}