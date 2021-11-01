#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;

    do
    {
        if (clothes.size() == 0)
        {
            answer = 0;
            break;
        }
        map<string, unsigned int> m;

        for (auto k : clothes)
        {
            if (m.find(k[1]) == m.end())
            {
                m[k[1]] = 1;
            }
            else
            {
                m[k[1]]++;
            }
        }
        answer = 1;
        for (auto k : m)
        {
            answer *= (k.second + 1);
        }

    } while (false);


    return answer - 1;

}

int main(void)
{
    solution({ {"yellowhat", "headgear"}, { "bluesunglasses", "eyewear" }, { "green_turban", "headgear" } });
    return 0;
}