#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    string strings[140];
    int total = 0;
    int j = 0;
    int valid = 0;
    while (j++ < 140)
    {
        cin >> strings[j];
    }
    for (int i = 0; i < 140; i++)
    {
        for (int j = 0; j < 140; j++)
        {
            string curr = strings[i];
            string num = "";
            if (isdigit(curr[j]))
            {
                valid = 0;
                if (i != 0 && j != 0)
                {
                    if (strings[i - 1][j - 1] != '.')
                    {
                        valid = 1;
                    }
                }
                if (i != 139 && j != 0)
                {
                    if (strings[i + 1][j - 1] != '.')
                    {
                        valid = 1;
                    }
                }
                if (j != 0)
                {
                    if (strings[i][j - 1])
                    {
                        valid = 1;
                    }
                }
                while (j <= 139 && isdigit(curr[j]))
                {
                    num += curr[j];
                    if (i != 0)
                    {
                        if (strings[i - 1][j] != '.')
                        {
                            valid = 1;
                        }
                    }
                    if (i != 139)
                    {
                        if (strings[i + 1][j] != '.')
                        {
                            valid = 1;
                        }
                    }
                    j++;
                }
                j--;
                if (i != 0 && j != 139)
                {
                    if (strings[i - 1][j + 1] != '.')
                    {
                        valid = 1;
                    }
                }
                if (i != 139 && j != 139)
                {
                    if (strings[i + 1][j + 1] != '.')
                    {
                        valid = 1;
                    }
                }
                if (j != 139)
                {
                    if (strings[i][j + 1] != '.')
                    {
                        valid = 1;
                    }
                }
            }
            if (valid == 1)
            {
                total += stoi(num);
                cout << "added: " << stoi(num) << endl;
                num = "";
                valid = 0;
            }
            else
            {
                num = "";
                valid = 0;
            }
        }
    }
    cout << total << endl;
    return 0;
}