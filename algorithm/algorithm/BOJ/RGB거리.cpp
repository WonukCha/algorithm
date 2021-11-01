#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int nArrInput[1005][3];
int nArrRGB[1005][3];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n;i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> nArrInput[i][j];
		}
	}

	nArrRGB[0][0] = nArrInput[0][0];
	nArrRGB[0][1] = nArrInput[0][1];
	nArrRGB[0][2] = nArrInput[0][2];
	
	for (int i = 1; i < n; i++)
	{
		nArrRGB[i][0] = min(nArrRGB[i - 1][1], nArrRGB[i - 1][2]) + nArrInput[i][0];
		nArrRGB[i][1] = min(nArrRGB[i - 1][0], nArrRGB[i - 1][2]) + nArrInput[i][1];
		nArrRGB[i][2] = min(nArrRGB[i - 1][1], nArrRGB[i - 1][0]) + nArrInput[i][2];
	}
	cout << min(nArrRGB[n-1][0], min(nArrRGB[n-1][1], nArrRGB[n-1][2]));

	return 0;

}