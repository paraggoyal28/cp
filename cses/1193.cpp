#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isValid(vector<vector<char>> &matrix, ll x, ll y, vector<vector<bool>> &visited, ll rows, ll cols)
{
    return x >= 0 && y >= 0 && x < rows && y < cols && !visited[x][y] && matrix[x][y] != '#';
}

char findDirection(ll x, ll y)
{
    if (x == 0 && y == 1)
    {
        return 'R';
    }
    if (x == 0 && y == -1)
    {
        return 'L';
    }
    if (x == 1 && y == 0)
    {
        return 'D';
    }
    return 'U';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    pair<ll, ll> start, end;
    vector<vector<char>> matrix(n, vector<char>(m, '.'));
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'A')
            {
                start = {i, j};
            }
            else if (matrix[i][j] == 'B')
            {
                end = {i, j};
            }
        }
    }

    queue<pair<ll, ll>> bfs;
    bfs.push(start);
    vector<vector<char>> path(n, vector<char>(m, '.'));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[start.first][start.second] = true;
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    while (!bfs.empty())
    {
        pair<ll, ll> curr = bfs.front();
        bfs.pop();

        ll x = curr.first;
        ll y = curr.second;
        if (end == curr)
        {
            break;
        }

        for (int dir = 0; dir < 4; ++dir)
        {
            int new_x = x + dr[dir];
            int new_y = y + dc[dir];
            if (isValid(matrix, new_x, new_y, visited, n, m))
            {
                visited[new_x][new_y] = true;
                path[new_x][new_y] = findDirection(dr[dir], dc[dir]);
                bfs.push({new_x, new_y});
            }
        }
    }

    if (path[end.first][end.second] == '.')
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        string res = "";
        ll x = end.first;
        ll y = end.second;
        while (x != start.first || y != start.second)
        {
            char direction = path[x][y];
            res += direction;
            if (direction == 'L')
            {
                y += 1;
            }
            else if (direction == 'R')
            {
                y -= 1;
            }
            else if (direction == 'D')
            {
                x -= 1;
            }
            else
            {
                x += 1;
            }
        }
        reverse(res.begin(), res.end());
        cout << res.length() << "\n";
        for (char ch : res)
        {
            cout << ch;
        }
        cout << "\n";
    }
}
