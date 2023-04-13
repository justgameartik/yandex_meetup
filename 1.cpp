#include <iostream>
#include <string>
#include <stack>
#include <vector>

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> glass(n);
    
    std::string s;
    getline(std::cin, s);
    for (int i = 0; i < n; i++)
    {
        getline(std::cin, s);
        glass[i] = s;
    }

    int k; 
    std::cin >> k;

    std::stack<int> numbers, chars;
    int sum_of_ingridients = 0;
    for (int i = 0; i < k; i++)
    {
        int number; 
        char ch;
        std::cin >> s >> number >> ch;

        numbers.push(number);
        chars.push(ch);
        sum_of_ingridients += number;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (i < (n - sum_of_ingridients - 1) )
        {
            std::cout << glass[i] << '\n';
            continue;
        }

        for (int j = 0; j < m; j++)
        {
            if (glass[i][j] == ' ')
                glass[i][j] = chars.top();
        }

        numbers.top() -= 1;
        if (numbers.top() == 0)
        {
            chars.pop();
            numbers.pop();
        }

        std::cout << glass[i] << '\n';
    }

    std:: cout << glass[n-1] << '\n';
}




















// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<string> stakan(n);
//     string str; getline(cin, str);
//     for (int i = 0; i < n; i++)
//     {
//         getline(cin, str);
//         stakan[i] = str;
//     }

//     int k; cin >> k;
//     stack<int> amount; stack<char> symbol;
//     string s;
//     int total = 0;
//     for (int i = 0; i < k; i++)
//     {
//         int cur_amount;
//         char cur_symbol;
//         cin >> s >> cur_amount >> cur_symbol;
//         amount.push(cur_amount);
//         symbol.push(cur_symbol);
//         total += cur_amount;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         string cur_s;
//         if (n - (i+1) - total > 0 || i == n-1)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 cur_s.push_back(stakan[i][j]);
//             }
//         }
//         else
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if (stakan[i][j] == ' ')
//                     cur_s.push_back(symbol.top());
//                 else
//                     cur_s.push_back(stakan[i][j]);
//             }
//             amount.top() -= 1;
//             if (amount.top() == 0)
//             {
//                 amount.pop(); symbol.pop();
//             }
//         }

//         cout << cur_s << '\n';
//     }
// }