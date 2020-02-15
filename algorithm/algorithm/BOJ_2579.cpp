#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<utility>

using namespace std;

int main(void)
{
	cin.tie(0);
	cin.sync_with_stdio(false);

	
	int n = 0;
	cin >> n;
	vector<int> arrinput;
	for (int i = 0; i < n; i++)
	{
		int nTemp = 0;
		cin >> nTemp;
		arrinput.push_back(nTemp);
	}
	vector<pair<int,int>> arr(n);
	//index는 계단 숫자
	//first는 계단 밟은 카운트 1일때
	//second는 계단 밟은 카운트 2일때

	arr[0].first = arrinput[0];
	arr[0].second = arrinput[0];
	arr[1].first = arrinput[1];
	arr[1].second = arrinput[1] + arrinput[0];

	for (int i = 2; i < n; i++)
	{
		int nMaxValue = 0;
		if (arr[i - 2].first >arr[i - 2].second)
		{
			nMaxValue = arr[i - 2].first;
		}
		else
		{
			nMaxValue = arr[i - 2].second;
		}
		arr[i].first = nMaxValue + arrinput[i];
		arr[i].second = arr[i-1].first + arrinput[i];
	}

	int nResult = 0;
	if (arr[n - 1].first > arr[n - 1].second)
	{
		nResult = arr[n - 1].first;
	}
	else
	{
		nResult = arr[n - 1].second;
	}
	cout << nResult;
	return 0;
}