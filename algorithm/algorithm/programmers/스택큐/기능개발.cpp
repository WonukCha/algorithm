#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> q;
    for (int i = 0; i < progresses.size(); i++)
    {
        int nRemainingDays = 0;
        nRemainingDays = (100 - progresses[i]) / speeds[i];
        if (((100 - progresses[i]) % speeds[i]) > 0)
            nRemainingDays++;

        q.push(nRemainingDays);
    }

    int nMaxRemainingDays = q.front(); q.pop();
    int nProgram = 1;
    while (!q.empty())
    {
        int nRemainingDays = q.front(); q.pop();

        if (nMaxRemainingDays < nRemainingDays)
        {
            answer.push_back(nProgram);
            nMaxRemainingDays = nRemainingDays;
            nProgram = 1;
        }
        else
        {
            nProgram++;
        }

    }

    if (nProgram > 0)
        answer.push_back(nProgram);


    return answer;
}

int main(void)
{
    
    solution({ 93, 30, 55 }, { 1, 30, 5 });
    return 0;
}