#include <iostream>

int& returnRandom(int a[], int n)
{
	return a[n];
}

int main()
{
	int arr[5] = { 1, 3, 2, 7, 5 };
	int num = 2;

    returnRandom(arr, num) += 1;

	std::cout << arr[num] << std::endl;

	system("pause");
	return 0;
}