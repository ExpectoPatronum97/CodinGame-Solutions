#include <iostream>
using namespace std;

int main()
{
    // game loop
    while (1)
    {
        int index = 0, max = 0;
        for (int i = 0; i < 8; i++)
        {
            int mountainH;
            cin >> mountainH; cin.ignore();
            if (mountainH > max) max = mountainH, index = i;
        }
        cout << index << endl;

    }
}
