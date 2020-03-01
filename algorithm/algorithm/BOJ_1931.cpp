#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int>> vConferenceTime;

bool ConferenceTimeSortOperator(const pair<int, int> &p1, const pair<int, int> &p2)
{
	bool result;
	if (p1.second == p2.second)
	{
		result = p1.first < p2.first;
	}
	else
	{
		result = p1.second < p2.second;
	}
	return result;
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int nCount = 0;;
	cin >> nCount;
	vConferenceTime.resize(nCount);

	for (int i = 0; i < nCount; i++)
	{
		cin >> vConferenceTime[i].first;
		cin >> vConferenceTime[i].second;
	}

	sort(vConferenceTime.begin(), vConferenceTime.end(), ConferenceTimeSortOperator);
	

	int nCurrentTime =0;
	int nConferenceCount = 0;
	for (int i = 0; i < nCount; i++)
	{
		if (vConferenceTime[i].first >= nCurrentTime)
		{
			nCurrentTime = vConferenceTime[i].second;
			nConferenceCount++;
		}
	}
	cout << nConferenceCount;
	return 0;
}
