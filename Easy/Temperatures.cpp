#include <iostream>
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    int rez = 10000;
    if (n == 0) rez = 0;

    while(n--)
    {
        cin >> x;
        if (abs(x) < abs(rez)) rez = x;
        else if (x == -rez) rez = abs(x);
    }

    cout << rez << endl;
}
