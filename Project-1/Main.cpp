#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cctype>

#include "Product.h"

using namespace std;

void main()
{
	int itemNumber;
	string name;
	int btp;
	double price;
	double number;
	int userInput;
	double total = 0;
	bool flag;
	double amount;
	char exit = 0;
	ifstream input;
	input.open("inventory.txt");
	Product temp[150];
	int numOfItems = 0;
	while(!input.eof())
		{
			input >> itemNumber >> name >> btp >> price >> amount;
			temp[numOfItems] = Product(itemNumber, name, btp, price, amount);
			numOfItems++;
			input.ignore(1000,'\n');
	}
	input.close();
	numOfItems -= 1;
	Product *stock = new Product[numOfItems];

	for(int x=0; x < numOfItems; x++)
		stock[x] = temp[x];

	while(true)
	{
		total = 0; 
		do
		{
			flag = false;
			cout << "Please enter an item number or 0 to check out: ";
			cin >> userInput;
			getchar();
			if (userInput == 0)
				break;
			int y = 0;
			for(y; y < numOfItems; y++)
			{
				if(userInput == stock[y].getItemNumber())
				{
					flag = true;
					cout << "Item found. Enter the amount of " << stock[y].getName() << " being purchased: ";
					cin >> number;
					if(stock[y].getAmount()-number < 0)
					{
						cout << "We do not have that amount of " << stock[y].getName() << " in stock \n";
						break;
					}
					stock[y].setAmount(stock[y].getAmount()-number);
					total += (number * stock[y].getPrice());
				}
			}
			if(flag == false)
				cout << "Item " << stock[y].getName() << " not found.";

		}while(true);
		cout << "Your total is $" << setiosflags(ios::fixed) << setprecision(2) << total << "\n";
		if(total >= 50)
			cout << "For spending over $50, you recieve a 5% discount. Your new total is $" << setiosflags(ios::fixed) << setprecision(2) << (total*.95);
		cout << "Enter C to exit or N for the next customer: ";
		cin >> exit;
		if((exit == 'C') || (exit == 'c'))
			break;
	}
	ofstream output("finalInventory.txt");
	for(int o = 0; o < numOfItems; o++)
		output << stock[o].getItemNumber() << " " << stock[o].getName() << " " << stock[o].getType() << " " << stock[o].getPrice() << " " << stock[o].getAmount() << endl;
	output.close();
	delete []stock;
	getchar();
}
