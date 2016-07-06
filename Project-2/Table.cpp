#include "Table.h"
#include <iostream>

using namespace std;

void Table::setWaiter(string x)
{
  waiterName = x;
  currentOrder.setWaiter(x);
} 

string Table::getWaiter()
{return waiterName;}

void Table::seatParty(int pSize)
{
	
	if(waiterName != "" && pSize <= size && status == 'E')
	{
		status = 'S';
		peopleSeated += pSize;
		partiesSeated++;
	}

}

void Table::order(string data, MenuItem* tempPointer, int arraySize)							
{
	if(status  == 'S')
	{
		string currentItem = "";
		int lastBreak = int(data.length());

		for(int x = int(data.length())-1; x > 0; x--)
		{
			if(toupper(data[x]) == 'O')
				break;
			else if(data[x] == ' ')
			{
				for(int y = x+1; y < lastBreak; y++)
					currentItem += data[y];
				
				std::remove(currentItem.begin(), currentItem.end(), ' ');

				for(int z=0; z < arraySize; z++)
				{
					
					if(currentItem.compare(tempPointer[z].getItemNumber()) == 0)
					{
						tempPointer[z].ordered();
						currentOrder.addItem(currentItem, tempPointer[z].getPrice());
					}
				}
				lastBreak = x;
				currentItem = "";
			}
		}
		status = 'O';
	}
}

void Table::serve()
{
	if(status == 'O')
		status = 'F';
}

void Table::pay()
{
	if(status != 'E')
	{
		status = 'E';
		ordersProcessed++;
	}
}

int Table::getOrdersProc()
{return ordersProcessed;}

double Table::getAvgOcc()
{return double(peopleSeated/partiesSeated);}

char Table::getStatus()
{return status;}

/*void Table::printData()
{
//	cout << tPtr;
}*/
