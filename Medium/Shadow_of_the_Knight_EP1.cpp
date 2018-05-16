#include <iostream>
using namespace std;

int main()
{
    int W, H, turns, startX, startY;
    cin >> W >> H >> turns >> startX >> startY;
    int up = 0, down = H-1, left = 0, right = W-1;

    int currX = startX;
    int currY = startY;
    while (1)
    {
        string bombDir;
        cin >> bombDir; cin.ignore();

        if (bombDir == "UR")
        {
            left = currX + 1;
            down = currY - 1;
        }
        else if (bombDir == "DR")
        {
            left = currX + 1;
            up = currY + 1;
        }
        else if (bombDir == "DL")
        {
            right = currX - 1;
            up = currY + 1;
        }
        else if (bombDir == "UL")
        {
            right = currX - 1;
            down = currY - 1;
        }
        else if (bombDir == "U")
        {
            down = currY - 1;
        }
        else if (bombDir == "D")
        {
            up = currY + 1;
        }
        else if (bombDir == "R")
        {
            left = currX + 1;
        }
        else if (bombDir == "L")
        {
            right = currX - 1;
        }

        currX = (left+right) / 2;
        currY = (up+down) / 2;

        cout << currX << " " << currY << endl;
    }
}
