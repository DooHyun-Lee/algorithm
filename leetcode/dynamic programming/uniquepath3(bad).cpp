class Solution {
public:
    bool inrange(int y,int x,vector<vector<int>> grid,int type){    // for type 0~3 check if next (y,x) is in range
        int m = grid.size();
        int n = grid[0].size();
        int movex[4] = {1,-1,0,0};
        int movey[4] = {0,0,1,-1};
        int nexty = movey[type] + y;
        int nextx = movex[type] + x;
        if(nexty <m && nexty >=0 && nextx<n && nextx >=0)
            return true;
        return false;
    }
    
    int nexty(int y,int type){
        int movey[4] = {0,0,1,-1};
        return movey[type] + y;
    }
    
    int nextx(int x,int type){
        int movex[4] = {1,-1,0,0};
        return movex[type] + x;
    }
    
    int counttot(int count, int num,int y,int x,vector<vector<int>> grid,vector<vector<int>>& cache){  // count: left squares to visit|| num: current visited squares
        int ret = 0;
        cache[y][x] = 1;
        if(grid[y][x] == -1)    return 0;
        if(grid[y][x] == 2 && count!=num)   return 0;
        if(count == num)    return 1;
        for(int i=0;i<4;i++){
            /*if(inrange(y,x,grid,i) && cache[nexty(y,i)][nextx(x,i)] != 1){
                ret += counttot(count,num+1,nexty(y,i),nextx(x,i),grid,cache);
                cache[nexty(y,i)][nextx(x,i)] = 0;  // return to original state
            }*/
            
            if(inrange(y,x,grid,i)){
                if(cache[nexty(y,i)][nextx(x,i)] != 1){
                    ret += counttot(count,num+1,nexty(y,i),nextx(x,i),grid,cache);    // try neighboring blocks
                cache[nexty(y,i)][nextx(x,i)] = 0;  // return to original state for another neighboring blocks
                }
            }
        }
        
        return ret;    
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>> cache;
        cache.assign(m,vector<int>(n,0));
        
        int startx,starty;
        
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] != -1)   count++;
                if(grid[i][j] == 1)   {starty = i; startx = j;}
            }
        }
        return counttot(count,1,starty,startx,grid,cache);    // starting from 1 makes function work
    }
};
