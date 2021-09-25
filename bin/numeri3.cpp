#include <bits/stdc++.h>
using namespace std;

// Definitions
#define DEBUG
#ifdef DEBUG
#endif // DEBUG

// Structures
struct myvalue
{
    int summed_value = 0;
    int zero_before = 0;
    int zero_after = 0;
};

// Variabiles
int N, M, sum, sol, tmp, tmp_zero;
myvalue start_value, end_value;
queue<myvalue> q;

// Functions definitions
void intial_setup();
void evaluate();
void calculate_end();
int main(int argc, char const *argv[]);

void intial_setup()
{
    freopen("input.txt", "r", stdin);
#ifndef DEBUG
    freopen("output.txt", "w", stdout);
#endif // DEBUG

    cin >> M >> N;
    tmp_zero = 0;
    sum = 0;
    sol = 0;

    do
    {
        cin >> tmp;
        N--;
        if (tmp == 0)
            tmp_zero++;
    } while (tmp == 0 && N != 0);

    calculate_end();
}

void evaluate()
{
    start_value = q.front();

    if (end_value.summed_value - start_value.summed_value == M || end_value.summed_value == M)
    {
        sol += (start_value.zero_after + 1) * (end_value.zero_after + 1);

        q.pop(); // index_start++;
        if (N != 0)
        {
            calculate_end(); // index_end++;
            evaluate();
        }
    }
    else if (end_value.summed_value - start_value.summed_value > M)
    {
        q.pop(); // index_start++;
        evaluate();
    }
    else
    { // end_value.summed_value - start_value.summed_value < M
        if (N != 0)
        {
            calculate_end(); // index_end++;
            evaluate();
        }
    }
}

void calculate_end()
{
    sum += tmp;

    end_value.zero_before = tmp_zero;
    end_value.summed_value = sum;
    tmp_zero = 0;

    do
    {
        cin >> tmp;
        N--;
        if (tmp == 0)
            tmp_zero++;
    } while (tmp == 0 && N != 0);

    end_value.zero_after = tmp_zero;

    q.push(end_value);
}

int main(int argc, char const *argv[])
{
    intial_setup();
    evaluate();

    cout << sol << endl; // Print answer

    return 0;
}
