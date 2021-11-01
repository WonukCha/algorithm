#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

int arr[10];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k,answer = 0;
	cin >> n >> k;


	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int j = n - 1; j >= 0; j--)
	{
		int t = k / arr[j];
		answer = answer + t;
		k = k - arr[j] * t;
	}

	cout << answer;
	return 0;
}
