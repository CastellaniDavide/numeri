/**
 * @file numeri.cpp
 *
 * @version 01.01 2020-11-4
 *
 * @brief https://training.olinfo.it/#/task/numeri/statement
 *
 * @ingroup numeri
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Castellani Davide
 *
 * Contact: contacts@castellanidavide.it
 *
 */

// Includes
#include <bits/stdc++.h>

#define DEBUG
using namespace std;

// Variabiles
int N, M;   // n° reses groups, orribile_number
int counter=0;
vector <int> sum_of_last_roses;

// 9 20 2 3 0 4 0 3 1 0 1 0 1 0 0 0 5 0 4 0 0 2
// Result: 18

// 0 5 0 0 0 0 0
// My result: 15

// Main code
int main()
{
    // Cncomment the following lines if you want to read/write from files
#ifndef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // DEBUG

    // Input
    cin >> M >> N;
#ifdef DEBUG
    cout << "N = " << N << endl << "M = " << M << endl;
#endif // DEBUG


    sum_of_last_roses.resize(N + 1);
    sum_of_last_roses[0] = 0;
    {
        int temp;
        for (int i = 0; i < N; ++i)
        {
            cin >> temp;
            sum_of_last_roses[i + 1] = temp + sum_of_last_roses[i];
        }
    }

#ifdef DEBUG
    cout << "My roses are: ";
    for (int i = 0; i < sum_of_last_roses.size(); ++i)
        cout << sum_of_last_roses[i] << " ";
    cout << endl;
#endif // DEBUG

    int my_init = -1;
    int my_end = 0;
    int temp;
    if (sum_of_last_roses[1] == 0)
        my_init = 1;

    while (my_init++ <= sum_of_last_roses.size())
    {
        temp = 0;
        my_end = my_init;

        while ( ((sum_of_last_roses[my_end] - sum_of_last_roses[my_init]) < M) )//|| (my_end == sum_of_last_roses.size()) ) // Search my_end option
            my_end++;

        if(sum_of_last_roses[my_end] - sum_of_last_roses[my_init] == M)
        {
            ++temp;

            int wanted = sum_of_last_roses[my_end];
            while (sum_of_last_roses[++my_end] == wanted)   // how many
                ++temp;
        }

#ifdef DEBUG
        if (temp != 0)
            cout << "Insert: " << temp << "\tmy_init: " << my_init << "\tmy_end: " << my_end << "\tcounter:" << counter << endl;
#endif // DEBUG
        counter += temp;

        if (sum_of_last_roses[my_init] != M)
        {
            while(sum_of_last_roses[my_init] == sum_of_last_roses[my_init + 1]  && my_init != sum_of_last_roses.size())
            {
#ifdef DEBUG
                cout << "Safe case: "  << temp << "\tmy_init: " << my_init << "\tmy_end: " << my_end << "\tcounter:" << counter << endl;
#endif // DEBUG

                counter += temp;
                my_init++;
            }
        }
    }
    /*int temp;
    if(sum_of_last_roses[sum_of_last_roses.size() - 1] != 0)
    {
        for (int my_init = 0; my_init < sum_of_last_roses.size(); ++my_init)
        {
            temp = 0;
            for (int my_end = my_init; my_end < sum_of_last_roses.size(); ++my_end)
            {

                if(sum_of_last_roses[my_end] - sum_of_last_roses[my_init] > M)
                    break;

                if(sum_of_last_roses[my_end] - sum_of_last_roses[my_init] == M)
                {
                    if(sum_of_last_roses[my_end] != 0)
                        ++temp;
                    while (sum_of_last_roses[my_end + 1] - sum_of_last_roses[my_init] == 0)
                    {
                        ++temp;
                        ++my_end;
                    }
                }

                if(sum_of_last_roses[my_end] - sum_of_last_roses[my_init] < M)
                {
                    while (sum_of_last_roses[my_end + 1] - sum_of_last_roses[my_init] < M && my_end != sum_of_last_roses.size())
                        ++my_end;
                }
            }
            counter += temp;/*
            while(sum_of_last_roses[my_init + 1] == sum_of_last_roses[my_init])
            {
                cout << "OK "  << my_init << " " << temp << endl;

                counter += --temp;
                my_init++;
            }*
        }
    }
    else
    {
        for (int my_init = 0; my_init < sum_of_last_roses.size(); ++my_init)
        {
            temp = 0;
            for (int my_end = my_init; my_end < sum_of_last_roses.size(); ++my_end)
            {

                if(sum_of_last_roses[my_end] - sum_of_last_roses[my_init] > M)
                    break;

                if(sum_of_last_roses[my_end] - sum_of_last_roses[my_init] == M)
                {
                    if(sum_of_last_roses[my_end] != 0)
                        ++temp;
                    while (sum_of_last_roses[my_end + 1] - sum_of_last_roses[my_init] == 0)
                    {
                        ++temp;
                        ++my_end;
                    }
                }

                if(sum_of_last_roses[my_end] - sum_of_last_roses[my_init] < M)
                {
                    while (sum_of_last_roses[my_end + 1] - sum_of_last_roses[my_init] < M && my_end != sum_of_last_roses.size())
                        ++my_end;
                }
            }
            counter += temp;/*
            while(sum_of_last_roses[my_init + 1] == sum_of_last_roses[my_init])
            {
                cout << "OK "  << my_init << " " << temp << endl;

                counter += --temp;
                my_init++;
            }*
        }
    }*/

// Output
    cout << counter << endl;

// End
    return 0;
}
