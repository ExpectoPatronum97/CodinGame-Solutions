#include <iostream>
using namespace std;

int main()
{
    int n, highest = 0, loss = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (x - highest < loss) loss = x - highest;
        if (x > highest) highest = x;
    }
    cout << loss << endl;
    return 0;
}
