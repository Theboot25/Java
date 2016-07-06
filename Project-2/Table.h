#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <cstring>

#include "Order.h"
#include "MenuItem.h"

using namespace std;

class Table
{
	private:
		int tableNum;
		int size;
		int numParty;
		char status;
		string waiterName;
		friend class Order;
		int ordersProcessed;
		int peopleSeated;
		int partiesSeated;
		Order currentOrder;
	public:
		Table::Table(int tNum, int tsize)
	{
		tableNum = tNum;
		size = tsize;
		status = 'E'; 
		string waiterName = "";
		ordersProcessed = 0;
		peopleSeated = 0;
		partiesSeated = 0;
	
	}

	Table()
	{
		tableNum = -1;
		size = -1;
		waiterName = "";
		status = 'E';
		ordersProcessed = 0;
		peopleSeated = 0;
		partiesSeated = 0;
	}

		void setWaiter(string);
		string getWaiter();
		void seatParty(int); 
		void order(string, MenuItem*,int);
		void serve();
		void pay();
		void printData();
		int getOrdersProc();
		char getStatus();
		double getAvgOcc();
};
#endif
