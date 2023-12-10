#pragma once
#include"status.h"
#include<iostream>
#include<print>
typedef int Elem;


typedef struct Lnode {
	Elem data;
	Lnode *next;
}Lnode, *LinkList;

Status InitList(LinkList &L) {
	L = new Lnode;
	L->next = NULL;
	return OK;
}

Status GetElem(LinkList &L, int i, ElemType &e) {
	Lnode *p = L->next;//��ʼ��p ָ����Դ�ڵ�
	int j = 1;
	while (p && j < i) {//���ɨ��֪��pΪ�ջ�pָ���i��λ��
		p = p->next;
		j++;
	}
	if (p == NULL || j > i) {//iֵ���Ϸ� i��n or i<= 0
		return ERROR;
	}
	e = p->data;
	return OK;
}


Lnode *LocateElem(LinkList &L, ElemType e) {
	Lnode *p = L->next;
	while (p && p->data!=e) {//���ɨ��֪��pΪ�ջ�pָ���i��λ��
		p = p->next;
	}
	return p;
}

Status ListInsert(LinkList&L,int i,ElemType e) {
	Lnode *p = L;
	int j = 0;
	while (p!=NULL&&j<(i-1)) {
		p = p->next;
		j++;
	}

	if (p == NULL || j > (i - 1)) {
		return ERROR;
	}
	Lnode *s = new Lnode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status ListDelete(LinkList &L, int i) {
	Lnode *p = L;
	int j = 0;

	while ((p->next)&&(j<-1)) {
		p = p->next;
		j++;
	}
	if (p->next == NULL || j > (i - 1)) {
		return ERROR;
	}
	Lnode *q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}

void CreateList_H(LinkList &L, int n) {
	InitList(L);

	for (int i = 0; i < n; i++) {
		Lnode *p = new Lnode;
		std::cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

void CreateList_R(LinkList &L, int n) {
	InitList(L);
	Lnode *r = L;
	for (int i = 0; i < n; i++) {
		Lnode *p = new Lnode;
		std::cin >> p->data;

		p->next = r->next;
		r->next = p;
		r = p;
	}
}

void TraverseList(const LinkList&L) {
	Lnode *p = L->next;
	while (p) {
		//todo
		std::println("{0}", p->data);
		p = p->next;
	}
}
//�����Դ�ͷ���ĵ������ʾ�ǵݼ������
//�����һ�㷨ɾ����������ֵ����min��С��max������min < max��ͬʱ�ͷŽ��ռ䡣
void DeleteBetweenMinMax(LinkList &L, ElemType min,ElemType max) 	{
	if (L==nullptr) {
		return;
	}
	Lnode *p = L;
	while (p) {
		if (p->next->data > min && p->next->data < max) {
			//����min��С��max
			Lnode *t = p->next;//��ʱ���������ͷŽ��
			p = p->next->next;//ָ����ƣ�ָ��ɾ��������һ��
			delete t;
		} else {
			p = p->next;
		}
	}
}