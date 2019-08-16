#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int nArrInput[305];
int nArrStep_1[305];
int nArrStep_2[305];


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i < n+1; i++)
	{
		cin >> nArrInput[i];
	}
	nArrStep_1[1] = nArrInput[1];
	nArrStep_1[2] = nArrInput[2];
	nArrStep_2[2] = nArrInput[1] + nArrInput[2];

	for (int i = 3; i < n + 1; i++)
	{
		nArrStep_1[i] = max(nArrStep_1[i - 2], nArrStep_2[i - 2])+nArrInput[i];
		nArrStep_2[i] = nArrStep_1[i - 1] + nArrInput[i];
	}

	cout << max(nArrStep_1[n], nArrStep_2[n]);

	return 0;
}