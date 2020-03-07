#include<iostream>
#include<vector>
#include<algorithm>

int arr[20000005];
int nCount;
int nInput;

using namespace std;

int main(void)
{
	cin.tie(0);
	cin.sync_with_stdio(false);

	cin >> nCount;
	for (int i = 0; i < nCount; i++)
	{
		cin >> nInput;
		arr[10000000 + nInput]++;
	}
	cin >> nCount;
	for (int i = 0; i < nCount; i++)
	{
		cin >> nInput;
		cout << arr[10000000 + nInput]<< ' ';
	}

	return 0;
}