#pragma once
#include"iostream"
#include"string"
using namespace std;

class Order
{
private:
	string country;
	string item;
	string sales;
	string order_date;
	string order_id;
	string ship_date;
public:
	Order();
	Order(string c, string i, string s, string order_date, string order_id, string ship_date);
	void setCountry(string c);
	string getCountry();
	void setItem(string i);
	string getItem();
	void setSales(string s);
	string getSales();
	void setOrder_Date(string od);
	string getOrder_Date();
	void setOrder_ID(string or );
	string getOrder_ID();
	void setShip_Date(string s);
	string getShip_Date();
	void Display_Order();
};
