#include <bits/stdc++.h>
using namespace std;

#define DEBUG
#ifdef DEBUG
#endif // DEBUG

struct myvalue
{
    int summed_value;
    int zero_before = 0;
    int zero_after = 0;
};

int N, M, tmp, tmp_zero;
vector<myvalue> values;
int index_start, index_end;
int sol;

int main(int argc, char const *argv[])
{
    freopen("input.txt", "r", stdin);
#ifndef DEBUG
    freopen("output.txt", "w", stdout);
#endif // DEBUG

    cin >> M >> N;
    tmp_zero = 0;

    for (size_t i = 0; i < N; ++i)
    {
        cin >> tmp;
        if (tmp == 0)
        {
            tmp_zero++;
        }
        else
        {
            myvalue myvalue_tmp;
            if (i == 0)
                myvalue_tmp.summed_value = tmp;
            else
                myvalue_tmp.summed_value = values[values.size() - 1].summed_value + tmp;
            myvalue_tmp.zero_before = tmp_zero;
            myvalue_tmp.zero_after = 0;
            tmp_zero = 0;

            values.push_back(myvalue_tmp);
        }
    }

    values[values.size() - 1].zero_after = tmp_zero;

    for (int i = values.size() - 2; i >= 0; --i)
    {
        values[i].zero_after = values[i + 1].zero_before;
    }

#ifdef DEBUG
    for (size_t i = 0; i < values.size(); ++i)
        cout << i << "\t" << values[i].summed_value << "\t" << values[i].zero_before << "\t" << values[i].zero_after << endl;
#endif // DEBUG

    index_start = 0;
    index_end = 0;
    sol = 0;

    while (index_end < N)
    {
        if (values[index_end].summed_value - values[index_start].summed_value == M || values[index_end].summed_value == M)
        {
            sol += (values[index_start].zero_after + 1) * (values[index_end].zero_after + 1);

            index_start++;
            index_end++;
        }
        else if (values[index_end].summed_value - values[index_start].summed_value > M)
        {
            index_start++;
        }
        else
        { // values[index_end].summed_value - values[index_start].summed_value < M
            index_end++;
        }
    }

    cout << sol << endl;

    return 0;
}
