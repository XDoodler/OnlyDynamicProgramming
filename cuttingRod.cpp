/*
	Cutting Rod DP
	link : https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
*/
#include <bits/stdc++.h> 
using namespace std; 

int cuttingRod(int prices[], int length)
{
	int values [length+1];
	values[0] = 0;

	for (int i = 1; i < length+1; ++i)
	{
		int maximum_length = INT_MIN;
		for (int j = 0; j < i; ++j)
		{
			maximum_length = max(maximum_length, prices[j]+values[(i-j-1)]);
		}
		values[i] = maximum_length;
	}

	return values[length];
}
int32_t main() 
{ 
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << cuttingRod(arr,n);
	return 0; 
} 
