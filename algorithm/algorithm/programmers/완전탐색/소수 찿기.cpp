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

using namespace std;

//TODO
// 너무 코드가 후지다
// isPrime은 에라토스테네스의 체 를 사용
// 원래 하던데로 스텍이나 큐를 사용해서 구현할것
// 다음에 한번 더 풀어보쟈

bool checkNum[10000000];
string gMumbers;
int countPrime = 0;

bool isPrime(int num) {
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void serch(vector<bool> useList, string currentStr,int useIndex)
{
	for (int i = 0; i < useList.size(); i++)
	{
		if (useList[i] == false)
		{
			currentStr[useIndex] = gMumbers[i];
			useList[i] = true;
			int currentValue = stoi(currentStr);
			if (checkNum[currentValue] == false)
			{
				if (isPrime(currentValue))
					countPrime++;
				checkNum[currentValue] = true;
			}
			serch(useList, currentStr, useIndex+1);
			useList[i] = false;
		}
	}
}

int solution(string numbers) {
	checkNum[0] = true;
	checkNum[1] = true;
	gMumbers = numbers;
	string result;
	result.resize(numbers.size());
	vector<bool> useCheckList(numbers.size(),false);

	serch(useCheckList, result,0);

	return countPrime;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	solution("17");
	//solution("011");

	return 0;
}

