class Solution {
public:
    struct smallBySize {
        bool operator()(const std::vector<int>& a, const std::vector<int>& b) const {
            if (a.size() != b.size())
                return a.size() < b.size();
            return a < b;
        }
    };
    struct largeBySize {
        bool operator()(const std::vector<int>& a, const std::vector<int>& b) const {
            if (a.size() != b.size())
                return a.size() > b.size();
            return a < b;
        }
    };
    set<vector<int>, smallBySize> cycles;
    set<vector<int>, largeBySize> linears; 

    bool dfs(int u, int parent, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                if(dfs(v, u, visited, adj)) return true;
            } else if(v != parent) return true;
        }
		return false;
    }
    vector<int> bfs(int V, int u, vector<vector<int>>& adj) {
        vector<bool> vis(V, false);
        vis[u] = true; 
        queue<int> q;
        q.push(u); 
        vector<int> bfs; 
        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            bfs.push_back(node); 
            for(int it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push(it); 
                }
            }
        }
        return bfs;
    }
    void findCycles(int V, vector<vector<int>>& adj) {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if(!visited[i]) {
                bool cycle = dfs(i, -1, visited, adj);
                if(cycle) cycles.insert(bfs(V, i, adj));
                else linears.insert(bfs(V, i, adj));
            }
        }
    }
    int getOutDegreeOneVertex(vector<int>& v, vector<vector<int>>& adj){
        for(int i: v){
            if(adj[i].size() == 1) return i;
        }
        return v[0];
    }
    long long maxScore(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        findCycles(n, adj);
        int edge = n;
        vector<int> val(n, -1);
        for (const auto& cycle : cycles) {
            for(int node: cycle){
                val[node] = edge;
                edge--;
            }
        }
        // cout << "Linears: " << endl;
        for (auto it = linears.begin(); it != linears.end(); it++) {
            vector<int> temp = *it;
            if(temp.size() == 1){
                val[temp[0]] = edge;
                edge--;
                continue;
            }
            int start = getOutDegreeOneVertex(temp, adj);
            temp = bfs(n, start, adj);
            int midIndex = temp.size()/2;
            int leftIndex = midIndex-1, rightIndex = midIndex+1;
            val[temp[midIndex]] = edge;
            edge--;
            while(!(leftIndex < 0 && rightIndex >= temp.size())){
                if(leftIndex >= 0){
                    val[temp[leftIndex]] = edge;
                    edge--;
                }
                if(rightIndex < temp.size()){
                    val[temp[rightIndex]] = edge;
                    edge--;
                }
                leftIndex--;
                rightIndex++;
            }
        }
        // for(int i: val) cout << i << " ";
        // cout << endl;
        // cout << "Adj: " << endl;
        // for(auto i: adj){
        //     for(int j: i) cout << j << " ";
        //     cout << endl;
        // }
        // cout << "Cycles: " << endl;
        // for(auto cycle: cycles){
        //     for(int node: cycle) cout << node << " ";
        //     cout << endl;
        // }
        // cout << "Linears: " << endl;
        // for(auto linear: linears){
        //     for(int node: linear) cout << node << " ";
        //     cout << endl;
        // }
        long long ans = 0;
        for(auto it: edges){
            ans += (long long)val[it[0]]*val[it[1]];
        }
        return ans;
    }
};
