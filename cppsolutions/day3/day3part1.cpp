#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    string strings[140];
    int total = 0;
    int j = 0;
    int valid = 0;
    for (int i = 0; i < 140; i++)
    {
        cin >> strings[i];
    }
    for (int i = 0; i < 140; i++)
    {
        string curr = strings[i];
        for (int j = 0; j < 140; j++)
        {

            string num = "";
            valid = 0;
            if (isdigit(curr[j]))
            {
                if (i != 0 && j != 0)
                {
                    if (strings[i - 1][j - 1] != '.' && !isdigit(strings[i - 1][j - 1]))
                    {
                        valid = 1;
                        cout << "1";
                    }
                }
                if (i != 139 && j != 0)
                {
                    if (strings[i + 1][j - 1] != '.' && !isdigit(strings[i + 1][j - 1]))
                    {
                        valid = 1;
                        cout << "2";
                    }
                }
                if (j != 0)
                {
                    if (strings[i][j - 1] != '.' && !isdigit(strings[i][j - 1]))
                    {
                        valid = 1;
                        cout << "3";
                    }
                }
                while (j < 140 && isdigit(curr[j]))
                {
                    num += curr[j];
                    if (i != 0)
                    {
                        if (strings[i - 1][j] != '.' && !isdigit(strings[i - 1][j]))
                        {
                            valid = 1;
                            cout << "4";
                        }
                    }
                    if (i != 139)
                    {
                        if (strings[i + 1][j] != '.' && !isdigit(strings[i + 1][j]))
                        {
                            valid = 1;
                            cout << "5";
                        }
                    }
                    j++;
                }
                j--;
                if (i != 0 && j != 139)
                {
                    if (strings[i - 1][j + 1] != '.' && !isdigit(strings[i - 1][j + 1]))
                    {
                        valid = 1;
                        cout << "6";
                    }
                }
                if (i != 139 && j != 139)
                {
                    if (strings[i + 1][j + 1] != '.' && !isdigit(strings[i + 1][j + 1]))
                    {
                        valid = 1;
                        cout << "7";
                    }
                }
                if (j != 139)
                {
                    if (strings[i][j + 1] != '.')
                    {
                        valid = 1;
                        cout << "8";
                    }
                }

                if (valid)
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
    }
    cout << total << endl;
    return 0;
}