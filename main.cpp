#include "ZFraction.h"
using namespace std;

int main()
{
    ZFraction a(1.32288,1.11803);      //Déclare une fraction valant 4/5
    ZFraction b(7,-4);        //Déclare une fraction valant 2/1 (ce qui vaut 2)
    ZFraction c,d;         //Déclare deux fractions valant 0

    c = a+b;               //Calcule 4/5 + 2/1 = 14/5

    d = a;               //Calcule 4/5 * 2/1 = 8/5

    cout << a << " + " << b << " = " << c << endl;

    cout << a << " * " << b << " = " << d << endl;

    cout << b << " - " << a << " = " << b-a << endl;

    cout << c << " / " << d << " = " << c/d << endl;

    cout << "abs(" << a << ") = " << abs(a) << endl;

    cout << "pow(" << a << ",2) = " << pow(a, 2) << endl;

    cout << "sqrt(" << d << ") = " << sqrt(d) << endl;

    if(a > b)
        cout << "a est plus grand que b." << endl;
    else if(a==b)
        cout << "a est egal a b." << endl;
    else
        cout << "a est plus petit que b." << endl;

    return 0;
}