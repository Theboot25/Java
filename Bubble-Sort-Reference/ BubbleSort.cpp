#include "BubbleSort.h"

void BubbleSort (char pNames [][], int NumElements)
{
	bool	Sorted;
	int		i;

	do	{
		Sorted = true;
		NumElements--;
		for (i = 0; i < NumElements; i++)
			if (pNames [i] > pNames [i + 1])
					{
					char Temp [];
					Temp []			= pNames [i];
					pNames [i]		= pNames [i + 1];
					pNames [i + 1]	= Temp [];
					Sorted			= false;
					}
			if (pNames [i] == pNames [i + 1])
				for (int j = 0; j < 15; j++)
				{
					if (pNames [i][j] < pNames [i][j]);
						j = 15;
					else if (pNames [i][j] > pNames [i][j])
					{
						char	Temp [];
						Temp []			= pNames [i];
						pNames [i]		= pNames [i + 1];
						pNames [i + 1]	= Temp [];
						Sorted			= false;
					}
					
		} while (!Sorted);
}
