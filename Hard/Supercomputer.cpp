#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;

    struct Task { int start, end;};
    Task tasks[n];
    for (int i = 0; i < n; i++)
    {
        cin >> tasks[i].start >> tasks[i].end;
        tasks[i].end = tasks[i].start + tasks[i].end - 1;
    }
    sort(tasks, tasks+n, [](Task& a, Task& b) {return a.end < b.end;});

    int cnt = 0, current_time = 0;
    for (int i = 0; i < n; i++)
        if (tasks[i].start > current_time)
        {
            cnt++;
            current_time = tasks[i].end;
        }
    cout << cnt << endl;
    return 0;
}
