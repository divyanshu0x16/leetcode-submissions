class Solution {
public:
//  rank & nodes
    vector<int> nodes, rank;
    
//  find
    int find(int a)
    {
        if(nodes[a] == -1) return a;
        else return nodes[a] = find(nodes[a]);
    }
    
//  union
    void uni(int a, int b)
    {
        int fa = find(a), fb = find(b);
        if(fa == fb) return;
        if(rank[fa] > rank[fb])
            nodes[fb] = fa;
        else if(rank[fa] < rank[fb])
            nodes[fa] = fb;
        else
        {
            nodes[fb] = fa;
            rank[fa]++;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        nodes.resize(1001, -1);
        rank.resize(1001,0);
        for(auto edg : edges)
        {
            if(find(edg[0]) == find(edg[1])) return edg;
            else uni(edg[0], edg[1]);
        }
        return {};
    }
};
