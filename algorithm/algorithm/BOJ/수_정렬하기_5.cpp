#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int arr[2000001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;

	cin >> n;
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		temp = temp + 1000000;
		arr[temp]++;

	}

	for (int j = 0; j < 2000001; j++)
	{
		while (arr[j])
		{
			cout << j - 1000000 << '\n';
			arr[j]--;
		}
	}
	return 0;
}