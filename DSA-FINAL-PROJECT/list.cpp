#include"list.h"
#include"iostream"
#include"windows.h"
using namespace std;


Node::Node()
{
	order1;
	location = 0;
	next = NULL;
}
Node::Node(Order order)
{
	order1 = order;
	location = 0;
	next = NULL;
}
void Node::setData(Order or1)
{
	order1 = or1;
}
string Node::getData()
{
	return order1.getOrder_ID();
}
void Node::setNext(Node* n)
{
	next = n;
}
Node* Node::getNext()
{
	return next;
}
int Node::getLoc()
{
	return location;
}
void Node::setLoc(int l)
{
	location = l;
}
void Node::Display_single()
{
	order1.Display_Order();
}

										// Linkedlist Implementation //

list::list()
{
	count = 0;
	head = NULL;
	tail = NULL;
}
void list::InsertAthead(Order o)
{
	if (isEmpty())
	{
		Node* temp = new Node(o);
		head = temp;
		tail = temp;
		count++;
		temp->setLoc(count);
	}
	else
	{
		Node* temp = new Node(o);
		temp->setNext(head);
		head = temp;
		count++;
		temp->setLoc(count);
	}
	
}

int list::search(int v)
{
	Node* temp = head;
	while (temp != NULL)
	{
		if (stoi(temp->getData()) == v)
		{
			temp->Display_single();
			cout <<"\t\t\tLocation of Record in Linkedlist: "<< temp->getLoc() <<"th Node!"<< endl;
			return temp->getLoc();
		}
		else
		{
			temp = temp->getNext();
		}
	}
	return temp->getLoc();
}
bool list::isEmpty()
{
	if (head == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void list::print()
{
	Node* temp = head;
	while (temp != NULL)
	{
		temp->Display_single();
		temp = temp->getNext();
	}
}
