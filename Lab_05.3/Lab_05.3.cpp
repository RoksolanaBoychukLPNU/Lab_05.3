#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double s(const double x);   // прототип допоміжної функції

int main()
{
    double tp, tk, y;
    int n;

    cout << "tp = "; cin >> tp;       // початок інтервалу
    cout << "tk = "; cin >> tk;       // кінець інтервалу
    cout << "n = ";  cin >> n;        // кількість відрізків розбиття

    double dt = (tk - tp) / n;        // крок табулювання

    cout << fixed;
    cout << endl << "           Solution" << endl;
    cout << "------------------------------" << endl;
    cout << "|" << setw(9) << "t" << "    |" << setw(10) << "y" << "    |" << endl;
    cout << "------------------------------" << endl;

    for (int i = 0; i <= n; i++)     
    {
        double t = tp + i * dt;
        y = s(2 * t + 1) + 2 * s(t * t) + sqrt(s(1));

        cout << "|" << setw(9) << setprecision(3) << t << "    |"
            << setw(10) << setprecision(5) << y << "    |" << endl;
    }
    cout << "------------------------------" << endl;

    return 0;
}

double s(const double x)
{
    if (abs(x) >= 1 || x == 0)
        return (cos(x) * cos(x) + 1) / exp(x);
    else
    {
        int k = 0;
        double a = 2 * x;              // перший доданок (k = 0)
        double S = a;
        do {
            k++;
            // коефіцієнт рекурентності
            double R = 4 * x * x / ((2 * k) * (2 * k + 1));
            a *= R;
            S += a;
        } while (k < 4);              
        return S / sin(2 * x);
    }
}
