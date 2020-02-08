#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

pair<int, int> arr[100005];

#define X first;
#define Y second;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 0;
	int answer = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].Y;
		cin >> arr[i].X;
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
	{
		if (t > arr[i].second)
			continue;
		answer++;
		t = arr[i].first;
	}

	cout << answer;

	return 0;
}
