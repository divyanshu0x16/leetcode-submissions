class Solution {
    
    bool bipartiteDfs(int node, vector<vector<int>> &adj, vector<int> &color){
        for(auto it : adj[node]){
            
            if( color[it] == -1 ){
                color[it] = 1 - color[node];
                if(!bipartiteDfs(it, adj, color))
                    return false;
            } else if( color[it] == color[node] ) return false;
        }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color(n, -1);
        
        for(int i = 0; i < n; i++){
            if( color[i] == -1 ) {
                color[i] = 1;
                if( !bipartiteDfs(i, graph, color)){
                    return false;
                }
            }
        }
        
        return true;
    }
};