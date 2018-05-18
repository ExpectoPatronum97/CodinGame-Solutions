#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int N, L, E;
    cin >> N >> L >> E; cin.ignore();

    vector<vector<int>> nodes (N);
    vector<int> exits;

    for (int i = 0; i < L; i++)
    {
        int N1, N2;
        cin >> N1 >> N2; cin.ignore();
        nodes[N1].push_back(N2);
        nodes[N2].push_back(N1);
    }
    for (int i = 0; i < E; i++)
    {
        int EI; cin >> EI;
        exits.push_back(EI);
    }
    // game loop
    while (1)
    {
        int SI; cin >> SI;
        int node;
        bool found = false;
        for (int i = 0; i < nodes[SI].size(); i++)
        {
            node = nodes[SI][i];
            for (int j = 0; j < exits.size(); j++)
            {
                if (nodes[SI][i] == exits[j]) found = true;
            }
            if (found) break;
        }
        cout << SI << " " << node << endl;
    }
}
