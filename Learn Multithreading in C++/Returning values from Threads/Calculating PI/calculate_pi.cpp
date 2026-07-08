#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

double calculate_pi(int terms)
{
    double sum = 0.0;
    for(int i=0;i<terms;i++)
    {
        int sign = pow(-1,i);
        double term = 1.0/(i * 2 + 1);
        sum += sign * term;
    }
    return sum * 4;
}

int main()
{
    cout<<setprecision(15)<<calculate_pi(1E9);
    return 0;
}