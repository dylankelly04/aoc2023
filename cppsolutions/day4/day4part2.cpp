#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int total = 0;
    string temp;
    int multipliers[197];
    for (int i = 0; i < 197; i++)
    {
        multipliers[i] = 0;
    }
    cin >> temp;
    for (int i = 0; i < 197; i++)
    {
        int count = 0;
        multipliers[i]++;
        cin >> temp;
        set<string> set;
        cin >> temp;
        while (temp != "|")
        {
            set.insert(temp);
            cin >> temp;
        }
        for (int j = 0; j < 25; j++)
        {
            cin >> temp;
            if (set.find(temp) != set.end())
            {
                count++;
            }
        }
        for (int j = 1; j <= count; j++)
        {
            if (i + j >= 197)
            {
                break;
            }
            multipliers[i + j] += multipliers[i];
        }
        count = 0;
    }
    for (int i = 0; i < 197; i++)
    {
        total += multipliers[i];
    }
    cout << total << endl;
    return 0;
}