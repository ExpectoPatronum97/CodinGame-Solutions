#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159
#define G 3.711
#define EPS 10
#define OFFSET_Y 30 // Giving it some time to slow down on landing, 1% of the height

int wrong_side(int x, int hSpeed, int left, int right)
{
    if (hSpeed < 0 && x < left)
        return 1;
    if (hSpeed > 0 && x > right)
        return 1;
    return 0;
}

int slower(int hSpeed, int vSpeed)
{
    double speed = sqrt(hSpeed*hSpeed + vSpeed*vSpeed);
    return asin(hSpeed / speed) * (180 / PI);
}

int main()
{
    const int maxVSpeed = 40, maxHSpeed = 20;

    int surfaceN;
    cin >> surfaceN; cin.ignore();

    int rightSideX = -1, leftSideX = -1, flatY = -1;
    int prevX = -1, prevY = -1;

    for (int i = 0; i < surfaceN; i++)
    {
        int landX, landY;
        cin >> landX >> landY; cin.ignore();

        if (prevY == landY)
        {
            leftSideX = prevX;
            rightSideX = landX;
            flatY = landY;
        }
        else
        {
            prevX = landX;
            prevY = landY;
        }
    }
    // game loop
    while (1)
    {
        int X, Y, hSpeed, vSpeed, fuel, rotate, power;
        cin >> X >> Y >> hSpeed >> vSpeed >> fuel >> rotate >> power; cin.ignore();


        if (X >= leftSideX && X <= rightSideX) // flat land
        {
            if (Y < flatY+OFFSET_Y)
            {
                rotate = 0;
                power = 3;
            }
            else if (abs(hSpeed) <= maxHSpeed-EPS && abs(vSpeed) <= maxVSpeed-EPS) // too fast?
            {
                rotate = 0;
                power = 2;
            }
            else
            {
                rotate = slower(hSpeed, vSpeed);
                power = 4;
            }
        }
        else // not flat
        {
            if (wrong_side(X, hSpeed, leftSideX, rightSideX) || (abs(hSpeed) > maxHSpeed * 4)) // too fast?
            {
                rotate = slower(hSpeed, vSpeed);
                power = 4;
            }
            else if (abs(hSpeed) < maxHSpeed * 2) // too slow?
            {
                rotate = acos(G / 4.0) * 180 / PI;
                rotate = X < leftSideX?-rotate:0;
                power = 4;
            }
            else
            {
                rotate = 0;
                power = vSpeed > 0? 3:4;
            }
        }
        cout << rotate << " " << power << endl;
    }
}
