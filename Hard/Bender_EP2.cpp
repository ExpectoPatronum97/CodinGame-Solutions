#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

struct Room
{
    int money;
    vector<int> connections;
};

int s2i(string s)
{
    stringstream str(s);
    int x;
    str >> x;
    return x;
}
int solve(Room rooms[], int n)
{
    int max = 0;
    vector<int> total(n, 0);
    queue<pair<int,int>> q;
    q.push({0,0});

    int old_room, new_room;
    while (!q.empty())
    {
        auto curr = q.front();
        old_room = curr.first;
        new_room = curr.second;
        q.pop();
        if (total[new_room] < total[old_room] + rooms[new_room].money)
        {
            total[new_room] = total[old_room] + rooms[new_room].money;
            if (total[new_room] > max)
                max = total[new_room];

            for (auto room : rooms[new_room].connections)
                q.push({new_room, room});
        }
    }
    return max;
}
int main()
{
    int n; cin >> n; cin.ignore();
    Room rooms[n];

    for (int i = 0; i < n; i++)
    {
        int nb, money;
        string connection1, connection2;
        cin >> nb >> money >> connection1 >> connection2;

        rooms[nb].money = money;
        if (connection1 != "E")
            rooms[nb].connections.push_back(s2i(connection1));

        if (connection2 != "E")
            rooms[nb].connections.push_back(s2i(connection2));
    }
    cout << solve(rooms, n) << endl;
    return 0;
}
