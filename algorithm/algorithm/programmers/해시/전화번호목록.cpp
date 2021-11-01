#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size(); i++)
    {
        if (phone_book.size() < 2)
            break;

        if (i == phone_book.size() - 1)
            break;

        bool isSame = false;
        for (int j = 0; j < phone_book[i].size(); j++)
        {
            if (phone_book[i][j] != phone_book[i + 1][j])
            {
                isSame = false;
                break;
            }
            else
            {
                isSame = true;
            }
        }

        if (isSame == true)
        {
            answer = false;
            break;
        }
    }
    return answer;
}

int main(void)
{
    solution({ "119", "97674223", "1195524421" });

    return 0;
}