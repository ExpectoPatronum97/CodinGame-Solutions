#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Bender
{
private:
    string dirs = "SENW";
    int height, width;
    int benderX, benderY;
    int exitX, exitY;
    pair<int,int> TP1, TP2;
    char curr_dir;
    bool breaker_mode;
    bool loop;

    struct State
    {
        int x, y;
        char curr_dir;
        bool breaker_mode;
        string dirs;
    };
    vector<State> states; // for LOOP detection


    string moves_taken;
    vector<pair<int, int>> directions; // first - xcoord, second - ycoord
    vector<string> board;

    int char_to_int(char);
    char int_to_char(int);
    bool legal_move(int, int);
    bool obstacle_incoming();

    bool is_looping();
    void inverter();
    void teleport();
    char next_dir();

    void move();

public:
    Bender(int, int, vector<string>);
    void play();
    void result();
};


int Bender::char_to_int(char x) {return dirs.find(x);};
char Bender::int_to_char(int x) {return dirs[x];};
bool Bender::legal_move(int y, int x)
{
    if (y < 0 || y > height-1) return false;
    if (x < 0 || x > width-1) return false;
    return true;
}
bool Bender::obstacle_incoming()
{
    char* c = &board[benderY + directions[char_to_int(curr_dir)].second][benderX + directions[char_to_int(curr_dir)].first];

    if (breaker_mode)
    {
        if (*c == 'X')
        {
            states.clear();
            *c = ' ';
            return false;
        }
        else
            return *c == '#';
    }
    else
        return *c == '#' || *c == 'X';
}
bool Bender::is_looping()
{
    for (auto it : states)
    {
        if (it.x == benderX && it.y == benderY && it.curr_dir == curr_dir && it.breaker_mode == breaker_mode && it.dirs == dirs)
        {
            loop = true;
            return true;
        }
    }
    return false;
}

void Bender::inverter()
{
    reverse(directions.begin(), directions.end());
    reverse(dirs.begin(), dirs.end());
}
void Bender::teleport()
{
    if (benderX == TP1.first && benderY == TP1.second)
    {
        benderX = TP2.first;
        benderY = TP2.second;
    }
    else
    {
        benderX = TP1.first;
        benderY = TP1.second;
    }
}
char Bender::next_dir()
{
    for ( int i = 0; i < 4; i++)
    {
        int tempX = benderX + directions[i].first;
        int tempY = benderY + directions[i].second;
        if (!legal_move(tempY, tempX)) continue;

        if (breaker_mode)
        {
            if (board[tempY][tempX] != '#')
                return dirs[i];
        }
        else
        {
            if (board[tempY][tempX] != '#' && board[tempY][tempX] != 'X')
                return dirs[i];
        }
    }
}

void Bender::move()
{
    int x = char_to_int(curr_dir);
    benderX += directions[x].first;
    benderY += directions[x].second;
    moves_taken += curr_dir;
}

Bender::Bender(int height, int width, vector<string> board)
{
    this->height = height;
    this->width = width;
    this->board = board;

    curr_dir = 'S';
    breaker_mode = false;
    loop = false;
    moves_taken = "";

    directions.push_back({0, +1});
    directions.push_back({+1, 0});
    directions.push_back({0, -1});
    directions.push_back({-1, 0});

    bool found_first = false;
    for (int i = 0; i < board.size(); i++)
    {
        int tmp = board[i].find('@');
        if (tmp != -1)
        {
            benderX = tmp;
            benderY = i;
        }

        tmp = board[i].find('$');
        if (tmp != -1)
        {
            exitX = tmp;
            exitY = i;
        }

        tmp = board[i].find('T');
        if (!found_first && tmp != -1)
        {
            found_first = true;
            TP1 = {tmp, i};

        }

        tmp = board[i].find('T');
        if (found_first && tmp != -1)
        {
            TP2 = {tmp, i};
        }
    }
}

void Bender::play()
{
    while (benderX != exitX || benderY != exitY)
    {
        char field = board[benderY][benderX];

        if (field == 'B') breaker_mode = !breaker_mode;
        if (field == 'I') inverter();
        if (field == 'T') teleport();

        if ( dirs.find(field) != string::npos)
            curr_dir = field;
        else if ( obstacle_incoming() )
            curr_dir = next_dir();

        move();

        if (is_looping()) break;
        states.push_back({benderX, benderY, curr_dir, breaker_mode, dirs});
    }
}

void Bender::result()
{
    if (loop)
    {
        cout << "LOOP" << endl;
        return;
    }

    for (auto i : moves_taken)
    {
        switch (i)
        {
            case 'S' : cout << "SOUTH" << endl; break;
            case 'E' : cout << "EAST" << endl; break;
            case 'N' : cout << "NORTH" << endl; break;
            case 'W' : cout << "WEST" << endl; break;
        }
    }
}
int main()
{
    int height, width;
    cin >> height >> width; cin.ignore();
    vector<string> board;
    for (int i = 0; i < height; i++)
    {
        string row;
        getline(cin, row);
        board.push_back(row);
    }

    Bender bender = Bender(height, width, board);
    bender.play();
    bender.result();
    return 0;
}
