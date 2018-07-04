#include<bits/stdc++.h>

using namespace std;

vector<vector<char>> field;

void dfs(int x, int y, int H, int W){
    field[x][y] = '.';
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int abs_x = x + i, abs_y = y + j;
            if(0 <= abs_x && abs_x < H && 0 <= abs_y && abs_y < W && field[abs_x][abs_y] == 'W'){
                dfs(abs_x, abs_y, H, W);
            }
        }
    }
    return;
}

int main(){
    int H, W; cin >> H >> W;
    int ans = 0;

    field.resize(H);
    for (int i = 0; i < H; ++i) {
        field[i].resize(W);
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> field[i][j];
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if(field[i][j] == 'W'){
                dfs(i, j, H, W);
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}