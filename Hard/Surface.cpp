#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool validMove(int width, int height, int x, int y)
{
    return (x >= 0 && x < width) && (y >= 0 && y < height);
}

int main()
{
    int width, height;
    cin >> width >> height;

    vector<vector<int>> grid(height, vector<int>(width));

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            char c; cin >> c;
            grid[i][j] = c == '#' ? -1 : 0 ;
        }

    struct Point {int x,y;};
    Point deltas[4] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
    vector<int> cache;
    cache.push_back(0);

    int cnt = 1;

    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
        if (grid[y][x] == 0)
        {
            int count = 0, c = 0;
            queue<Point> pts;
            pts.push({x,y});
            while (!pts.empty())
            {
                Point point = pts.front();
                pts.pop();
                if (grid[point.y][point.x] == 0)
                {

                    grid[point.y][point.x] = cnt;
                    count++;

                    for (int i = 0; i < 4; i++)
                    {
                        int tempX = point.x + deltas[i].x;
                        int tempY = point.y + deltas[i].y;

                        if (validMove(width, height, tempX, tempY))
                        {
                            pts.push({tempX, tempY});
                        }
                    }
                }
            }
            cache.push_back(count);
            cnt++;
        }

    int n; cin >> n;
    while(n--)
    {
        int x, y;
        cin >> x >> y;
        cout << cache[grid[y][x]] << endl;
    }
    return 0;
}
