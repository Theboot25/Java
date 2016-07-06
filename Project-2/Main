#include <iostream>
#include <iomanip>
#include <fstream>

#include "Table.h"

using namespace std;

int Main()
{
	MenuItem tempM[150];
	Table tempT[100];
	ifstream input;
	input.open("config.txt");
	string temp;
	getline(input,temp);
	getline(input,temp);
	int numTables = 0;
	do
	{
		int tempNum, tempSize;

		for(int x = 0; x < int(temp.length()); x++)
		{
			string num;
			string size;
			if(temp[x] == ' ')
			{
				for(int y = 0; y < x; y++)
					num += temp[y];

				for(int z = x+1; z < int(temp.length()); z++)
					size += temp[z];
				
				tempNum = atoi(num.c_str());
				tempSize = atoi(size.c_str());
				break;
			}
		}
		tempT[numTables++] = Table(tempNum, tempSize);
		getline(input,temp);
	}while(temp != "");
	Table *tableList = new Table[numTables];
	for(int x=0; x < numTables; x++)
		tableList[x] = tempT[x];
	getline(input,temp);
	getline(input,temp);
	do
	{
		for(int x = 0; x < int(temp.length()); x++)
		{
			string name;
			string size;
			if(temp[x] == ' ')
			{
				for(int y = 0; y < x; y++)
					name = name + temp[y];

				for(int z = x+1; z < int(temp.length()); z++)
				{
					if(temp[z] != ',')
					{
						string stn;
						int inc = 0;
						while(temp[z+inc] != ',' && z+inc < int(temp.length()))
						{
							stn += temp[z+inc];
							inc++;
						}
						if(stn.length() > 1)
							z += stn.length()-1;
						int tn = atoi(stn.c_str());
						tableList[tn-1].setWaiter(name);
					}				
				}
				break;
			}
		}
		getline(input,temp);
	}while(temp != "");
	getline(input,temp);
	getline(input,temp);
	int numItems = 0;
	do
	{
		string itemNum;
		string descrip;
		string tprice;
		double price;
		for(int x = 0; x < int(temp.length()); x++)
		{
			if(temp[x] == ' ')
			{
				for(int y = 0; y < x; y++)
					 itemNum += temp[y];
				int break1 = x;
				int break2;
				for(int p = x+1; p < int(temp.length()); p++)
				{
					if(temp[p] == ' ')
					{
						break2 = p;
						for(int q = break1; q < break2; q++)
							descrip += temp[q];
						for(int r = break2+1; r < int(temp.length()); r++)
							tprice += temp[r];
					}
				}
				price = atof(tprice.c_str());
				break;
			}
		}
		tempM[numItems++] = MenuItem(itemNum, descrip, price);
		getline(input,temp);
	}while(temp != "");
	MenuItem *menu = new MenuItem[numItems];
	for(int x=0; x < numItems; x++)
		menu[x] = tempM[x];
	MenuItem* menuPointer = menu;
	input.close();
	ifstream input2;
	input2.open("activity.txt");
	getline(input2,temp);
	do
	{
		if(toupper(temp[0]) == 'T')
		{	
			string token = "";
			int currentTable;
			currentTable = atoi(&temp[1]);
			for(int x=0; x<int(temp.length());x++)
			{
				if(temp[x] == ' ')
				{
					int start = x;
					for(int y=start+1; y<=int(temp.length()); y++)				
					{
						if(temp[y] == ' ' || y >= (int(temp.length())))
						{
							for(int z=start+1; z<y; z++)
								token += temp[z];
							break;
						}
					}
				}
				switch(toupper(token[0]))
				{
					case 'P': tableList[currentTable-1].seatParty(atoi(&token[1])); break;
					case 'O': tableList[currentTable-1].order(temp, menuPointer, numItems); break;
					case 'S': tableList[currentTable-1].serve(); break;
					case 'C': tableList[currentTable-1].pay(); break;
					default:;
				}
			}
		}		
		getline(input2,temp);
	}while(temp != "");
	input2.close();
	for(int x=0; x<16; x++)
		cout << menu[x].getItemNumber() << " >> " << menu[x].getTimesOrdered() << endl;
	int questionNum;
	int numParty = 0;
	int i = 0;
	do{
		cout << "Select a question number.\n";
		cout << "1. How many tables are occupied right now?\n";
		cout << "2. How many open orders right now?\n";
		cout << "3. How many orders have been processed so far?\n";
		cout << "4. What is the average occupancy of paritcular table today?\n";
		cout << "5. What are the top 3 popular entries today?\n";
		cout << "6. How many tables are currently served\n";
		cout << "7. Which was the most popular table?\n";
		cin >> questionNum;
		switch(questionNum)
		{
			case 1: 
				{
					for(i = 0; i < 100; i++)
					{
						if((tempT[i].getStatus() == 'S') || (tempT[i].getStatus() == 'O') || (tempT[i].getStatus() == 'F'))
							cout << "Table " << i+1 << endl;
					}
				}break;
			case 2:
				{
					for(i = 0; i < 100; i++)
					{
						if(tempT[i].getStatus() == 'O')
							cout << "Table " << i+1 << endl;
					}
				}break;
			case 3:
				{
					for(i = 0; i < 100; i++)
					{
						int totalOrders = totalOrders + tempT[i].getOrdersProc();
						cout << totalOrders << endl;
					}
				}break;
			case 4:
				{
					int selection;
					cout << "Enter table number >> ";
					cin >> selection;

					double output = tableList[selection-1].getAvgOcc();
					
					cout << "Table " << selection << "'s average occupancy is " << output << endl << endl;
				}break;
			case 5:
				{
					int previousMax = 0;
					for(int x=0;x<3;x++)
					{
						int store = 0;
						for(int y=0;y<numItems;y++)
						{
							if(menu[y].getTimesOrdered() > store)
							{
								if(menu[y].getTimesOrdered() < previousMax)
								{
									store = menu[y].getTimesOrdered();
								}
								else if(x == 0)
								{
									store = menu[y].getTimesOrdered();
								}
							}
						}
						switch(x)
						{
							case 0: cout << "Most popular: "; break;
							case 1: cout << "Second most popular: "; break;
							case 2: cout << "Third most popular: "; break;
						}
						for(int p=0;p<numItems;p++)
						{
							if(menu[p].getTimesOrdered() == store)
								cout << menu[p].getDescription() << ",";
						}
						cout << '\b' << " " << endl;
						previousMax = store;
					}
								
					cout << endl << endl;

				}break;
			case 6:
				{
					for(i = 0; i < 100; i++)
					{
						if(tempT[i].getStatus() == 'F')
							cout << "Table " << i+1 << endl;
					}
				}break;
			case 7:
				{	
					for(i = 0; i < 100; i++)
					{
						if (tempT[i].getOrdersProc() > numParty)
							numParty = tempT[i].getOrdersProc();
					}
					cout << "Table " << i+1 << endl;
				}break;
			default:;
		}
	}while(questionNum != 0);

	delete []tableList;
	delete []menu;
	getchar();
}
