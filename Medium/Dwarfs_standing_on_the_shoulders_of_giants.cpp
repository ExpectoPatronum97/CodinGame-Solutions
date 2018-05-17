#include <iostream>
#include <map>
#include <vector>
using namespace std;

int calc_depth(map<int, vector<int>> mapa, int vertex, int depth)
{
    int curr_max = 0;
    for (auto i : mapa[vertex])
    {
        curr_max = max(curr_max, calc_depth(mapa, i, depth+1));
    }
    if (curr_max == 0) return depth+1;
}
int main()
{
    int n; cin >> n;
    map<int, vector<int>> mapa;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        mapa[x].push_back(y);
    }

    int max_depth = 0;
    for (auto it: mapa)
    {
        max_depth = max(max_depth, calc_depth(mapa, it.first, 0));
    }
    cout << max_depth << endl;
    return 0;
}
