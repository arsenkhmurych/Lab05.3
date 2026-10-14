// Lab 5_3
// Варіант 29
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Прототип допоміжної функції z(x)
double z(const double x);

int main()
{
    double pp, pk, res;
    int n;

    cout << "pp = "; cin >> pp;
    cout << "pk = "; cin >> pk;
    cout << "n = ";  cin >> n;

    double dp = (pk - pp) / n;
    double p = pp;

    cout << fixed;
    cout << "-------------------------------------" << endl;
    cout << "|" << setw(12) << "p" << " |"
        << setw(18) << "result" << " |"
        << endl;
    cout << "-------------------------------------" << endl;

    while (p <= pk)
    {
        res = z(p * p + 1) - z(p * p - 1) + 2 * z(p);

        cout << "|" << setw(12) << setprecision(5) << p << " |"
            << setw(18) << setprecision(5) << res << " |"
            << endl;

        p += dp;
    }

    cout << "-------------------------------------" << endl;

    return 0;
}

// Визначення допоміжної функції z(x)
double z(const double x)
{
    if (abs(x) >= 1)
    {
        return (sin(x) + 1.0) / (cos(x) * cos(x) + exp(x));
    }
    else
    {
        double S = 0;
        int k = 0;
        double a = 1.0; // k = 0 -> a_0 = 1
        S = a;

        do
        {
            k++;
            double R = (2.0 * x) / k;
            a *= R;
            S += a;
        } while (k < 6);

        return (1.0 / exp(x * x)) * S;
    }
}