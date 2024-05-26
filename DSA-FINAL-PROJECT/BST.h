#pragma once
#include"iostream"
#include"string"
#include"Order.h"
using namespace std;


class treeNode
{
private:
	Order order1;
	treeNode* right;
	treeNode* left;
public:
	treeNode();
	treeNode(Order);
	void setLeft(treeNode*);
	void setOrder(Order);
	void getOrder();
	treeNode* getLeft();
	void setKey(string);
	string getKey();
	void setRight(treeNode*);
	treeNode* getRight();
};


class BST
{
private:
	treeNode* Root;
public:
	BST();
	bool isEmpty();
	void InsertinTree(Order);
	void search(int);
};