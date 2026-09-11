class Solution {
    public:
    bool bipartite(int vertex,vector<vector<int>>&graph,vector<int>&colour,queue<int>&q,vector<bool>&visited){
        colour[vertex]=0;
        q.push(vertex);
        visited[vertex]=1;
        while(!q.empty()){
            int node =q.front();
            q.pop();
            for(int i=0;i<graph[node].size();i++){
                if(colour[node]==colour[graph[node][i]]){
                    return false;
                }
                else if(colour[graph[node][i]]==-1){
                    visited[graph[node][i]]=1;
                    if(colour[node]==1){
                        colour[graph[node][i]]=0;
                    }
                    else{
                        colour[graph[node][i]]=1;
                    }
                    q.push(graph[node][i]);
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>colour(n,-1);
        queue<int>q;
        vector<bool>visited(graph.size(),0);
            for (int i =0;i<graph.size();i++){
                if(!visited[i]){
                    if(!bipartite(i,graph,colour,q,visited)){
                        return false;
                    }
                }
            }
            return true;
    }
};