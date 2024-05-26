#pragma once
#include"iostream"
#include"fstream"
#include"string"
#include"windows.h"
#include"list.h"
#include"BST.h"
#include"Order.h"
#include"chrono"
using namespace std;
using namespace std::chrono;


void menu();                         // prototype for displaying menu


long int LON, t_Linkedlist, t_BinaryST =0;

int main()
{

	// ********************************* Reading Data ********************************** //
	ifstream inFile;
	inFile.open("DataSet.csv");

	if (!inFile.is_open())
	{
		cout << "File opening error occurred! " << endl;
		Sleep(1000);
		exit(0);
	}

	string country = "";
	string item = "";
	string sales = "";
	string orderID = "";
	string Order_date = "XX-XX-XXXX";
	string Ship_date = "XX-XX-XXXX";

	// Linkedlist Creation

	list l1;

	// Binary Search Tree

	BST t1;


	int records = 0;           // to checked if it inserted all the records 

	cout << "\n\t\t\t\t\t  Just a moment, while we store Data!" << endl;
	while (inFile.good())
	{
		getline(inFile, country, ',');
		getline(inFile, item, ',');
		getline(inFile, sales, ',');
		getline(inFile, Order_date, ',');
		getline(inFile, orderID, ',');
		getline(inFile, Ship_date, '\n');


		
		Order o1(country, item, sales, Order_date, orderID, Ship_date);   // order object to be inserted
		l1.InsertAthead(o1);             // linkedlist insertion
		
		t1.InsertinTree(o1);             // BST Insertion

		records++;
		/*
		cout << "Country: " << country << endl;
		cout << "Item: " << item << endl;
		cout << "Sales: " << sales << endl;
		cout << "Order-date: " << Order_date << endl;
		cout << "Order-ID: " << orderID << endl;
		cout << "Ship-date: " << Ship_date << endl;

		*/
		
	}
	inFile.close();
	system("cls");
	cout <<"\n\t\t\t\t\t\t  [ "<< records <<" ]"<< " Records! " << endl;
	Sleep(2000);
	// ********************************* Reading Data *********************************** //


	// ************ User Menu *************** // 

	int choice;
	do {

		int number = 0;
		int number1 = 0;

		menu();


		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("Color 0A");
			cout << "\n\t\t\t-----> Enter Order-ID you want to search: ";
			cin >> number;
			auto start = high_resolution_clock::now();
			cout << endl << endl << endl;
			LON = l1.search(number);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			t_Linkedlist = duration.count();
			cout << "\n\t\t\tSearch through Linkedlist: " << t_Linkedlist << " Microseconds! " << endl;
			Sleep(5000);
			break;
		}
		case 2:
		{
			system("Color 0A");
			cout << "\n\t\t\t-----> Enter Order-ID you want to search: ";
			cin >> number1;
			auto start = high_resolution_clock::now();
			cout << endl << endl << endl;
			t1.search(number1);
			auto stop = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(stop - start);
			t_BinaryST = duration.count();
			cout << "\t\t\tLocation of Record in Binary Search Tree: " << LON << "th Node!" << endl;
			cout << "\n\t\t\tSearch through Binary Search Tree: " << t_BinaryST << " Microseconds! " << endl;
			Sleep(5000);
			break;
		}
		case 3:
			system("Color 0A");
			system("cls");
			cout << "\n\t\t\t---------------------> TIME-TAKEN <---------------------" << endl;
			cout << "\t\t\t---> Linked-list to search the " << LON << "th Node is: " << t_Linkedlist << " Micro-Seconds!" << endl;
			cout << "\t\t\t---> Binary Search Tree to search the " << LON << "th Node is: " << t_BinaryST << " Micro-Seconds!" << endl;
			Sleep(5000);
			break;
		case 4:
			exit(0);
			break;
		}
	} while (choice != 4);

	system("PAUSE");
	return 0;

}


void menu()
{
	system("Color 0A");
	system("cls");
	cout << "\t\t\t..............Searching 100K Records of orders across the globe.............." << endl;
	cout << "\t\t\t-----> Enter (1) to Search Record Stored in Linkedlist: " << endl;
	cout << "\t\t\t-----> Enter (2) to Search Record Stored in Binary Search Tree: " << endl;
	cout << "\t\t\t-----> Enter (3) to view the time-taken of the previous search: " << endl;
	cout << "\t\t\t-----> Enter (4) to Exit" << endl;
	cout << "\t\t\t-----> Your Choice: ";
}