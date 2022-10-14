class Solution {
    
private:
    bool checkForCycle(int node, vector<int> &vis, vector<int> &recStack, vector<vector<int> > &adj){
        
        if(vis[node] == false){

            vis[node] = true;
            recStack[node] = true;

            for(auto i: adj[node]){
                if( vis[i] == false and checkForCycle(i, vis, recStack, adj))
                    return true;
                else if ( recStack[i] == 1)
                    return true;
            }
        }
        recStack[node] = false;
        return false;
    }

    vector<vector<int> > makeGraph(vector<vector<int>>& prerequisites, int numCourses){

        vector<vector<int> > adj(numCourses);

        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        return adj;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> vis(numCourses, 0);
        vector<int> recStack(numCourses, 0);

        vector<vector<int> > adj = makeGraph(prerequisites, numCourses);
        
        for (int i = 0; i < numCourses; i++)
            if( !vis[i] and checkForCycle(i, vis, recStack, adj))
                return false;
        
        return true;
    }
};
