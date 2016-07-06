#include <iostream>

using namespace std;

void main ()
{
	char pNames [20][15];
	char c;
	for (int x = 0; x < 20; x++)
		for (int y = 0; y < 15; y++)
		{
			if ((c = cin.get ()) != '\n')
				pNames [x][y] = c;
			else 
				y = 15;
		}
	for (int x = 0; x < 20; x++)
		for (int y = 0; y < 15; y++)
			cout << pNames [x][y];
		cout << endl;
}
