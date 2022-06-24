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
#include<tuple>
#include <bitset>

using namespace std;

// 3¿ù 1ÀÏ ~ 11¿ù 30

class FlowerInfo
{
public:
	FlowerInfo(uint8_t startMonth, uint8_t startDay, uint8_t endMonth, uint8_t endDay)
		:mStartMonth(startMonth),
		mStartDay(startDay),
		mEndMonth(endMonth),
		mEndDay(endDay)
	{

	}
	uint8_t mStartMonth = 0;
	uint8_t mStartDay = 0;
	uint8_t mEndMonth = 0;
	uint8_t mEndDay = 0;
};

pair<uint32_t, uint32_t> MaxEndValue(queue<pair<uint32_t, uint32_t>>& q)
{
	uint32_t maxMonth = 0;
	uint32_t maxDay = 0;

	uint32_t curMonth = 0;
	uint32_t curDay = 0;
	while (!q.empty())
	{
		curMonth = q.front().first;
		curDay = q.front().second;
		q.pop();

		if (curMonth > maxMonth)
		{
			maxMonth = curMonth;
			maxDay = curDay;
		}
		else if (curMonth == maxMonth && curDay > maxDay)
		{
			maxMonth = curMonth;
			maxDay = curDay;
		}
	}

	return { maxMonth ,maxDay };
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	uint32_t count = 0;
	uint32_t input[4] = {0,0,0,0};
	cin >> count;

	vector<FlowerInfo> vFlowerInfo;

	for (size_t i = 0; i < count; i++)
	{
		cin >> input[0];
		cin >> input[1];
		cin >> input[2];
		cin >> input[3];

		if (input[0] < 3 && input[2] < 3)
			continue;

		if (11 < input[0] && 11 < input[2])
			continue;

		vFlowerInfo.emplace_back(FlowerInfo(input[0], input[1], input[2], input[3]));
	}
	sort(vFlowerInfo.begin(), vFlowerInfo.end(), [](FlowerInfo first, FlowerInfo second)
		{
			if (first.mStartMonth == second.mStartMonth)
			{
				if (first.mStartDay == second.mStartDay)
				{
					if (first.mEndMonth == second.mEndMonth)
					{
						return first.mEndDay < second.mEndDay;
					}
					else
					{
						return first.mEndMonth < second.mEndMonth;
					}
				}
				else
				{
					return first.mStartDay < second.mStartDay;
				}
			}
			else
			{
				return first.mStartMonth < second.mStartMonth;
			}
		});

	uint32_t result = 0;
	uint32_t curMonth = 3;
	uint32_t curDay = 1;
	const uint32_t destMonth = 11;
	const uint32_t destDay = 30;

	queue<pair<uint32_t, uint32_t>> q;

	for (auto it : vFlowerInfo)
	{
		if (curMonth > destMonth)
			break;
		if (curMonth == destMonth && curDay == destDay)
			break;

		if (it.mStartMonth > curMonth)
		{
			auto pair = MaxEndValue(q);
			curMonth = pair.first;			
			curDay = pair.second;
			result++;
		}
		else if (it.mStartMonth == curMonth && curDay > it.mStartDay)
		{
			auto pair = MaxEndValue(q);
			curMonth = pair.first;
			curDay = pair.second;
			result++;
		}
		q.push({ it.mEndMonth ,it.mEndDay });
	}

	cout << result;
	return 0;
}
