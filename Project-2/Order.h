#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <cstring>

#include "MenuItem.h"

using namespace std;

class Order
{
	private:
		double orderAmount;
		string waiterServed;
		string itemsOrdered;
	public:
		void addItem(string, double price);
		double getTotal();
		void setWaiter(string);
	//	void printTicket();			// To add in future
};
#endif
