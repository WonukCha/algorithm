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

/*
1번 수포자가 찍는 방식: 1, 2, 3, 4, 5,
2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 
3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5,
*/

unsigned char arr1[10] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
unsigned char arr2[10] = { 2, 1, 2, 3, 2, 4, 2, 5 };
unsigned char arr3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };


vector<int> solution(vector<int> answers) {
	vector<int> answer;

	unsigned int index13 = 0;
	unsigned int index2 = 0;

	unsigned int countArr1 = 0;
	unsigned int countArr2 = 0;
	unsigned int countArr3 = 0;
	unsigned int conuntMax = 0;

	for (auto i : answers)
	{
		if (i == arr1[index13])
			countArr1++;
		if (i == arr2[index2])
			countArr2++;
		if (i == arr3[index13])
			countArr3++;

		index13++;
		index2++;

		if (index13 > 9)
			index13 = 0;
		if (index2 > 7)
			index2 = 0;
	}

	conuntMax = max(countArr1, max(countArr2, countArr3));

	if (conuntMax == 0)
		return answer;
	

	if (conuntMax == countArr1)
		answer.push_back(1);
	if (conuntMax == countArr2)
		answer.push_back(2);
	if (conuntMax == countArr3)
		answer.push_back(3);

	return answer;
}

int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	solution({ 1,2,3,4,5 });
	solution({ 1,3,2,4,2 });

	return 0;
}
