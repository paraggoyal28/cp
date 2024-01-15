#include <iostream>
#include <vector>
#include <unordered_map>
#define ll long long int
using namespace std;

bool isUnvisitedRoom(vector<vector<char>> &matrix, vector<vector<bool>> &visited, ll row, ll col)
{
    return !visited[row][col] && matrix[row][col] == '.';
}

bool insideBounds(ll r, ll c, ll rows, ll cols)
{
    return r >= 0 && c >= 0 && r < rows && c < cols;
}

void coverFullRoom(vector<vector<char>> &matrix, vector<vector<bool>> &visited, ll row, ll col, ll rows, ll cols)
{
    if (!insideBounds(row, col, rows, cols))
        return;

    // if visited previously
    if (visited[row][col])
        return;

    // if encountered wall
    if (matrix[row][col] == '#')
        return;

    // visit the current cell
    visited[row][col] = true;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    for (int d = 0; d < 4; ++d)
    {
        int new_row = row + dr[d];
        int new_col = col + dc[d];
        if (insideBounds(new_row, new_col, rows, cols) && !visited[new_row][new_col] &&
            matrix[new_row][new_col] == '.')
        {
            coverFullRoom(matrix, visited, new_row, new_col, rows, cols);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m, '.'));
    for (ll row = 0; row < n; ++row)
    {
        for (ll col = 0; col < m; ++col)
        {
            cin >> matrix[row][col];
        }
    }
    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    ll rooms = 0;
    for (ll row = 0; row < n; ++row)
    {
        for (ll col = 0; col < m; ++col)
        {
            if (isUnvisitedRoom(matrix, isVisited, row, col))
            {
                coverFullRoom(matrix, isVisited, row, col, n, m);
                rooms += 1;
            }
        }
    }
    cout << rooms << endl;
}