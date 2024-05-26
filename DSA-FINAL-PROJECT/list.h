#include"iostream"
#include"Order.h"
using namespace std;


class Node
{
private:
	Order order1;
	int location;
	Node *next;
public:
	Node();
	Node(Order);
	void setData(Order);
	string getData();                   // order-get comparing purposes
	void setNext(Node*);
	int getLoc();
	void setLoc(int);
	Node *getNext();
	void Display_single();           // displaying orders
};

class list
{
private:
	int count;
	Node *head;
	Node *tail;
public:
	list();
	void InsertAthead(Order);
	int search(int);
	bool isEmpty();
	void print();
};