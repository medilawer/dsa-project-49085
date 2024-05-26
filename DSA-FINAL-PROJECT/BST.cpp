#include"BST.h"
#include"iostream"
#include"windows.h"
using namespace std;

/* stoi() used to convert string type fetched data
into int type for insertion and searching purposes
in both linkedlist and BST.
*/

treeNode::treeNode()
{
	order1;
	left = NULL;
	right = NULL;
}
treeNode::treeNode(Order o1)
{
	order1 = o1;
	left = NULL;
	right = NULL;
}
void treeNode::setLeft(treeNode* l)
{
	left = l;
}
void treeNode::setRight(treeNode* r)
{
	right = r;
}
treeNode* treeNode::getLeft()
{
	return left;
}
treeNode* treeNode::getRight()
{
	return right;
}
void treeNode::setKey(string k)
{
	order1.setOrder_ID(k);
}
string treeNode::getKey()
{
	return order1.getOrder_ID();
}
void treeNode::setOrder(Order o)
{
	order1 = o;
}
void treeNode::getOrder()
{
	return order1.Display_Order();
}

										// Binary Search Tree Implementation //

BST::BST()
{
	Root = NULL;
}
void BST::InsertinTree(Order o1)
{
	if (isEmpty())
	{
		treeNode* temp = new treeNode(o1);
		Root = temp;
		return;
	}
	else
	{
		treeNode* temp = Root;
		treeNode* parent;
		while (temp != NULL)
		{
			if (stoi(temp->getKey()) == stoi(o1.getOrder_ID()))
			{
				return;
			}
			else if (stoi(temp->getKey()) > stoi(o1.getOrder_ID()))
			{
				parent = temp;
				temp = temp->getLeft();
			}
			else
			{
				parent = temp;
				temp = temp->getRight();
			}
		}
		treeNode* newNode = new treeNode(o1);
		if (stoi(parent->getKey()) > stoi(o1.getOrder_ID()))
		{
			parent->setLeft(newNode);
		}
		else
		{
			parent->setRight(newNode);
		}
	}
}
bool BST::isEmpty()
{
	if (Root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void BST::search(int order_ID)
{
	treeNode* temp = Root;
	while (temp != NULL)
	{
		if (stoi(temp->getKey()) == order_ID)
		{
			temp->getOrder();
			return;
		}
		else if (stoi(temp->getKey()) > order_ID)
		{
			temp = temp->getLeft();
		}
		else
		{
			temp = temp->getRight();
		}
	}
	return;
}