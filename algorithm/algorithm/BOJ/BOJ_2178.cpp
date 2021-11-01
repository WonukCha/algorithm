#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool bCheckMap[101][101];
int  nResultMap[101][101]; 
queue<pair<int, int>> q;

int main(void)
{
	int nResult = 0;
	int row, column;

	cin >> row >> column;

	for (int i = 0; i < row; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < column; j++)
		{
			if (str[j] == '1')
			{
				bCheckMap[i][j] = true;
			}
		}
	}


	q.push({0 , 0 });
	nResultMap[0][0] = 1;
	bCheckMap[0][0] = false;
	while (!q.empty())
	{
		pair<int, int> p;
		p = q.front(); q.pop();
		bCheckMap[p.first][p.second] = false;
		
		//哭率
		if (p.second >= 0 && bCheckMap[p.first][p.second-1] == true)
		{
			nResultMap[p.first][p.second - 1] = nResultMap[p.first][p.second] + 1;
			q.push({ p.first, p.second - 1 });
		}
		//坷弗率
		if (p.second <= column && bCheckMap[p.first][p.second + 1] == true)
		{
			nResultMap[p.first][p.second + 1] = nResultMap[p.first][p.second] + 1;
			q.push({ p.first, p.second + 1 });
		}
		//困率
		if (p.first >= 0 && bCheckMap[p.first-1][p.second] == true)
		{
			nResultMap[p.first-1][p.second] = nResultMap[p.first][p.second] + 1;
			q.push({ p.first-1, p.second});

		}
		//酒阀率
		if (p.first <= row && bCheckMap[p.first + 1][p.second] == true)
		{
			nResultMap[p.first + 1][p.second] = nResultMap[p.first][p.second] + 1;
			q.push({ p.first + 1, p.second });
		}
	}

	cout << nResultMap[row-1][column-1];

	return 0;
}