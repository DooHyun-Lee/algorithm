
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> arr;
        arr.assign(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(obstacleGrid[i-1][j-1]) continue;  // 문제 해결의 핵심 포인트로 이 곳이 장애물일 경우 단순히 경우의 수 0으로 취급
                if(i == 1 && j ==1 )   {arr[i][j] = 1; continue;}
                if(i ==1)   {arr[i][j] = arr[i][j-1]; continue;}
                if(j ==1)   {arr[i][j] = arr[i-1][j]; continue;}    // 이 두 줄을 통해 가장자리에 장애물이 있는 경우 control
                arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }
        return arr[m][n];
    }
};
