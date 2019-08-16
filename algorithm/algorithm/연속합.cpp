#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int nArr[100005];
int nArrInput[100005];
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> nArrInput[i];
	}

	nArr[0] = nArrInput[0];

	for (int i = 1; i < n; i++)
	{
		nArr[i] = max(0, nArr[i - 1]) + nArrInput[i];
	}

	cout << *max_element(nArr, nArr + n);

	return 0;
}
