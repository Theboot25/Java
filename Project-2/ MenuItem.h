#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class MenuItem
{
	private:
		string itemNumber;
		string description;
		double price;
		int timesOrdered;
	//	string* orderReceived;

	public:
		MenuItem(string tNum, string tDes, double tPrice)
		{
			itemNumber = tNum;
			description = tDes;
			price = tPrice;
			timesOrdered = 0;
		}

		MenuItem(){}

		void printData();
		void ordered();
		string getItemNumber();
		double getPrice();
		int getTimesOrdered();
		string getDescription();
};

#endif
