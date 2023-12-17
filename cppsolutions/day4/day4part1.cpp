#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int total = 0;
    string temp;
    cin >> temp;
    for (int i = 0; i < 197; i++)
    {
        int count = 0;
        cin >> temp;
        unordered_set<string> set;
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
                if (count == 0)
                {
                    count = 1;
                }
                else
                {
                    count *= 2;
                }
            }
        }
        total += count;
        count = 0;
    }
    cout << total << endl;
    return 0;
}