// https://leetcode.com/problems/flood-fill/

// time complexity : O(N*M)
// space complexity : O(N*M) + O(N*M) for vis and stack

void dfs(vector<vector<int>> &vis, int orgColor, int color, int sr, int sc, vector<vector<int>> &image, int rows, int cols){
    vis[sr][sc] = 1;
    image[sr][sc] = color;

    // neigh 
    int delrow[] = {-1, +1, 0, 0};
    int delcol[] = {0, 0, -1, +1};

    for(int i = 0; i<4; i++){
        int nr = sr + delrow[i];
        int nc = sc + delcol[i];

        if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && vis[nr][nc] == -1 && image[nr][nc] == orgColor){
            dfs(vis, orgColor, color, nr, nc, image, rows, cols);
        }
    }

}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m = image.size();
    int n = image[0].size();

    int orgColor = image[sr][sc];

    vector<vector<int>>vis(m, vector<int>(n, -1));

    dfs(vis, orgColor, color, sr, sc, image, m, n);

    return image;
}