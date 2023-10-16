#include <iostream>

void findMaxAndMin(int a[5], int& maxVal, int& minVal)
{
	maxVal = a[0];
	minVal = a[0];

	for (int i = 1; i < 5; i++)
	{
		if (a[i] > maxVal)
			maxVal = a[i];
		if (a[i] < minVal)
			minVal = a[i];
	}
}

int main1()
{
	int arr[5] = {1, 3, 2, 7, 5};
	int max, min;

	findMaxAndMin(arr, max, min);
	std::cout << "max je: " << max << std::endl;
	std::cout << "min je: " << min << std::endl;
	
	system("pause");

	return 0;
}