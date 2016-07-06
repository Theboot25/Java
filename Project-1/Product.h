#ifndef PRODUCT_H
#define PRODUCT_H

#include <string.h>

using namespace std;

class Product
{
	private:
		int stockNumber;
		string stockName;
		int stockBtp;
		double stockPrice;
		double stockAmount;

	public:
		Product::Product(int itemNumber, string name, int btp, double price, double amount)
		{
			stockNumber = itemNumber;
			stockName = name;
			stockBtp = btp;
			stockPrice = price;
			stockAmount = amount;
		}

		Product(){}

		void setData(int itemNumber, string name, int btp, double price, double amount)
		{
			stockNumber = itemNumber;
			stockName = name;
			stockBtp = btp;
			stockPrice = price;
			stockAmount = amount;
		}

		int getItemNumber()
		{
			return stockNumber;
		}
		string getName()
		{
			return stockName;
		}
		int getType()
		{
			return stockBtp;
		}
		double getPrice()
		{
			return stockPrice;
		}
		double getAmount()
		{
			return stockAmount;
		}

		void setItemNumber(int num)
		{
			stockNumber = num;
		}
		void setName(string itemName)
		{
			stockName = itemName;
		}
		void setType(int byThePound)
		{
			stockBtp = byThePound;
		}
		void setPrice(double itemPrice)
		{
			stockPrice = itemPrice;
		}
		void setAmount(double itemAmount)
		{
			stockAmount = itemAmount;
		}
};

#endif
