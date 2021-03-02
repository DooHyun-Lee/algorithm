bool check(vector<vector<int>>& grid){    // check whether any block hasn't been visited
        for(vector<int> r : grid){
            for(int c : r){
                if(c==0) return false;
            }
        }
        return true;
    }
    int done(vector<vector<int>>& grid,int i,int j){   
        if(i<0 || j <0 || j>= grid[0].size() || i>=grid.size() || grid[i][j]==3 || grid[i][j]==-1) return 0;    // outof bounds, visited, or unreachtable then skip
        if(grid[i][j]==2) {     // arrived at final position
            if(check(grid)) return 1;   // every other block is visited
            return 0;     // not all the blocks are visited yet
        }
        grid[i][j]=3;     // cache grid as 3 if visited
        int c=0; 
        c += done(grid,i+1,j)+done(grid,i,j+1)+done(grid,i-1,j)+done(grid,i,j-1);       // visit all the adjacent blocks
        grid[i][j]=0;     // return back to state before being visited for recursion
        return c;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return done(grid,i,j);
                }
            }
        }
        return 0;
    }
