#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int mod = 10007;
int arr[1005];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i < n+1; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % mod;
	}

	cout << arr[n];
	return 0;
}