#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;

#define PI 3.141519

double to_double(string str)
{
    replace(str.begin(), str.end(), ',', '.');
    return atof(str.c_str()) * PI / 180;
}
int main()
{
    string x, y, name;
    cin >> x >> y;

    double userX = to_double(x);
    double userY = to_double(y);
    double min = numeric_limits<double>::max();

    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++)
    {
        vector<string> defib;
        string input, temp;
        getline(cin, input);

        istringstream str(input);
        while (getline(str, temp, ';'))
            defib.push_back(temp);

        double lon = to_double(defib[4]);
        double lat = to_double(defib[5]);

        double x = (userX - lon) * cos((userY + lat) / 2.0);
        double y = userY - lat;
        double d = sqrt((x*x + y*y)) * 6371;

        if (d < min) min = d, name = defib[1];
    }
    cout << name << endl;
    return 0;
}
