#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    string strings[140];
    long total = 0;
    int tempj = 0;
    string tempnum = "";
    int num1 = 0;
    int num2 = 0;
    for (int i = 0; i < 140; i++)
    {
        cin >> strings[i];
    }
    for (int i = 0; i < 140; i++)
    {
        for (int j = 0; j < 140; j++)
        {
            if (strings[i][j] == '*')
            {
                // presetup
                num1 = 0;
                num2 = 0;
                // top parts
                if (i > 0 && j > 0 && isdigit(strings[i - 1][j - 1]))
                {
                    tempj = j - 1;
                    tempnum = "";
                    while (tempj >= 0 && isdigit(strings[i - 1][tempj]))
                    {
                        tempj--;
                    }
                    tempj++;
                    while (tempj < 140 && isdigit(strings[i - 1][tempj]))
                    {
                        tempnum += strings[i - 1][tempj];
                        tempj++;
                    }
                    tempj--;
                    if (num1 == 0)
                    {
                        num1 = stoi(tempnum);
                    }
                    else if (num2 == 0)
                    {
                        num2 = stoi(tempnum);
                    }
                    else
                    {
                        cout << "three inputs" << endl;
                        break;
                    }
                    if (tempj == j - 1 && j < 139 && isdigit(strings[i - 1][j + 1]))
                    {
                        tempj = j + 1;
                        tempnum = "";
                        while (tempj < 140 && isdigit(strings[i - 1][tempj]))
                        {
                            tempnum += strings[i - 1][tempj];
                            tempj++;
                        }
                        if (num1 == 0)
                        {
                            num1 = stoi(tempnum);
                        }
                        else if (num2 == 0)
                        {
                            num2 = stoi(tempnum);
                        }
                    }
                }
                else if (i > 0 && j < 140 && isdigit(strings[i - 1][j]))
                {
                    tempj = j;
                    tempnum = "";
                    while (tempj < 140 && isdigit(strings[i - 1][tempj]))
                    {
                        tempnum += strings[i - 1][tempj];
                        tempj++;
                    }
                    if (num1 == 0)
                    {
                        num1 = stoi(tempnum);
                    }
                    else if (num2 == 0)
                    {
                        num2 = stoi(tempnum);
                    }
                }
                else if (i > 0 && j < 139 && isdigit(strings[i - 1][j + 1]))
                {
                    tempj = j + 1;
                    tempnum = "";
                    while (tempj < 140 && isdigit(strings[i - 1][tempj]))
                    {
                        tempnum += strings[i - 1][tempj];
                        tempj++;
                    }
                    if (num1 == 0)
                    {
                        num1 = stoi(tempnum);
                    }
                    else if (num2 == 0)
                    {
                        num2 = stoi(tempnum);
                    }
                }
                // side parts
                if (j > 0 && isdigit(strings[i][j - 1]))
                {
                    tempj = j - 1;
                    tempnum = "";
                    while (tempj >= 0 && isdigit(strings[i][tempj]))
                    {
                        tempj--;
                    }
                    tempj++;
                    while (tempj < 140 && isdigit(strings[i][tempj]))
                    {
                        tempnum += strings[i][tempj];
                        tempj++;
                    }
                    tempj--;
                    if (num1 == 0)
                    {
                        num1 = stoi(tempnum);
                    }
                    else if (num2 == 0)
                    {
                        num2 = stoi(tempnum);
                    }
                }
                if (j < 139 && isdigit(strings[i][j + 1]))
                {
                    tempj = j + 1;
                    tempnum = "";
                    while (tempj < 140 && isdigit(strings[i][tempj]))
                    {
                        tempnum += strings[i][tempj];
                        tempj++;
                    }
                    if (num1 == 0)
                    {
                        num1 = stoi(tempnum);
                    }
                    else if (num2 == 0)
                    {
                        num2 = stoi(tempnum);
                    }
                }
                // bottom parts
                if (i < 139 && j > 0 && isdigit(strings[i + 1][j - 1]))
                {
                    tempj = j - 1;
                    tempnum = "";
                    while (tempj >= 0 && isdigit(strings[i + 1][tempj]))
                    {
                        tempj--;
                    }
                    tempj++;
                    while (tempj < 140 && isdigit(strings[i + 1][tempj]))
                    {
                        tempnum += strings[i + 1][tempj];
                        tempj++;
                    }
                    tempj--;
                    if (num1 == 0)
                    {
                        num1 = stoi(tempnum);
                    }
                    else if (num2 == 0)
                    {
                        num2 = stoi(tempnum);
                    }
                    else
                    {
                        cout << "three inputs" << endl;
                        break;
                    }
                    if (tempj == j - 1 && j < 139 && isdigit(strings[i + 1][j + 1]))
                    {
                        tempj = j + 1;
                        tempnum = "";
                        while (tempj < 140 && isdigit(strings[i + 1][tempj]))
                        {
                            tempnum += strings[i + 1][tempj];
                            tempj++;
                        }
                        if (num1 == 0)
                        {
                            num1 = stoi(tempnum);
                        }
                        else if (num2 == 0)
                        {
                            num2 = stoi(tempnum);
                        }
                    }
                }
                else if (i < 139 && j < 140 && isdigit(strings[i + 1][j]))
                {
                    tempj = j;
                    tempnum = "";
                    while (tempj < 140 && isdigit(strings[i + 1][tempj]))
                    {
                        tempnum += strings[i + 1][tempj];
                        tempj++;
                    }
                    if (num1 == 0)
                    {
                        num1 = stoi(tempnum);
                    }
                    else if (num2 == 0)
                    {
                        num2 = stoi(tempnum);
                    }
                }
                else if (i < 139 && j < 139 && isdigit(strings[i + 1][j + 1]))
                {
                    tempj = j + 1;
                    tempnum = "";
                    while (tempj < 140 && isdigit(strings[i + 1][tempj]))
                    {
                        tempnum += strings[i + 1][tempj];
                        tempj++;
                    }
                    if (num1 == 0)
                    {
                        num1 = stoi(tempnum);
                    }
                    else if (num2 == 0)
                    {
                        num2 = stoi(tempnum);
                    }
                }
                // end
                total += num1 * num2;
                cout << num1 << " * " << num2 << " = " << total << endl;
            }
        }
    }
    cout << total << endl;
    return 0;
}