#include <iostream>
#include <string>
#include <vector>
//using namespace::std;

int main()
{
    int n; 
    std::string s; 
    std::cin >> n >> s;

    std::vector<int> res(n, -1);

    std::vector<std::vector<int>> dp( n, std::vector<int>(2) );
    std::vector<int> last = {-1, -1};
    for (int i = 0; i < n; i++)
    {
        int cur = s[i] - '0';
        
        if (last[cur] == -1)
        {
            last[cur] = i;
            dp[i][0] = i; dp[i][1] = 1;
        }
        else
        {
            dp[i][0] = dp[ last[cur] ][0];
            dp[i][1] = dp[ last[cur] ][1] + 1 - (i - last[cur] - 1);

            last[cur] = i;

            if (dp[i][1] > 0)
                res[i] = dp[i][0] + 1;
            else
            {
                dp[i][0] = i;
                dp[i][1] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << res[i] << ' ';
    }
}