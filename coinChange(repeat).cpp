/*
	Coin Change Repeated
	https://www.geeksforgeeks.org/coin-change-dp-7/
*/
#include<bits/stdc++.h> 
using namespace std;

int coins(int c[],int n, int m) //n = size of array; m = 1 to coins
{
	int tmp[n][m+1];

	for (int i = 0; i < n; ++i)
	{
		tmp[i][0] = 1;
	}
	int x,y;
	//cout << "hi"<<endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < m+1; ++j)
		{
			if(i==0)
			{
				if(j - c[i] >= 0) x = tmp[i][j - c[i]];
				else x = 0;

				tmp[i][j] = x;
			}
			else
			{
				if(j - c[i] >= 0) x = tmp[i][j - c[i]];
				else x = 0;

				y = tmp[i-1][j];

				tmp[i][j] = x+y;
			}
		}
	}

	/*for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m+1; ++j)
		{
			cout << tmp[i][j] <<' ';
		} cout << endl;
	}*/
	return tmp[n-1][m];

}
int32_t main() 
{ 
	int tt;
	cin >> tt;
	while(tt--)
	{
		int n,m;
		cin >> n >> m;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		cout << coins(arr, n, m) << endl;

	}
	return 0; 
} 

/*
	0	1	2	3	4    1->m

2	1	0	1	0	1

3	1	0	1	1	1

4	1	0	1	1	2

*/
