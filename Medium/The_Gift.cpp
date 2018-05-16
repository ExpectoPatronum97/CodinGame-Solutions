#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, price, total = 0;
    cin >> n >> price;
    int money[n];
    for (int i = 0; i < n; i++)
    {
        cin >> money[i];
        total += money[i];
    }
    if (total < price)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        sort(money, money+n);
        for (int i = 0; i < n; i++)
        {
            int should_pay = price / (n-i);
            int paid = money[i] < should_pay ? money[i] : should_pay;
            cout << paid << endl;
            price -= paid;
        }
    }
    return 0;
}
