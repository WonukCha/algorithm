#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	for (int j = 0; j < n; j++)
	{
		cout << v[j] << '\n';
	}

	return 0;
}