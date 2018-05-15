#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main()
{
    int N,d;
    int min = numeric_limits<int>::max();
    cin >> N; cin.ignore();
    vector<int>snage;

    for (int i = 0; i < N; i++)
    {
        int Pi;
        cin >> Pi; cin.ignore();
        snage.push_back(Pi);
    }
    sort(snage.begin(),snage.end());
    for (int i = 0; i < snage.size()-1; i++)
        if ( snage[i+1] - snage[i] < min) min = snage[i+1]-snage[i];
    cout << min << endl;
}
