#include <string>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int nCurValue = 0;
    int nCurPos = 0;
    int nRemainingCapacity = weight;
    queue<int> q;

    for (int i = 0; i < bridge_length; i++)
    {
        q.push(0);
    }
    // 반복자 생성 

    while (!q.empty())
    {
        nCurValue = q.front(); q.pop();
        nRemainingCapacity += nCurValue;

        if (nCurPos < truck_weights.size())
        {
            if (nRemainingCapacity >= truck_weights[nCurPos])
            {
                nRemainingCapacity -= truck_weights[nCurPos];
                q.push(truck_weights[nCurPos]);
                nCurPos++;
            }
            else
            {
                q.push(0);
            }
        }
        answer++;
    }
    return answer;
}

int main(void)
{
    solution(2,10, { 7, 4, 5, 6 });
    return 0;
}