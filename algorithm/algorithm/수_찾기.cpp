#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;
bool bArr[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int nInput;
		cin >> nInput;
		bArr[nInput] = true;
	}

	cin >> m;
	for (int j = 0; j < m; j++)
	{
		int nInput;
		cin >> nInput;

		if (nInput > 100004)
		{
			cout << "0\n";
			continue;
		}

		if (bArr[nInput])
		{
			cout << "1\n";
		}
		else
		{
			cout << "0\n";
		}
	}
	return 0;
}