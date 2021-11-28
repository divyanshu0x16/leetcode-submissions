class Solution {
public:

    vector<vector<int>> ans;

    void helper(int u, int d, vector<bool>& visited, vector<int>& path, vector<vector<int>> graph){
        visited[u] = true;
        path.push_back(u);

        if(u == d){
            ans.push_back(path);
        }else{
            vector<int>::iterator i;
            for(i = graph[u].begin(); i != graph[u].end(); ++i)
                if( !visited[*i] )
                    helper(*i, d, visited, path, graph);
        }

        path.pop_back();
        visited[u] = false;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), 0);
        vector<int> path;

        helper(0, graph.size()-1, visited, path, graph);

        return ans;
    }
};
