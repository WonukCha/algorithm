#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<list>
#include<utility>
#include<stack>
#include<string>
#include<map>
#include<set>

using namespace std;
vector<vector<int>> nCityToCityPrice(101, vector<int>(101, 100000 * 100 + 1));
int arrPath[101][101];
int nCityCount, nBusLineCount;

void printPath()
{
	for (int nStart = 1; nStart <= nCityCount; nStart++)
	{
		for (int nEnd = 1; nEnd <= nCityCount; nEnd++)
		{
			if (arrPath[nStart][nEnd] == 0)
			{
				cout << arrPath[nStart][nEnd] << '\n';
				continue;
			}

			vector<int> vPath;
			int nCount = 0;
			int nCur;
			vPath.push_back(nStart);
			nCur = nStart;
			nCount++;
			
			while (nCur != nEnd)
			{
				nCur = arrPath[nCur][nEnd];
				vPath.push_back(nCur);
				nCount++;
			}
			cout << nCount << ' ';

			for (auto path : vPath)
			{
				cout << path << ' ';
			}
			cout << '\n';

		}
	}
}

int main(void)
{
	cin.tie(0);
	cin.sync_with_stdio(false);

	cin >> nCityCount;
	cin >> nBusLineCount;

	for (int i = 0; i < nBusLineCount; i++)
	{
		int nStart, nEnd, nPrice;
		cin >> nStart >> nEnd >> nPrice;
		if (nCityToCityPrice[nStart][nEnd] >= nPrice)
		{
			nCityToCityPrice[nStart][nEnd] = nPrice;
			//arrPath[nStart][nEnd].push_back(nStart);
			//arrPath[nStart][nEnd].push_back(nEnd);
			arrPath[nStart][nEnd] = nEnd;
		}
	}

	for (int nStopover = 1; nStopover <= nCityCount; nStopover++)// 경유지
	{
		for (int nStartCity = 1; nStartCity <= nCityCount; nStartCity++)// 출발지
		{
			for (int nEndCity = 1; nEndCity <= nCityCount; nEndCity++)//도착지
			{
				if (nEndCity == nStartCity)
				{
					nCityToCityPrice[nStartCity][nEndCity] = 0;
					continue;
				}
				
				if (nCityToCityPrice[nStartCity][nEndCity] > nCityToCityPrice[nStartCity][nStopover] + nCityToCityPrice[nStopover][nEndCity])
				{
					nCityToCityPrice[nStartCity][nEndCity] = nCityToCityPrice[nStartCity][nStopover] + nCityToCityPrice[nStopover][nEndCity];
					arrPath[nStartCity][nEndCity] = arrPath[nStartCity][nStopover];
				}
			}
		}
	}

	for (int i = 1; i <= nCityCount; i++)
	{
		for (int j = 1; j <= nCityCount; j++)
		{
			if (nCityToCityPrice[i][j] == 100000 * 100 + 1)
			{
				cout << '0' << ' ';
			}
			else
			{
				cout << nCityToCityPrice[i][j] << ' ';
			}
		}
		cout << '\n';
	}

	printPath();

	return 0;
}