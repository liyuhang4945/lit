#ifndef MYBTREE_H
#define MYBTREE_H
#include"status.h"
#include<iostream>
typedef struct BiTNode {
	ElemType data;
	BiTNode *lchild, *rchild;
}BiTnode,*BiTree;
void CreateBiTree(BiTree& T) {
	char ch;
	std::cin >> ch;
	if (ch == '#') {
		T = NULL;
	} else {
		T = new BiTNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}

}
//先序遍历
void PriorOrderTraverse(BiTree &T) {
	if (T) {
		std::cout << T->data << std::endl;
		PriorOrderTraverse(T->lchild);
		PriorOrderTraverse(T->rchild);
	}
}void InOrderTraverse(BiTree &T) {
	if (T) {
		
		PriorOrderTraverse(T->lchild);
		std::cout << T->data << std::endl;
		PriorOrderTraverse(T->rchild);
	}
}void RearOrderTraverse(BiTree &T) {
	if (T) {
		PriorOrderTraverse(T->lchild);
		PriorOrderTraverse(T->rchild);
		std::cout << T->data << std::endl;
	}
}

//统计二叉树叶子结点
int NodeCount(BiTree &T) {
	if (T == NULL) {
		return 0;
	} else {
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
	}
}
#endif // !MYBTREE_H
