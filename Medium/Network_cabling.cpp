#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define pint pair<int, int>
int main()
{
    int n; cin >> n;
    vector<pint> buildings;
    int west = (1<<30) + 1; // since max value is 2^30
    int east = 0;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        buildings.push_back({x,y});
        if (x > east) east = x;
        if (x < west) west = x;
    }

    sort(buildings.begin(), buildings.end(),[](pint &a, pint &b) {return a.second < b.second;});

    long long res = east - west;
    for (auto &i : buildings)
        res = res + abs(buildings[n/2].second - i.second);

    cout << res << endl;
    return 0;
}
