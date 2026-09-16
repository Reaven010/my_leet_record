class Solution {
  public:
  int l,r;
  int row[4]={-1,1,0,0};
  int col[4]={0,0,-1,1};
  
  bool valid(int i ,int j){
      return i>=0 && i<r && j>=0 && j<l;
  }
  
  
    int orangesRotting(vector<vector<int>>& mat) {
        // code here
        r=mat.size();
        l=mat[0].size();
        queue<pair<int,int>>q;
        int fresh =0;
        for(int i=0;i<r;i++){
            for(int j=0;j<l;j++){
                if(mat[i][j]==2){
                    q.push(make_pair(i,j));
                   
                }
                if(mat[i][j]==1){
                    fresh ++;
                }
            }
        }
        if(fresh==0){
            return 0;
        }


        int time=0;
        while(!q.empty()){
            
            int curr=q.size();
            time++;
            while(curr--){
                int i =q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    if(valid(i+row[k],j+col[k])&& mat[i+row[k]][j+col[k]]==1){
                        mat[i+row[k]][j+col[k]]=2;
                        q.push(make_pair(i+row[k],j+col[k]));
                    }
                }
            }
            
            
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<l;j++){
                if(mat[i][j]==1){
                    return -1;
                }
            }
        }
        return time-1;
        
        
    }
};