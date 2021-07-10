class Solution
{
public:
    int nearestExit(vector<vector<char> > &maze, vector<int> &entrance)
    {
        int n = maze.size();    //Rows
        int m = maze[0].size(); //Columns

        vector<vector<bool>> visited(n, vector<bool> (m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
            {
                if (maze[i][j] == '.')
                    visited[i][j] = false;
                else
                    visited[i][j] = true;
            }
        }

        queue<pair<pair<int, int>, int>> q;
        visited[entrance[0]][entrance[1]] = true;
        q.push(make_pair(make_pair(entrance[0], entrance[1]), 0));
        while (!q.empty())
        {
            pair<int, int> curr = q.front().first;
            int currDist = q.front().second;
            int currX = curr.first;
            int currY = curr.second;
            q.pop();

            if (currX == 0 or currX == n - 1 or currY == 0 or currY == m - 1)
                if (make_pair(currX, currY) != make_pair(entrance[0], entrance[1]))
                    return currDist;

            //Moving Up
            if (currX - 1 >= 0 and visited[currX - 1][currY] == false)
            {
                q.push(make_pair(make_pair(currX - 1, currY), currDist + 1));
                visited[currX-1][currY] = true;
            }

            //Moving Down
            if (currX + 1 < n and visited[currX + 1][currY] == false)
            {
                q.push(make_pair(make_pair(currX + 1, currY), currDist + 1));
                visited[currX + 1][currY] = true;
            }

            //Moving Left
            if (currY - 1 >= 0 and visited[currX][currY - 1] == false)
            {
                q.push(make_pair(make_pair(currX, currY - 1), currDist + 1));
                visited[currX][currY - 1] = true;
            }

            //Moving Right
            if (currY + 1 < m and visited[currX][currY + 1] == false)
            {
                q.push(make_pair(make_pair(currX, currY + 1), currDist + 1));
                visited[currX][currY + 1] = true;
            }
        }
        return -1;
    }
};