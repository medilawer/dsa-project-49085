#include"Order.h"
#include"iostream"

Order::Order()
{
	this->country = "";
	this->item = "";
	this->sales = "";
	this->order_date = "";
	this->order_id = "";
	this->ship_date = "";
}
Order::Order(string c, string i, string s, string order_date, string order_id, string ship_date)
{
	this->country = c;
	this->item = i;
	this->sales = s;
	this->order_date = order_date;
	this->order_id = order_id;
	this->ship_date = ship_date;
}
void Order::setCountry(string c)
{
	this->country = c;
}
string Order::getCountry()
{
	return country;
}
void Order::setItem(string i)
{
	this->item = i;
}
string Order::getItem()
{
	return item;
}
void Order::setSales(string s)
{
	this->sales = s;
}
string Order::getSales()
{
	return sales;
}
void Order::setOrder_Date(string od)
{
	this->order_date = od;
}
string Order::getOrder_Date()
{
	return order_date;
}
void Order::setOrder_ID(string or )
{
	this->order_id = or ;
}
string Order::getOrder_ID()
{
	return order_id;
}
void Order::setShip_Date(string s)
{
	this->ship_date = s;
}
string Order::getShip_Date()
{
	return ship_date;
}
void Order::Display_Order()
{
	cout << "\t\t\t-----> Country Name: " << getCountry() << "\n\t\t\t-----> Item is: " << getItem() << "\n\t\t\t-----> Sales are: " << getSales() << "\n\t\t\t-----> Order-Date is: " << getOrder_Date() << "\n\t\t\t-----> Order-ID: " << getOrder_ID() << "\n\t\t\t-----> Shipping-Date is: " << getShip_Date() << "\n";
}