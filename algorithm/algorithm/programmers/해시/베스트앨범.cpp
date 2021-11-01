#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

struct MyStruct
{
    int nSumPlays;
    vector<pair<int, int>> v;
};

struct cmp
{
    bool operator()(MyStruct t, MyStruct u)
    {
        return t.nSumPlays < u.nSumPlays;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    map<string, MyStruct> sumMap;
    priority_queue < MyStruct, vector<MyStruct>, cmp> pq;
    pair<int, int> p;

    for (int i = 0; i < genres.size(); i++)
    {
        if (sumMap.find(genres[i]) != sumMap.end())
        {
            sumMap[genres[i]].nSumPlays += plays[i];
        }
        else
        {
            sumMap[genres[i]].nSumPlays = plays[i];
        }
        sumMap[genres[i]].v.push_back(make_pair(plays[i], i));
    }

    for (auto k : sumMap)
    {
        pq.push(k.second);
    }

    while (!pq.empty())
    {
        MyStruct st;
        st = pq.top(); pq.pop();
        sort(st.v.begin(), st.v.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first)
            {
                return a.second < b.second;
            }
            else
            {
                return a.first > b.first;
            }
            });
        queue<int> q;
        for (auto k : st.v)
        {
            q.push(k.second);
        }

        if (q.size() > 0)
        {
            answer.push_back(q.front());
            q.pop();
        }
        if (q.size() > 0)
        {
            answer.push_back(q.front());
            q.pop();
        }
    }

    return answer;
}

int main(void)
{
    
    solution({ "classic", "pop", "classic", "classic", "pop" }, { 500, 600, 150, 800, 2500 });
    return 0;
}