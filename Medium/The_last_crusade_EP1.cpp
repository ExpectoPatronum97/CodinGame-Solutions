#include <iostream>
using namespace std;

// no error handling in this one
string next(string direction, int type)
{
    switch(type)
    {
        case 1: case 3: case 7: case 8: case 9: case 12: case 13:
            return "BOTTOM";
        case 2: case 6:
            return direction == "LEFT" ? "RIGHT" : "LEFT";
        case 10:
            return "LEFT";
        case 11:
            return "RIGHT";
        case 4:
            return direction == "TOP" ? "LEFT" : "BOTTOM";
        case 5:
            return direction == "TOP" ? "RIGHT" : "BOTTOM";
    }
}
int main()
{
    int W, H;
    cin >> W >> H; cin.ignore();
    int grid[H][W];
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> grid[i][j];


    int EX; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
    cin >> EX; cin.ignore();

    // game loop
    while (1)
    {
        int x, y;
        string POS;
        cin >> x >> y >> POS; cin.ignore();

        string where = next(POS, grid[y][x]);
        if (where == "BOTTOM")
            y++;
        else if (where == "RIGHT")
            x++;
        else
            x--;
        cout << x << " "<< y << endl;
    }
}
