#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int countone = 0;
    for (int i = 0; i < 60; i++)
    {
        if (i * (60 - i) > 475)
        {
            countone++;
        }
    }
    int counttwo = 0;
    for (int i = 0; i < 94; i++)
    {
        if (i * (94 - i) > 2138)
        {
            counttwo++;
        }
    }
    int countthree = 0;
    for (int i = 0; i < 78; i++)
    {
        if (i * (78 - i) > 1015)
        {
            countthree++;
        }
    }
    int countfour = 0;
    for (int i = 0; i < 82; i++)
    {
        if (i * (82 - i) > 1650)
        {
            countfour++;
        }
    }
    cout << countone * counttwo * countthree * countfour << endl;
    return 0;
}