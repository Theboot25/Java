include "Order.h"

using namespace std;

void Order::addItem(string itemNum, double price)
{
	orderAmount += price;
	itemsOrdered += itemNum;
}
double Order::getTotal()
{return orderAmount;}

void Order::setWaiter(string tWaiter)
{waiterServed = tWaiter;}

/*void printTicket()		// To add in future
{

}*/
