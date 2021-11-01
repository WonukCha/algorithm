#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        else
        {
            return a.first < b.first;
        }
    }
};

int solution(vector<int> priorities, int location) {
    int answer = 0;

    priority_queue <int, vector<int>> pq;
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++)
    {
        pq.push(priorities[i]);
        q.push({ priorities[i],i });
    }

    while (!pq.empty())
    {
        auto targetValue = pq.top(); pq.pop();
        bool out = false;
        while (!q.empty())
        {
            auto curValue = q.front(); q.pop();

            if (targetValue == curValue.first)
            {
                answer++;
                if (curValue.second == location)
                {
                    out = true;
                }
                break;
            }
            else
            {
                q.push(curValue);
            }
        }
        if (out)
            break;
    }
    return answer;
}

int main(void)
{
    
    solution({ 2, 1, 3, 2}, 2);
    return 0;
}