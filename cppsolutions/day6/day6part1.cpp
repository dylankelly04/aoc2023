#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    long countone = 0;
    for (long i = 0; i < 60947882; i++)
    {
        long l = i * (60947882 - i);
        cout << l << endl;
        if (l > 475213810151650)
        {
            countone++;
        }
    }
    cout << countone << endl;
    return 0;
}