#ifndef MYQUEUE_H
#define MYQUEUE_H
#include"status.h"
#include<iostream>
typedef struct SqQueue {
	ElemType *data;
	int front;
	int rear;
}SqQueue;
//循环队列
Status InitQueue(SqQueue& Q) {
	Q.data = new ElemType[MAXSIZE];
	if (Q.data == NULL) {
		exit(OVERFLOW);
	}
	Q.front = Q.rear = 0;
	return OK;
}
int Queue_Get_Length(SqQueue &Q) {
	return (Q.rear - Q.front) % MAXSIZE;
}

Status Queue_Push_Back(SqQueue &Q, ElemType e) {
	if ((Q.rear + 1) % MAXSIZE == Q.front) {//队满
		return ERROR;
	}
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
}
Status Queue_Pop_Back(SqQueue &Q, ElemType &e) {
	if (Q.front == Q.rear) {
		return ERROR;
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK;
}

ElemType Queue_Get_Head(SqQueue &Q) {
	if (Q.front != Q.rear) {
		return Q.data[Q.front];
	}
}


typedef struct QNode {
	ElemType data;
	QNode *next;
}QNode,*QueuePtr;

typedef struct LinkQueue {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q) {
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
	return OK;
}
Status LinkQueue_Push_Back(LinkQueue &Q, ElemType e) {
	QNode *p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
Status LinkQueue_Pop(LinkQueue &Q, ElemType &e) {
	if (Q.front == Q.rear) {
		return ERROR;
	}
	QNode *p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) {
		Q.rear = Q.front;
	}
	delete p;
	return OK;
}
ElemType Queue_Get_Head(LinkQueue &Q) {
	if (Q.front != Q.rear) {
		return Q.front->next->data;
	}
}
#endif // !MYQUEUE_H
