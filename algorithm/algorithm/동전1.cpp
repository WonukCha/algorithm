#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;


int nArrInput[105];
vector<int> v1;
vector<int> v2;


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> nArrInput[i];
	}
	v1.resize(k + 1);
	v2.resize(k + 1);

	for (int i = 0; i <= k; i += nArrInput[1])
	{
		v1[i] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		fill(v2.begin(), v2.end(), 0);
		for (int j = 0; j <= k; j++)
		{
			v2[j] = v1[j];
			if (j >= nArrInput[i])
			{
				v2[j] += v2[j - nArrInput[i]];
			}
		}
		v1 = v2;
	}

	cout << v1[k];

	return 0;
}