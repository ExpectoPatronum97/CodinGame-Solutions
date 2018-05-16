#include <iostream>
using namespace std;

int main()
{
    int width, height;
    cin >> width >> height;
    char grid[height][width];

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            cin >> grid[i][j];

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            int x2, x3, y2, y3;
            x2 = x3 = y2 = y3 = -1;
            if (grid[i][j] == '0')
            {
                if (j+1 < width)
                {
                    int movx = j+1;
                    while(movx < width && grid[i][movx] != '0') movx++;
                    if (movx < width && grid[i][movx] == '0')
                        y2 = i, x2 = movx;
                }

                if (i+1 < height)
                {
                    int movy = i+1;
                    while (movy < height && grid[movy][j] != '0') movy++;
                    if (grid[movy][j] == '0')
                        y3 = movy, x3 = j;
                }
                cout << j << " " << i << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
            }
        }
    return 0;
}
