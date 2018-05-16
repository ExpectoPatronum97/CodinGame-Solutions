#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int nbFloors, exitFloor, exitPos, nbElevators;
    scanf("%d%*d%*d%d%d%*d%*d%d", &nbFloors, &exitFloor, &exitPos, &nbElevators); // %*d ignores input

    int elevators[nbElevators];
    for (int i = 0; i < nbElevators; i++)
    {
        int elevatorFloor;
        int elevatorPos;
        scanf("%d%d",&elevatorFloor, &elevatorPos);
        elevators[elevatorFloor] = elevatorPos;
    }
    elevators[exitFloor] = exitPos;
    // game loop
    while (1)
     {
        int cloneFloor, clonePos;
        string direction;
        cin >> cloneFloor >> clonePos >> direction; cin.ignore();

        if (direction == "LEFT")
        {
            cout << (elevators[cloneFloor] > clonePos ? "BLOCK" : "WAIT") << endl;
        }
        else if (direction == "RIGHT")
        {
            cout << (elevators[cloneFloor] < clonePos ? "BLOCK" : "WAIT") << endl;
        }
        else
            cout << "WAIT" << endl;
    }
}
