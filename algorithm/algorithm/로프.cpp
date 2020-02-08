#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

int nArr[100000];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int nMaxOfValue = 0;

	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> nArr[i];
	}

	sort(nArr, nArr + n);

	for (int j = 1; j <= n; j++)
	{
		nMaxOfValue = max(nMaxOfValue, nArr[n - j] * j);
	}
	cout << nMaxOfValue;
	return 0;
}
