#include <iostream>
#include <vector>
#include <stack>
#include <set>

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<long long> tower;
    for (int i = 0; i < n; i++)
    {
        long long cur; std::cin >> cur;
        tower.push_back(cur);
    }
    tower.push_back(0);

    std::multiset<long long> human;
    for (int i = 0; i < m; i++)
    {
        long long cur; std::cin >> cur;
        human.insert(cur);
    }

    int ans = 0;
    for (int i = n; i > 0; i--)
    {
        long long cur_width = tower[i-1] - tower[i];
        if (cur_width < 0)
        {
            tower[i-1] = tower[i];
            continue;
        }
        // n + mlogm + n(logm + logm)
        std::multiset<long long>::iterator it = human.upper_bound(cur_width);

        if (it != human.begin())
        {
            it = next(it, -1);
            human.erase(it);
            ans += 1;
        }
    }

    std::cout << ans;
}