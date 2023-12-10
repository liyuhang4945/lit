#include<iostream>
#include"SqList.h"
//#include"LinkList.h"
#include "myStack.h"
#include<print>
void testSqList() {
	SqList L;
	InitList(L);
	SqList_push_back(L, 1);
	TraverseSqList(L);
	DeStroySqList(L);
}

//void testLinkList() {
//	
//	LinkList L;
//	CreateList_R(L,3);
//	TraverseList(L);
//	
//}
void Parlindromic() {
	char s[100];
	std::cin >> s;
	int length = std::strlen(s);
	std::print("s:{},length:{}\n", s, length);
	SqStack stack;
	InitStack(stack);
	bool flag = true;
	int pos = 0;

	for (; pos < length/2; pos++) {
		Stack_Push(stack, s[pos]);
	}
	if (length % 2 != 0) {
		pos++;
	}
	for (; pos < length; pos++) {
		int e;
		Stack_Pop(stack, e);
		std::print("{}:{}\n", e, s[pos]);
		if (s[pos] != e) {
			flag = false;
			break;
		}
	}
	if (flag) {
		std::print("yes");
	} else {
		std::print("no");
	}

}
#include"MyBTree.h"
void testBT() {
	BiTree T{};
	CreateBiTree(T);//
	PriorOrderTraverse(T);
}

#include"MyQueue.h"
void PrintTriangle(int n) {
	//创建队列
	int y = 0;
	LinkQueue lq;
	InitQueue(lq);
	LinkQueue_Push_Back(lq, 1);
	printf("%5d\n", 1);


	for (int i=2; i < n; ++i) {
		int x = 0;
		for (int j = 1; j <= i - 1; j++) {
			
			LinkQueue_Pop(lq,y);
			printf("%5d   ", x + y);
			LinkQueue_Push_Back(lq, x + y);
			x = y;
		}
		LinkQueue_Push_Back(lq, 1);
		printf("%5d\n",1 );
	}
}
class Person {
public:
	int age;
	char a;
	char b;
	Person();
	~Person();

private:

};

Person::Person() {
}

Person::~Person() {
}
int main(int argc, char *argv[]) {
	Person p;
	return 0;
}
