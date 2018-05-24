#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Idea: "Middle" of the connection tree
// Half the distance between 2 furthest (from each other) points
// Tried taking it from the root, but it failed. So I tried with a leaf

struct Node
{
    int value;
    int prev;
    int distance;
};

int BFS(map<int, vector<int>> graf, int start_node)
{
    queue<Node> q;
    q.push({start_node, -1, 0});

    int max_dist = 0;
    while (!q.empty())
    {
        Node temp = q.front();
        q.pop();

        if (temp.distance > max_dist)
            max_dist = temp.distance;

        for (int i = 0; i < graf[temp.value].size(); i++)
        {
            if (graf[temp.value][i] != temp.prev)
                q.push({graf[temp.value][i], temp.value, 1+temp.distance});
        }
    }
    return max_dist;
}
int main()
{
    int n, leaf; cin >> n;
    map< int, vector<int>> graf;
    for (int i = 0; i < n; i++)
    {
        int xi, yi;
        cin >> xi >> yi;
        graf[xi].push_back(yi);
        graf[yi].push_back(xi);
    }
    for (int i = 0; i < graf.size(); i++)
    {
        if (graf[i].size() == 1)
        {
            leaf = i;
            break;
        }
    }
    int dist = BFS(graf, leaf) + 1;
    cout << dist / 2 << endl;
    return 0;
}
