class Solution {
public:
    vector<vector<int>> cache;
    int m,n;

    bool inbound(int y,int x){
        return (y>=0 && y<m && x>=0 && x<n);
    }
    
    void initialize(vector<vector<char>> board){
        m = board.size();
        n = board[0].size();
        cache.assign(m,vector<int>(n,0));
        /*for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'X') 
                    cache[i][j] = 1;
            }
        }*/
    }
    
    void beforedfs(vector<vector<char>> board){     // 가장자리와 닿아있는 블럭들을 cache 에 표시후 'X'로 바꾸지 못하게 
        for(int i=0;i<n;i++){
            if(board[0][i] == 'O' && cache[0][i] ==0)   dfs(0,i,board,1);
            if(board[m-1][i] == 'O' && cache[m-1][i] == 0)    dfs(m-1,i,board,1);
        }
        for(int i=0;i<m;i++){
            if(board[i][0] == 'O' && cache[i][0] == 0)  dfs(i,0,board,1);
            if(board[i][n-1] == 'O' && cache[i][n-1] == 0)  dfs(i,n-1,board,1);
        }
    }

    
    void dfs(int y,int x,vector<vector<char>>& board,int isedge){       // 벽에 닿는 블럭 있으면 
        if(isedge){    // cache 0인 부분에 대해서만 탐구한다 가정
            cache[y][x] = 1;
        }
        else{
            cache[y][x] = 1;
            board[y][x] = 'X';
        }
        if(inbound(y+1,x)){
            if(cache[y+1][x] ==0 && board[y+1][x] == 'O'){
                dfs(y+1,x,board,isedge);
            }
        }
        if(inbound(y-1,x)){
            if(cache[y-1][x] ==0 && board[y-1][x] == 'O'){
                dfs(y-1,x,board,isedge);
            }
        }
        if(inbound(y,x+1)){
            if(cache[y][x+1] ==0 && board[y][x+1] == 'O'){
                dfs(y,x+1,board,isedge);
            }
        }
        if(inbound(y,x-1)){
            if(cache[y][x-1] ==0 && board[y][x-1] == 'O'){
                dfs(y,x-1,board,isedge);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
       initialize(board);
       beforedfs(board);
        int count = 0;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){   // 가장자리 안쪽에 있는 둘러쌓인 블럭에 대해서만 탐구
                if(cache[i][j] == 0 && board[i][j] == 'O'){
                    dfs(i,j,board,0);
                    count++;
                }
            }
        }
       // cout<<m<<' '<<n<<count;
    }
};





